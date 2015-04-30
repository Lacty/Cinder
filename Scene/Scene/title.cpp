
#include "title.h"
#include "scene_mgr.h"
#include "MyLib/graph.h"
#include "MyLib/key.h"


Title::Title(SceneMgr* manager) :
Scene(manager) {}

void Title::update() {
  if (Key::get().isPush(KeyEvent::KEY_a)) {
    console() << "Title >> push 'A'" << std::endl;
  }
}

void Title::draw() {
  ly::drawCube(Vec3f::zero(), Vec3f(50, 50, 50), Color::white());
}