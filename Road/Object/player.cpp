
#include "player.h"


Player::Player() :
move(std::make_shared<PlayerMove>(this)),
lean(std::make_shared<PlayerLean>(this)) {}


void Player::update() {

}

void Player::draw() {

}

Vec3f Player::getPos() const {
  return move->getPos();
}

LeanStatus Player::getLean() const {
  return move->getLean();
}