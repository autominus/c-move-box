#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
 
int  map[2][7][8] =
{
 
	{
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 3, 1, 0, 1, 1, 3, 1,
	1, 4, 0, 0, 4, 0, 3, 1,
	1, 0, 1, 0, 1, 1, 4, 1,
	1, 0, 0, 5, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1
	},
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 3, 1, 0, 1, 1, 3, 1,
		1, 3, 4, 5, 4, 0, 3, 1,
		1, 4, 1, 0, 1, 1, 4, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1
	}
};
int cas = 0;
int boxSum[2] = {3,4};
void drawMap()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j == 0)
				printf("\t\t");
			switch (map[cas][i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("■");
				break;
			case 3:
				printf("☆");
				break;
			case 4:
				printf("★");
				break;
				//5：※		  //人
			case 5:
			case 8:
				printf("※");
				break;
			case 7:
				printf("⊙");
				break;
			}
		}
		printf("\n");
	}
}
//按键处理
void keyDown()
{
	int i, j;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (map[cas][i][j] == 5 || map[cas][i][j] == 8)
			{
				break;
			}
		}
		if (map[cas][i][j] == 5 || map[cas][i][j] == 8)
		{
			break;
		}
	}
 
	char ch = _getch()；
	switch (ch)
	{
		//72 80   75 77
	case 'w':
	case 'W':
	case 72:
		if (map[cas][i - 1][j] == 0 || map[cas][i - 1][j] == 3)
		{
			map[cas][i - 1][j] += 5;
			map[cas][i][j] -= 5;
		}

		else if (map[cas][i - 1][j] == 4 || map[cas][i - 1][j] == 7)
		{
			if (map[cas][i - 2][j] == 0 || map[cas][i - 2][j] == 3)
			{
				map[cas][i - 2][j] += 4;
				map[cas][i - 1][j] += 1;
				map[cas][i][j] -= 5;
			}
 
		}
 
		break;
	case 's':
	case 'S':
	case 80:
		if (map[cas][i + 1][j] == 0 || map[cas][i + 1][j] == 3)
		{
			map[cas][i + 1][j] += 5;
			map[cas][i][j] -= 5;
		}
		else if (map[cas][i + 1][j] == 4 || map[cas][i + 1][j] == 7)
		{
			if (map[cas][i + 2][j] == 0 || map[cas][i + 2][j] == 3)
			{
				map[cas][i + 2][j] += 4;
				map[cas][i + 1][j] += 1;
				map[cas][i][j] -= 5;
			}
 
		}
		break;
 
	case 'a':
	case 'A':
	case 75:
		if (map[cas][i][j - 1] == 0 || map[cas][i][j - 1] == 3)
		{
			map[cas][i][j - 1] = map[cas][i][j - 1] + 5;
			map[cas][i][j] = map[cas][i][j] - 5;
 
		}
		else if (map[cas][i][j - 1] == 4 || map[cas][i][j - 1] == 7)
		{
			if (map[cas][i][j - 2] == 0 || map[cas][i][j - 2] == 3)
			{
				map[cas][i][j - 2] += 4;
				map[cas][i][j - 1] += 1;
				map[cas][i][j] -= 5;
			}
 
		}
 
		break;
	case 'D':
	case 'd':
	case 77:
		if (map[cas][i][j + 1] == 0 || map[cas][i][j + 1] == 3)
		{
			map[cas][i][j + 1] += 5;
			map[cas][i][j] -= 5;
		}
		
		else if (map[cas][i][j + 1] == 4 || map[cas][i][j + 1] == 7)
		{
			if (map[cas][i][j + 2] == 0 || map[cas][i][j + 2] == 3)
			{
				map[cas][i][j + 2] += 4;
				map[cas][i][j + 1] += 1;
				map[cas][i][j] -= 5;
			}
 
		}
		break;
	}
}

int gameOver()
{
	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[cas][i][j] == 7)
				count++;
		}
	}
	return count;
}
int gameOver2()
{
	int count = 3;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[cas][i][j] == 3)
				count--;
		}
	}
	return count;
}
 
int main()
{
	while (1)
	{
		printf("\n\t用方向键或w a s d键移动※推动★进入☆\n",cas+1);
		printf("\n\t\t 共两关 第 %d 关\n",cas+1);
		drawMap();
		if (gameOver() == boxSum[cas])
		{
			cas++;
			if (cas == 2)
				break;
			else
			    printf("\n\t\t 该关 OK！按任一键进继续\n");	
		}
		keyDown();
		system("cls");
	}
	printf("游戏结束！");
	printf("\n");
	system("pause");
	return 0;
}
