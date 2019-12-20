CREATE TABLE card (
	card_id INTEGER PRIMARY KEY AUTOINCREMENT,
	card_name VARCHAR(64) NOT NULL,
	card_attack INTEGER NOT NULL,
	card_heal INTEGER NOT NULL
);

CREATE TABLE monster (
	monster_id INTEGER PRIMARY KEY AUTOINCREMENT,
	monster_name VARCHAR(64) NOT NULL,
	monster_attack INTEGER NOT NULL,
	monster_health INTEGER NOT NULL
);

CREATE TABLE player (
	player_id INTEGER PRIMARY KEY AUTOINCREMENT,
	player_name VARCHAR(64) NOT NULL,
	player_attack INTEGER NOT NULL,
	player_health INTEGER NOT NULL
);

CREATE TABLE player_cards (
	player_id INTEGER REFERENCES player(player_id),
	amount INTEGER NOT NULL,
	card_id INTEGER REFERENCES card(card_id)
);

CREATE TABLE monster_cards (
	monster_id INTEGER REFERENCES monster(monster_id),
	amount INTEGER NOT NULL,
	card_id INTEGER REFERENCES card(card_id)
);

INSERT INTO card (card_name, card_attack, card_heal)
VALUES ('Punch I', 1, 0);
INSERT INTO card (card_name, card_attack, card_heal)
VALUES ('Punch II', 2, 0);
INSERT INTO card (card_name, card_attack, card_heal)
VALUES ('Shoot', 2, 0);
INSERT INTO card (card_name, card_attack, card_heal)
VALUES ('Double Shoot', 4, 0);
INSERT INTO card (card_name, card_attack, card_heal)
VALUES ('Shield', 0, 4);
INSERT INTO card (card_name, card_attack, card_heal)
VALUES ('Shield wall', 0, 8);

INSERT INTO player (player_name, player_attack, player_health)
VALUES ('Default', 0, 20);
INSERT INTO player (player_name, player_attack, player_health)
VALUES ('Tank', -1, 30);
INSERT INTO player (player_name, player_attack, player_health)
VALUES ('Assasin', 2, 15);

INSERT INTO monster (monster_name, monster_attack, monster_health)
VALUES ('Default', 0, 20);

INSERT INTO player_cards (player_id, amount, card_id)
VALUES (1, 5, 1);
INSERT INTO player_cards (player_id, amount, card_id)
VALUES (1, 1, 2);
INSERT INTO player_cards (player_id, amount, card_id)
VALUES (1, 1, 3);
INSERT INTO player_cards (player_id, amount, card_id)
VALUES (1, 2, 5);
INSERT INTO player_cards (player_id, amount, card_id)
VALUES (1, 1, 6);

INSERT INTO monster_cards (monster_id, amount, card_id)
VALUES (1, 5, 1);
INSERT INTO monster_cards (monster_id, amount, card_id)
VALUES (1, 5, 5);
