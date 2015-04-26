
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
  ly::drawCube(Vec3f(int(WindowSize::Width) / 2, int(WindowSize::Height) / 2, 0),
               Vec3f(50, 50, 50),
               Color::white(),
               Vec3f(0, 0, 0),
               Vec3f(0, 0, 0),
               Vec3f(1, 1, 1));
}

CINDER_APP_NATIVE( CommonApp, RendererGl )
