#include<stdio.h>

#pragma warning(disable:4996)
#pragma warning(disable:6031)

void computerchoose(struct data* choose, int* computer);
void winlose();

int playerwin = 0, computerwin = 0;		//��ǻ�Ϳ� �÷��̾��� �̱�Ƚ���� ī��Ʈ

struct data {		//�÷��̾��� �������ü��� ī��Ʈ �ϴ� ����ü
	int rockcnt;
	int papercnt;
	int scissorcnt;
};

int main(){
	struct data rock, paper,scissor;	//�÷��̾��� �������� ī��Ʈ�ϱ����� ����ü ����
	int computer = 1, player;		//��ǻ���� ���ð� �÷��̾��� ������ �����ϴ� ����

	while (1){
		printf("1(rock) 2(paper) 3(scissor) : ");	//GUI
		scanf("%d", &player);						//�÷��̾� ��

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

void computerchoose(struct data *choose,int *computer){		//��밡 �� ���� ���߾� �ٲٴ� �Լ�
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