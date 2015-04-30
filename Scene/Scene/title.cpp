
#include "title.h"
#include "scene_mgr.h"
#include "game_main.h"
#include "MyLib/graph.h"
#include "MyLib/key.h"


Title::Title(SceneMgr* manager) :
Scene(manager) {}

Title::~Title() {
  console() << "Delete" << std::endl;
}

void Title::update() {
  if (Key::get().isPush(KeyEvent::KEY_a)) {
    console() << "Title >> push 'A'" << std::endl;
  }
  if (Key::get().isPush(KeyEvent::KEY_w)) {
    m_manager->shiftNextScene(std::make_shared<GameMain>(m_manager));
    //m_manager->shiftNextScene(new GameMain(m_manager));
    console() << "erro‚Ü‚¹‚ñI" << std::endl;
  }
}

void Title::draw() {
  ly::drawCube(Vec3f::zero(), Vec3f(50, 50, 50), Color::white());
}