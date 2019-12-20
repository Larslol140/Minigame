#include "view.h"

void View::selectPlayerCard(const QPoint &point)
{
  if (PLAYER_CARD_LEFT.contains(point))
    model->selectLeftPlayerCard();
  else if (PLAYER_CARD_RIGHT.contains(point))
    model->selectRightPlayerCard();
}

void View::selectMonsterCard(const QPoint &point)
{
  if (MONSTER_CARD_LEFT.contains(point))
    model->selectLeftMonsterCard();
  else if (MONSTER_CARD_RIGHT.contains(point))
    model->selectRightMonsterCard();
}

void View::playSelectedCards()
{
  if (model->getPlayer()->isCardSelected())
    model->playerTurn();
  else if (model->getMonster()->isCardSelected())
    model->monsterTurn();
  else
  {
    model->getPlayer()->selectCard(nullptr);
    model->getMonster()->selectCard(nullptr);
  }
}

void View::drawMonsterElements(QPainter &painter)
{
  drawMonsterStatusBar(painter, model->getMonster());
  drawCard(painter, MONSTER_CARD_LEFT, model->getMonster()->getCard1());
  drawCard(painter, MONSTER_CARD_RIGHT, model->getMonster()->getCard2());
}

void View::drawPlayerElements(QPainter &painter)
{
  drawPlayerStatusBar(painter, model->getPlayer());
  drawCard(painter, PLAYER_CARD_LEFT, model->getPlayer()->getCard1());
  drawCard(painter, PLAYER_CARD_RIGHT, model->getPlayer()->getCard2());
}

void View::drawCard(QPainter &painter, QRect rect, Card *card)
{
  painter.setBrush(getCardColor(card));
  painter.drawRect(rect);
  printCardText(painter, rect, card);
}

void View::printCardText(QPainter &painter, QRect rect, Card *card)
{
  painter.setPen(ATTACK_COLOR);
  painter.drawText(rect, Qt::AlignCenter, card->getAttackText());
  painter.setPen(HEALTH_COLOR);
  painter.drawText(rect, Qt::AlignCenter, card->getHealText());
  resetToDefaultColor(painter);
}

void View::drawPlayerStatusBar(QPainter &painter, Player *player)
{
  painter.setBrush(UNSELECTED_CARD_COLOR);
  painter.drawRect(PLAYER_STATUS_BAR);
  painter.setPen(HEALTH_COLOR);
  painter.drawText(PLAYER_STATUS_BAR, Qt::AlignCenter, player->getHealthText());
  resetToDefaultColor(painter);
}

void View::drawMonsterStatusBar(QPainter &painter, Monster *monster)
{
  painter.setBrush(UNSELECTED_CARD_COLOR);
  painter.drawRect(MONSTER_STATUS_BAR);
  painter.setPen(HEALTH_COLOR);
  painter.drawText(MONSTER_STATUS_BAR, Qt::AlignCenter, monster->getHealthText());
  resetToDefaultColor(painter);
}

void View::drawNewGame(QPainter &painter)
{
  painter.setBrush(ATTACK_COLOR);
  painter.drawRect(START_NEW_GAME);
}

bool View::isInNewGameRegion(const QPoint &point)
{
  return START_NEW_GAME.contains(point);
}

QColor View::getCardColor(Card *card)
{
  return model->isThisCardSelected(card) ? SELECTED_CARD_COLOR : UNSELECTED_CARD_COLOR;
}

void View::resetToDefaultColor(QPainter &painter)
{
  painter.setPen(OUTLINE_AND_TEXT_COLOR);
}

void View::validCardClick(const QPoint &pos)
{
  if ( isPlayerCard(pos) /* || isMonsterCard(pos) */ )
    playSelectedCards();
  else
  {
    model->getPlayer()->selectCard(nullptr);
    model->getMonster()->selectCard(nullptr);
  }
}

bool View::isPlayerCard(const QPoint &pos)
{
  if (PLAYER_CARD_LEFT.contains(pos) || PLAYER_CARD_RIGHT.contains(pos))
    return true;
  return false;
}

bool View::isMonsterCard(const QPoint &pos)
{
  if (MONSTER_CARD_LEFT.contains(pos) || MONSTER_CARD_RIGHT.contains(pos))
    return true;
  return false;
}

View::View(QWidget *parent) : QWidget (parent)
{
  model = Model::getInstance();
  this->setFixedSize(420, 390);
  this->show();
}

View::~View()
{
  delete model;
}

void View::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  painter.setPen(OUTLINE_AND_TEXT_COLOR);
  drawPlayerElements(painter);
  drawMonsterElements(painter);
  drawNewGame(painter);
  event->accept();
}

void View::mousePressEvent(QMouseEvent *event)
{
  if ( event->button() != Qt::LeftButton ) return;
  if ( isInNewGameRegion(event->pos())) model->restartGame(1, 1);
  selectPlayerCard(event->pos());
  selectMonsterCard(event->pos());
  update();
}

void View::mouseMoveEvent(QMouseEvent *event)
{
  // TODO: move cards to enemy
  event->accept();
}

void View::mouseReleaseEvent(QMouseEvent *event)
{
  validCardClick(event->pos());
  update();
}

void View::playerDead()
{
  QMessageBox::information(this, "Game Lost", "You have lost the game, your player died.");
}

void View::monsterDead()
{
  QMessageBox::information(this, "Game Won", "You have won the game, the monster is defeated.");
}
