
#include "title.h"
#include "../System/scene_mgr.h"
#include "../MyLib/common.h"
#include "../MyLib/graph.h"
#include "../MyLib/mouse.h"
#include "cinder/Rand.h"
#include "cinder/Matrix.h"

#include "game_main.h"


Title::Title(SceneMgr* mgr) :
Scene(mgr)
{
  Rand::randomize();
  for (int i = 0; i < 400; ++i) {
    star.emplace_back(Vec3f(randFloat(-int(WindowSize::Width) * 0.5f, int(WindowSize::Width) * 0.5f),
                            randFloat(int(WindowSize::Height) * 0.5f, -int(WindowSize::Height) * 0.5f),
                            randFloat(1.0f, 300.0f)));
  }
}


void Title::update() {
  for (auto &it : star) {
    it.z -= 0.2f;
    if (it.z <= 0.0f) {
      it.z += 300.0f;
    }
  }

  if (Mouse::get().Left().isPush) {
    mgr->shiftNextScene(std::make_shared<GameMain>(mgr));
  }
}

void Title::draw() {
  for (auto &pos : star) {
    ly::drawCircle(Vec2f(pos.x / pos.z + (int(WindowSize::Width) / 2),
                         pos.y / pos.z + (int(WindowSize::Height) / 2)),
                   5 / pos.z, 0, Color::white());
  }

  gl::drawString("Title", Vec2f(180, 150),
                 Color::white(), Font("nicomoji-plus_v0.9.ttf", 150));
}