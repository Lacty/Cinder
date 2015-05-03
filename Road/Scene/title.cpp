
#include "title.h"
#include "../System/scene_mgr.h"
#include "../MyLib/common.h"
#include "../MyLib/mouse.h"
#include "../MyLib/graph.h"
#include "../MyLib/key.h"

#include "game_main.h"


Title::Title(SceneMgr* mgr) :
Scene(mgr),
star(600, 5.0f, 400.0f, 0.2f),
font(new Font(loadAsset("nicomoji-plus_v0.9.ttf"),150)){}

Title::~Title() {
  delete font;
}


void Title::update() {
  star.update();
  if (Mouse::get().Left().isPush) {
    mgr->shiftNextScene(std::make_shared<GameMain>(mgr));
  }
}

void Title::draw() {
  star.draw();
  gl::drawString("Title", Vec2f(180.0f, 150.0f),
                 Color::white(), *font);
}