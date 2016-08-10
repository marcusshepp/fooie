const webpack = require('webpack');
const fs      = require('fs');
const path    = require('path'),
      join    = path.join,
      resolve = path.resolve;

const getConfig = require('hjs-webpack');

const cssModulesNames = `${isDev ? '[path][name]__[local]__': ''}[hash:base64:5]`;

var config = getConfig({
  in: join(__dirname, 'src/app.js'),
  out: join(__dirname, 'dist'),
  clearBeforeBuild: true
})

config.postcss = [].concat([
  require('precss')({}),
  require('autoprefixer')({}),
  require('cssnano')({})
])

const matchCssLoaders = /(^|!)(css-loader)($|!)/;
const findLoader = (loaders, match) => {
  const found = loaders.filter(l => l &&
    l.loader && l.loader.match(match));
  return found ? found[0] : null;
}
const cssloader = findLoader(config.module.loaders, matchCssLoaders);

module.exports = config;