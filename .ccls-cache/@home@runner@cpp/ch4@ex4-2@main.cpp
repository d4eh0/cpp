#include <iostream>
using namespace std;

class Circle {
  int radius;

public:
  Circle() { radius = 1; }
  Circle(int r) { radius = r; }
  double getArea();
  void setRadius(int r) { radius = r; }
};

double Circle::getArea() { return 3.14 * radius * radius; }

int main() {
  Circle circleArray[3];
  circleArray[0].setRadius(10);
  circleArray[1].setRadius(20);
  circleArray[2].setRadius(30);

  // 위와 동치: Circle circleArray[3] = { Circle(10), Circle(20), Circle(30) };

  // 2차원 객체배열 초기화 :
  /*
  1.circles[0][0].setRadius(1);
    circles[0][1].setRadius(2);
    circles[0][2].setRadius(3);
    circles[1][0].setRadius(4);
    circles[1][1].setRadius(5);
    circles[1][2].setRadius(6);

  2. Circle circles[2][3] = { { Circle(1), Circle(2), Circle(3) },
                              { Circle(4), Circle(5), Circle(6) } };
  */

  // 객체의 이름으로 멤버 접근
  for (int i = 0; i < 3; i++) {
    cout << "Circle " << i << "의 면적은 : " << circleArray[i].getArea()
         << endl;
  }

  // 객체의 포인터로 멤버 접근
  Circle *p = circleArray;
  for (int i = 0; i < 3; i++) {
    cout << "Circle " << i << "의 면적은 : " << (*p++).getArea() << endl;
  }

  // 다음은 동치이다.
  // 1. (p+i)->getArea();
  // 2. (*p++).getArea();
  // 3. (circleArray+i)->getArea();
  // 이때 3에서는 배열의 이름으로 포인터를 사용하기 때문에 Circle *p =
  // circleArray 선언x
}