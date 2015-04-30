
#include "MyLib/common.h"
#include "MyLib/key.h"
#include "MyLib/mouse.h"


class RoadApp : public AppNative {
public:
  void setup();

  void mouseDown(MouseEvent event) {
    Mouse::get().PushEvent(event);
  }
  void mouseUp(MouseEvent event) {
    Mouse::get().PullEvent(event);
  }
  void mouseMove(MouseEvent event) {
    Mouse::get().MoveEvent(event);
  }
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

void RoadApp::setup() {
  setWindowSize(static_cast<int>(WindowSize::Width),
                static_cast<int>(WindowSize::Height));
  Mouse::get();
  Key::get();
}

void RoadApp::update() {
  if (Mouse::get().Left().isPress) {
    console() << "press Left" << std::endl;
  }
}

void RoadApp::draw() {
  // clear out the window with black
  gl::clear();
  Mouse::get().flashInput();
  Key::get().flashInput();
}

CINDER_APP_NATIVE(RoadApp, RendererGl)
