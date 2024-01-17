-- Create the following tables if finance.db doesn't have.
CREATE TABLE holding (
	user_id INTEGER NOT NULL,
	symbol TEXT NOT NULL,
	shares INTEGER NOT NULL,
	total NUMERIC NOT NULL,
	FOREIGN KEY(user_id) REFERENCES users(id)
);

CREATE TABLE history (
	user_id INTEGER NOT NULL,
	symbol TEXT NOT NULL,
	shares INTEGER NOT NULL,
	total NUMERIC NOT NULL,
	action TEXT NOT NULL,
	date TEXT NOT NULL,
	FOREIGN KEY(user_id) REFERENCES users(id)
);
