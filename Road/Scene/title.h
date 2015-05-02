
#pragma once
#include "scene.h"
#include "../Object/star.h"


class Title : public Scene {
private:
  Star star;

public:
  Title(SceneMgr*);

  void update();
  void draw();
};