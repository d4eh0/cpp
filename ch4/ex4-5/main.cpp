#include <iostream>
using namespace std;

int main() {
  int *p;
  p = new int; // int *p = new int; 와 동일

  if (!p) {
    cout << "메모리를 할당할 수 없습니다." << endl;
    return 0;
  }

  *p = 5;
  int n = *p;
  cout << "*p = " << *p << endl;
  cout << "n = " << n << endl;

  delete p;
}