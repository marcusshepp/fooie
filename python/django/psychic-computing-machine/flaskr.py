import sqlite3
from contextlib import closing
from flask import (
		Flask, 
		request, 
		session, 
		g, 
		redirect, 
		url_for,
		abort, 
		render_template, 
		flash,
		)
from config import (
		DATABASE, 
		DEBUG,
		SECRET_KEY,
		USERNAME,
		PASSWORD,
		PROJECT_NAMES,
		)

# init app
app = Flask(__name__)
app.config.from_object(__name__)

def connect_db():
	"""to easily connect to the db specified in config"""
	return sqlite3.connect(app.config['DATABASE'])

def init_db():
	"""initialize db executes sql schema"""
	with closing(connect_db()) as db:
		with app.open_resource('schema.sql', mode='r') as f:
			db.cursor().executescript(f.read())
		db.commit()

# def add_column():
# 	q = "ALTER TABLE entries ADD archived INTEGER DEFAULT 0"
# 	g.db = connect_db()
# 	g.db.execute(q)
# 	g.db.commit()

@app.before_request
def before_request():
	g.db = connect_db()

@app.teardown_request
def teardown_request(exception):
	db = getattr(g, 'db', None)
	if db is not None:
		db.close()

""" Views """
@app.route('/')
def show_entries():

	q = 'SELECT title, text, id, project FROM entries WHERE archived=0 ORDER BY id desc'
	cur = g.db.execute(q)
	rows = cur.fetchall()
	entries = [dict(
			title=row[0], 
			text=row[1], 
			id=row[2], 
			project=row[3]) for row in rows]

	""" filter catagories as to not repeat """
	filtered_catagories = set([ x[3] for x in rows ])

	return render_template('show_entries.html', 
		entries=entries, 
		catagories=filtered_catagories,
		filtered=False,
		archived=False,
		)

@app.route('/filter/<project>', methods=['GET', 'POST'])
def filter_entries(project):
	""" TODO: rename project to catagory """

	query = 'SELECT title, text, id, project \
						FROM entries \
						WHERE project="%s"' % project
	cur = g.db.execute(query)
	entries = [dict(
			title=row[0], 
			text=row[1], 
			id=row[2], 
			project=row[3]) for row in cur.fetchall()]

	return render_template('show_entries.html', entries=entries, filtered=True)

@app.route('/add', methods=['POST'])
def add_entry():
	q = 'INSERT INTO entries (title, text, project) VALUES (?, ?, ?)'
	params = (
		str(request.form['title']), 
		str(request.form['text']), 
		str(request.form['project']))

	if not session.get('logged_in'):
		abort(401)

	# validation
	if request.form['title'] == "":
		flash("Title field was empty. Submission aborted")
		return redirect(url_for('show_entries'))

	if request.form['text'] == "":
		flash("Text field was empty. Submission aborted")
		return redirect(url_for('show_entries'))

	if request.form['project'] not in PROJECT_NAMES:
		flash("Select a catagory. Submission aborted")
		return redirect(url_for('show_entries'))

	g.db.execute(q, params)
	g.db.commit()
	flash("New entry successful.")

	return redirect(url_for('show_entries'))

@app.route('/view/<int:entry_id>', methods=['GET'])
def edit_render(entry_id):
	""" Render the correct object to be edited. """

	query = 'SELECT title, text, id, project FROM entries WHERE id="%s"' % str(entry_id)
	cur = g.db.execute(query)
	entry = [dict(
			title=row[0], 
			text=row[1], 
			id=row[2], 
			project=row[3]) for row in cur.fetchall()]

	return render_template('edit_entry.html', entry=entry)

@app.route('/edit/<int:entry_id>', methods=['POST'])
def edit_entry(entry_id):
	""" Updates the Text field of a giving entry. """

	if not session.get('logged_in'):
		about(401)

	query = 'UPDATE entries SET text="%s" WHERE id="%s"' % (
		request.form['text'], str(entry_id))
	g.db.execute(query)
	g.db.commit()
	flash("Entry Edited")

	return redirect(url_for('show_entries'))

@app.route('/archive', methods=['GET'])
def render_archives():
	""" renders only archived entries """

	q = "SELECT title, text, id, project FROM entries WHERE archived=1 ORDER BY id desc"
	cur = g.db.execute(q)
	rows = cur.fetchall()
	entries = [dict(
			title=row[0], 
			text=row[1], 
			id=row[2], 
			project=row[3]) for row in rows]

	""" filter catagories as to not repeat """
	filtered_catagories = set([ x[3] for x in rows ])

	return render_template('show_entries.html', 
		entries=entries, 
		catagories=filtered_catagories,
		filtered=False,
		archived=True,
		)

@app.route('/archive/<int:entry_id>', methods=['POST', 'GET'])
def archive_entry(entry_id):
	""" Archives an entry. """

	if not session.get('logged_in'):
		abort(401)

	query = 'UPDATE entries SET archived=1 WHERE id="%s"' % str(entry_id)
	g.db.execute(query)
	g.db.commit()
	flash('Entry Archived')

	return redirect(url_for('show_entries'))

@app.route('/archive-undo/<int:entry_id>', methods=['POST', 'GET'])
def archive_undo(entry_id):
	""" Undo an archived entry """

	if not session.get('logged_in'):
		abort(401)

	query = 'UPDATE entries SET archived=0 WHERE id="%s"' % str(entry_id)
	g.db.execute(query)
	g.db.commit()
	flash('Entry Unarchived')

	return redirect(url_for('render_archives'))

@app.route('/login', methods=['GET', 'POST'])
def login():

	error = None
	if request.method == 'POST':
		if request.form['username'] != app.config['USERNAME']:
			error = "Invalid username"
		elif request.form['password'] != app.config['PASSWORD']:
			error = "Invalid password"
		else:
			session['logged_in'] = True
			flash("You're logged in.")
			return redirect(url_for('show_entries'))

	return render_template('login.html', error=error)

@app.route('/logout')
def logout():

	session.pop('logged_in', None)
	flash('You\'re logged out')

	return redirect(url_for('show_entries'))

if __name__ == '__main__':
	app.run()
