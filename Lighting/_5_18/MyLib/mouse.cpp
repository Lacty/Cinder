
#include "mouse.h"


Mouse::Mouse() {
  pos = ci::Vec2i::zero();
  left = { false, false, false };
  right = { false, false, false };
}


Mouse& Mouse::get() {
  static Mouse mouse;
  return mouse;
}

void Mouse::flashInput() {
  left.isPush  = false;
  left.isPull  = false;
  right.isPush = false;
  right.isPull = false;
}

void Mouse::MoveEvent(ci::app::MouseEvent event) {
  pos = event.getPos();
}

void Mouse::PushEvent(ci::app::MouseEvent event) {
  left.isPush   = event.isLeftDown();
  left.isPress  = event.isLeft();
  right.isPush  = event.isRightDown();
  right.isPress = event.isRight();
}

void Mouse::PullEvent(ci::app::MouseEvent event) {
  left.isPull = event.isLeft() ? true : false;
  right.isPull = event.isRight() ? true : false;

  left.isPress  = false;
  right.isPress = false;
}

ci::Vec2i Mouse::Pos() {
  return pos;
}

Mouse::MouseStatus Mouse::Left() {
  return left;
}

Mouse::MouseStatus Mouse::Right() {
  return right;
}