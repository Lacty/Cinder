
#pragma once
#include "scene.h"
#include "../Object/star.h"


class Title : public Scene {
private:
  Star star;
  Font* font;

public:
  Title(SceneMgr*);
  ~Title();

  void update();
  void draw();
};