#ifndef SOMEONE_H
#define SOMEONE_H

#include "card.h"

class Someone
{
  protected:
    Database    *db;

    int         health;
    int         attack;
    QString     name;

    Card        *card1;
    Card        *card2;

    Card        *selectedCard;

    QList<int>  cards;

    void        clearCards();
    int         getRandomCardId();

  public:
    Someone();
    ~Someone();

    int       getAttackValue();
    int       getHealthValue();
    QString   getName();

    QString   getHealthText();

    Card      *getCard1();
    Card      *getCard2();
    Card      *getSelectedCard();
    bool      isCardSelected();

    void      drawCards();
    void      selectCard(Card *card);

    void      attackWith(Card *card);
    void      healWith(Card *card);

};

class Player : public Someone
{
  private:
    int   player_id;
    void  setDefaultValues();

  public:
    Player(int id);
};

class Monster : public Someone
{
  private:
    int   monster_id;
    void  setDefaultValues();

  public:
    Monster(int id);
};

#endif // SOMEONE_H
