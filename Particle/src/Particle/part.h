
#pragma once
#include "../MyLib/ci_app.h"
#include "cinder/gl/Texture.h"


class Part {
private:
  Vec2f  pos;
  Vec2f  scale;
  Vec2f  speed;
  Vec2f  gravidy;
  Vec2f  velocity;
  ColorA color;
  float  life;

  gl::Texture* image;

  void runGravidy();
  void move();

public:
  Part() = default;

  bool isDead() const { return life < 0.f; }

  Vec2f  getPos()      const { return pos; }
  Vec2f  getScale()    const { return scale; }
  Vec2f  getSpeed()    const { return speed; }
  Vec2f  getGravidy()  const { return gravidy; }
  Vec2f  getVelocity() const { return velocity; }
  ColorA getColor()    const { return color; }
  float  getLife()     const { return life; }

  void setPos(const Vec2f& pos)           { this->pos      = pos; }
  void setScale(const Vec2f& scale)       { this->scale    = scale; }
  void setSpeed(const Vec2f& speed)       { this->speed    = speed; }
  void setGravidy(const Vec2f& gravidy)   { this->gravidy  = gravidy; }
  void setVelocity(const Vec2f& velocity) { this->velocity = velocity; }
  void setColor(const Color& color)       { this->color    = color; }
  void setLife(const float& life)         { this->life     = life; }

  void setTexture(gl::Texture& tex) { this->image = &tex; }

  void update();
  void draw();
};
