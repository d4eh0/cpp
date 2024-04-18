#include "ArrayUtility2.h"
#include <iostream>
using namespace std;

int main() {
  int x[5], y[5];
  cout << "정수 5개 x[]:";
  for (int i = 0; i < 5; i++)
    cin >> x[i];

  cout << "정수 5개 y[]:";
  for (int i = 0; i < 5; i++)
    cin >> y[i];

  int *p = ArrayUtility2::concat(x, y, 5);
  cout << " x+y :" << endl;
  for (int i = 0; i < 10; i++)
    cout << p[i] << ' ';
  cout << endl;

  int retSize;
  int *q = ArrayUtility2::remove(x, y, 5, retSize);
  cout << "x-y 결과, 개수는" << retSize << endl;
  for (int i = 0; i < retSize; i++)
    cout << q[i] << ' ';
  cout << endl;

  delete[] p;
  delete[] q;
}