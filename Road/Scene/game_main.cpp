
#include "game_main.h"
#include "../System/scene_mgr.h"
#include "../MyLib/common.h"
#include "../MyLib/graph.h"
#include "cinder/Rand.h"


GameMain::GameMain(SceneMgr* mgr) :
Scene(mgr),
star(100, 5.0f, 200.0f, 0.2f),
bg_ring(20, 80.0f, 200.0f, 0.16f) {}


void GameMain::update() {
  star.update();
  bg_ring.update();
  road.update();
  player.update();
}

void GameMain::draw() {
  star.draw();
  bg_ring.draw();
  road.draw();
  player.draw();
}