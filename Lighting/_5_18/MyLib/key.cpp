
#include "key.h"


Key& Key::get() {
  static Key key;
  return key;
}


void Key::flashInput() {
  key_push.clear();
  key_pull.clear();
}


void Key::setKeyPush(int key_number) {
  if (key_press.find(key_number) == key_press.end()) {
    key_push.emplace(key_number);
  }
}

void Key::setKeyPress(int key_number) {
  key_press.emplace(key_number);
}

void Key::setKeyPull(int key_number) {
  key_pull.emplace(key_number);
}

void Key::popKeyPress(int key_number) {
  key_press.erase(key_press.find(key_number));
}


bool Key::isPush(int key_number) {
  if (key_push.find(key_number) == key_push.end()) return false;
  key_push.erase(key_push.find(key_number));
  return true;
}

bool Key::isPress(int key_number) {
  return key_press.find(key_number) != key_press.end();
}

bool Key::isPull(int key_number) {
  if (key_pull.find(key_number) == key_pull.end()) return false;
  key_pull.erase(key_pull.find(key_number));
  return true;
}