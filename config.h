#ifndef CONFIG_H
#define CONFIG_H

#include <QRect>
#include <QColor>
#include <QString>

const QString DB_FILE = "data.db";
const QString SETTINGS_FILE = "settings.ini";

const QColor BACKGROUND_COLOR       = QColor(Qt::gray);

const QColor SELECTED_CARD_COLOR    = QColor(Qt::white);
const QColor UNSELECTED_CARD_COLOR  = QColor(Qt::lightGray);
const QColor OUTLINE_AND_TEXT_COLOR = QColor(Qt::black);

const QColor HEALTH_COLOR       = QColor(Qt::darkGreen);
const QColor ATTACK_COLOR       = QColor(Qt::red);

const QColor HEALTH_BAR_COLOR   = QColor(Qt::yellow);

const QRect MONSTER_CARD_LEFT   = QRect(20, 80, 200, 300);
const QRect MONSTER_CARD_RIGHT  = QRect(620, 80, 200, 300);
const QRect MONSTER_STATUS_BAR  = QRect(20, 20, 800, 40);
const QRect PLAYER_CARD_LEFT    = QRect(20, 400, 200, 300);
const QRect PLAYER_CARD_RIGHT   = QRect(620, 400, 200, 300);
const QRect PLAYER_STATUS_BAR   = QRect(20, 720, 800, 40);

const QRect START_NEW_GAME      = QRect(400, 375, 40, 40);

#endif // CONFIG_H
