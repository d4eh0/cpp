#include "Random.h"
// 구현할때는 static 뺴도 됨. 근데 그냥 두면 전체범위니까 Random::붙여주기

//구현부는 디폴트값x
int Random::nextInt(int min, int max) {
  int range = max - min;
  if (range < 0)
    return -1;
  return (rand() % (range + 1)) + min;
} // min 과 max사이의 랜덤 정수 리턴

char Random::nextAlphabet() {
  int n = rand() % 52; // 0~52까지 난수, 0~25는 대문자, 26~51은 소문자.
  if (n < 26)
    return 'A' + n;
  else
    return 'a' + (n - 26);
}
double Random::nextDouble() { return rand() / (double)RAND_MAX; };