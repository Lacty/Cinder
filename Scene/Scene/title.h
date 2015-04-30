
#pragma once
#include "scene.h"

class SceneMgr;


class Title : public Scene {
public:

  Title(SceneMgr*);
  ~Title();

  void update();
  void draw();
};