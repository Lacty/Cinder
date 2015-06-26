
#include "MyLib/window_size.h"
#include "MyLib/ci_app.h"
#include "MyLib/mouse.h"

#include "cinder/Rand.h"
#include "Particle/particle.h"


class ParticleApp : public AppNative {
private:
  Particle particle;

public:
  void setup();

  void mouseMove(MouseEvent event) {
    Mouse::get().MoveEvent(event);
  }
  void mouseDrag(MouseEvent event) {
    Mouse::get().MoveEvent(event);
  }
  void mouseDown(MouseEvent event) {
    Mouse::get().PushEvent(event);
  }
  void mouseUp(MouseEvent event) {
    Mouse::get().PullEvent(event);
  }

  void update();
  void draw();
};

void ParticleApp::setup() {
  setWindowSize(int(WindowSize::Width),
                int(WindowSize::Height));
  particle.setup();
  Rand::randomize();
}

void ParticleApp::update() {
  particle.update();
}

void ParticleApp::draw() {
  gl::clear(Color(0, 0, 0));
  particle.draw();
  Mouse::get().flashInput();
}

CINDER_APP_NATIVE(ParticleApp, RendererGl)
