
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/audio/Context.h"
#include "cinder/audio/NodeEffects.h"
#include "cinder/audio/SamplePlayerNode.h"

using namespace ci;
using namespace ci::app;

class SoundApp : public AppNative {
private:
  audio::BufferPlayerNodeRef sound;
  audio::GainNodeRef         gain;

public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void SoundApp::setup() {
  // �f�o�C�XGet
  auto ctx = audio::Context::master();

  // �I�[�f�B�I�f�[�^��ǂݍ���ŏ�����
  audio::SourceFileRef sourceFile = audio::load(loadAsset("sample.wav"));
  audio::BufferRef buffer = sourceFile->loadBuffer();
  sound = ctx->makeNode(new audio::BufferPlayerNode(buffer));

  gain = ctx->makeNode(new audio::GainNode(1.0f));

  // �ǂݍ��񂾃I�[�f�B�I���o�̓f�o�C�X�Ɋ֘A�t���Ă���
  sound >> gain >> ctx->getOutput();

  // �o�̓f�o�C�X��L���ɂ���
  ctx->enable();
}

void SoundApp::mouseDown(MouseEvent event) {
  gain->setValue(0.1f);
  sound->start();
}

void SoundApp::update() {}

void SoundApp::draw() {
  gl::clear();
}

CINDER_APP_NATIVE(SoundApp, RendererGl)
