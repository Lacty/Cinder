
#pragma once
#include <memory>

class Scene;


class SceneMgr {
private:
  std::shared_ptr<Scene> current_scene;
  // Scene* current_scene;

public:

  SceneMgr();

  void update();
  void draw();

  void shiftNextScene(std::shared_ptr<Scene> next_scene);
  //void shiftNextScene(Scene*);
};