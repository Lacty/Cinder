
#pragma once
#include "common.h"


namespace ly {
  void drawCube(const Vec3f&  pos,
                const Vec3f&  size,
                const ColorA& color);

  void drawCube(const Vec3f&  pos,
                const Vec3f&  size,
                const ColorA& color,
                const Vec3f&  rotate,
                const Vec3f&  translate,
                const Vec3f&  scale);

  void drawLine(const Vec3f&  pos,
                const Vec3f&  size,
                const ColorA& color);

  void drawLine(const Vec2f&  pos,
                const Vec2f&  size,
                const ColorA& color);

  void drawCircle(const Vec2f& center,
                  const float  radius,
                  const int&   segment_num,
                  const ColorA color);

  void drawEllipse(const Vec2f&  center,
                   const float&  radiusX,
                   const float&  radiusY,
                   const int&    segment_num,
                   const ColorA& color);

  void drawStrokedCircle(const Vec2f&  center,
                         const float&  radius,
                         const int&    segment_num,
                         const ColorA& color);

  void drawStrokedCube(const Vec3f&  center,
                       const Vec3f&  size,
                       const ColorA& color);

  void drawString(const std::string& str,
                  const Vec2f&       pos,
                  const ColorA&      color,
                  const int&         font_size);
}