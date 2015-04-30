
#pragma once
#include <memory>

class Scene;


class SceneMgr {
private:
  std::shared_ptr<Scene> current_scene;

public:

  SceneMgr() = default;

  void start();

  void update();
  void draw();

  void shiftNextScene(std::shared_ptr<Scene> next_scene);
};