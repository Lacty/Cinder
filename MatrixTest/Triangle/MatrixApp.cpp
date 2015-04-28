
#include "common.h"
#include "graph.h"

#include <vector>
#include "cinder/Matrix.h"


class MatrixApp : public AppNative {
private:
  struct Line {
    Vec3f begin;
    Vec3f end;
  };
  std::vector<Line> lines;

  float anime;

public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void MatrixApp::setup() {
  setWindowSize(int(WindowSize::Width), int(WindowSize::Height));
  anime = 0.0f;

  lines.push_back({ { 0, 1, 0 }, { -1, -1, 1 } }); // a-b
  lines.push_back({ { 0, 1, 0 }, { 1, -1, 1 } }); // a-c
  lines.push_back({ { 0, 1, 0 }, { 1, -1, -1 } }); // a-d
  lines.push_back({ { 0, 1, 0 }, { -1, -1, -1 } }); // a-e

  lines.push_back({ { -1, -1, 1 }, { 1, -1, 1 } }); // b-c
  lines.push_back({ { 1, -1, 1 }, { 1, -1, -1 } }); // c-d
  lines.push_back({ { 1, -1, -1 }, { -1, -1, -1 } }); // d-e
  lines.push_back({ { -1, -1, -1 }, { -1, -1, 1 } }); // e-b
}

void MatrixApp::mouseDown(MouseEvent event) {}

void MatrixApp::update() {
  anime += 0.01f;
}

void MatrixApp::draw() {
  gl::clear();

  Matrix44f scale     = Matrix44f::createScale(Vec3f(100, 100, 100));
  Matrix44f translate = Matrix44f::createTranslation(Vec3f(0.0f, 0.0f, 1000.0f));
  Matrix44f rotate    = Matrix44f::createRotation(Vec3f(0.0f, anime, 0.0f));
  const float viewing_angle = 0.001f;
  
  gl::pushModelView();
  gl::translate(getWindowCenter());

  for (auto line : lines) {
    auto begin = line.begin;
    auto end = line.end;

    begin = translate * scale * rotate * begin;
    end = translate * scale * rotate * end;

    ly::drawLine(begin.xy() / (begin.z * viewing_angle),
                 end.xy() / (end.z * viewing_angle),
                 Color(1, 1, 1));
  }

  gl::popModelView();
}

CINDER_APP_NATIVE(MatrixApp, RendererGl)
