module.exports = process.env.NODE_ENV == 'production' ? {
    mongoURI: 'mongodb+srv://root:6451@dbex-juoyu.mongodb.net/test?retryWrites=true&w=majority'
} : {
    mongoURI: 'mongodb://localhost/blogapp'
}