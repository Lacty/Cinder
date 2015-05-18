
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Json.h"

using namespace ci;
using namespace ci::app;

class JsonApp : public AppNative {
private:
  struct Object {
    std::string name;
    float Hp;
    float speed;
  } player;
public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void JsonApp::setup() {
  // データ読み込み
  JsonTree js_load(loadAsset("Source.json"));
  auto js_player = js_load["Player"];
  player.name    = js_player["Name"].getValue<std::string>();
  player.Hp      = js_player["Hp"].getValue<float>();
  player.speed   = js_player["Speed"].getValue<float>();

  console() << player.name  << std::endl;
  console() << player.Hp    << std::endl;
  console() << player.speed << std::endl;

  // データ書き込み
  JsonTree js_write = JsonTree::makeObject("Enemy");
  js_write.addChild(JsonTree("name", "yanai"));

  js_write.write(getAppPath() / "../../assets/Enemy.json", JsonTree::WriteOptions().createDocument());
}

void JsonApp::mouseDown(MouseEvent event) {}

void JsonApp::update() {}

void JsonApp::draw() {
  gl::clear();
}

CINDER_APP_NATIVE(JsonApp, RendererGl)
