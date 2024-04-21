#include <iostream>
using namespace std;

class Circle {
private:
  int radius;

public:
  Circle() { radius = 1; }
  Circle(int radius) { this->radius = radius; }
  ~Circle() {}
  double getArea() { return 3.14 * radius * radius; };
  int getRadius() { return radius; }
  void setRadius(int radius) { this->radius = radius; }
};

void readRadius(Circle &waffle) {
  int r;
  cout << "정수 값으로 반지름을 입력하세요 : ";
  cin >> r;
  waffle.setRadius(r);
}

int main() {
  Circle waffle;
  readRadius(waffle);
  cout << "waffle의 면적 :" << waffle.getArea() << endl;
}