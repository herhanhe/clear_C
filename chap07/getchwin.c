/*getch的使用示例
 * 在提供了Visual C++的MS-Windows/MS-DOS环境下运行*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main (void){
	int ch;
	int retry;
	do {
		printf("请按键。");
		ch = getch();
		
		printf("\n按下的键是%c，值是%d。\n",isprintf(ch) ? ch : ' ',ch);

		printf("再来一次？（Y/N）:");
		retry = getch();
		if (isprintf(retry))
			putch(retry);
		putchar('\n');
	} while (retry == 'Y' || retry == 'y');
	return 0;
}
