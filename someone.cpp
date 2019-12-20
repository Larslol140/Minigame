#include "someone.h"

void Someone::clearCards()
{
  delete leftCard;
  leftCard = nullptr;
  delete rightCard;
  rightCard = nullptr;
  selectedCard = nullptr;
}

void Someone::drawCards()
{
  clearCards();
  leftCard = new Card(getRandomCardId());
  rightCard = new Card(getRandomCardId());
}

void Someone::selectCard(Card *card)
{
  selectedCard = card;
}

void Someone::healWith(Card *card)
{
  this->health += card->getHealValue();
}

void Someone::attackWith(Card *card)
{
  this->health -= card->getAttackValue();
  if ( health < 0 ) health = 0;
}

int Someone::getRandomCardId()
{
  while (true)
    foreach (int id, cards)
      if ( rand() % 5 == 0 )
        return id;
}

Someone::Someone()
{
  db = Database::getInstance();
  srand(uint(time(nullptr)));
}

Someone::~Someone()
{
  clearCards();
}

int Someone::getAttackValue()
{
  return attack;
}

int Someone::getHealthValue()
{
  return health;
}

QString Someone::getHealthText()
{
  return "Health: "+QString::number(health);
}

Card *Someone::getLeftCard()
{
  return leftCard;
}

Card *Someone::getRightCard()
{
  return rightCard;
}

Card *Someone::getSelectedCard()
{
  return selectedCard;
}

bool Someone::isCardSelected()
{
  return selectedCard != nullptr;
}

void Player::setDefaultValues()
{
  this->cards         = db->getPlayerCardDeck(player_id);
  this->health        = db->getPlayerHealthValue(player_id);
  this->attack        = db->getPlayerAttackValue(player_id);
  this->name          = db->getPlayerName(player_id);
  this->leftCard         = nullptr;
  this->rightCard         = nullptr;
  this->selectedCard  = nullptr;
}

Player::Player(int id)
{
  player_id = id;
  setDefaultValues();
}

void Monster::setDefaultValues()
{
  this->cards   = db->getMonsterCardDeck(monster_id);
  this->health  = db->getMonsterHealthValue(monster_id);
  this->attack  = db->getMonsterAttackValue(monster_id);
  this->name    = db->getMonsterName(monster_id);
  this->leftCard         = nullptr;
  this->rightCard         = nullptr;
  this->selectedCard  = nullptr;
}

Monster::Monster(int id)
{
  monster_id = id;
  setDefaultValues();
}
