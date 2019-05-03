/*三字母词联想训练（完成3个连续的数字.英文字母）*/

#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getputch.h"

#define MAX_STAGE 10			/*挑战次数*/
#define swap(type,x,y)		do {type t = x; x = y; y = t;} while(0);

int main (void){
	char *qstr[] = {"0123456789",						/*数字*/
					"ABCDEFGHIJKLMNOPQRSTUVWXYZ",		/*大写英文字母*/
					"abcdefghijklmnopqrstuvwxyz",		/*小写英文字母*/
					};
	int chmax[] = {10,26,26};							/*设定随机数的种子*/
	int i,stage;
	int key;					/*已读取的键盘值*/
	double jikan;				/*时间*/
	clock_t start,end;			/*开始时间和结束时间*/	
	
	init_getputch();

	srand(time(NULL));			/*设定随机数的种子*/	
	printf("请输入连续的3个数字或英文字母中。\n");
	printf("被隐去的字符。\n");
	printf("例如显示A？C:就请输入B\n");
	printf("    显示45？：就请输入6\n");
	printf("。\n");
	printf("按下空格键开始。\n");
	fflush(stdout);
	while (getch() != ' ')
		;

	start = clock();
	for (stage = 0;stage < MAX_STAGE;stage++){
		int qtype = rand() % 3;		/*0:数字/1:大写英文字母/2:小写英文字母*/
		int nhead = rand() % (chmax[qtype] - 2);					/*开头字符的下标*/
		int x = rand() % 3;			/*要把3个字符中的哪一个设为‘？’呢*/

		putchar('\r');

		for (i = 0;i < 3;i++){	/*显示题目*/
			if (i != x)
				printf(" %c",qstr[qtype][nhead + i]);
			else 
				printf("?");
		}
		printf(" : ");
		fflush(stdout);
		
		do{
			key = getch();
			if (isprint(key)){		/*如果能显示的话*/
				putch(key);			/*显示按下的键*/
				if (key != qstr[qtype][nhead + x])		/*如果回答错误*/
					putch('\b');		/*把光标往前退一格*/
				else 
					printf("\n");		/*换行*/
				fflush(stdout);
			}
		}while (key != qstr[qtype][nhead + x] );	/*循环到玩家输入正确答案为止*/
	}
	end = clock();
	jikan = (double)(end - start) / CLOCKS_PER_SEC * 1000;
	printf("用时%.1f秒。\n",jikan);
	
	if(jikan > 25.0)
		printf("反应太慢了。\n");
	else if (jikan > 20.0)
		printf("反应有点慢呀。\n");
	else if (jikan > 17.0)
		printf("反应还行吧。\n");
	else 
		printf("反应真快啊。\n");
	//term_getputch();
	return 0;
}
