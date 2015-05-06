
#include "player_model.h"
#include "player.h"
#include "../MyLib/graph.h"


PlayerModel::PlayerModel(Player* player) :
IObject(player),
angle(0.f)
{
  // ‘¤–Ê
  lines.push_back({ { -0.5f, 2.f, 0.f }, { 0.5f, 2.f, 0.f } }); // a-b
  lines.push_back({ { 0.5f, 2.f, 0.f }, { 2.f, -2.5f, 0.f } }); // b-c
  lines.push_back({ { 2.f, -2.5f, 0.f }, { -2.f, -2.5f, 0.f } }); // c-d
  lines.push_back({ { -2.f, -2.5f, 0.f }, { -0.5f, 2.f, 0.f } }); // d-a

  lines.push_back({ { -0.5f, 2.f, 0.f }, { -0.5f, -2.5f, -1.f } }); // a-e
  lines.push_back({ { 0.5f, 2.f, 0.f }, { 0.5f, -2.5f, -1.f } }); // b-f
  lines.push_back({ { 2.f, -2.5f, 0.f }, { 0.5f, -2.5f, -1.f } }); // c-f
  lines.push_back({ { -2.f, -2.5f, 0.f }, { -0.5f, -2.5f, -1.f } }); // d-e
  lines.push_back({ { -0.5f, -2.5f, -1.f }, { 0.5f, -2.5f, -1.f } }); // e-f
}


void PlayerModel::update() {
  angle = player->getLeanAngle();
}

void PlayerModel::draw() {
  Matrix44f translate = Matrix44f::createTranslation(Vec3f(player->getPos().x, 50.f, 820.f));
  Matrix44f scale = Matrix44f::createScale(Vec3f(10.f, -10.f, 10.f));
  Matrix44f rotate = Matrix44f::createRotation(Vec3f(-1.3f, 0.0f, angle));

  const float viewing_angle = 0.0004f;

  gl::pushModelView();
  gl::translate(getWindowCenter());

  for (auto pos : lines) {
    auto begin = pos.begin;
    auto end = pos.end;

    begin = translate * rotate * scale * begin;
    end = translate * rotate * scale * end;

    ly::drawLine(begin.xy() / (begin.z * viewing_angle),
                 end.xy() / (end.z * viewing_angle),
                 Color(0.f, 1.f, 1.f));
  }

  gl::popModelView();
}