#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "4+4*6-3";
  int sum = 0;
  string trim;
  while(true) {

    int mulIndex = 0;
    mulIndex = s.find("*"); // 곱셈 기호의 인덱스 찾기
    if (mulIndex == -1) break;
    // 곱셈 기호 기준 직전 수 구하기
    string front = s.substr(0, mulIndex);
    int frontIndex = -1;
    for (int i = front.length(); i > 0; --i) {
      if (front[i] == '+' || front[i] == '-') {
        frontIndex = i; 
        break;
      }
    }
    front = front.substr(frontIndex); // 부호포함

    // 곱셈 기호 기준 바로 다음 수 구하기
    string back = s.substr(mulIndex + 1);
    int backIndex = -1;
    for (int i = 0; i < back.length(); i++) { 
      if (back[i] == '+' || back[i] == '-') {
        backIndex = i;
        break;
      }
    }
    back = back.substr(0, backIndex); 

    // 곱셈을 미리 연산 후 sum에 미리 저장
    trim = s.substr(frontIndex , front.length() + back.length() + 1);
    cout << trim << endl;
    sum += stoi(trim);
    cout << sum << endl;

    // 연산 한 부분은 잘라내기
    s = s.replace(frontIndex , front.length() + back.length() + 1, "");
    cout << s << endl;
  }

}