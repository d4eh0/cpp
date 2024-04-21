#include "Person.h"
#include <cstring>
#include <iostream>
using namespace std;

Person::Person(int id, const char *name) {
  this->id = id;
  int len = strlen(name);         // name의 문자 개수
  this->name = new char[len + 1]; // name 문자열 공간 할당
  strcpy(this->name, name);       // name에 문자열 복사
}
Person::Person(Person &person) {
  this->id = person.id;
  int len = strlen(person.name);
  this->name = new char[len + 1];
  strcpy(this->name, person.name);
  cout << "복사 생성자 실행. 원본 객체의 이름 : " << this->name << endl;
}
Person::~Person() {
  if (name)
    delete[] name;
  // 만약 name에 동적할당된 메모리가 있다면 동적할당메모리 소멸
}

void Person::changeName(const char *name) {
  if (strlen(name) > strlen(this->name))
    return;
  strcpy(this->name, name);
}
void Person::show() { cout << id << ", " << name << endl; }