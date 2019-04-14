/*把从键盘输入的值存入储存空间的整数中（错误）*/

#include <stdio.h>
#include <stdlib.h>

int main (void){
	int *x;
	x  = calloc(1,sizeof(int));		//分配
	if(x == NULL){
		puts("储存空间分配失败");
	}
	else{
		printf("要存入*x的值");
		scanf("%d",x);
		printf("*x = %d\n",*x);
		free(x);					//释放
	}
	return 0;
}
