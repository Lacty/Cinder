
#pragma once

class SceneMgr;


class Scene {
protected:
  Scene(SceneMgr*);
  SceneMgr* m_manager;

public:

  virtual void update() = 0;
  virtual void draw() = 0;
};