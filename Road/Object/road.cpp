
#include "road.h"
#include "cinder/Matrix.h"
#include "../MyLib/graph.h"


Road::Road() {
  // Rane
  rane.push_back({ { 2, 1.5, 0 }, { 2, -1.5, 0 } });       // b-c
  rane.push_back({ { -2, -1.5, 0 }, { -2, 1.5, 0 } });     // d-a
  rane.push_back({ { 2, 1.5, 0.5 }, { 2, -1.5, 0.5 } });   // f-g
  rane.push_back({ { -2, -1.5, 0.5 }, { -2, 1.5, 0.5 } }); // h-e

  // Lines
  lines.push_back({ { -2, 1.5, 0 }, { 2, 1.5, 0 } });     // a-b
  lines.push_back({ { -2, 1.5, 0.5 }, { 2, 1.5, 0.5 } }); // e-f
  lines.push_back({ { -2, 1.5, 0 }, { -2, 1.5, 0.5 } });  // a-e
  lines.push_back({ { 2, 1.5, 0 }, { 2, 1.5, 0.5 } });    // b-f

  for (int i = 0; i < Road_Max; ++i) {
    depth[i] = i * (200.0f / Road_Max);
  }
  speed = 0.8f;
}


void Road::update() {
  for (int i = 0; i < Road_Max; ++i) {
    depth[i] -= speed;
    if (depth[i] <= 0.0f) {
      depth[i] += 200.0f;
    }
  }
}

void Road::draw() {
  Matrix44f scale = Matrix44f::createScale(Vec3f(80, 80, 80));
  Matrix44f rotate = Matrix44f::createRotation(Vec3f(-1.58f, 0.0f, 0.0f));
  const float viewing_angle = 0.008f;

  gl::pushModelView();
  gl::translate(getWindowCenter());

  for (int i = 0; i < Road_Max; ++i) {
    if (depth[i] <= 10.0f) continue;
    Matrix44f translate = Matrix44f::createTranslation(Vec3f(0.0f, 50.0f, depth[i] * 18));
    for (auto line : lines) {
      auto begin = line.begin;
      auto end = line.end;

      begin = translate * scale * rotate * begin;
      end = translate * scale * rotate * end;

      ly::drawLine(begin.xy() / (begin.z * viewing_angle),
                   end.xy() / (end.z * viewing_angle),
                   Color(1, 1, 1));
    }
  }
  scale = Matrix44f::createScale(Vec3f(80, 80, 500));
  Matrix44f translate = Matrix44f::createTranslation(Vec3f(0.0f, 50.0f, 800.0f));
  for (auto line : rane) {
    auto begin = line.begin;
    auto end = line.end;

    begin = translate * scale * rotate * begin;
    end = translate * scale * rotate * end;

    ly::drawLine(begin.xy() / (begin.z * viewing_angle),
                 end.xy() / (end.z * viewing_angle),
                 Color::white());
  }

  gl::popModelView();
}