#include "ArrayUtility2.h"

int *ArrayUtility2::concat(int s1[], int s2[], int size) {
  int *p = new int[size * 2];
  if (!p)
    return nullptr; // 동적할당이 되었는지 확인!!

  for (int i = 0; i < size; i++)
    p[i] = s1[i];
  for (int i = 0; i < size; i++)
    p[i + size] = s2[i];
  return p;
}
int *ArrayUtility2::remove(int s1[], int s2[], int size, int &retSize) {
  int *p = new int[size];
  if (!p) {
    retSize = 0;
    return nullptr;
  }
  int k = 0;

  for (int i = 0; i < size; i++) {
    int j = 0;
    for (int j = 0; j < size; j++) { // for 바깥에서도 j활용하기 위해 밖에서선언
      if (s1[i] == s2[j])
        break;
    }
    if (j == size) {
      p[k] = s1[i];
      k++;
    }
  }
  retSize = k;
  if (k == 0)
    return nullptr;
  int *q = new int[retSize];
  if (!q) {
    retSize = 0;
    return nullptr;
  }
  for (int i = 0; i < retSize; i++)
    q[i] = p[i];
  delete[] p;
  return q;
}