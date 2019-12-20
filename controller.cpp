#include "controller.h"

Controller *Controller::instance = nullptr;

Controller::Controller()
{
  view = new View;
  model = Model::getInstance();
  connectComponents();
}

void Controller::connectComponents()
{
  connect(model, SIGNAL(playerDead()), view, SLOT(playerDead()));
  connect(model, SIGNAL(monsterDead()), view, SLOT(monsterDead()));
}

Controller::~Controller()
{
  delete view;
}

Controller *Controller::getInstance()
{
  if (instance == nullptr)
    instance = new Controller;
  return instance;
}
