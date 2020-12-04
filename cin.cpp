#include <iostream>
#include <cstdio>
using namespace std;

// 이번에는 cin으로 입력을 받을때 사용할수 있는
// cin.fail(), cin.clear(), cin.ignore() 함수에 대해 알아보자. 

int main()
{
  int val;
  cout << "정수를 입력해주세요:\n";
  cin >> val;
  /* 근데 사용자가 정수를 입력했는지 문자를 입력했는지 
  확인을 해줘야 안전한 코드가 될거아니야. 이처럼 cin에서 입출력 오류가
  발생했는지 안했는지 알려주는 함수가 cin.fail()이야. 
  val을 int로 지정해놨으니 정수형이 들어와야 하는데, char라든지 이상한게 들어오면 오류를 띄워야해. 그러면 자동으로 cin내부에 있는 오류 플래그를 1로 바꾼단 말이야. fail() 함수는 오류 플래그가 1이면 true를 0이면 false를 반환한다.
  */
  while(cin.fail()) // 입력오류인경우
  {
    cin.clear(); // 오류플래그 초기화
    // cin.ignore(256, '\n'); // 일단 지금 버퍼에 있는거 다 비우기.
    cin.ignore();
    cout << "아니 정수입력하라니깐 딴거 입력하면 우짜노.\n";
    cout << "다시 입력하세요!!\n";
    cin >> val;
  } 
  cout << "제대로 입력하셨네용 빠빠이\n";
  return 0;
}

/*
cin.clear()는 cin 내부에 있는 오류 플래그를 초기화 시켜주는 역할을 한다.
위의 코드에서 cin.clear()를 쓰지 않을 경우, cin.fail()은 계속 true를 리턴하여 무한루프를 돌게된다. cin.fail()로 while문을 쓸 경우, cin.clear()와 cin.ignore은 꼭 같이 따라와야 한다. cin.ignore()은 cin 버퍼에 있는 내용을 비우는 건데, cin.ignore(무시문자 최대길이, 종료문자)의 형식을 가진다.  안쓰면 입력버퍼의 모든것을 비워준다.
*/
