const express = require('express');
const bodyParser = require('body-parser');

// creates app
const app = express();

// parse requests of content-type - application/x-www-form-urlencoded
app.use(bodyParser.urlencoded({extended: true}));

// parse requests of content-type - application/json
app.use(bodyParser.json());

const dbConfig = require('./config/database.config.js');
const mongoose = require('mongoose');

mongoose.Promise = global.Promise;

// connecting to the database
mongoose.connect(dbConfig.url, {
  useNewUrlParser: true
}).then(() => {
  console.log("successfully connected to the database");
}).catch(err => {
  console.log("could not connect to the database. exiting", err);
  process.exit();
});

// define a simple route
app.get('/', (req, res) => {
  res.json({ "message": "welcome fool" });
});

// requite notes routes
require('./app/routes/note.routes.js')(app);

app.listen(3000, () => {
  console.log("server is listening on port 3000");
});
