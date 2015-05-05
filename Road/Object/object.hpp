
#pragma once


class Object {
public:

  Object() = default;

  virtual void update() = 0;
  virtual void draw()   = 0;
};