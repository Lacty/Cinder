
#pragma once

class SceneMgr;


class Scene {
protected:
  SceneMgr* mgr;
  Scene(SceneMgr*);

public:

  virtual void update() = 0;
  virtual void draw()   = 0;
};