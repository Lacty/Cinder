
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

  m_eye    = Vec3f(0.0f, 0.0f, 500.f);
  m_center = Vec3f::zero();              // Vec3f(0.0f, 0.0f, 0.0f)
  m_up     = Vec3f::yAxis();             // Vec3f(0.0f, 1.0f, 0.0f) // Axis(軸)

  m_cam.lookAt(m_eye, m_center, m_up);
}

void CinderProjectApp::mouseDown(MouseEvent event)
{
}

void CinderProjectApp::update()
{
  angle++;
}

void CinderProjectApp::draw()
{
  gl::clear(Color(1, 1, 1));

  gl::color(Color(0, 1, 1)); // 色指定
  { // キューブがクルクル回転
    gl::pushModelView();
    gl::translate(Vec3f(300, HEIGHT / 2, 0));
    gl::rotate(Vec3f(0.0f, angle, 0.0f));

    gl::drawCube(Vec3f(0, 0, 0), size);

    gl::popModelView();
  }

  gl::setMatrices(m_cam);

  // キューブ中央に描画させてるはずなんだが・・・
  // 左上で回転してる＾ｐ＾
}

CINDER_APP_NATIVE(CinderProjectApp, RendererGl)
