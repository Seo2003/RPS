#include<stdio.h>

#pragma warning(disable:4996)
#pragma warning(disable:6031)

void computerchoose(struct data* choose, int* computer);
void winlose(int player, int computer);
void cntplus(struct data* list, int player);

int playerwin = 0, computerwin = 0,draw=0;			//컴퓨터와 플레이어의 이긴횟수를 카운트

struct data {										//플레이어의 다음나올수를 카운트 하는 구조체
	int rockcnt;
	int papercnt;
	int scissorcnt;
};

int main(){
	struct data rock = { 0,0,0 }, paper = { 0,0,0 }, scissor = { 0,0,0 };			//플레이어의 다음수를 카운트하기위한 구조체 생성
	int computer = NULL, player=NULL, oldplayer=NULL;	//컴퓨터의 선택과 플레이어의 선택을 저장하는 변수

	while (1){
		printf("1(rock) 2(paper) 3(scissor) : ");	//GUI
		oldplayer = player;							//플레이어의 수를 입력하기전 기록을 위한 변수
		scanf("%d", &player);						//플레이어 턴

		if (oldplayer == 1) {						
			computerchoose(&rock, &computer);
			winlose(player,computer);
			cntplus(&rock,player);
		}
		else if (oldplayer == 2) {
			computerchoose(&paper, &computer);
			winlose(player,computer);
			cntplus(&paper,player);
		}
		else if(oldplayer ==3) {
			computerchoose(&scissor, &computer);
			winlose(player,computer);
			cntplus(&scissor,player);
		}
	}
	return 0;
}

void winlose(int player,int computer) {
	int judgement = player - computer;				//judgement = 판단 변수	
	printf("판단: %d - %d = %d\n",player,computer, judgement);
	if (judgement == 0)								// (플레이어 - 컴퓨터)가 -2,1이 나올때 플레이어 승리 0일시 비김,나머지 패배
		draw++;
	else if (judgement == -1 || judgement == 2)		//컴퓨터승리
		computerwin++;
	else											//플레이어 승리
		playerwin++;
	printf("현재 컴퓨터승리: %d  플레이어승리: %d  비김: %d \n", computerwin, playerwin, draw);
}

void cntplus(struct data *list,int player) {
	if (player == 1)
		list->rockcnt++;
	else if (player == 2)
		list->papercnt++;
	else
		list->scissorcnt++;
}

void computerchoose(struct data *choose,int *computer){		//상대가 낸 수를 맞추어 바꾸는 함수
	if (choose->papercnt > choose->rockcnt && choose->papercnt > choose->scissorcnt)
		*computer = 3;
	else if (choose->rockcnt > choose->scissorcnt && choose->rockcnt > choose->papercnt)
		*computer = 2;
	else
		*computer = 1;
}