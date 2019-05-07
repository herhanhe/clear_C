/*一个字符创的键盘打字练习（其中）*/

#include <time.h>
#include <stdio.h>
#include <string.h>
#include "getputch.h"

#define QNO   12  /*题目数量*/

int main (void){
	char *str[QNO] = {"book","computer","default","confort",
					  "monday","power","light","music",
					  "progamming","dog","video","include"
					};		/*要输入的字符串*/
	int i,stage;
	clock_t start,end;					/*开始时间和结束时间*/

	init_getputch();

	printf("开始打字练习。\n");
	printf("按下空格键开始。\n");
	while (getch() != ' ')             /*一直等待到*/
		;

	start = clock();					/*开始时间*/

	for (stage = 0;stage < QNO;stage++){
		int len = strlen(str[stage]);		/*字符串str[stage]的字符数量*/

		for (i = 0;i < len;i++){
			/*显示str[stage][i]以后的字符并把光标返回到开头*/
			printf("%s \r",&str[stage][i]);

			fflush(stdout);
			while (getch() != str[stage][i])	
				;
		}
		
	}

	end = clock();						/*结束时间*/ 

	printf("\n用时%.1f秒。\n",(double)(end - start) / CLOCKS_PER_SEC * 1000);

//	term_getputch();
	
	return 0;
}
