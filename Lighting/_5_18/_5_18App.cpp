
#include "MyLib/common.h"
#include "MyLib/key.h"
#include "MyLib/graph.h"
#include <vector>
#include <algorithm>

class _5_18App : public AppNative {
private:
  // 面情報を定義
  //  三角形の頂点、色
  struct Face {
    Vec3f v1, v2, v3;
    Color color;

    // 法線ベクトル
    Vec3f normal;
  };
  std::vector<Face> faces;

  Vec3f light;
  Vec2f light_pos;
  float light_al;

  float rx;
  float ry;
  float rz;

public:
  void setup();
  void mouseDown(MouseEvent event);
  void keyDown(KeyEvent event) {
    Key::get().setKeyPush(event.getCode());
    Key::get().setKeyPress(event.getCode());
  }
  void keyUp(KeyEvent event) {
    Key::get().popKeyPress(event.getCode());
    Key::get().setKeyPull(event.getCode());
  }
  void update();
  void draw();
};

void _5_18App::setup() {
  gl::enableAlphaBlending();

  // 面情報を生成
  faces.push_back({ { -1, -1, -1 }, { 1, 1, -1 }, { 1, -1, -1 }, { 0, 1, 1 } });
  faces.push_back({ { -1, -1, -1 }, { -1, 1, -1 }, { 1, 1, -1 }, { 0, 1, 1 } });

  faces.push_back({ { -1, 1, -1 }, { -1, 1, 1 }, { 1, 1, 1 }, { 1, 0, 0 } });
  faces.push_back({ { -1, 1, -1 }, { 1, 1, 1 }, { 1, 1, -1 }, { 1, 0, 0 } });

  faces.push_back({ { 1, -1, -1 }, { 1, 1, -1 }, { 1, 1, 1 }, { 0, 1, 0 } });
  faces.push_back({ { 1, -1, -1 }, { 1, 1, 1 }, { 1, -1, 1 }, { 0, 1, 0 } });

  faces.push_back({ { -1, -1, -1 }, { -1, -1, 1 }, { -1, 1, 1 }, { 0, 0, 1 } });
  faces.push_back({ { -1, -1, -1 }, { -1, 1, 1 }, { -1, 1, -1 }, { 0, 0, 1 } });

  faces.push_back({ { -1, -1, -1 }, { 1, -1, 1 }, { -1, -1, 1 }, { 1, 1, 0 } });
  faces.push_back({ { -1, -1, -1 }, { 1, -1, -1 }, { 1, -1, 1 }, { 1, 1, 0 } });

  faces.push_back({ { 1, 1, 1 }, { -1, 1, 1 }, { -1, -1, 1 }, { 1, 0, 1 } });
  faces.push_back({ { 1, 1, 1 }, { -1, -1, 1 }, { 1, -1, 1 }, { 1, 0, 1 } });

  // 法線の計算
  for (auto& face : faces) {
    Vec3f a = face.v2 - face.v1;
    Vec3f b = face.v3 - face.v1;
    Vec3f c = b.cross(a);

    // 長さを１にしたベクトル
    face.normal = c.normalized();
    // face.normal = b.cross(a).normalized();
  }

  rx = 0.0;
  ry = 0.0;
  rz = 0.0;

  // 向きのみの設定
  light = Vec3f(0, 0, 0.5);
  light_al = 1;

  light_pos = Vec2f::zero();
}

void _5_18App::mouseDown(MouseEvent event) {}

void _5_18App::update() {
  rx += 0.01f;
  ry += 0.01f;
  rz += 0.01f;

  if (Key::get().isPress(KeyEvent::KEY_d)) {
    light.x -= 0.01f;
  }
  if (Key::get().isPress(KeyEvent::KEY_a)) {
    light.x += 0.01f;
  }
  if (Key::get().isPress(KeyEvent::KEY_w)) {
    light.y += 0.01f;
  }
  if (Key::get().isPress(KeyEvent::KEY_s)) {
    light.y -= 0.01f;
  }

  if (Key::get().isPress(KeyEvent::KEY_f)) {
    light_al += 0.01f;
  }
  if (Key::get().isPress(KeyEvent::KEY_g)) {
    light_al -= 0.01f;
  }

  if (Key::get().isPush(KeyEvent::KEY_r)) {
    light = Vec3f(0, 0, 0.6);
    light_al = 1.0f;
  }

  light_pos = Vec2f(light.x * -getWindowCenter().x, light.y * -getWindowCenter().y);

  console() << light.x << "," << light.y << "," << light.z << std::endl;
}

void _5_18App::draw() {
  // clear out the window with black
  gl::clear(Color(0, 0, 0));

  // 行列生成
  Matrix44f translate = Matrix44f::createTranslation(Vec3f(0.0, 0.0, 750.0));
  Matrix44f scale = Matrix44f::createScale(Vec3f(150.0, 150.0, 150.0));
  Matrix44f rotate = Matrix44f::createRotation(Vec3f(rx, ry, rz));

  // 事前に計算しておくと、ループ内での計算量を減らせる
  Matrix44f transform_matrix = translate * rotate * scale;

  float viewing_angle = 0.003f;

  // 表示オフセット
  Vec2f offset = getWindowSize() / 2;

  for (auto& face : faces) {
    // 頂点の座標を行列を使って変換
    auto v1 = transform_matrix * face.v1;
    auto v2 = transform_matrix * face.v2;
    auto v3 = transform_matrix * face.v3;

    // Zで割る
    auto t1 = Vec2f(v1.x, v1.y) / (v1.z * viewing_angle) + offset;
    auto t2 = Vec2f(v2.x, v2.y) / (v2.z * viewing_angle) + offset;
    auto t3 = Vec2f(v3.x, v3.y) / (v3.z * viewing_angle) + offset;

    ly::drawLine(t1, t2, ColorA(1, 1, 1, 0.2f));
    ly::drawLine(t2, t3, ColorA(1, 1, 1, 0.2f));
    ly::drawLine(t3, t1, ColorA(1, 1, 1, 0.2f));

    // 表と裏の判定
    // TIPS:外積を使って判定できる
    Vec2f a = t2 - t1;
    Vec2f b = t3 - t1;
    if (b.cross(a) < 0.0f) continue;

    // 光線ベクトルとめん法線との内積を計算する
    Vec3f normal = transform_matrix.transformVec(face.normal);
    // これが面の明るさ
    normal.normalize();
    float bright = normal.dot(light);

    // 色指定
    gl::color(ColorA(face.color * bright, light_al));

    // 面(三角形)の描画
    gl::drawSolidTriangle(t1, t2, t3);
  }

  // ライブラリ更新
  // Font情報をstatic pointerで保存
  // 一応処理は軽くなったけど、処理としていいのかわからない
  ly::drawEllipse(light_pos + getWindowCenter(), Vec2f(10, 10), 40, Color(1, 1, 0));
  ly::drawString("Press WASD to move Light_Pos", Vec2f(0, 10), Color(1, 1, 1), 50.f);
  ly::drawString("Press F,G to change Alfha",    Vec2f(0, 50), Color(1, 1, 1), 50.f);
  ly::drawString("Push R to Reset",              Vec2f(0, 90), Color(1, 1, 1), 50.f);
}

CINDER_APP_NATIVE(_5_18App, RendererGl)
