#include<stdio.h>
#include<stdlib.h>
#include<time.h>

enum status { Continue, won, lost };
int rolldice(void);
int main()
{
	int sum;
	int mypoint;
	enum status gamestatus;

	srand(time(NULL));
	sum = rolldice();

	switch (sum)
	{
	case 7:
	case 11:
		gamestatus = won;
		break;
	case 2:
	case 3:
	case 12:
		gamestatus = lost;
		break;
	default:
		gamestatus = Continue;
		mypoint = sum;
		printf("Point is %d\n", mypoint);
		break;
	}

	while (gamestatus == Continue)
	{
		sum = rolldice();
		if (sum == mypoint)
		{
			gamestatus = won;
		}
		else
		{
			if (sum == 7)
			{
				gamestatus = lost;
			}
		}
	}
	if (gamestatus == won)
	{
		printf("Player wins\n");
	}
	else
	{
		printf("Player loses\n");
	}
	system("pause");
	return 0;
}

int rolldice(void)
{
	int die1;
	int die2;
	int worksum;

	die1 = 1 + (rand() % 6);
	die2 = 1 + (rand() % 6);
	worksum = die1 + die2;
	printf("Player rolled %d + %d = %d\n", die1, die2, worksum);
	return worksum;
}