
#include "player.h"


Player::Player() :
move(std::make_shared<PlayerMove>(this)),
lean(std::make_shared<PlayerLean>(this)),
model(std::make_shared<PlayerModel>(this)) {}


void Player::update() {
  move->update();
  lean->update();
  model->update();
}

void Player::draw() {
  model->draw();
}


Vec3f Player::getPos() const {
  return move->getPos();
}

LeanStatus Player::getLean() const {
  return move->getLean();
}

float Player::getLeanAngle() const {
  return lean->getLeanAngle();
}