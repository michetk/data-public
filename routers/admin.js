const mongoose = require('mongoose')
const express = require('express')
router = express.Router()
require('../models/Categoria')
const Categoria = mongoose.model('categorias')
require('../models/Postagem')
const Postagem = mongoose.model('postagens')
const {eAdmin} = require('../helpers/eAdmin')

router.get('/', eAdmin, (req, res) => {
    res.render('admin/index')
})

// categoria
router.get('/cadcategorias', eAdmin, (req, res) => {
    res.render('admin/cadcategorias')
})

router.post('/cadcategorias/cad', eAdmin, (req, res) => {
    let erros = []

    if (!req.body.nome || typeof req.body.nome == undefined || req.body.nome == null) {
        erros.push({ texto: 'Campo nome vazio, preenca o campo!' })
    }
    if (!req.body.slug || typeof req.body.slug == undefined || req.body.slug == null) {
        erros.push({ texto: 'Campo slug vazio, preencha o campo!' })
    }
    if ((req.body.nome && !isNaN(req.body.nome)) || (req.body.slug && !isNaN(req.body.slug))) {
        erros.push({ texto: 'Não é permitido só numero!' })
    }
    if (req.body.nome.length <= 2 || req.body.slug.length <= 2) {
        erros.push({ texto: 'O campo não pode ter menos que 4 caracteres!' })
    }
    if (erros.length > 0) {
        res.render('admin/cadcategorias', { erros: erros })
    } else {
        const novaCategoria = {
            nome: req.body.nome.toUpperCase(),
            slug: req.body.slug.toLowerCase()
        }

        new Categoria(novaCategoria).save().then(() => {
            req.flash('success_msg', 'Categoria cadastrada com sucesso!')
            res.redirect('/categorias')
        }).catch((err) => {
            req.flash('error_msg', 'Erro ao cadastrar categoria!')
            res.redirect('/admin')
        })
    }
})

router.get('/cadcategorias/edit/:id', eAdmin, (req, res) => {
    Categoria.findOne({ _id: req.params.id }).lean().then((categoria) => {
        res.render('admin/editcategoria', { categoria: categoria })
    }).catch((err) => {
        req.flash('error_msg', 'Erro ao carrecar página de edição de categoria')
        res.redirect('/categorias')
    })
})

router.post('/cadcategorias/edited', eAdmin, (req, res) => {
    Categoria.findOne({ _id: req.body.id }).then((categoria) => {
        let erros = []

        if (!req.body.nome || typeof req.body.nome == undefined || req.body.nome == null) {
            erros.push({ texto: 'Campo nome vazio, preenca o campo!' })
        }
        if (!req.body.slug || typeof req.body.slug == undefined || req.body.slug == null) {
            erros.push({ texto: 'Campo slug vazio, preencha o campo!' })
        }
        if ((req.body.nome && !isNaN(req.body.nome)) || (req.body.slug && !isNaN(req.body.slug))) {
            erros.push({ texto: 'Não é permitido só numero!' })
        }
        if (req.body.nome.length <= 2 || req.body.slug.length <= 2) {
            erros.push({ texto: 'O campo não pode ter menos que 2 caracteres!' })
        }
        if (erros.length > 0) {
            res.render('admin/editcategoria', { erros: erros })
        } else {
            categoria.nome = req.body.nome.toUpperCase()
            categoria.slug = req.body.slug.toLowerCase()
            categoria.save().then(() => {
                req.flash('success_msg', 'Categoria editada com sucesso!')
                res.redirect('/categorias')
            }).catch((err) => {
                req.flash('error_msg', 'Erro ao salvar categoria!')
                res.redirect('/admin/cadcategorias/edit/' + req.body.id)
            })
        }
    }).catch((err) => {
        req.flash('error_msg', 'Categoria não encontrada!')
        res.redirect('/admin/cadcategorias/edit/' + req.body.id)
    })
})

router.get('/cadcategorias/del/:id', eAdmin, (req, res) => {
    Categoria.findOne({ _id: req.params.id }).then((categoria) => {
        categoria.remove()
        req.flash('success_msg', 'Categoria removida com sucesso!')
        res.redirect('/categorias')
    }).catch((err) => {
        req.flash('error_msg', 'Erro, categoria não encontrada!')
        res.redirect('/categorias')
    })
})

// Postagem
router.get('/cadpostagens', eAdmin, (req, res) => {
    Categoria.find().lean().sort({ nome: 1 }).then((categorias) => {
        res.render('admin/cadpostagens', { categorias: categorias })
    }).catch((err) => {
        req.flash('error_msg', 'Erro no campo de categorias')
        res.redirect('/postagens')
    })
})

router.post('/cadpostagens/cad', eAdmin, (req, res) => {
    let erros = []

    if (!req.body.titulo || typeof req.body.titulo == undefined || req.body.titulo == null) {
        erros.push({ texto: 'Campo título vazio, preenca o campo!' })
    }
    if (!req.body.descricao || typeof req.body.desdricao == undefined || req.body.descricao == null) {
        erros.push({ texto: 'Campo descrição vazio, preencha o campo!' })
    }
    if (!req.body.conteudo || typeof req.body.conteudo == undefined || req.body.conteudo == null) {
        erros.push({ texto: 'Campo conteúdo vazio, preencha o campo!' })
    }
    if ((req.body.titulo && !isNaN(req.body.titulo)) || (req.body.descricao && !isNaN(req.body.descricao))) {
        erros.push({ texto: 'Não é permitido só numero!' })
    }
    if (req.body.titulo.length <= 2 || req.body.conteudo.length <= 2) {
        erros.push({ texto: 'O campo não pode ter menos que 3 caracteres!' })
    }
    if (erros.length > 0) {
        res.render('admin/cadpostagens', { erros: erros })
    } else {
        const novaPostagem = {
            titulo: req.body.titulo.toUpperCase(),
            descricao: req.body.descricao.toUpperCase(),
            conteudo: req.body.conteudo,
            categoria: req.body.categoria
        }

        new Postagem(novaPostagem).save().then(() => {
            req.flash('success_msg', 'Postagem cadastrada com sucesso!')
            res.redirect('/postagens')
        }).catch((err) => {
            req.flash('error_msg', 'Erro ao cadastrar postagem!')
            res.redirect('/postagens')
        })
    }
})

router.get('/cadpostagens/edit/:id', eAdmin, (req, res) => {
    Postagem.findOne({ _id: req.params.id }).lean().then((postagem) => {
        Categoria.find().lean().sort({ nome: 1 }).then((categorias) => {
            res.render('admin/editpostagens', { postagem: postagem, categorias: categorias })
        }).catch((err) => {
            req.flash('error_msg', 'Erro ao carregar campo de categorias!')
            res.redirect('/postagens')
        })
    }).catch((err) => {
        req.flash('error_msg', 'Erro ao carrecar postagem')
        res.redirect('/postagens')
    })
})

router.post('/cadpostagens/edited', eAdmin, (req, res) => {
    let erros = []

    if (!req.body.titulo || typeof req.body.titulo == undefined || req.body.titulo == null) {
        erros.push({ texto: 'Campo título vazio, preenca o campo!' })
    }
    if (!req.body.descricao || typeof req.body.desdricao == undefined || req.body.descricao == null) {
        erros.push({ texto: 'Campo descrição vazio, preencha o campo!' })
    }
    if (!req.body.conteudo || typeof req.body.conteudo == undefined || req.body.conteudo == null) {
        erros.push({ texto: 'Campo conteúdo vazio, preencha o campo!' })
    }
    if ((req.body.titulo && !isNaN(req.body.titulo)) || (req.body.descricao && !isNaN(req.body.descricao))) {
        erros.push({ texto: 'Não é permitido só numero!' })
    }
    if (req.body.titulo.length <= 2 || req.body.conteudo.length <= 2) {
        erros.push({ texto: 'O campo não pode ter menos que 3 caracteres!' })
    }
    if (erros.length > 0) {
        res.render('admin/cadpostagens', { erros: erros })
    } else {
        Postagem.findOne({ _id: req.body.id }).then((postagem) => {
            postagem.titulo = req.body.titulo.toUpperCase()
            postagem.descricao = req.body.descricao.toUpperCase()
            postagem.conteudo = req.body.conteudo
            postagem.categoria = req.body.categoria
            postagem.save().then(() => {
                req.flash('success_msg', 'Postagem editada com sucesso!')
                res.redirect('/postagens')
            }).catch((err) => {
                req.flash('error_msg', 'Erro ao salvar postagem!')
                res.redirect('/admin/cadpostagens/edit/' + req.body.id)
            })
        }).catch((err) => {
            req.flash('error_msg', 'Postagem não encontrada!')
            res.redirect('/admin/cadpostagens/edit/' + req.body.id)
        })
    }
})

router.get('/cadpostagens/del/:id', eAdmin, (req, res) => {
    Postagem.findOne({ _id: req.params.id }).then((postagem) => {
        postagem.remove()
        req.flash('success_msg', 'Postagem removida com sucesso!')
        res.redirect('/postagens')
    }).catch((err) => {
        req.flash('error_msg', 'Erro, postagem não encontrada!')
        res.redirect('/postagens')
    })
})

router.get('/postcategoria/:id', eAdmin, (req, res) => {
    Categoria.findOne({ _id: req.params.id }).lean().then((categoria) => {
        if (categoria) {
            Postagem.find({categoria: categoria._id}).lean().sort({ titulo: 1 }).then((postagens) => {
                if (postagens) {
                    res.render('admin/postcategoria', { categoria: categoria, postagens: postagens })
                } else {
                    req.flash('error_msg', 'Categoria sem postagens!')
                    res.redirect('/categorias')
                }
            }).catch((err) => {
                req.flash('error_msg', 'Houve um erro interno!')
                res.redirect('/categorias')
            })
        } else {
            req.flash('error_msg', 'Categoria não encontrada!')
            res.redirect('/categorias')
        }
    }).catch((err) => {
        req.flash('error_msg', 'Houve um erro interno!')
        res.redirect('/categorias')
    })
})

module.exports = router