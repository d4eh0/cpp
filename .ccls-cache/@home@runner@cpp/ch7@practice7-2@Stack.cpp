#include "Stack.h"

Stack::Stack(int size) {
  // 디폴트 매개변수는 선언부에 있으면 구현부에는 없어야 함.
  this->size = size;
  p = new int[size];
  tos = 0;
}
Stack::~Stack() {
  if (p)
    delete[] p;
}
Stack &Stack::operator<<(int n) {
  // push
  if (tos == size) {
    // stack full
    return *this;
  }
  p[tos++] = n;
  return *this; // 연쇄적으로 이 연산자를 쓰기 위해 자기를 리턴
}
Stack &Stack::operator>>(int &n) {
  // pop, stack empty
  if (tos == 0)
    return *this;
  n = p[--tos];
  return *this;
}
bool Stack::operator!() {
  if (tos == 0)
    return true;
  else
    return false;
}