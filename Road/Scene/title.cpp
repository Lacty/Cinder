
#include "title.h"
#include "../System/scene_mgr.h"
#include "../MyLib/common.h"
#include "../MyLib/graph.h"
#include "../MyLib/key.h"

#include "game_main.h"


Title::Title(SceneMgr* mgr) :
Scene(mgr),
star(600, 5.0f, 400.0f, 0.2f) {}


void Title::update() {
  star.update();
}

void Title::draw() {
  star.draw();
  ly::drawString("Title", Vec2f(180.0f, 150.0f),
                 Color::white(), 150);
}