
#include "common.h"
#include "graph.h"
#include "key.h"


class CommonApp : public AppNative {
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

void CommonApp::setup() {
  setWindowSize(int(WindowSize::Width), int(WindowSize::Height));
}

void CommonApp::update() {
  if (Key::get().isPush(KeyEvent::KEY_w)) {
    console() << "push W" << std::endl;
  }
  if (Key::get().isPress(KeyEvent::KEY_a)) {
    console() << "press A" << std::endl;
  }
  if (Key::get().isPull(KeyEvent::KEY_d)) {
    console() << "pull D" << std::endl;
  }
}

void CommonApp::draw() {
  gl::clear();
}

CINDER_APP_NATIVE(CommonApp, RendererGl)
