#include <iostream>
using namespace std;

class Circle {
  int radius;

public:
  Circle() { radius = 1; }
  Circle(int r) { radius = r; }
  double getArea();
};

double Circle::getArea() { return 3.14 * radius * radius; }

int main() {
  Circle donut;
  Circle pizza(30);

  Circle *p;
  p = &donut;

  cout << donut.getArea() << endl; // 객체의 이름으로 멤버 접근
  cout << (*p).getArea() << endl;  //객체의 포인터로 멤버 접근
  cout << p->getArea() << endl;    //객체의 포인터로 멤버 접근

  p = &pizza;

  cout << (*p).getArea() << endl;
  cout << p->getArea() << endl;

  // p = &poly;
  // p->draw() or (*p).draw()
}