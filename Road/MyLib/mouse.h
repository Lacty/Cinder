
#pragma once
#include "cinder/app/MouseEvent.h"
#include <set>


class Mouse : private boost::noncopyable {
public:

  struct MouseStatus {
    bool isPush;
    bool isPress;
    bool isPull;
  };

  static Mouse& get();

  void flashInput();

  ci::Vec2i   Pos();
  MouseStatus Left();
  MouseStatus Right();

  void MoveEvent(ci::app::MouseEvent event);
  void PushEvent(ci::app::MouseEvent event);
  void PullEvent(ci::app::MouseEvent event);

private:
  Mouse();

  ci::Vec2i   pos;
  MouseStatus left, right;
};