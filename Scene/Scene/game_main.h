
#pragma once
#include "scene.h"

class SceneMgr;


class GameMain : public Scene {
public:
  GameMain(SceneMgr*);

  void update();
  void draw();
};