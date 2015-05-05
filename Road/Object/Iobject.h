
#pragma once

class Player;


class IObject {
protected:
  Player* player;

public:
  IObject(Player*);

  virtual void update() = 0;
};