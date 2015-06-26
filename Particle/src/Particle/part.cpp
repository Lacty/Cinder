
#include "part.h"


void Part::runGravidy() {
  velocity -= gravidy;
  pos += velocity;
}

void Part::move() {
  pos += speed;
}

void Part::update() {
  life--;
  move();
  runGravidy();
}

void Part::draw() {
  gl::pushModelView();
  gl::translate(pos);
  gl::scale(scale);
  gl::color(color);
  gl::draw(*image, Area(-60, -60, 60, 60));
  gl::popModelView();
}