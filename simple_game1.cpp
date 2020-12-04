#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

bool gameStart(int difficulty); 
// 난이도만 넣어주면 되는 게임. 게임의 단계 성공여부를 불린으로 리턴해줌. 
void printGame(int difficulty); 
// 게임에 필요한 정보를 출력해주는 함수. 
bool gameStart(int difficulty)
{
  printGame(difficulty);
  srand(time(NULL));
  int user1, user2, user3;
  int ans1 = rand() % 10;
  int ans2 = rand() % 10;
  int ans3 = rand() % 10;
  int ans_sum = ans1 + ans2 + ans3;
  int ans_mul = ans1 * ans2 * ans3;
  while(true)
  {
    printf("각 자리수의 합은 %d, 각 자리수의 곱은 %d입니다!!\n", ans_sum, ans_mul);
    printf("1번째 자리 숫자를 입력하세요:\n");
    scanf("%d", &user1);
    printf("2번째 자리 숫자를 입력하세요:\n");
    scanf("%d", &user2);
    printf("3번째 자리 숫자를 입력하세요:\n");
    scanf("%d", &user3);
    int user_sum = user1 + user2 + user3;
    int user_mul = user1 * user2 * user3;
    if(user_sum == ans_sum && user_mul == ans_mul)
    {
      printf("아싸!!! 비밀번호를 맞췄습니다!\n");
      printf("다음 단계로 넘어갑니다.\n\n");
      return true;
    } else // 답이 틀렸다든지, 입력 오류가 발생했다든지
    {
      cin.clear(); // 일단 오류플래그를 초기화시키고, 
      cin.ignore(); //입력 버퍼를 비워줍니다. 
      printf("아이 아저씨 그게 아니잖아요, 다시 잘 좀 해봐요ㅡㅡ;\n\n");
    }
  }

};

void printGame(int difficulty)
{
  printf("시크릿 에이전트 미스터 777씨, 당신은 지금 북한 핵발전소에 비밀침투했습니다.\n");
  printf("당신의 목표는 여러 관문을 통과하여 북한의 핵폭탄 정보를 빼내고\n");
  printf("무사히 귀환하는 겁니다.\n");
  printf("현재 당신은 %d번째 관문 앞에 서있습니다.\n" , difficulty);
  printf("각 관문을 통과하려면 비밀번호를 맞춰서 문을 열어야 합니다.\n");
  printf("국정원 최고 해커의 말에 따르면 비밀번호는 0 ~ 9 까지의 수 \n");
  printf("3자리로 이루어져 있으며, 해킹을 통해 각자리수를 합한 값과\n");
  printf("각 자리수를 곱한 값을 알아냈다고 합니다.\n");
  printf("당신의 천재적인 두뇌로 비밀번호를 맞춰서 관문을 통과하세요!!\n");
}

int main()
{
  int difficulty = 1;
  int maxDifficulty = 5; // 난 5단계까지만 만들꺼야. 
  while(difficulty <= maxDifficulty)
  {
    if(gameStart(difficulty)) // 단계를 성공적으로 마쳤다면
    {
      difficulty++;
    } 
  }
  printf("축하합니다. 비밀요원 777씨, 북한의 핵폭탄 정보를 무사히 탈취하고 안전하게 탈출했습니다.\n");
  printf("당신이 이 나라를 구했어요!!!!!!\n");
  return 0;
}
