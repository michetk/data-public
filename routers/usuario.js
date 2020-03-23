const express = require('express')
router = express.Router()
const mongoose = require('mongoose')
const bcrypt = require('bcryptjs')
const passport = require('passport')
require('../models/Usuario')
const Usuario = mongoose.model('usuarios')

router.get('/registro', (req, res) => {
    res.render('usuarios/registro')
})

router.post('/registro/reg', (req, res) => {
    let erro = ''

    if (!req.body.nome || typeof req.body.nome == undefined || req.body.nome == null) {
        erro = 'Campo nome vazio!'
    } else if (!req.body.email || typeof req.body.email == undefined || req.body.email == null) {
        erro = 'Campo e-mail vazio!'
    } else if (!req.body.senha || typeof req.body.senha == undefined || req.body.senha == null) {
        erro = 'campo senha vazio!'
    } else if (req.body.senha != req.body.senha2) {
        erro = 'Senhas diferentes!'
    } else {

        Usuario.findOne({ email: req.body.email }).then((usuario) => {
            if (usuario) {
                req.flash('error_msg', 'Usuário já existe!')
                res.redirect('/usuarios/registro')
            } else {
                const novoUsuario = new Usuario({
                    nome: req.body.nome,
                    email: req.body.email,
                    senha: req.body.senha
                })

                bcrypt.genSalt(10, (err, salt) => {

                    bcrypt.hash(novoUsuario.senha, salt, (err, hash) => {
                        if (err) {
                            req.flash('error_msg', 'Houve um erro durane o salvamento do usuário!')
                            res.redirect('/usuarios/registro')
                        }

                        novoUsuario.senha = hash

                        novoUsuario.save().then(() => {
                            req.flash('success_msg', 'Usuário salvo com sucesso')
                            res.redirect('/admin')
                        }).catch((err) => {
                            req.flash('error_msg', 'Houve um erro durante o salvamento do usuário!')
                            res.redirect('/usuarios/registro')
                        })
                    })

                }).catch((err) => {
                    req.flash('error_msg', 'Houve um erro interno!')
                    res.redirect('/usuarios/registro')
                })
            }
        })

    }

    if (erro) {
        req.flash('error_msg', erro)
        res.redirect('/usuarios/registro')
    }

})

router.get('/login', (req, res) => {
    res.render('usuarios/login')
})

router.post('/login', (req, res, next) => {
    passport.authenticate('local', {
        successRedirect: '/',
        failureRedirect: '/usuarios/login',
        failureFlash: true
    })(req, res, next)
})

router.get('/logout', (req, res) => {
    req.logout()
    req.flash('success_msg', 'Você saiu da sua conta com sucesso')
    res.redirect('/')
})

module.exports = router