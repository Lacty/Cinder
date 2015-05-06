
#include "player_lean.h"
#include "player.h"


PlayerLean::PlayerLean(Player* player) :
IObject(player),
lean_angle(angle_status.speed) {}


void PlayerLean::update() {
  leanLeft();
  leanRight();
  leanCenter();
  leanBound();
}


void PlayerLean::leanLeft() {
  if (player->getLean() != LeanStatus::Left) return;
  lean_angle -= angle_status.speed;
}

void PlayerLean::leanRight() {
  if (player->getLean() != LeanStatus::Right) return;
  lean_angle += angle_status.speed;
}

void PlayerLean::leanCenter() {
  if (player->getLean() != LeanStatus::Center) return;
  if (lean_angle == angle_status.center) return;
  if (lean_angle <= angle_status.center) {
    lean_angle += angle_status.speed;
  }
  if (lean_angle >= angle_status.center) {
    lean_angle -= angle_status.speed;
  }
}

void PlayerLean::leanBound() {
  if (lean_angle <= angle_status.left_max) {
    lean_angle += angle_status.speed;
  }
  if (lean_angle >= angle_status.right_max) {
    lean_angle -= angle_status.speed;
  }
}


float PlayerLean::getLeanAngle() const {
  return lean_angle;
}