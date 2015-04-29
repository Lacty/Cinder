
#include "key.h"


Key::Key() {}

Key& Key::get() {
  static Key key;
  return key;
}

void Key::isPush() {
  
}