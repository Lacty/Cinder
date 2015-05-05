
#pragma once

class Object;


class IObject {
protected:

  Object* obj;
  IObject(Object*);

public:

  virtual void update() = 0;
};