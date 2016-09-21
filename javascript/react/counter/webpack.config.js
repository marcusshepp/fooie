module.exports = {
	entry: './app.js',
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
		}
		]
	}
}
