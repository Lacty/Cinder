
#pragma once
#include "cinder/app/KeyEvent.h"
#include <set>


class Key : private boost::noncopyable {
private:

  std::set<int> key_push;
  std::set<int> key_press;
  std::set<int> key_pull;

  Key();

public:

  static Key& get();

  void isPush();
};