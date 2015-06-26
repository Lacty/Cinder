
#pragma once
#include "cinder/app/KeyEvent.h"
#include <set>


class Key : private boost::noncopyable {
private:

  std::set<int> key_push;
  std::set<int> key_press;
  std::set<int> key_pull;

  Key() = default;

public:

  static Key& get();

  void flashInput();

  void setKeyPush(int key_number);
  void setKeyPress(int key_number);
  void setKeyPull(int key_number);

  void popKeyPress(int key_number);

  bool isPush(int key_number);
  bool isPress(int key_number);
  bool isPull(int key_number);
};