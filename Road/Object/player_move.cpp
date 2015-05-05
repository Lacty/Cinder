
#include "player_move.h"
#include "../MyLib/key.h"


PlayerMove::PlayerMove(Player* player) :
IObject(player),
pos(Vec3f::zero()),
lean_status(LeanStatus::Center) {}


void PlayerMove::update() {
  moveLeft();
  moveRight();
  moveBound();
}

void PlayerMove::moveLeft() {
  if (!Key::get().isPress(KeyEvent::KEY_a)) return;
  if (lean_status != LeanStatus::Left) {
    lean_status = LeanStatus::Left;
  }
  pos.x -= Speed;
}

void PlayerMove::moveRight() {
  if (!Key::get().isPress(KeyEvent::KEY_d)) return;
  if (lean_status != LeanStatus::Right) {
    lean_status = LeanStatus::Right;
  }
  pos.x += Speed;
}

void PlayerMove::moveBound() {
  if (pos.x < edge.left)  { pos.x += Speed; }
  if (pos.x > edge.right) { pos.x -= Speed; }
}


Vec3f PlayerMove::getPos() const {
  return pos;
}

LeanStatus PlayerMove::getLean() const {
  return lean_status;
}