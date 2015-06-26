
#include "particle.h"
#include "cinder/Json.h"
#include <sstream>

#include "../MyLib/mouse.h"
#include "cinder/Rand.h"
#include "part.h"


Particle::Particle() {}

Particle::~Particle() {}

void Particle::setup() {
  JsonTree json(loadAsset("Data/particle_data.json"));
  std::ostringstream path;
  path << "Image/" << json["Path"].getValue<std::string>();
  image = loadImage(loadAsset(path.str()));

  gl::enableAlphaBlending();
}

Part Particle::create() {
  Part part;
  part.setPos(Mouse::get().Pos());
  part.setScale(Vec2f(Rand::randFloat(0.5f, 1.f),
                      Rand::randFloat(0.5f, 1.f)));
  part.setSpeed(Vec2f(Rand::randFloat(-3.f, 3.f),
                      Rand::randFloat(-5.f, -5.f)));
  part.setGravidy(Vec2f(0.f, -0.1f));
  part.setVelocity(Vec2f::zero());
  part.setColor(Color(Rand::randFloat(0.8f, 1.f),
                      Rand::randFloat(0.8f, 1.f),
                      Rand::randFloat(0.8f, 1.f)));
  part.setLife(300.f);
  part.setTexture(image);
  return part;
}

void Particle::kill() {
  std::list<Part>::iterator it;
  it = parts.begin();
  while (it != parts.end()) {
    if (it->isDead()) {
      it = parts.erase(it);
    } else {
      ++it;
    }
  }
}

void Particle::update() {
  if (Mouse::get().Left().isPress) {
    parts.emplace_back(create());
  }
  for (auto& it : parts) {
    it.update();
  }
  kill();
}

void Particle::draw() {
  for (auto it : parts) {
    it.draw();
  }
}