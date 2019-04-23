/*显示当前日期和时间（其二：利用asctime函数）*/
#include <time.h>
#include <stdio.h>

int main (void){
	time_t current = time(NULL);							//日历时间（单独的算数类型）

	printf("当前日期和时间是:%s",asctime(localtime(&current)));

	printf("。\n");

	return 0;
}
