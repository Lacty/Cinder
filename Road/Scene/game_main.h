
#pragma once
#include "scene.h"
#include "../Object/star.h"
#include "../Object/bg_ring.h"
#include "../Object/road.h"
#include "../Object/player.h"
#include <vector>


class GameMain : public Scene {
private:
  Star star;
  BgRing bg_ring;
  Road road;
  Player player;

public:
  GameMain(SceneMgr*);

  void update();
  void draw();
};