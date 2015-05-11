
#include "MyLib/common.h"
#include "MyLib/graph.h"
#include "MyLib/key.h"

#include <vector>

class _5_11App : public AppNative {
private:
  struct Triangle {
    Vec3f posA;
    Vec3f posB;
    Vec3f posC;
    Color color;
  };
  std::vector<Triangle> triangle;

  struct Box {
    Vec3f pos;
    Vec3f scale;
    Vec3f rotate;
  };
  std::vector<Box> boxes;

  Vec3f root_rotate;
  Vec3f root_translate;

public:
  void setup();
  void keyDown(KeyEvent event) {
    Key::get().setKeyPush(event.getCode());
    Key::get().setKeyPress(event.getCode());
  }
  void keyUp(KeyEvent event) {
    Key::get().popKeyPress(event.getCode());
    Key::get().setKeyPull(event.getCode());
  }
  void update();
  void draw();
};

void _5_11App::setup() {
  gl::enableAlphaBlending();
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  // –Ê1
  triangle.push_back({ { -1, 1, -1 }, { 1, 1, -1 }, { 1, -1, -1 }, { Color(1, 1, 1) } }); // a-b-c
  triangle.push_back({ { -1, 1, -1 }, { 1, -1, -1 }, { -1, -1, -1 }, { Color(1, 1, 1) } }); // a-c-d
  // –Ê2
  triangle.push_back({ { 1, 1, -1 }, { 1, 1, 1 }, { 1, -1, 1 }, { Color(1, 0, 1) } }); // b-f-g
  triangle.push_back({ { 1, 1, -1 }, { 1, -1, 1 }, { 1, -1, -1 }, { Color(1, 0, 1) } }); // b-g-c
  // –Ê3
  triangle.push_back({ { 1, 1, 1 }, { -1, 1, 1 }, { -1, -1, 1 }, { Color(1, 1, 0) } }); // f-e-h
  triangle.push_back({ { 1, 1, 1 }, { -1, -1, 1 }, { 1, -1, 1 }, { Color(1, 1, 0) } }); // f-h-g
  // –Ê4
  triangle.push_back({ { -1, 1, 1 }, { -1, 1, -1 }, { -1, -1, -1 }, { Color(0, 1, 1) } }); // e-a-d
  triangle.push_back({ { -1, 1, 1 }, { -1, -1, -1 }, { -1, -1, 1 }, { Color(0, 1, 1) } }); // e-d-h
  // –Ê5
  triangle.push_back({ { -1, 1, -1 }, { 1, 1, 1 }, { 1, 1, -1 }, { Color(0, 0, 1) } }); // a-f-b
  triangle.push_back({ { -1, 1, -1 }, { -1, 1, 1 }, { 1, 1, 1 }, { Color(0, 0, 1) } }); // a-e-f
  // –Ê6
  triangle.push_back({ { 1, -1, -1 }, { -1, -1, 1 }, { -1, -1, -1 }, { Color(0, 1, 0) } }); // c-h-d
  triangle.push_back({ { 1, -1, -1 }, { 1, -1, 1 }, { -1, -1, 1 }, { Color(0, 1, 0) } }); // c-g-h

  for (int x = -1; x <= 1; ++x) {
    Vec3f pos(x * 120, 0, 0);
    Vec3f scale(50, 50, 50);
    Vec3f rotate(0, 0, 0);

    boxes.push_back({ pos, scale, rotate });
  }

  root_translate = Vec3f(0, 0, 1200);
  root_rotate = Vec3f::zero();

  gl::enable(GL_CULL_FACE);
}

void _5_11App::update() {
  root_rotate += Vec3f(0, 0.01, 0);

  for (int i = 0; i < boxes.size(); ++i) {
    boxes[i].rotate += Vec3f(i * 0.01, i * 0.02, 0.01);
  }

  if (Key::get().isPress(KeyEvent::KEY_a)) {
    for (auto &tri : triangle) {
      tri.color.r += 0.01;
      tri.color.g += 0.01;
      tri.color.g += 0.01;
    }
  }
  if (Key::get().isPress(KeyEvent::KEY_d)) {
    for (auto &tri : triangle) {
      tri.color.r -= 0.01;
      tri.color.g -= 0.01;
      tri.color.g -= 0.01;
    }
  }
}

void _5_11App::draw() {
  gl::clear();
  gl::pushModelView();
  gl::translate(getWindowCenter());

  const float viewing_angle = 0.0004f;

  Matrix44f root_rotate_matrix = Matrix44f::createRotation(root_rotate);
  Matrix44f root_translate_matrix = Matrix44f::createTranslation(root_translate);

  for (auto box : boxes) {

    Matrix44f translate = Matrix44f::createTranslation(box.pos);
    Matrix44f scale = Matrix44f::createScale(box.scale);
    Matrix44f rotate = Matrix44f::createRotation(box.rotate);

    for (auto tri : triangle) {
      auto posA = tri.posA;
      auto posB = tri.posB;
      auto posC = tri.posC;
      auto col = tri.color;

      posA = root_translate_matrix * root_rotate_matrix * translate * rotate * scale * posA;
      posB = root_translate_matrix * root_rotate_matrix * translate * rotate * scale * posB;
      posC = root_translate_matrix * root_rotate_matrix * translate * rotate * scale * posC;

      ly::drawSoildTriangle(posA.xy() / (posA.z * viewing_angle),
                            posB.xy() / (posB.z * viewing_angle),
                            posC.xy() / (posC.z * viewing_angle),
                            col);
    }
  }

  ly::drawString("Press A light Up",   Vec2f(-200, 100), Color::white(), 50);
  ly::drawString("Press D light Down", Vec2f(-200, 150), Color::white(), 50);
  gl::popModelView();
}

CINDER_APP_NATIVE(_5_11App, RendererGl)
