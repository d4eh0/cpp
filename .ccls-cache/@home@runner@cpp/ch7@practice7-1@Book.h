#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
using namespace std;

class Book {
  string title;
  int price;
  int pages;

public:
  Book(string title = "", int price = 0, int pages = 0) {
    this->title = title;
    this->price = price;
    this->pages = pages;
  }
  void show() {
    cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
  }
  string getTitle() { return title; }

  // 멤버함수로 구현
  /*
  Book &operator+=(int n);
  Book &operator-=(int n);
  */

  friend Book &operator+=(Book &book, int n);
  friend Book &operator-=(Book &book, int n);

  bool operator!();
  friend bool operator<(string name, Book &book);
};

// 외부함수로 구현
Book &operator+=(Book &book, int n);
Book &operator-=(Book &book, int n);

#endif