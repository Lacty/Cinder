
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include <vector>
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;

class TestApp : public AppNative {
public:
  void prepareSettings(Settings* setting) override;
  void setup();
  void mouseDown(MouseEvent event) override;
  void update();
  void draw();

private:
  enum WindowSize {
    WIDTH = 500,
    HEIGHT = 500
  };

  enum PointNum {
    Point_Max = 500
  };

  float angle;

  std::vector<Vec3f> pos;
  std::vector<Color> color;
};

void TestApp::prepareSettings(Settings* setting) {
  setting->setWindowSize(WIDTH, HEIGHT);
}

void TestApp::setup()
{
  Rand::randomize();
  angle = 0.0f;

  for (int i = 0; i < Point_Max; ++i){
    Vec3f pos_temp = Vec3f(Rand::randFloat(-WIDTH  / 2, WIDTH  / 2),
                           Rand::randFloat(-HEIGHT / 2, HEIGHT / 2),
                           Rand::randFloat(1, 200));

    Color color_temp = Color(Rand::randFloat(0.0f, 1.0f),
                             Rand::randFloat(0.0f, 1.0f),
                             Rand::randFloat(0.0f, 1.0f));

    pos.emplace_back(pos_temp);
    color.emplace_back(color_temp);
  }
}

void TestApp::mouseDown(MouseEvent event)
{
}

void TestApp::update()
{
  const float speed = 0.05f;

  for (auto &it : pos) {
    it.z -= speed;
    if (it.z <= 0) {
      it.z += 200;
    }
  }

  angle += 1;
}

void TestApp::draw()
{
  gl::clear(Color(0, 0, 0));

  const float r = 20;

  for (int i = 0; i < pos.size(); ++i){
    gl::color(Color((color[i].r / pos[i].z),
                    (color[i].g / pos[i].z),
                    (color[i].b / pos[i].z)));
    gl::drawSolidCircle(Vec2f((pos[i].x / pos[i].z) + (WIDTH  / 2),
                              (pos[i].y / pos[i].z) + (HEIGHT / 2)),
                              (r / pos[i].z));
  }


}

CINDER_APP_NATIVE(TestApp, RendererGl)
