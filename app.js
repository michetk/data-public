const express = require('express')
const app = express()
const handlebars = require('express-handlebars')
const path = require('path')
const admin = require('./routers/admin')
const usuarios = require('./routers/usuario')
const mongoose = require('mongoose')
const bodyParser = require('body-parser')
const session = require('express-session')
const flash = require('connect-flash')
const passport = require('passport')
const db = require('./config/db')
require('./models/Categoria')
Categoria = mongoose.model('categorias')
require('./models/Postagem')
Postagem = mongoose.model('postagens')
require('./config/auth')(passport)

// session
app.use(session({
    secret: 'chave-secreta',
    resave: true,
    saveUninitialized: true
}))
app.use(passport.initialize())
app.use(passport.session())
app.use(flash())

// middleware
app.use((req, res, next) => {
    res.locals.success_msg = req.flash('success_msg')
    res.locals.error_msg = req.flash('error_msg')
    res.locals.error = req.flash('error')
    res.locals.user = req.user || null
    next()
})

// body-parser
app.use(bodyParser.urlencoded({ extended: true }))
app.use(bodyParser.json())

// handlebars
app.engine('handlebars', handlebars({ defaultLayout: 'main' }))
app.set('view engine', 'handlebars')

// file static
app.use(express.static(path.join('public')))

// mongoose
mongoose.Promise = global.Promise
mongoose.connect(db.mongoURI, { useNewUrlParser: true, useUnifiedTopology: true }).then(() => {
    console.log('Mongoose Conectato!')
}).catch((err) => {
    console.log('Falha ao Conectar Mongoose: ' + err)
})

// rotas
app.use('/admin', admin)
app.use('/usuarios', usuarios)

app.get('/', (req, res) => {
    res.render('index')
})

app.get('/categorias', (req, res) => {
    Categoria.find().lean().then((categorias) => {
        res.render('categorias/categorias', { categorias: categorias })
    })
})

app.get('/postagens', (req, res) => {
    Postagem.find().lean().then((postagens) => {
        res.render('postagens/postagens', {postagens: postagens})
    })
})



const PORT = process.env.PORT || 8081
app.listen(PORT, () => {
    console.log('Servidor Conectado')
})