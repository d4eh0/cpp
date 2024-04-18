#include "Book.h"
/*
Book &Book::operator+=(int n){
  price += n;
  return *this;
}
Book &Book::operator-=(int n){
  price -= n;
  return *this;
}
*/

Book &operator+=(Book &book, int n) {
  book.price += n;
  return book;
}

Book &operator-=(Book &book, int n) {
  book.price -= n;
  return book;
}

bool Book::operator!() {
  if (price == 0)
    return true;
  else
    return false;
}

bool operator<(string name, Book &book) {

  if (name < book.title)
    return true;
  else
    return false;
}