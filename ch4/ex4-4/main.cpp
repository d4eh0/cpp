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
  Circle circles[2][3] = {{Circle(1), Circle(2), Circle(3)},
                          {Circle(4), Circle(5), Circle(6)}};

  /* for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "Circle " << i+j << "의 면적은 : " << circles[i][j].getArea() <<
  endl;
    }
  } */
  Circle(*p)[3] = circles;

  for (int i = 0; i < 2; i++) {
    Circle *q = *(p + i);
    for (int j = 0; j < 3; j++) {
      cout << "Circle " << i + j << "의 면적은 : " << (q + j)->getArea()
           << endl;
    }
  }

  // 다음은 동치이다.
  // 1. circleArray[i].getArea();
  // 2. (p+i)->getArea();
  // 3. (*p++).getArea();
  // 4. (circleArray+i)->getArea();
  // 5. p->getArea(); p++;

  // 이때 3.에서는 배열의 이름으로 포인터를 사용하기 때문에 Circle *p =
  // circleArray 선언x
}