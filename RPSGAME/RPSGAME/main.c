#include<stdio.h>

#pragma warning(disable:4996)
#pragma warning(disable:6031)

void computerchoose(struct data* choose, int* computer);
void winlose();

int playerwin = 0, computerwin = 0;		//컴퓨터와 플레이어의 이긴횟수를 카운트

struct data {		//플레이어의 다음나올수를 카운트 하는 구조체
	int rockcnt;
	int papercnt;
	int scissorcnt;
};

int main(){
	struct data rock, paper,scissor;	//플레이어의 다음수를 카운트하기위한 구조체 생성
	int computer = 1, player;		//컴퓨터의 선택과 플레이어의 선택을 저장하는 변수

	while (1){
		printf("1(rock) 2(paper) 3(scissor) : ");	//GUI
		scanf("%d", &player);						//플레이어 턴

		if (computer == 1) {					
			computerchoose(&rock, &computer);
			winlose();
		}
		else if (computer == 2) {
			computerchoose(&paper, &computer);
			winlose();
		}
		else {
			computerchoose(&scissor, &computer);
			winlose();
		}
	}
	return 0;
}

void winlose() {

}

void computerchoose(struct data *choose,int *computer){		//상대가 낸 수를 맞추어 바꾸는 함수
	if (choose->papercnt > choose->rockcnt)
		if (choose->papercnt > choose->scissorcnt)
			*computer = 1;
	else{
		if (choose->rockcnt > choose->scissorcnt)
			*computer = 2;
		else 
			*computer = 3;
	}
}