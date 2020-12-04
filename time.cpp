#include <iostream>
#include <ctime>

/*
ctime 라이브러리 공부하려고 만든 파일. 
컴퓨터는 우선 컴퓨터는 시간을 표현할 때 좀 더 편하게 표현하려고
time_t 라는 타입과 tm구조체를 정의해놨다. 
time_t는 특정시간 이후로 현재까지의 초(정수값)을 나타내고, 
tm구조체는 time_t를 좀 더 사용자가 사용하기 편하게 
년, 월, 일, 분, 시 , 초 등등을 필드로 저장해놓은 구조체이다. 
*/

// 첫번째 함수 time함수 
int main()
{
  time_t tmp;
  tmp = time(NULL);
  printf("%ld\n", tmp);

  char * str = ctime(&tmp);
  printf("%s\n", str);
  // 근데 이게 표준시가 한국기준이 아닌가보다. 9시간이 느리네.
  // 어디 유럽기준으로 정해놓았나봐.
  
  struct tm *t;
  t = localtime(&tmp);
  // 근데 tm 구조체의 모든 필드를 내가 %d 포멧 문자열로 가공해서 표현하기는
  // 존내 귀찮다는 말이지 
  // 그럴때 쓰는게 asctime 함수임. 
  char * str2 = asctime(t);
  printf("%s\n", str2);
  return 0;
}
