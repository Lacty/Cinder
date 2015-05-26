
#include "MyLib/window_size.h"
#include "MyLib/ci_app.h"
#include "MyLib/graph.h"
#include "MyLib/key.h"

#include "cinder/gl/Light.h"
#include "cinder/TriMesh.h"
#include "cinder/Camera.h"


class _5_25App : public AppNative {
private:
  TriMesh mesh;

  std::unique_ptr<gl::Light> light;

  CameraPersp camera;

  Vec3f rotate;
  Vec3f light_dir;

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

void _5_25App::setup() {
  Key::get();

  Vec3f vA( 0,  1.5,  0);
  Vec3f vB( 1,    0,  0);
  Vec3f vC( 0, -1.5,  0);
  Vec3f vD(-1,    0,  0);
  Vec3f vE( 0,    0,  1);
  Vec3f vF( 0,    0, -1);

  Vec3f vertices[] = {
    vA, vB, vF,
    vA, vF, vD,
    vA, vD, vE,
    vA, vE, vB,

    vC, vF, vB,
    vC, vD, vF,
    vC, vE, vD,
    vC, vB, vE
  };
  mesh.appendVertices(&vertices[0],
                      sizeof(vertices) / sizeof(vertices[0]));

  Color cA(1, 1, 1);
  Color cB(0, 1, 1);
  Color cC(1, 0, 1);
  Color cD(1, 1, 0);
  Color cE(0, 0, 1);
  Color cF(0, 1, 0);

  Color colors[] = {
    cA, cB, cF,
    cA, cF, cD,
    cA, cD, cE,
    cA, cE, cB,

    cC, cF, cB,
    cC, cD, cF,
    cC, cE, cD,
    cC, cB, cE
  };
  mesh.appendColorsRgb(&colors[0],
                       sizeof(colors) / sizeof(colors[0]));

  uint32_t indices[] = {
    0,  1,  2,
    3,  4,  5,
    6,  7,  8,
    9, 10, 11,

    12, 13, 14,
    15, 16, 17,
    18, 19, 20,
    21, 22, 23
  };
  mesh.appendIndices(&indices[0],
                     sizeof(indices) / sizeof(indices[0]));

  mesh.recalculateNormals();

  light = std::unique_ptr<gl::Light>(new gl::Light(gl::Light::DIRECTIONAL, 0));
  light->setAmbient(Color(0, 0, 0));
  light->setDiffuse(Color(1, 1, 1));

  camera = CameraPersp(getWindowWidth(), getWindowHeight(),
                       35.0f, 0.5f, 800.0f);
  camera.lookAt(Vec3f(0.0f, 0.0f, 700.0f),
                Vec3f(0.0f, 0.0f, 0.0f));

  rotate = Vec3f::zero();
  light_dir = Vec3f(0, 0, 0.5).normalized();

  light->setDirection(light_dir);

  gl::enable(GL_CULL_FACE);
  gl::enable(GL_COLOR_MATERIAL);
  gl::enable(GL_LIGHTING);
  gl::enable(GL_NORMALIZE);
}

void _5_25App::update() {
  rotate += Vec3f(0, 1, 0);

  if (Key::get().isPress(KeyEvent::KEY_a)) {
    light_dir.x -= 0.1f;
  }
  if (Key::get().isPress(KeyEvent::KEY_d)) {
    light_dir.x += 0.1f;
  }
  if (Key::get().isPress(KeyEvent::KEY_w)) {
    light_dir.y += 0.1f;
  }
  if (Key::get().isPress(KeyEvent::KEY_s)) {
    light_dir.y -= 0.1f;
  }

  if (Key::get().isPress(KeyEvent::KEY_r)) {
    light_dir = Vec3f(0, 0, 0.5).normalized();
  }

  light->setDirection(light_dir);
}

void _5_25App::draw() {
  gl::clear();

  gl::setMatrices(camera);
  light->enable();

  /////////////////////////////////////
  gl::pushModelView();
  gl::scale(100, 100, 100);
  gl::rotate(rotate);

  // •`‰æ
  gl::draw(mesh);

  light->disable();
  gl::popModelView();
  /////////////////////////////////////

  /////////////////////////////////////
  /*gl::pushModelView();
  gl::translate(Vec3f(0, 0, 0));
  gl::scale(Vec3f::one());*/
  ly::drawString("Press WASD to move Light!", getWindowCenter(), Color::white(), 50);
  //gl::popModelView();
  /////////////////////////////////////

  Key::get().flashInput();
}

CINDER_APP_NATIVE(_5_25App, RendererGl)
