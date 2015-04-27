
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
  
public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void MatrixApp::setup()
{
  setWindowSize(int(WindowSize::Width), int(WindowSize::Height));

  lines.push_back({ { 0, 0, 0 }, { 1, 1, 0 } });
}

void MatrixApp::mouseDown(MouseEvent event)
{
}

void MatrixApp::update()
{
}

void MatrixApp::draw()
{
  gl::clear();

  Matrix44f scale = Matrix44f::createScale(Vec3f(100, 100, 100));
  Matrix44f translate = Matrix44f::createTranslation(Vec3f(0.0f, 0.0f, 500.0f));


  for (auto line : lines) {
    auto begin = line.begin;
    auto end   = line.end;

    begin = translate * scale * begin;
    end = translate * scale * end;

    ly::drawLine(Vec2f(begin.x / (begin.z * 0.004f) + getWindowWidth() / 2, begin.y / (begin.z * 0.004f) + getWindowHeight() / 2),
                 Vec2f(end.x / (end.z * 0.004f) + getWindowWidth() / 2, end.x / (end.z * 0.004f) + getWindowHeight() / 2),
                 Color::white());
  }
}

CINDER_APP_NATIVE(MatrixApp, RendererGl)
