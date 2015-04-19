
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

  // verticalFovDegrees ���p(60~90�������炵��)
  // aspectRatio        ���c��(�A�X�y�N�g��A�֐��Ŏ擾�ł���)
  // nearPlane
  // farPlane           near��far�̊ԕ`��
  // ����̓��t�@�����X�Ɠ������l�ɂ��Ă���(�w�肵�����l�����ɂȂ�̂����킩���
  m_cam.setPerspective(60.0f, getWindowAspectRatio(), 5.0f, 3000.0f);

  m_eye    = Vec3f(WIDTH/2, HEIGHT/2, 500.f);
  m_center = Vec3f(WIDTH/2, HEIGHT/2, 0.0f);              // Vec3f(0.0f, 0.0f, 0.0f)
  m_up     = Vec3f::yAxis();             // Vec3f(0.0f, 1.0f, 0.0f) // Axis(��)

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

  gl::color(Color(0, 1, 1)); // �F�w��
  { // �L���[�u���N���N����]
    gl::pushModelView();
    gl::translate(Vec3f(WIDTH/2, HEIGHT / 2, 0));
    gl::rotate(Vec3f(0.0f, angle, 0.0f));

    gl::drawCube(Vec3f(0, 0, 0), size);

    gl::popModelView();
  }

  gl::setMatrices(m_cam);

  // �ڂ̈ʒu��(0, 0)���������炨����������
  // �ڂ̈ʒu�𒆉��ɁAcenter�������ɂ����Ă����炤�܂�������
}

CINDER_APP_NATIVE(CinderProjectApp, RendererGl)
