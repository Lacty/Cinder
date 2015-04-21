
#include "common.h"

#include "cinder/Camera.h"
#include "cinder/params/Params.h"


class ParamApp : public AppNative {
private:
  CameraPersp camera;
  Quatf       camera_rotate;
  Vec3f       rotate;
  cinder::params::InterfaceGl param;

public:
  void prepareSettings(Settings* setting) override;
  void setup();

  void update();
  void draw();
};

void ParamApp::prepareSettings(Settings* setting) {
  setting->setWindowSize(Width, Height);
}

void ParamApp::setup() {
  gl::enableDepthRead();
  gl::enableAlphaBlending();

  param = cinder::params::InterfaceGl("Param Test", Vec2i(300, 200));

  param.addParam("Camera", &camera_rotate);
  param.addParam("Rotate", &rotate);

  camera.setPerspective(60.0f, getWindowAspectRatio(), 5.0f, 2000.0f);
  camera.lookAt(Vec3f(0, 0, 300), Vec3f::zero(), Vec3f::yAxis());
}

void ParamApp::update() {
  gl::setMatrices(camera);
  gl::rotate(camera_rotate);
}


void ParamApp::draw()
{
  gl::clear();
  param.draw();

  gl::pushModelView();

  ly::drawCube(Vec3f(0,  0, 0), Vec3f(50, 50, 50), ColorA(0, 1, 1, 0.4f));
  ly::drawCube(Vec3f(0, 20, 0), Vec3f(60, 50, 50), ColorA(1, 0, 1, 0.4f));

  gl::popModelView();
}

CINDER_APP_NATIVE(ParamApp, RendererGl)
