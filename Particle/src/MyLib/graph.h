
#pragma once
#include "ci_app.h"


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

  void drawLine(const Vec3f&  begin,
                const Vec3f&  end,
                const ColorA& color);

  void drawLine(const Vec2f&  begin,
                const Vec2f&  end,
                const ColorA& color);

  void drawCircle(const Vec2f&  center,
                  const float&  radius,
                  const int&    segment_num,
                  const ColorA& color);

  void drawCircle(const Vec2f&  center,
                  const float&  radius,
                  const int&    segment_num,
                  const ColorA& color,
                  const Vec3f&  rotate,
                  const Vec3f&  translate,
                  const Vec3f&  scale);

  void drawEllipse(const Vec2f&  center,
                   const Vec2f&  radius,
                   const int&    segment_num,
                   const ColorA& color);

  void drawEllipse(const Vec2f&  center,
                   const Vec2f&  radius,
                   const int&    segment_num,
                   const ColorA& color,
                   const Vec3f&  rotate,
                   const Vec3f&  translate,
                   const Vec3f&  scale);

  void drawStrokedCircle(const Vec2f&  center,
                         const float&  radius,
                         const int&    segment_num,
                         const ColorA& color);

  void drawStrokedCircle(const Vec2f&  center,
                         const float&  radius,
                         const int&    segment_num,
                         const ColorA& color,
                         const Vec3f&  rotate,
                         const Vec3f&  translate,
                         const Vec3f&  scale);

  void drawStrokedCube(const Vec3f&  center,
                       const Vec3f&  size,
                       const ColorA& color);

  void drawStrokedCube(const Vec3f&  center,
                       const Vec3f&  size,
                       const ColorA& color,
                       const Vec3f&  rotate,
                       const Vec3f&  translate,
                       const Vec3f&  scale);

  void drawSoildTriangle(const Vec2f& posA,
                         const Vec2f& posB,
                         const Vec2f& posC,
                         const Color& color);

  void drawString(const std::string& str,
                  const Vec2f&       pos,
                  const ColorA&      color,
                  const int&         font_size);

  void drawString(const std::string& str,
                  const Vec2f&       pos,
                  const ColorA&      color,
                  const int&         font_size,
                  const Vec3f&       rotate,
                  const Vec3f&       translate,
                  const Vec3f&       scale);
}