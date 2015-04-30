
#include "MyLib/common.h"
#include "MyLib/graph.h"
#include "MyLib/key.h"
#include "scene_mgr.h"


class SceneApp : public AppNative {
private:
  SceneMgr scene;

public:
  void setup();
  void mouseDown(MouseEvent event);

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

void SceneApp::setup() {
  setWindowSize(static_cast<int>(WindowSize::Width),
                static_cast<int>(WindowSize::Height));
  Key::get();
}

void SceneApp::mouseDown(MouseEvent event) {}

void SceneApp::update() {
  scene.update();
}

void SceneApp::draw() {
  // clear out the window with black
  gl::clear();
  scene.draw();
}

CINDER_APP_NATIVE(SceneApp, RendererGl)
