
#pragma once


namespace ly {
  // ���̃N���X���p�������N���X�̓R�s�[�s�Ƃ���
  class noncopyable {
  private:
    noncopyable(const noncopyable&) = delete;
    noncopyable& operator =(const noncopyable&) = delete;

  public:
    noncopyable()  = default;
    ~noncopyable() = default;
  };
}