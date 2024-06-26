#ifndef RANDOM_H
#define RANDOM_H

#include <ctime>
#include <iostream>

class Random {
public:
  static void seed() { srand((unsigned)time(0)); }
  static int nextInt(int min = 0, int max = 32767);
  static char nextAlphabet();
  static double nextDouble();
};

#endif