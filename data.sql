CREATE TABLE card (
	card_id INTEGER PRIMARY KEY AUTOINCREMENT,
	card_name VARCHAR(64) NOT NULL,
	card_attack INTEGER NOT NULL,
	card_heal INTEGER NOT NULL,
	card_img_path VARCHAR(255) NOT NULL
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

INSERT INTO card (card_name, card_img_path, card_attack, card_heal)
VALUES ('Punch I', ':/src/images/punch.png', 1, 0);
INSERT INTO card (card_name, card_img_path, card_attack, card_heal)
VALUES ('Punch II', ':/src/images/punch.png', 2, 0);
INSERT INTO card (card_name, card_img_path, card_attack, card_heal)
VALUES ('Shoot', ':/src/images/shot.png', 2, 0);
INSERT INTO card (card_name, card_img_path, card_attack, card_heal)
VALUES ('Double Shoot', ':/src/images/double_shot.png', 4, 0);
INSERT INTO card (card_name, card_img_path, card_attack, card_heal)
VALUES ('Shield', ':/src/images/shield.png', 0, 1);
INSERT INTO card (card_name, card_img_path, card_attack, card_heal)
VALUES ('Shield wall', ':/src/images/shield_wall.png', 0, 2);

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
INSERT INTO player_cards (player_id, amount, card_id)
VALUES (1, 1, 3);
INSERT INTO player_cards (player_id, amount, card_id)
VALUES (1, 1, 4);

INSERT INTO monster_cards (monster_id, amount, card_id)
VALUES (1, 5, 1);
INSERT INTO monster_cards (monster_id, amount, card_id)
VALUES (1, 2, 5);
INSERT INTO monster_cards (monster_id, amount, card_id)
VALUES (1, 5, 4);
