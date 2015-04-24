
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Rand.h"
#include "cinder/Matrix44.h"

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;

enum class WindowSize {
  Width  = 600,
  Height = 400
};

/*
class Common : public AppNative {
private:
  void prepareSettings(Settings* setting) override;
};

void Common::prepareSettings(Settings* setting) {
  setting->setWindowSize(static_cast<int>(WindowSize::Width),
                         static_cast<int>(WindowSize::Height));
}
*/


class ly {
private:
  ly() = default;

public:
  static void drawCube(const Vec3f&  pos,
                       const Vec3f&  size,
                       const ColorA& color)
  {
    gl::color(color);
    gl::drawCube(pos, size);
  }

  static void drawCube(const Vec3f&  pos,
                       const Vec3f&  size,
                       const ColorA& color,
                       const Vec3f&  scale,
                       const Vec3f&  rotate)
  {
    gl::color(color);
    Matrix44f m_rotate = Matrix44f::createRotation(rotate);
    gl::drawCube((m_rotate * pos), size * scale);
  }

  static void drawLine(const Vec3f&  pos,
                       const Vec3f&  size,
                       const ColorA& color)
  {
    gl::color(color);
    gl::drawLine(pos, size);
  }

  static void drawLine(const Vec2f&  pos,
                       const Vec2f&  size,
                       const ColorA& color)
  {
    gl::color(color);
    gl::drawLine(pos, size);
  }

  static void drawCircle(const Vec2f& center,
                         const float  radius,
                         const int&   segment_num,
                         const ColorA color)
  {
    gl::color(color);
    gl::drawSolidCircle(center, radius, segment_num);
  }

  static void drawEllipse(const Vec2f&  center,
                          const float&  radiusX,
                          const float&  radiusY,
                          const int&    segment_num,
                          const ColorA& color)
  {
    gl::color(color);
    gl::drawSolidEllipse(center, radiusX, radiusY, segment_num);
  }

  static void drawStrokedCircle(const Vec2f&  center,
                                const float&  radius,
                                const int&    segment_num,
                                const ColorA& color)
  {
    gl::color(color);
    gl::drawStrokedCircle(center, radius, segment_num);
  }

  static void drawStrokedCube(const Vec3f&  center,
                              const Vec3f&  size,
                              const ColorA& color)
  {
    gl::color(color);
    gl::drawStrokedCube(center, size);
  }

  static void drawString(const std::string& str,
                         const Vec2f&       pos,
                         const ColorA&      color,
                         const int&         font_size)
  {
    gl::drawString(str, pos, color, Font("", font_size));
  }
};