//只能使用内核提供的函数    //387号
asmlinkage int sys_mycall(char *sourceFile, char *destFile)
{
	int ret1 = sys_open(sourceFile, O_RDONLY, 0);
	int ret2;
	if (ret1 > 0)
		ret2 = sys_open(destFile, O_WRONLY | O_CREAT | O_TRUNC, 0600);  //TRUNC如果存在长度截0
	char buff[4096];
	mm_segment_t fs;
	fs = get_fs();
	set_fs(get_ds());
	int i;
	if (ret1 > 0 && ret2 > 0)
	{
		do {
			i = sys_read(ret1, buff, 4096);  //读
			sys_write(ret2, buff, i);  //写
		} while (i);  //直到写完为止
		i = 1;
	}
	else {  //open失败
		printk("error!"); 
		i = -1;
	}
	sys_close(ret1);
	sys_close(ret2);
	set_fs(fs);
	return i;
}