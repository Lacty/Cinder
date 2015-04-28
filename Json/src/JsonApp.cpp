
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Json.h"

using namespace ci;
using namespace ci::app;

class JsonApp : public AppNative {
private:
  float hoge;
public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void JsonApp::setup() {
  JsonTree json_test(loadAsset("Source.json"));
  hoge = json_test["object"].getValue<double>();
  console() << hoge << std::endl;
}

void JsonApp::mouseDown(MouseEvent event) {}

void JsonApp::update() {}

void JsonApp::draw() {
  gl::clear();
}

CINDER_APP_NATIVE(JsonApp, RendererGl)
