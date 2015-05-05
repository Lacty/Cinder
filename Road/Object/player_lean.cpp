
#include "player_lean.h"
#include "player.h"


PlayerLean::PlayerLean(Player* player) :
IObject(player),
lean_angle(0.0f) {}


void PlayerLean::update() {
  
}


void PlayerLean::leanLeft() {
  
}

void PlayerLean::leanRight() {

}

void PlayerLean::leanBound() {

}


float PlayerLean::getLeanAngle() const {
  return lean_angle;
}