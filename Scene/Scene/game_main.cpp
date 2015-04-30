
#include "game_main.h"
#include "scene_mgr.h"
#include "title.h"
#include "MyLib/graph.h"
#include "MyLib/key.h"


GameMain::GameMain(SceneMgr* manager) :
Scene(manager) {}


void GameMain::update() {
  if (Key::get().isPush(KeyEvent::KEY_d)) {
    m_manager->shiftNextScene(std::make_shared<Title>(m_manager));
  }
}

void GameMain::draw() {
  ly::drawCube(Vec3f(100, 100, 0),
               Vec3f(50, 50, 50),
               Color::white());
}