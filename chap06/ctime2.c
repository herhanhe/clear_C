/*---根据ctime函数把time_t型表示的时间转换成字符串（不添加换行符）---*/
char *ctime2(const time_t *timer){
	return asctime2(localtime(timer));
}
