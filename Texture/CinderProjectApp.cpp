
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;


class CinderProjectApp : public AppNative {
private:
  enum WindowSize {
    WIDTH = 500,
    HEIGHT = 300
  };

  gl::Texture image;

  Vec2f pos;

public:
  void prepareSettings(Settings* setting) override;

  void setup();
  void mouseDown(MouseEvent event) override;
  void keyDown(  KeyEvent   event) override;
  void update();
  void draw();
};

void CinderProjectApp::prepareSettings(Settings* setting) {
  setting->setWindowSize(Vec2i(WIDTH, HEIGHT));
}

void CinderProjectApp::setup()
{
  image = loadImage(loadAsset("pork.png"));

  gl::enableAdditiveBlending();
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  pos = Vec2f(WIDTH / 2, HEIGHT / 2);
}

void CinderProjectApp::mouseDown(MouseEvent event)
{
}

void CinderProjectApp::keyDown(KeyEvent event) {
  //if (event.getChar() == 'd')
  //if (event.getChar() == 'a')
  //if (event.getChar() == 'w')
  //if (event.getChar() == 's')
}

void CinderProjectApp::update()
{
}

void CinderProjectApp::draw()
{
  gl::clear(Color(1, 1, 1));

  gl::draw(image, pos);
}

CINDER_APP_NATIVE(CinderProjectApp, RendererGl)
