//ֻ��ʹ���ں��ṩ�ĺ���    //387��
asmlinkage int sys_mycall(char *sourceFile, char *destFile)
{
	int ret1 = sys_open(sourceFile, O_RDONLY, 0);
	int ret2;
	if (ret1 > 0)
		ret2 = sys_open(destFile, O_WRONLY | O_CREAT | O_TRUNC, 0600);  //TRUNC������ڳ��Ƚ�0
	char buff[4096];
	mm_segment_t fs;
	fs = get_fs();
	set_fs(get_ds());
	int i;
	if (ret1 > 0 && ret2 > 0)
	{
		do {
			i = sys_read(ret1, buff, 4096);  //��
			sys_write(ret2, buff, i);  //д
		} while (i);  //ֱ��д��Ϊֹ
		i = 1;
	}
	else {  //openʧ��
		printk("error!"); 
		i = -1;
	}
	sys_close(ret1);
	sys_close(ret2);
	set_fs(fs);
	return i;
}