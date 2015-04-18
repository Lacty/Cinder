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

  // íÜâõ
  gl::drawColorCube(Vec3f(WIDTH/2, HEIGHT/2, 0.0f),
                    Vec3f(50.0f, 50.0f, 50.0f));

  // ç∂è„
  gl::drawColorCube(Vec3f(60.0f, 60.0f, 0.0f),
                    Vec3f(50.0f, 50.0f, 50.0f));
  
  // ç∂â∫
  gl::drawColorCube(Vec3f(60.0f, 250.0f, 0.0f),
                    Vec3f(50.0f, 50.0f, 50.0f));

  // âEè„
  gl::drawColorCube(Vec3f(400.0f, 60.0f, 0.0f),
                    Vec3f(50.0f, 50.0f, 50.0f));

  // âEâ∫
  gl::drawColorCube(Vec3f(400.0f, 250.0f, 0.0f),
                    Vec3f(50.0f, 50.0f, 50.0f));
}

CINDER_APP_NATIVE( CinderProjectApp, RendererGl )
