#ifndef STACK_H
#define STACK_H

class Stack {
  int size;
  int *p;
  int tos; // top of stack

public:
  Stack(int size = 10);
  ~Stack();
  Stack &operator<<(int n);
  Stack &operator>>(int &n);
  bool operator!();
};

#endif