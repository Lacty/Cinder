
#pragma once
#include "player_move.h"
#include "player_lean.h"
#include <memory>


class Player {
private:
  std::shared_ptr<PlayerMove> move;
  std::shared_ptr<PlayerLean> lean;

public:
  Player();

  Vec3f      getPos()  const;
  LeanStatus getLean() const;

  void update();
  void draw();
};