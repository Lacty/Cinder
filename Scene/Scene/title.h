
#pragma once
#include "scene.h"

class SceneMgr;


class Title : public Scene {
public:

  Title(SceneMgr*);

  void update();
  void draw();
};