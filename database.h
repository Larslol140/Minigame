#ifndef DATABASE_H
#define DATABASE_H

#include <QtCore>
#include <QtSql>
#include "config.h"

class Database
{
  private:
    static Database *instance;
    Database();

    void        loadDatabase();

    int         genericIntQuery(QString table, QString column, int id);
    QString     genericQStringQuery(QString table, QString column, int id);
    QVariant    genericQuery(QString table, QString column, int id);

    int         getCardAmount(QString table, int type_id, int card_id);
    QSqlQuery   getSqlQuery();

    QList<int>  getCardsFrom(QString table, int id);

  public:
    ~Database();
    static Database *getInstance();

    int         getCardAttackValue(int id);
    int         getCardHealValue(int id);

    int         getMonsterAttackValue(int id);
    int         getMonsterHealthValue(int id);

    int         getPlayerAttackValue(int id);
    int         getPlayerHealthValue(int id);

    int         getPlayerCardAmount(int player_id, int card_id);
    int         getMonsterCardAmount(int monster_id, int card_id);

    QString     getCardImgPath(int id);

    QString     getPlayerName(int id);
    QString     getMonsterName(int id);
    QString     getCardName(int id);

    QList<int>  getPlayerCardDeck(int id);
    QList<int>  getMonsterCardDeck(int id);
};

#endif // DATABASE_H
