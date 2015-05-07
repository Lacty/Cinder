
#include "boost_ring.h"
#include "../MyLib/graph.h"
#include "cinder/Rand.h"


BoostRing::BoostRing() :
distance(50),
radius(10),
speed(-0.2f),
segment_num(40)
{
  m_ring.push_back({ { Center }, { Center, 0, distance} });
}


void BoostRing::update() {
  for (auto& ring : m_ring) {
    ring.pos.z += speed;
    if (ring.pos.z <= 0.f) {
      ring.pos.z += distance;
    }
  }
}

void BoostRing::draw() {
  gl::pushModelView();
  gl::translate(getWindowCenter());

  Matrix44f translate;
  const float viewing_angle = 0.008f;

  for (auto& ring : m_ring) {
    auto pos = ring.pos;
    translate = Matrix44f::createTranslation(Vec3f(0.0f, 0.0f, pos.z));

    pos = translate * pos;

    ly::drawStrokedCircle(pos.xy(),
                          radius / ring.pos.z,
                          segment_num, Color(0, 1, 1));
  }



  gl::popModelView();
}