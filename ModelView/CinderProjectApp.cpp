
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;


class CinderProjectApp : public AppNative {
private:
  enum WindowSize {
    WIDTH = 500,
    HEIGHT = 300
  };

  Vec3f pos;
  Vec3f size;

  float angle;

public:
  void prepareSettings(Settings* setting) override;

  void setup();
  void mouseDown( MouseEvent event ) override;
  void update();
  void draw();
};

void CinderProjectApp::prepareSettings(Settings* setting) {
  setting->setWindowSize(Vec2i(WIDTH, HEIGHT));
}

void CinderProjectApp::setup()
{
  pos   = Vec3f(WIDTH/2, HEIGHT/2, 0);
  size  = Vec3f(50, 50, 50);
  angle = 0;
}

void CinderProjectApp::mouseDown( MouseEvent event )
{
}

void CinderProjectApp::update()
{
  angle++;
}

void CinderProjectApp::draw()
{
  gl::clear( Color( 1, 1, 1 ) );

  gl::color(Color(0, 1, 1)); // 色指定

  { // 右
    gl::pushModelView();
    gl::translate(Vec3f(300, HEIGHT / 2, 0));
    gl::rotate(Vec3f(0.0f, angle, 0.0f));

    gl::drawCube(Vec3f(0, 0, 0), size);

    gl::popModelView();
  }

  gl::color(Color(1, 0.5, 0.5)); // 色指定
  { // 左
    gl::pushModelView();
    gl::translate(Vec3f(60, HEIGHT / 2, 0));
    gl::rotate(Vec3f(0.0f, angle, 0.0f));

    gl::drawCube(Vec3f(0, 0, 0), size);

    gl::popModelView();
  }
}

CINDER_APP_NATIVE( CinderProjectApp, RendererGl )
