#pragma once

#include "Game/Game.h"

class Aria : public Game {
public:
  Aria();

  void setup() override;

private:
  Uint32 collisionEvent;
  Scene* createGamePlayScene();
};

