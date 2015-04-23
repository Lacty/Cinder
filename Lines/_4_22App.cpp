
#include "common.h"
#include "cinder/Rand.h"
#include "cinder/Matrix44.h"

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"


class _4_22App : public AppNative {
private:
  struct Line {
    Vec3f begin;
    Vec3f end;
  };
  std::vector<Line> lines;

  float anime_count;
  float anime_up;
  float anime_down;
  float anime_right;
  float anime_left;

  gl::Texture image;
  Rectf image_rect;
  Vec3f image_pos;

  void imageAnime();

public:
  void prepareSettings(Settings* setting) override;
  void setup();

  void mouseDown(MouseEvent event);
  void keyDown(KeyEvent event)override;

  void update();
  void draw();
};

void _4_22App::prepareSettings(Settings* setting) {
  setting->setWindowSize(Width, Height);
}

void _4_22App::setup()
{
  //gl::enableDepthRead();
  gl::enableAlphaBlending();
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  anime_count = 0.0f;
  anime_up = 0.0f;
  anime_down = 0.0f;
  anime_right = 0.0f;
  anime_left = 0.0f;

  // Žè‘O‚Ì–Ê
  lines.push_back({ { -1, 1, -1 }, { 1, 1, -1 } }); //0-1
  lines.push_back({ { 1, 1, -1 }, { 1, -1, -1 } }); //1-2
  lines.push_back({ { 1, -1, -1 }, { -1, -1, -1 } }); //2-3
  lines.push_back({ { -1, -1, -1 }, { -1, 1, -1 } }); //3-0

  // ‰œ‚Ì–Ê
  lines.push_back({ { -1, 1, 1 }, { 1, 1, 1 } }); //4-5
  lines.push_back({ { 1, 1, 1 }, { 1, -1, 1 } }); //5-6
  lines.push_back({ { 1, -1, 1 }, { -1, -1, 1 } }); // 6-7
  lines.push_back({ { -1, -1, 1 }, { -1, 1, 1 } }); //7-4

  // Žè‘O‚Æ‰œ‚ð‚Â‚È‚°‚éLine
  lines.push_back({ { -1, 1, -1 }, { -1, 1, 1 } }); //0-4
  lines.push_back({ { 1, 1, -1 }, { 1, 1, 1 } }); //1-5
  lines.push_back({ { 1, -1, -1 }, { 1, -1, 1 } }); //2-6
  lines.push_back({ { -1, -1, -1 }, { -1, -1, 1 } }); //3-7
  /*
  lines.push_back({ {-1, 1, -1}, {1, 1, 1} }); //0-5
  lines.push_back({ {1, 1, -1}, {1, -1, 1} }); //1-6
  lines.push_back({ {1, -1, -1}, {-1, -1, 1} }); //2-7
  lines.push_back({ {-1, -1, -1}, {-1, 1, 1} }); //3-4
  */

  image = loadImage(loadAsset("miku.png"));
  image_pos = Vec3f(-image.getWidth() / 2, -image.getHeight() / 2, 1000);
  image_rect = Rectf(Vec2f(-image.getWidth()/2, -image.getHeight()/2), image.getSize());
}

void _4_22App::imageAnime() {
  static float anime = 0.0f;
  anime += 0.1f;

  image_pos.z = (sin(anime) * 50);

  image_rect = Rectf(Vec2f(image_pos.x / image_pos.z, image_pos.y / image_pos.z),
                     Vec2f(image.getSize().x, image.getSize().y));
}

void _4_22App::mouseDown(MouseEvent event) {}

void _4_22App::keyDown(KeyEvent event) {
  if (event.getCode() == KeyEvent::KEY_UP) {
    anime_up += 0.02f;
  }
  if (event.getCode() == KeyEvent::KEY_DOWN) {
    anime_down -= 0.02f;
  }
  if (event.getCode() == KeyEvent::KEY_RIGHT) {
    anime_right += 0.02f;
  }
  if (event.getCode() == KeyEvent::KEY_LEFT) {
    anime_left -= 0.02f;
  }
}

void _4_22App::update()
{
  anime_count += 0.01f;

  imageAnime();
}

void _4_22App::draw()
{
  gl::clear(Color::white());

  gl::pushModelView();
  gl::translate(Vec2f(Width/2, Height/2));

  Matrix44f translate = Matrix44f::createTranslation(Vec3f(0, 0, 800));
  Matrix44f scale = Matrix44f::createScale(Vec3f(300, 300, 300));
  Matrix44f rotate = Matrix44f::createRotation(Vec3f(anime_right + anime_left,
                                                     anime_count,
                                                     anime_down + anime_up));

  // image
  gl::color(Color::white());
  gl::draw(image, image_rect);

  gl::rotate(Vec3f(0, /*anime_count*/0, 0));

  for (auto line : lines) {
    auto begin = line.begin;
    auto end   = line.end;

    begin = translate * rotate * scale * begin;
    end   = translate * rotate * scale * end;

    ly::drawLine(Vec2f(begin.x / (begin.z * 0.01f),
                       begin.y / (begin.z * 0.01f)),
                 Vec2f(end.x / (end.z * 0.01f),
                       end.y / (end.z * 0.01f)),
                 Color(0, 1, 1));
  }


  gl::drawString("<< Press Direction Key >>", Vec2f(30, -20), Color(0, 0, 0), Font("",30));

  gl::popModelView();

}

CINDER_APP_NATIVE(_4_22App, RendererGl)
