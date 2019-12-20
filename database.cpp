#include "database.h"

Database *Database::instance = nullptr;

Database::Database()
{
  loadDatabase();
}

void Database::loadDatabase()
{
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "DB_CONN");
  db.setDatabaseName(DB_FILE);

  if (QFile::exists(DB_FILE) && db.open())
    qDebug() << "Database opend";
  else
    qDebug() << "Database error";
}

QSqlQuery Database::getSqlQuery()
{
  QSqlDatabase db = QSqlDatabase::database("DB_CONN");
  QSqlQuery q(db);
  return q;
}

QList<int> Database::getCardsFrom(QString table, int id)
{
  QList<int> tmp;
  QSqlQuery q = getSqlQuery();
  q.exec("SELECT card_id FROM "+table+"_cards WHERE "+table+"_id="+QString::number(id));
  while (q.next())
    tmp.append(q.value(0).toInt());
  return tmp;
}

int Database::genericIntQuery(QString table, QString column, int id)
{
  return genericQuery(table, column, id).toInt();
}

QString Database::genericQStringQuery(QString table, QString column, int id)
{
  return genericQuery(table, column, id).toString();
}

QVariant Database::genericQuery(QString table, QString column, int id)
{
  QSqlQuery q = getSqlQuery();
  q.exec("SELECT "+column+" FROM "+table+" WHERE "+table+"_id="+QString::number(id));
  if ( q.first() )
    return q.value(0);
  else
    return 0;
}

int Database::getCardAmount(QString type, int type_id, int card_id)
{
  QSqlQuery q = getSqlQuery();
  q.exec("SELECT amount FROM "+type+"_cards WHERE "+type+"_id="+QString::number(type_id)+" AND card_id="+QString::number(card_id));
  if (q.first())
    return q.value(0).toInt();
  return
      -1;
}

int Database::getCardAttackValue(int id)
{
  return genericIntQuery("card", "card_attack", id);
}

int Database::getCardHealValue(int id)
{
  return genericIntQuery("card", "card_heal", id);
}

int Database::getMonsterAttackValue(int id)
{
  return genericIntQuery("monster", "monster_attack", id);
}

int Database::getMonsterHealthValue(int id)
{
  return genericIntQuery("monster", "monster_health", id);
}

int Database::getPlayerAttackValue(int id)
{
  return genericIntQuery("player", "player_health", id);
}

int Database::getPlayerHealthValue(int id)
{
  return genericIntQuery("player", "player_health", id);
}

int Database::getPlayerCardAmount(int player_id, int card_id)
{
  return getCardAmount("player", player_id, card_id);
}

int Database::getMonsterCardAmount(int monster_id, int card_id)
{
  return getCardAmount("monster", monster_id, card_id);
}

QString Database::getPlayerName(int id)
{
  return genericQStringQuery("player", "player_name", id);
}

QString Database::getMonsterName(int id)
{
  return genericQStringQuery("monster", "monster_name", id);
}

QString Database::getCardName(int id)
{
  return genericQStringQuery("card", "card_name", id);
}

QList<int> Database::getPlayerCardDeck(int id)
{
  return getCardsFrom("player", id);
}

QList<int> Database::getMonsterCardDeck(int id)
{
  return getCardsFrom("monster", id);
}

Database::~Database()
{
  instance = nullptr;
}

Database *Database::getInstance()
{
  if (instance == nullptr)
    instance = new Database;
  return instance;
}
