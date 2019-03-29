/*转义字符\'和\"的使用示例*/
#include <stdio.h>

int main (void){
	printf("关于字符串常量和字符常量。\n");

	printf("双引号");
	putchar('\"');
	printf("用双引号括起来的\"ABC\"是字符串常量。\n");

	printf("单引号");
	putchar('\'');
	printf("用单引号括起来的\'A\'是字符串常量。\n");
	return 0;
}
