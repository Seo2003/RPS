#include<stdio.h>

#pragma warning(disable:4996)
#pragma warning(disable:6031)

void computerchoose(struct data* choose, int* computer);
void winlose(int player, int computer);

int playerwin = 0, computerwin = 0,draw=0;			//��ǻ�Ϳ� �÷��̾��� �̱�Ƚ���� ī��Ʈ

struct data {										//�÷��̾��� �������ü��� ī��Ʈ �ϴ� ����ü
	int rockcnt;
	int papercnt;
	int scissorcnt;
};

int main(){
	struct data rock, paper,scissor;				//�÷��̾��� �������� ī��Ʈ�ϱ����� ����ü ����
	int computer = 1, player=0, oldplayer;			//��ǻ���� ���ð� �÷��̾��� ������ �����ϴ� ����

	while (1){
		printf("1(rock) 2(paper) 3(scissor) : ");	//GUI
		oldplayer = player;							//�÷��̾��� ���� �Է��ϱ��� ����� ���� ����
		scanf("%d", &player);						//�÷��̾� ��

		if (oldplayer == 1) {						
			computerchoose(&rock, &computer);
			winlose(player,computer);
		}
		else if (oldplayer == 2) {
			computerchoose(&paper, &computer);
			winlose(player,computer);
		}
		else if(oldplayer ==3) {
			computerchoose(&scissor, &computer);
			winlose(player,computer);
		}
	}
	return 0;
}

void winlose(int player,int computer) {
	int judgement = player - computer;				//judgement = �Ǵ� ����	
	if (judgement == 0)								// �÷��̾� - ��ǻ�Ͱ� -2,1�� ���ö� �÷��̾� �¸� 0�Ͻ� ���,������ �й�
		draw++;
	else if (judgement == -1 || judgement == 2)
		computerwin++;
	else
		playerwin++;
	printf("���� ��ǻ�ͽ¸�: %d  �÷��̾�¸�: %d  ���: %d \n", computerwin, playerwin, draw);
}

void computerchoose(struct data *choose,int *computer){		//��밡 �� ���� ���߾� �ٲٴ� �Լ�
	if (choose->papercnt > choose->rockcnt)
		if (choose->papercnt > choose->scissorcnt)
			*computer = 3;
	else{
		if (choose->rockcnt > choose->scissorcnt)
			*computer = 1;
		else 
			*computer = 2;
	}
}