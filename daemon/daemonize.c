/*
 *
 * 
 */

#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

using namespace std;

int daemonize()
{
	// 创建子进程，关闭父进程	
	pid_t pid;
	if((pid = fork()) < 0)
		return -1;
	else if(pid != 0)
		exit(0);

	// 创建新session，成为session leader
	if(setsid() < 0) 
		return -1;
	// 改变当前工作目录到根目录
	if(chdir("/") < 0) 
	// 设置文件创建mask为0
	if(umask(0) < 0)
		return -1;
	// 关闭不需要的打开的文件描述符（STDIN STDOUT STDERR)
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	
	open("dev/null", O_RDONLY);
	open("dev/null", O_RDWR);
	open("dev/null", O_RDWR);

	return 0;
}

int main() {
	
	if( daemonize() < 0)
		return 0;
	while(1)
	{
		cout << "can" << endl;
	}
	return 0;
}
