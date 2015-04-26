
#include "common.h"
#include "graph.h"


class CommonApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void CommonApp::setup()
{
  setWindowSize(int(WindowSize::Width), int(WindowSize::Height));
}

void CommonApp::mouseDown( MouseEvent event )
{
}

void CommonApp::update()
{
}

void CommonApp::draw()
{
	gl::clear();
  ly::drawCircle(getWindowSize() / 2, 50,
                 0, Color::white(),
                 Vec2f::zero(),
                 Vec2f::zero(),
                 Vec2f::one());
}

CINDER_APP_NATIVE( CommonApp, RendererGl )
