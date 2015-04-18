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

  gl::color(Color(0, 1, 1)); // êFéwíË::cyan

  // ç∂
  gl::drawStrokedCube(Vec3f(50, 50, 0),
                      Vec3f(50, 50, 20));

  // íÜâõ
  gl::drawStrokedCube(Vec3f(WIDTH/2, HEIGHT / 2, 0),
                      Vec3f(50, 50, 20));

  // âE
  gl::drawStrokedCube(Vec3f(WIDTH-50, HEIGHT-50, 0),
                      Vec3f(50, 50, 20));
}

CINDER_APP_NATIVE( CinderProjectApp, RendererGl )
