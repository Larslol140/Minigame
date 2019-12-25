#ifndef CONFIG_H
#define CONFIG_H

#include <QRect>
#include <QColor>
#include <QString>

struct Pos {
    double x;
    double y;
    double w;
    double h;
};

const QString DB_FILE = "data.db";
const QString SETTINGS_FILE = "settings.ini";

const QColor BACKGROUND_COLOR       = QColor(Qt::gray);

const QColor SELECTED_CARD_COLOR    = QColor(Qt::white);
const QColor UNSELECTED_CARD_COLOR  = QColor(Qt::lightGray);
const QColor OUTLINE_AND_TEXT_COLOR = QColor(Qt::black);

const QColor HEALTH_COLOR       = QColor(Qt::darkGreen);
const QColor ATTACK_COLOR       = QColor(Qt::red);

const QColor HEALTH_BAR_COLOR   = QColor(Qt::yellow);

const Pos MONSTER_CARD_LEFT   = {0.78750, 0.0555, 0.08125, 0.2222};
const Pos MONSTER_CARD_RIGHT  = {0.89375, 0.0555, 0.08125, 0.2222};
const Pos MONSTER_STATUS_BAR  = {0.18750, 0.2222, 0.56250, 0.0555};
const Pos MONSTER_AVATAR_IMG  = {0.03150, 0.0555, 0.12500, 0.2222};

const Pos PLAYER_CARD_LEFT    = {0.72500, 0.5555, 0.10625, 0.2777};
const Pos PLAYER_CARD_RIGHT   = {0.86250, 0.5555, 0.10625, 0.2777};
const Pos PLAYER_STATUS_BAR   = {0.03150, 0.8888, 0.93750, 0.0555};
const Pos PLAYER_AVATAR_IMG   = {0.03150, 0.5555, 0.15625, 0.2777};

const Pos START_NEW_GAME      = {0.03150, 0.4444, 0.15625, 0.0555};

#endif // CONFIG_H
