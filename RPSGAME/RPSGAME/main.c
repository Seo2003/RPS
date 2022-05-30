#include<stdio.h>
#include<string.h>
#include<conio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning(disable:4996)
#pragma warning(disable:6031)

void computerchoose(struct data* choose, int* computer);

struct data
{
	int rockcnt;
	int papercnt;
	int scissorcnt;
};

int main(){
	struct data rock = { .rockcnt = 0, .papercnt = 0, .scissorcnt = 0 };
	struct data paper = { .rockcnt = 0, .papercnt = 0, .scissorcnt = 0 };
	struct data scissor = { .rockcnt = 0, .papercnt = 0, .scissorcnt = 0 };
	int computer=1,player;

	while (1)
	{
		printf("1(rock) 2(paper) 3(scissor) : ");
		scanf("%d", &player);
		if (computer == 1)
			computerchoose(&rock, &computer);
		else if (computer == 2)
			computerchoose(&paper, &computer);
		else
			computerchoose(&scissor, &computer);

		printf("구조체rock의 변수들: %d, %d, %d", rock.papercnt, rock.rockcnt, rock.scissorcnt);
		pritnf("구조체paper의 변수들: %d, %d, %d", paper.papercnt, paper.rockcnt, paper.scissorcnt);
		pritnf("구조체scissor의 변수들: %d, %d, %d", scissor.papercnt, scissor.rockcnt, scissor.scissorcnt);
	}
	return 0;
}

void computerchoose(struct data *choose,int *computer)
{
	if (choose->papercnt > choose->rockcnt){
		if (choose->papercnt > choose->scissorcnt){
			*computer = 1;
			choose->papercnt++;
		}	
	}
	else {
		if (choose->rockcnt > choose->scissorcnt) {
			*computer = 2;
			choose->rockcnt++;
		}
		else {
			*computer = 3;
			choose->scissorcnt++;
		}	
	}
}

