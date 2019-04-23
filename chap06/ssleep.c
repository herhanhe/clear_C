/*---等待经过x秒---*/

int ssleep(double x){
	time_t t1 = time(NULL),t2;
	do{
		if((t2 = time(NULL)) == (time_t)-1)			//错误
			return 0;
	}while(difftime(t2,t1) < x);
	return 1;
}
