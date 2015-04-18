#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

class CinderProjectApp : public AppNative {
public:
  void prepareSettings(Settings* setting) override;

	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void CinderProjectApp::prepareSettings(Settings* setting) {
  // WindowSizeの設定(Vec2i)
  setting->setWindowSize(Vec2i(500, 500));
  // 起動時のアプリ描画位置(Vec2i)
  setting->setWindowPos(Vec2i(100, 100));
  // FrameRate設定(float)
  setting->setFrameRate(30.0f);
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
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( CinderProjectApp, RendererGl )
