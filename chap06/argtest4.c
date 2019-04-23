/*不用argc来显示程序名和程序形式参数*/

#include <stdio.h>

int main (int argc, char **argv){
	int i = 0;
	while (*argv)
		printf("argc[%d] = \"%s\"\n",i++,*argv++);

	return 0;
}
