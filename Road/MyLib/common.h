
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

enum class WindowSize {
  Width  = 600,
  Height = 400
};

enum class LeanStatus {
  Center,
  Left,
  Right
};