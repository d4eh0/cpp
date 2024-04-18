#include "Book.h"
#include <iostream>

int main() {
  Book a("청춘", 20000, 300), b("미래", 30000, 500);
  a += 500; // 책 a의 가격 500원 증가
  b -= 500; // 책 b의 가격 500원 감소
  a.show();
  b.show();
  Book book("벼룩시장", 0, 50); // 가격은 0
  if (!book)
    cout << "공짜다" << endl;

  Book a1("청춘", 20000, 300);
  string b1;
  cout << "책 이름을 입력하세요>>";
  getline(cin, b1);
  if (b1 < a1)
    cout << a1.getTitle() << "이 " << b1 << "보다 뒤에 있구나!" << endl;
  else
    cout << a1.getTitle() << "이 " << b1 << "보다 앞에 있구나!" << endl;
}