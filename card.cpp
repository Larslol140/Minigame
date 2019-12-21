#include "card.h"

void Card::setValues()
{
  this->img_path = db->getCardImgPath(card_id);
  this->attack_value = db->getCardAttackValue(card_id);
  this->heal_value = db->getCardHealValue(card_id);
  this->card_name = db->getCardName(card_id);
}

Card::Card(int card_id)
{
  db = Database::getInstance();
  this->card_id = card_id;
  setValues();
}

int Card::getHealValue() const
{
  return heal_value;
}

int Card::getAttackValue() const
{
  return attack_value;
}

int Card::getCardId() const
{
  return card_id;
}

QString Card::getCardName() const
{
  return card_name;
}

QString Card::getImgPath() const
{
  return img_path;
}

QString Card::getAttackText() const
{
  return "Attack: "+QString::number(attack_value)+"\n";
}

QString Card::getHealText() const
{
  return "\nHeal: "+QString::number(heal_value);
}
