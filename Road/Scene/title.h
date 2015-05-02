
#pragma once
#include "scene.h"
#include "../Object/star.h"
#include "../MyLib/common.h"
#include <vector>


class Title : public Scene {
private:
  Star star;

public:
  Title(SceneMgr*);

  void update();
  void draw();
};