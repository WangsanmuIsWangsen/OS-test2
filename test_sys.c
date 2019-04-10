#include<stdio.h>
#include<stdlib.h>
#include<linux/unistd.h>
#include<asm/unistd.h>
int main(int argc,char *argv[])
{
	if (argc != 3)
	{
		printf("parament error!\n");
		return 0;
	}
	syscall(387, argv[1], argv[2]);  //请求系统调用
	return 0;
}