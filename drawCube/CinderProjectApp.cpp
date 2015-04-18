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

public:
  void prepareSettings(Settings* setting) override;

	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void CinderProjectApp::prepareSettings(Settings* setting) {
  setting->setWindowSize(Vec2i(WIDTH, HEIGHT));
}

void CinderProjectApp::setup()
{
}

void CinderProjectApp::mouseDown( MouseEvent event )
{
}

void CinderProjectApp::update()
{
}

void CinderProjectApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );

  gl::color(Color(0, 1, 1)); // 色指定::cyan

  // 左上
  gl::drawCube(Vec3f(50, 50, 0),
               Vec3f(50, 50, 50));

  // 左下
  gl::drawCube(Vec3f(50, 250, 0),
               Vec3f(50, 50, 50));

  // 右上
  gl::drawCube(Vec3f(300, 50, 0),
               Vec3f(50, 50, 50));

  gl::color(Color(1, 0, 0)); // 色指定::red

  // 右下
  gl::drawCube(Vec3f(300, 250, 0),
               Vec3f(50, 50, 50));
}

CINDER_APP_NATIVE( CinderProjectApp, RendererGl )
