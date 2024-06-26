#include "Random.h"
#include <iostream>
using namespace std;

int main() {
  Random::seed();

  cout << "1에서 100까지의 랜덤한 정수 10개를 출력합니다. " << endl;
  for (int i = 0; i < 10; i++) {
    cout << Random::nextInt(1, 100) << ' ';
  }
  cout << endl;

  cout << "알파벳을 랜덤하게 10개 출력합니다." << endl;
  for (int i = 0; i < 10; i++) {
    cout << Random::nextAlphabet() << ' ';
  }
  cout << endl;

  cout << "랜덤한 실수 10개를 출력합니다. " << endl;
  for (int i = 0; i < 10; i++) {
    cout << Random::nextDouble() << ' ';
  }
  cout << endl;
}
