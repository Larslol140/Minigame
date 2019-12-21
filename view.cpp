#include "view.h"

void View::selectPlayerCard(const QPoint &point)
{
  if ( model->isGameFinished() ) return;
  else if (isPointInLeftPlayerCard(point))
    model->selectLeftPlayerCard();
  else if (isPointInRightPlayerCard(point))
    model->selectRightPlayerCard();

}

void View::selectMonsterCard(const QPoint &point)
{
  if ( model->isGameFinished() ) return;
  else if (isPointInLeftMonsterCard(point))
    model->selectLeftMonsterCard();
  else if (isPointInRightMonsterCard(point))
    model->selectRightMonsterCard();
}

void View::unselectAllCards()
{
  model->getPlayer()->selectCard(nullptr);
  model->getMonster()->selectCard(nullptr);
}

void View::playSelectedCards()
{
  if (model->getPlayer()->isCardSelected())
    model->playerTurn();
  else if (model->getMonster()->isCardSelected())
    model->monsterTurn();
  unselectAllCards();
}

void View::drawMonsterElements(QPainter &painter)
{
  drawMonsterStatusBar(painter, model->getMonster());
  drawCard(painter, MONSTER_CARD_LEFT, model->getMonster()->getLeftCard());
  drawCard(painter, MONSTER_CARD_RIGHT, model->getMonster()->getRightCard());
}

void View::drawPlayerElements(QPainter &painter)
{
  drawPlayerStatusBar(painter, model->getPlayer());
  drawCard(painter, PLAYER_CARD_LEFT, model->getPlayer()->getLeftCard());
  drawCard(painter, PLAYER_CARD_RIGHT, model->getPlayer()->getRightCard());
}

void View::drawCard(QPainter &painter, QRect rect, Card *card)
{
  if (card == cardWithOffset)
    makeOffsetQRect(rect);
  painter.setBrush(getCardColor(card));
  painter.drawPixmap(rect, QPixmap(card->getImgPath()));
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
  drawPlayerHealthBar(painter, player);
  painter.setPen(HEALTH_COLOR);
  painter.drawText(PLAYER_STATUS_BAR, Qt::AlignCenter, player->getHealthText());
  resetToDefaultColor(painter);
}

void View::drawMonsterStatusBar(QPainter &painter, Monster *monster)
{
  painter.setBrush(UNSELECTED_CARD_COLOR);
  painter.drawRect(MONSTER_STATUS_BAR);
  drawMonsterHealthBar(painter, monster);
  painter.setPen(HEALTH_COLOR);
  painter.drawText(MONSTER_STATUS_BAR, Qt::AlignCenter, monster->getHealthText());
  resetToDefaultColor(painter);
}

void View::drawNewGame(QPainter &painter)
{
  painter.setBrush(ATTACK_COLOR);
  painter.drawRect(START_NEW_GAME);
}

void View::drawPlayerHealthBar(QPainter &painter, Player *player)
{
  if ( !model->isPlayerAlive() ) painter.setBrush(ATTACK_COLOR);
  else painter.setBrush(HEALTH_BAR_COLOR);
  painter.drawRect(getFilledBarRect(PLAYER_STATUS_BAR, player->getHealthValue()));
  resetToDefaultColor(painter);
}

void View::drawMonsterHealthBar(QPainter &painter, Monster *monster)
{
  if ( !model->isMonsterAlive() ) painter.setBrush(ATTACK_COLOR);
  else painter.setBrush(HEALTH_BAR_COLOR);
  painter.drawRect(getFilledBarRect(MONSTER_STATUS_BAR, monster->getHealthValue()));
  resetToDefaultColor(painter);
}

QRect View::getFilledBarRect(QRect bar, int health)
{
  if ( health > 20 || health <= 0 ) health = 20;
  QRect tmp(bar);
  tmp.setWidth((bar.width()/20)*health);
  return tmp;
}

bool View::isInNewGameRegion(const QPoint &point)
{
  return START_NEW_GAME.contains(point);
}

bool View::isPointInLeftPlayerCard(const QPoint &point)
{
  return PLAYER_CARD_LEFT.contains(point);
}

bool View::isPointInRightPlayerCard(const QPoint &point)
{
  return PLAYER_CARD_RIGHT.contains(point);
}

bool View::isPointInLeftMonsterCard(const QPoint &point)
{
  return MONSTER_CARD_LEFT.contains(point);
}

bool View::isPointInRightMonsterCard(const QPoint &point)
{
  return MONSTER_CARD_RIGHT.contains(point);
}

bool View::isPointInPlayerBar(const QPoint &point)
{
  return PLAYER_STATUS_BAR.contains(point);
}

bool View::isPointInMonsterBar(const QPoint &point)
{
  return MONSTER_STATUS_BAR.contains(point);
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
  if ( isPointInMonsterBar(pos) )
    playSelectedCards();
  else
  {
    unselectAllCards();
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

void View::updateCardOffset(const QPoint &pos)
{
  cardOffsetX = pos.x();
  cardOffsetY = pos.y();
}

void View::resetCardOffset()
{
  cardOffsetX = 0;
  cardOffsetY = 0;
  cardWithOffset = nullptr;
}

void View::setClickedCardForOffset(const QPoint &pos)
{
  if ( isPointInLeftPlayerCard(pos) ) cardWithOffset = model->getPlayer()->getLeftCard();
  else if ( isPointInRightPlayerCard(pos) ) cardWithOffset = model->getPlayer()->getRightCard();
  else if ( isPointInLeftMonsterCard(pos) ) cardWithOffset = model->getMonster()->getLeftCard();
  else if ( isPointInRightMonsterCard(pos) ) cardWithOffset = model->getMonster()->getRightCard();
  else cardWithOffset = nullptr;
}

void View::makeOffsetQRect(QRect &rect)
{
  rect = QRect(cardOffsetX-(rect.width()/2), cardOffsetY-(rect.height()/2), rect.width(), rect.height());
}

View::View(QWidget *parent) : QWidget (parent)
{
  model = Model::getInstance();
  resetCardOffset();
  this->setFixedSize(840, 780);
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
  painter.setFont(QFont("Open Sans", 20));
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
  setClickedCardForOffset(event->pos());
  updateCardOffset(event->pos());
  update();
}

void View::mouseMoveEvent(QMouseEvent *event)
{
  // TODO: move cards to enemy
  updateCardOffset(event->pos());
  update();
}

void View::mouseReleaseEvent(QMouseEvent *event)
{
  validCardClick(event->pos());
  resetCardOffset();
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
