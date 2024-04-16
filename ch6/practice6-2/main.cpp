#include <iostream>
using namespace std;

/*
2. 디폴트 매개변수
int big(int a, int b, int max = 100) {
  if (a > max || b > max)
    return max;
  else if (a > b)
    return a;
  else
    return b;
}*/

// 1. 함수중복
int big(int x, int y) {
  int max = (x > y) ? x : y;
  return (max > 100) ? 100 : max;
}

int big(int x, int y, int z) {
  int max = (x > y) ? x : y;
  return (max > z) > z ? z : max;
}

int main() {
  int x = big(3, 5);
  int y = big(300, 60);
  int z = big(30, 60, 50);
  cout << x << ' ' << y << ' ' << z << endl;
}