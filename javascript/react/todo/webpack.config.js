var webpack = require("webpack");
var path = require("path");

module.exports = {
    entry: [
		"webpack-dev-server/client?http://localhost:8080",
		"webpack/hot/only-dev-server",
		"./src",
	],
    output: {
        path: path.join(__dirname, "bin"),
        filename: 'bundle.js',
    },
	resolve: {
		modulesDirectories: ["node_modules", "src"],
		extensions: ["", ".js"]
	},
    module: {
        loaders: [
            {
                test: /\.js$/,
                exclude: /node_modules/,
                loaders: ["react-hot", "babel?presets[]react,presets[]=es2015"],
            }
        ]
    },
	plugins: [
		new webpack.HotModuleReplacementPlugin(),
		new webpack.NoErrorsPlugin(),
	]
}
