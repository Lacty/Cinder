#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Rand.h"

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
  Rand::randomize();
  size = Vec3f(50, 50, 50);
}

void CinderProjectApp::mouseDown( MouseEvent event )
{
  pos = Vec3f(Rand::randInt(0, WIDTH), HEIGHT / 2, 0);
}

void CinderProjectApp::update()
{
}

void CinderProjectApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );

  gl::color(Color(0, 1, 1)); // êFéwíË

  gl::drawCube(pos, size);
}

CINDER_APP_NATIVE( CinderProjectApp, RendererGl )
