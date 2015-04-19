
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

public:
  void prepareSettings(Settings* setting) override;

	void setup();
	void mouseDown( MouseEvent event ) override;	
  void keyDown(   KeyEvent   event)  override;
	void update();
	void draw();
};

void CinderProjectApp::prepareSettings(Settings* setting) {
  setting->setWindowSize(Vec2i(WIDTH, HEIGHT));
}

void CinderProjectApp::setup()
{
  pos  = Vec3f(WIDTH/2, HEIGHT/2, 0);
  size = Vec3f(50, 50, 50);
}

void CinderProjectApp::mouseDown( MouseEvent event )
{
}

void CinderProjectApp::keyDown(KeyEvent event) {
  if (event.getChar() == 'a') {
    pos.x -= 20;
  }
  if (event.getChar() == 'd') {
    pos.x += 20;
  }
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
