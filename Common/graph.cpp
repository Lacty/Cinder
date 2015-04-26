
#include "graph.h"
#include "cinder/Matrix44.h"


void ly::drawCube(const Vec3f&  pos,
                  const Vec3f&  size,
                  const ColorA& color)
{
  gl::color(color);
  gl::drawCube(pos, size);
}

void ly::drawCube(const Vec3f&  pos,
                  const Vec3f&  size,
                  const ColorA& color,
                  const Vec3f&  rotate,
                  const Vec3f&  translate,
                  const Vec3f&  scale)
{
  gl::pushModelView();
  gl::translate(pos);
  gl::rotate(rotate);
  gl::color(color);
  gl::drawCube(translate, (size * scale));
  gl::popModelView();
}

void ly::drawLine(const Vec3f&  pos,
                  const Vec3f&  size,
                  const ColorA& color)
{
  gl::color(color);
  gl::drawLine(pos, size);
}

void ly::drawLine(const Vec2f&  pos,
                  const Vec2f&  size,
                  const ColorA& color)
{
  gl::color(color);
  gl::drawLine(pos, size);
}

void ly::drawCircle(const Vec2f& center,
                    const float  radius,
                    const int&   segment_num,
                    const ColorA color)
{
  gl::color(color);
  gl::drawSolidCircle(center, radius, segment_num);
}

void ly::drawEllipse(const Vec2f&  center,
                     const float&  radiusX,
                     const float&  radiusY,
                     const int&    segment_num,
                     const ColorA& color)
{
  gl::color(color);
  gl::drawSolidEllipse(center, radiusX, radiusY, segment_num);
}

void ly::drawStrokedCircle(const Vec2f&  center,
                           const float&  radius,
                           const int&    segment_num,
                           const ColorA& color)
{
  gl::color(color);
  gl::drawStrokedCircle(center, radius, segment_num);
}

void ly::drawStrokedCube(const Vec3f&  center,
                         const Vec3f&  size,
                         const ColorA& color)
{
  gl::color(color);
  gl::drawStrokedCube(center, size);
}

void ly::drawString(const std::string& str,
                    const Vec2f&       pos,
                    const ColorA&      color,
                    const int&         font_size)
{
  gl::drawString(str, pos, color, Font("", font_size));
}