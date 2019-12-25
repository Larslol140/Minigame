#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets>
#include "model.h"

class View : public QWidget
{
    Q_OBJECT

  private:
    Model *model;

    int cardOffsetY;
    int cardOffsetX;

    Card *cardWithOffset;

    void selectPlayerCard(const QPoint &point);
    void selectMonsterCard(const QPoint &point);
    void playSelectedCards();

    void drawMonsterElements(QPainter &painter);
    void drawPlayerElements(QPainter &painter);

    void drawCard(QPainter &painter, QRect rect, Card *card);
    void printCardText(QPainter &painter, QRect rect, Card *card);

    void drawPlayerStatusBar(QPainter &painter, Player *player);
    void drawMonsterStatusBar(QPainter &painter, Monster *monster);
    void drawNewGame(QPainter &painter);

    void drawPlayerHealthBar(QPainter &painter, Player *player);
    void drawMonsterHealthBar(QPainter &painter, Monster *monster);

    QRect getFilledBarRect(QRect bar, int health);

    bool isInNewGameRegion(const QPoint &point);

    bool isPointInLeftPlayerCard(const QPoint &point);
    bool isPointInRightPlayerCard(const QPoint &point);

    bool isPointInLeftMonsterCard(const QPoint &point);
    bool isPointInRightMonsterCard(const QPoint &point);

    bool isPointInPlayerBar(const QPoint &point);
    bool isPointInMonsterBar(const QPoint &point);

    QColor  getCardColor(Card *card);
    QRect   getCardRect(Card *card);

    void resetToDefaultColor(QPainter &painter);

    void validCardClick(const QPoint &pos);
    bool isPlayerCard(const QPoint &pos);
    bool isMonsterCard(const QPoint &pos);

    void redrawOffsetCard(QPainter &painter);

    void updateCardOffset(const QPoint &pos);
    void resetCardOffset();
    void setClickedCardForOffset(const QPoint &pos);

    void makeOffsetQRect(QRect &rect);

    void unselectAllCards();

    QRect relativeToRect(const Pos &p);

    void drawPlayerAvatar(QPainter &painter, QRect rect, Player *player);
    void drawMonsterAvatar(QPainter &painter, QRect rect, Monster *monster);

  public:
    View(QWidget *parent = nullptr);
    ~View();

  protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);

  public slots:
    void playerDead();
    void monsterDead();
};

#endif // VIEW_H
