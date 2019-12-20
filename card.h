#ifndef CARD_H
#define CARD_H

#include "database.h"

class Card
{

  private:
    Database *db;

    int       heal_value;
    int       attack_value;
    int       card_id;
    QString   card_name;

    void setValues();

  public:
    Card(int card_id);

    int       getHealValue() const;
    int       getAttackValue() const;
    int       getCardId() const;
    QString   getCardName() const;

    QString   getAttackText() const;
    QString   getHealText() const;
};

#endif // CARD_H
