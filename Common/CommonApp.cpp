
#include "common.h"
#include "graph.h"
#include "key.h"


class CommonApp : public AppNative {
private:

public:

  void setup();

  void mouseDown(MouseEvent event) {
    
  }

  void update();
  void draw();
};

void CommonApp::setup() {
  setWindowSize(int(WindowSize::Width), int(WindowSize::Height));
}

void CommonApp::mouseDown(MouseEvent event) {}

void CommonApp::update() {
  Key& key = Key::get();
  key.isPushKey();
}

void CommonApp::draw() {
  gl::clear();
}

CINDER_APP_NATIVE(CommonApp, RendererGl)
