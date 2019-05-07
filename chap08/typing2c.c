/*多个字符串的键盘打字练习（其二：打乱出题顺序“方法二”）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define QNO   12  /*题目数量*/

#define swap(type,x,y)    do {type t = x;x = y;y = t;} while (0)

int main (void){
	char *str[QNO] = {"book","computer","default","confort",
					  "monday","power","light","music",
					  "progamming","dog","video","include"
					};		/*要输入的字符串*/
	int i,stage;
	clock_t start,end;					/*开始时间和结束时间*/

	init_getputch();
	srand(time(NULL));

	for (i = QNO - 1;i > 0;i--){		/*重新排列数组str*/
		int j = rand() % (i + 1);
		if (i != j)
			swap(char *,str[i],str[j]);
	}
	
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
