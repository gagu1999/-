#include <iostream>
#include <cstdlib>
#include <ctime>

// 오늘은 난수생성에 대해 알아볼거다. 

int main()
{
  int random;
  random = rand(); // 난수를 만들고 싶으면 rand()를 쓰면 된다. 
  for(int i = 0; i < 10; i++)
  {
    printf("%d\n", rand() % 100);
  }
  /*
근데 뭔가 이상하다 10번 실행해도 10번 다 똑같은 수가 나온다. 그것도 
순서도 변하지 않고 ㅋㅋ 이게 난수라고 할 수 있는건가?
rand()함수의 원리를 한번 생각해보자. x라는 수를 어떤 함수에 나온 값을
rand()함수의 값이라고 하면, 그다음 rand()는 첫번째 나온 값을 넣어서 나온 값이고 ... 이걸 무한 반복한다고 하자. 
이때 맨 처음 들어가는 값을 seed 라고 하는데, 이게 맨 처음 프로그램을 작성할 때 정해져버린다. 그래서 같은 프로그램의 경우 100번 실행해도 똑같은 
난수가 같은 순서로 나올 수 밖에 없다.
  */

  srand(2);
  printf("%d\n", rand()% 100);
  srand(4);
  printf("%d\n", rand()% 100);
  srand(7);
  printf("%d\n", rand()% 100);
  srand(8);
  printf("%d\n", rand()% 100);
  srand(10);
  printf("%d\n", rand()% 100);

  /*
  그래서 쓰는게 srand(x) 함수이다. x라는 seed를 넣어줌으로써 rand()의 
  seed를 사용자가 임의로 갱신하는 것이다. 근데 이코드 역시 실행해보면 
  10번해도 10번동안 똑같은 값이 나온다. 
  즉, 같은 x값에 대해서는 srand(x)를 아무리해도 rand()함수의 결과로 
  같은 값이 나온다. 진정으로 랜덤인 난수를 만들려면 프로그램을 실행할때마다 바뀌는 값을 seed로 넣어주어야 할 것 같다. 이러한 값으로 
  가장 좋은게 프로그램을 실행할때의 시간을 활용하는 것이다. 실행할때마다 시간이 무조건 다를 수 밖에 없기 때문이다.
  */
  time_t t;
  t = time(NULL);
  srand((t));
  for(int i = 0; i < 10; i++)
  {
    printf("%d\n", rand()%100);
  }
  return 0;
}
