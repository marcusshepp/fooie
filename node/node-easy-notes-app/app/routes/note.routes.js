module.exports = (app) => {
  const notes = require('../controllers/note.controller.js');

  // Create a new note
  app.post('/notes', notes.create);

  // retrieve all notes
  app.get('/notes', notes.findAll);

  // retrieve a single note with noteId
  app.get('/notes/:noteId', notes.findOne);

  // update a note with noteId
  app.put('/notes/:noteId', notes.update);

  // delete a note with noteId
  app.delete('/notes/:noteId', notes.delete);
}
