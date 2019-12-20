#include "model.h"

Model *Model::instance = nullptr;

Model::Model(QObject *parent) : QObject (parent)
{
  player = nullptr;
  monster = nullptr;
  startGame(1, 1);
}

Player *Model::getPlayer()
{
  return player;
}

Monster *Model::getMonster()
{
  return monster;
}

bool Model::isPlayerAlive()
{
  return (player->getHealthValue() > 0);
}

bool Model::isMonsterAlive()
{
  return (monster->getHealthValue() > 0);
}

void Model::nextTurn()
{
  player->drawCards();
  monster->drawCards();
}

Model::~Model()
{
  delete player;
  delete monster;
  instance = nullptr;
}

void Model::startGame(int player_id, int monster_id)
{
  player = new Player(player_id);
  monster = new Monster(monster_id);
  nextTurn();
}

void Model::endGame()
{
  delete player;
  player = nullptr;
  delete monster;
  monster = nullptr;
}

void Model::restartGame(int player_id, int monster_id)
{
  endGame();
  startGame(player_id, monster_id);
}

void Model::selectLeftPlayerCard()
{
  player->selectCard(player->getLeftCard());
}

void Model::selectRightPlayerCard()
{
  player->selectCard(player->getRightCard());
}

void Model::selectNoPlayerCard()
{
  player->selectCard(nullptr);
}

void Model::selectLeftMonsterCard()
{
  monster->selectCard(monster->getLeftCard());
}

void Model::selectRightMonsterCard()
{
  monster->selectCard(monster->getRightCard());
}

void Model::selectNoMonsterCard()
{
  monster->selectCard(nullptr);
}

void Model::playerTurn()
{
  if (isGameFinished()) return;
  if (player->isCardSelected())
  {
    attackMonster();
    healPlayer();
    nextTurn();
  }
  monsterAutoTurn();
}

void Model::monsterTurn()
{
  if (isGameFinished()) return;
  if (monster->isCardSelected())
  {
    attackPlayer();
    healMonster();
    nextTurn();
  }
}

bool Model::isThisCardSelected(Card *card) const
{
  if ( monster->getSelectedCard() == card || player->getSelectedCard() == card )
    return true;
  return false;
}

void Model::attackPlayer()
{
  player->attackWith(monster->getSelectedCard());
  if (!isPlayerAlive())
    emit playerDead();
}

void Model::attackMonster()
{
  monster->attackWith(player->getSelectedCard());
  if (!isMonsterAlive())
    emit monsterDead();
}

void Model::healPlayer()
{
  player->healWith(player->getSelectedCard());
}

void Model::healMonster()
{
  monster->healWith(monster->getSelectedCard());
}

void Model::monsterAutoTurn()
{
  if ( rand() % 1 == 0 )
    monster->selectCard(monster->getLeftCard());
  else
    monster->selectCard(monster->getRightCard());
  monsterTurn();
}

bool Model::isGameFinished()
{
  return !(isPlayerAlive() && isMonsterAlive());
}

Model *Model::getInstance(QObject *parent)
{
  if (instance == nullptr)
    instance = new Model(parent);
  return instance;
}
