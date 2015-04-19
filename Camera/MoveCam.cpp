
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Camera.h"

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

  CameraPersp m_cam;
  Vec3f m_eye;
  Vec3f m_center;
  Vec3f m_up;

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
  pos = Vec3f(WIDTH / 2, HEIGHT / 2, 0);
  size = Vec3f(50, 50, 50);
  angle = 0;

  // verticalFovDegrees 視角(60~90がいいらしい)
  // aspectRatio        横縦比(アスペクト比、関数で取得できる)
  // nearPlane
  // farPlane           nearとfarの間描画
  // 今回はリファレンスと同じ数値にしておく(指定した数値が何になるのかがわからん
  m_cam.setPerspective(60.0f, getWindowAspectRatio(), 5.0f, 3000.0f);

  m_eye    = Vec3f(WIDTH/2, HEIGHT/2, 500.f);
  m_center = Vec3f(WIDTH/2, HEIGHT/2, 0.0f);     // Vec3f(0.0f, 0.0f, 0.0f)
  m_up     = Vec3f::yAxis();                     // Vec3f(0.0f, 1.0f, 0.0f) // Axis(軸)
}

void CinderProjectApp::mouseDown(MouseEvent event)
{
}

void CinderProjectApp::keyDown(KeyEvent event) {
  const float cam_move_speed = 5.0f;
  if (event.getChar() == 'd') m_eye.x += cam_move_speed;
  if (event.getChar() == 'a') m_eye.x -= cam_move_speed;
  if (event.getChar() == 'w') m_eye.z -= cam_move_speed;
  if (event.getChar() == 's') m_eye.z += cam_move_speed;
}

void CinderProjectApp::update()
{
  angle++;
  m_cam.lookAt(m_eye, m_center, m_up);
}

void CinderProjectApp::draw()
{
  gl::clear(Color(1, 1, 1));

  gl::color(Color(0, 1, 1)); // 色指定
  { // キューブがクルクル回転
    gl::pushModelView();
    gl::translate(Vec3f(WIDTH/2, HEIGHT / 2, 0));
    gl::rotate(Vec3f(0.0f, angle, 0.0f));

    gl::drawCube(Vec3f(0, 0, 0), size);

    gl::popModelView();
  }

  gl::setMatrices(m_cam);

  // 目の位置が(0, 0)だったからおかしかった
  // 目の位置を中央に、centerも中央にもってきたらうまくいった
}

CINDER_APP_NATIVE(CinderProjectApp, RendererGl)
