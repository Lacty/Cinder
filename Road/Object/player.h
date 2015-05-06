
#pragma once
#include "player_move.h"
#include "player_lean.h"
#include "player_model.h"
#include <memory>


class Player {
private:
  std::shared_ptr<PlayerMove> move;
  std::shared_ptr<PlayerLean> lean;
  std::shared_ptr<PlayerModel> model;

public:
  Player();

  Vec3f      getPos()       const;
  LeanStatus getLean()      const;
  float      getLeanAngle() const;

  void update();
  void draw();
};