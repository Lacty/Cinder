
#pragma once
#include "../MyLib/common.h"
#include <vector>
#include "scene.h"


class Title : public Scene {
private:
  std::vector<Vec3f> star;

public:
  Title(SceneMgr*);

  void update();
  void draw();
};