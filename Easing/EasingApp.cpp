
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Timeline.h"
#include "cinder/Tween.h"

using namespace ci;
using namespace ci::app;


class EasingApp : public AppNative {
private:
  Anim<Vec2f> current_pos;
  Anim<Vec2f> end_pos;

public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void EasingApp::setup() {
  current_pos = Vec2f(0, 0);
}

void EasingApp::mouseDown(MouseEvent event) {
  end_pos = event.getPos();

  timeline().apply(&current_pos,
                   end_pos.value(),
                   1.0f, easeOutInCirc);
}

void EasingApp::update() {}

void EasingApp::draw() {
  gl::clear();
  gl::color(Color::white());
  gl::drawCube(Vec3f(current_pos, 0), Vec3f(50, 50, 50));
}

CINDER_APP_NATIVE(EasingApp, RendererGl)
