
#pragma once
#include "cinder/gl/Texture.h"
#include "../MyLib/ci_app.h"
#include "cinder/ImageIo.h"
#include <list>


class Part;

class Particle {
private:
  Vec2f  pos;
  Vec2f  scale;
  Vec2f  speed;
  Vec2f  gravidy;
  Vec2f  velocity;
  ColorA color;
  float  life;

  std::string path;
  gl::Texture image;

  Part create();
  void kill();
  std::list<Part> parts;

public:
  Particle();
  ~Particle();
  void setup();

  void update();
  void draw();
};