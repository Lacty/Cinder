
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

enum class WindowSize {
  Width  = 600,
  Height = 400
};


class Common : public AppNative {
private:
  void prepareSettings(Settings* setting) override;
};

void Common::prepareSettings(Settings* setting) {
  setting->setWindowSize(static_cast<int>(WindowSize::Width),
                         static_cast<int>(WindowSize::Height));
}

namespace ly {
  void drawCube(const Vec3f&  pos,
    const Vec3f&  size,
    const ColorA& color = ColorA::white())
  {
    gl::color(color);
    gl::drawCube(pos, size);
  }

  void drawLine(const Vec3f&  pos,
    const Vec3f&  size,
    const ColorA& color = ColorA::white())
  {
    gl::color(color);
    gl::drawLine(pos, size);
  }

  void drawLine(const Vec2f&  pos,
    const Vec2f&  size,
    const ColorA& color = ColorA::white())
  {
    gl::color(color);
    gl::drawLine(pos, size);
  }

  void drawCircle(const Vec2f& center,
    const float  radius,
    const int&   segment_num = 0,
    const ColorA color = ColorA::white())
  {
    gl::color(color);
    gl::drawSolidCircle(center, radius, segment_num);
  }

  void drawEllipse(const Vec2f&  center,
    const float&  radiusX,
    const float&  radiusY,
    const int&    segment_num = 0,
    const ColorA& color = ColorA::white())
  {
    gl::color(color);
    gl::drawSolidEllipse(center, radiusX, radiusY, segment_num);
  }

  void drawStrokedCircle(const Vec2f& center,
    const float& radius,
    const int&   segment_num,
    const ColorA& color = ColorA::white())
  {
    gl::color(color);
    gl::drawStrokedCircle(center, radius, segment_num);
  }

  void drawStrokedCube(const Vec3f&  center,
    const Vec3f&  size,
    const ColorA& color = ColorA::white())
  {
    gl::color(color);
    gl::drawStrokedCube(center, size);
  }
}