var path = require('path');
module.exports = {

    entry: {
        javascript: path.join(__dirname, 'src/app.js'),
        html: path.join(__dirname, 'index.html')
    },
    output: {
        path: './',
        filename: 'bundle.js'
    },
    module: {
        loaders: [
            {
                test: /\.js$/,
                loaders: ['babel?presets[]=react,presets[]=es2015'],
                exclude: /node_modules/,
            },
            {
                test: /\.html$/,
                loader: "file?name=[name].[ext]",
            }
        ]
    }
}
