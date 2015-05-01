
#include "scene_mgr.h"
#include "../Scene/title.h"


SceneMgr::SceneMgr() :
current_scene(std::make_shared<Title>(this)) {}


void SceneMgr::update() {
  current_scene->update();
}

void SceneMgr::draw() {
  current_scene->draw();
}


void SceneMgr::shiftNextScene(std::shared_ptr<Scene> next_scene) {
  current_scene = next_scene;
}