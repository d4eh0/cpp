#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cout << "입력식 : ";
  getline(cin, s);
  if (!isdigit(s.back())) { // 문자열 's'의 마지막 문자가 숫자인지 확인
    cout << "결과 : 입력식이 잘못되었습니다." << endl;
    return 0;
  }
  char input[s.length()]; // 입력받은 문자열 's'를 char 배열 'input'에 쪼개어
                          // 복사
  s.copy(input, s.length());

  // 숫자와 연산자를 분리하여 배열에 순서대로 저장 (ex : 4,0,0 -> 400)
  string output[100];
  int startIndex = 0;
  string tempNum = "";
  for (int i = 0; i < s.length();
       i++) { // 배열 앞에서부터 확인하여 숫자들을 확인
    if (isdigit(input[i])) {
      tempNum += input[i]; // 숫자는 tempNum에 누적하여 저장
    } else { // 연산자를 만나면 tempNum을 새로운 string 배열 'output'에 저장 후
             // 초기화
      if (!tempNum.empty()) {
        output[startIndex++] = tempNum;
        tempNum.clear();
      }
      output[startIndex++] = string(1, input[i]);
    }
  }
  if (!tempNum.empty()) {
    output[startIndex++] = tempNum;
  }
  // 곱셈과 나눗셈을 먼저 처리
  // 곱셈과 나눗셈 연산자를 찾고, 연산자를 기준으로 앞, 뒤의 값으로 연산 실행 및
  // 배열 업데이트
  int outputIndex = 0;
  for (int i = 0; i < startIndex; ++i) {
    if (output[i] == "*") {
      int left = stoi(output[outputIndex - 1]);
      int right = stoi(output[i + 1]);
      output[outputIndex - 1] = to_string(left * right);
      i++;
    } else if (output[i] == "/") {
      int left = stoi(output[outputIndex - 1]);
      int right = stoi(output[i + 1]);
      if (right == 0) {
        cerr << "Division by zero error!" << endl;
        return 1;
      }
      output[outputIndex - 1] = to_string(left / right);
      i++;
    } else {
      output[outputIndex++] = output[i];
    }
  }
  // 마찬가지로 덧셈과 뺄셈 연산
  int result = stoi(output[0]);
  for (int i = 1; i < outputIndex; ++i) {
    if (output[i] == "+") {
      result += stoi(output[i + 1]);
      i++;
    } else if (output[i] == "-") {
      result -= stoi(output[i + 1]);
      i++;
    }
  }
  // 최종 결과 출력
  cout << "결과 : " << result << endl;
}