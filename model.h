#ifndef MODEL_H
#define MODEL_H

#include "someone.h"

class Model : public QObject
{
    Q_OBJECT

  private:
    static Model *instance;
    Model(QObject *parent);

    Player  *player;
    Monster *monster;

    bool    isPlayerAlive();
    bool    isMonsterAlive();

    void    nextTurn();

    void    attackPlayer();
    void    attackMonster();
    void    healPlayer();
    void    healMonster();

    void    monsterAutoTurn();

  public:
    static Model *getInstance(QObject *parent = nullptr);
    ~Model();

    void startGame(int player_id, int monster_id);
    void endGame();

    void restartGame(int player_id, int monster_id);

    void selectLeftPlayerCard();
    void selectRightPlayerCard();
    void selectNoPlayerCard();

    void selectLeftMonsterCard();
    void selectRightMonsterCard();
    void selectNoMonsterCard();

    Player  *getPlayer();
    Monster *getMonster();

    void playerTurn();
    void monsterTurn();

    bool isThisCardSelected(Card *card) const;

  signals:
    void playerDead();
    void monsterDead();
};

#endif // MODEL_H
