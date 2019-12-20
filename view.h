#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets>
#include "model.h"

class View : public QWidget
{
    Q_OBJECT

  private:
    Model *model;

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
    bool isInNewGameRegion(const QPoint &point);

    QColor getCardColor(Card *card);

    void resetToDefaultColor(QPainter &painter);

    void validCardClick(const QPoint &pos);
    bool isPlayerCard(const QPoint &pos);
    bool isMonsterCard(const QPoint &pos);

    void unselectAllCards();

  public:
    View(QWidget *parent = nullptr);
    ~View();

  protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

  public slots:
    void playerDead();
    void monsterDead();
};

#endif // VIEW_H
