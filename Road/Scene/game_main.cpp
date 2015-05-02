
#include "game_main.h"
#include "../System/scene_mgr.h"
#include "../MyLib/common.h"
#include "../MyLib/graph.h"
#include "cinder/Rand.h"


GameMain::GameMain(SceneMgr* mgr) :
Scene(mgr),
star(600, 5.0f, 400.0f, 0.2f),
ring(50, 50.0f, 400.0f, 0.2f) {}


void GameMain::update() {
  star.update();
  ring.update();
}

void GameMain::draw() {
  star.draw();
  ring.draw();
}