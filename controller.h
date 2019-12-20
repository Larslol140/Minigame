#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view.h"

class Controller : public QObject
{
    Q_OBJECT
  private:
    static Controller *instance;
    Controller();

    Model *model;
    View  *view;

    void connectComponents();

  public:
    static Controller *getInstance();
    ~Controller();
};

#endif // CONTROLLER_H
