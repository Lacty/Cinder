
#include "graph.h"
#include "cinder/Matrix44.h"


void ly::drawCube(const Vec3f&  pos,
                  const Vec3f&  size,
                  const ColorA& color) {
  gl::color(color);
  gl::drawCube(pos, size);
}

void ly::drawCube(const Vec3f&  pos,
                  const Vec3f&  size,
                  const ColorA& color,
                  const Vec3f&  rotate,
                  const Vec3f&  translate,
                  const Vec3f&  scale) {
  gl::pushModelView();
  gl::translate(translate);
  gl::rotate(rotate);
  gl::color(color);
  gl::scale(scale);
  gl::drawCube(pos, size);
  gl::popModelView();
}

void ly::drawLine(const Vec3f&  begin,
                  const Vec3f&  end,
                  const ColorA& color) {

  gl::color(color);
  gl::drawLine(begin, end);
}

void ly::drawLine(const Vec2f&  begin,
                  const Vec2f&  end,
                  const ColorA& color) {
  gl::color(color);
  gl::drawLine(begin, end);
}

void ly::drawCircle(const Vec2f&  center,
                    const float&  radius,
                    const int&    segment_num,
                    const ColorA& color) {
  gl::color(color);
  gl::drawSolidCircle(center, radius, segment_num);
}

void ly::drawCircle(const Vec2f&  center,
                    const float&  radius,
                    const int&    segment_num,
                    const ColorA& color,
                    const Vec3f&  rotate,
                    const Vec3f&  translate,
                    const Vec3f&  scale) {
  gl::pushModelView();
  gl::translate(translate);
  gl::rotate(rotate);
  gl::color(color);
  gl::scale(scale);
  gl::drawSolidCircle(center, radius, segment_num);
  gl::popModelView();
}

void ly::drawEllipse(const Vec2f&  center,
                     const Vec2f&  radius,
                     const int&    segment_num,
                     const ColorA& color) {
  gl::color(color);
  gl::drawSolidEllipse(center, radius.x, radius.y, segment_num);
}

void ly::drawEllipse(const Vec2f&  center,
                     const Vec2f&  radius,
                     const int&    segment_num,
                     const ColorA& color,
                     const Vec3f&  rotate,
                     const Vec3f&  translate,
                     const Vec3f&  scale) {
  gl::pushModelView();
  gl::translate(translate);
  gl::rotate(rotate);
  gl::color(color);
  gl::scale(scale);
  gl::drawSolidEllipse(center, radius.x, radius.y, segment_num);
  gl::popModelView();
}

void ly::drawStrokedCircle(const Vec2f&  center,
                           const float&  radius,
                           const int&    segment_num,
                           const ColorA& color) {
  gl::color(color);
  gl::drawStrokedCircle(center, radius, segment_num);
}

void ly::drawStrokedCircle(const Vec2f&  center,
                           const float&  radius,
                           const int&    segment_num,
                           const ColorA& color,
                           const Vec3f&  rotate,
                           const Vec3f&  translate,
                           const Vec3f&  scale) {
  gl::pushModelView();
  gl::translate(translate);
  gl::rotate(rotate);
  gl::color(color);
  gl::scale(scale);
  gl::drawStrokedCircle(center, radius, segment_num);
  gl::popModelView();
}

void ly::drawStrokedCube(const Vec3f&  center,
                         const Vec3f&  size,
                         const ColorA& color) {
  gl::color(color);
  gl::drawStrokedCube(center, size);
}

void ly::drawStrokedCube(const Vec3f&  center,
                         const Vec3f&  size,
                         const ColorA& color,
                         const Vec3f&  rotate,
                         const Vec3f&  translate,
                         const Vec3f&  scale) {
  gl::pushModelView();
  gl::translate(translate);
  gl::rotate(rotate);
  gl::color(color);
  gl::scale(scale);
  gl::drawStrokedCube(center, size);
  gl::popModelView();
}

void ly::drawSoildTriangle(const Vec2f& posA,
                           const Vec2f& posB,
                           const Vec2f& posC,
                           const Color& color) {
  gl::color(color);
  gl::drawSolidTriangle(posA, posB, posC);
}

void ly::drawString(const std::string& str,
                    const Vec2f&       pos,
                    const ColorA&      color,
                    const int&         font_size) {
  static std::unique_ptr<Font> font = std::make_unique<Font>("", font_size);
  gl::drawString(str, pos, color, *font);
}

void ly::drawString(const std::string& str,
                    const Vec2f&       pos,
                    const ColorA&      color,
                    const int&         font_size,
                    const Vec3f&       rotate,
                    const Vec3f&       translate,
                    const Vec3f&       scale) {
  gl::pushModelView();
  gl::translate(translate);
  gl::rotate(rotate);
  gl::scale(scale);
  gl::drawString(str, pos, color, Font("", font_size));
  gl::popModelView();
}