#include<stdio.h>

#pragma warning(disable:4996)
#pragma warning(disable:6031)

void computerchoose(struct data* choose, int* computer);
void winlose(int player, int computer);
void cntplus(struct data* list, int player);

int playerwin = 0, computerwin = 0,draw=0;			//��ǻ�Ϳ� �÷��̾��� �̱�Ƚ���� ī��Ʈ

struct data {										//�÷��̾��� �������ü��� ī��Ʈ �ϴ� ����ü
	int rockcnt;
	int papercnt;
	int scissorcnt;
};

int main(){
	struct data rock = { 0,0,0 }, paper = { 0,0,0 }, scissor = { 0,0,0 };			//�÷��̾��� �������� ī��Ʈ�ϱ����� ����ü ����
	int computer = NULL, player=NULL, oldplayer=NULL;	//��ǻ���� ���ð� �÷��̾��� ������ �����ϴ� ����

	while (1){
		printf("1(rock) 2(paper) 3(scissor) : ");	//GUI
		oldplayer = player;							//�÷��̾��� ���� �Է��ϱ��� ����� ���� ����
		scanf("%d", &player);						//�÷��̾� ��

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
	int judgement = player - computer;				//judgement = �Ǵ� ����	
	printf("�Ǵ�: %d - %d = %d\n",player,computer, judgement);
	if (judgement == 0)								// (�÷��̾� - ��ǻ��)�� -2,1�� ���ö� �÷��̾� �¸� 0�Ͻ� ���,������ �й�
		draw++;
	else if (judgement == -1 || judgement == 2)		//��ǻ�ͽ¸�
		computerwin++;
	else											//�÷��̾� �¸�
		playerwin++;
	printf("���� ��ǻ�ͽ¸�: %d  �÷��̾�¸�: %d  ���: %d \n", computerwin, playerwin, draw);
}

void cntplus(struct data *list,int player) {
	if (player == 1)
		list->rockcnt++;
	else if (player == 2)
		list->papercnt++;
	else
		list->scissorcnt++;
}

void computerchoose(struct data *choose,int *computer){		//��밡 �� ���� ���߾� �ٲٴ� �Լ�
	if (choose->papercnt > choose->rockcnt && choose->papercnt > choose->scissorcnt)
		*computer = 3;
	else if (choose->rockcnt > choose->scissorcnt && choose->rockcnt > choose->papercnt)
		*computer = 2;
	else
		*computer = 1;
}