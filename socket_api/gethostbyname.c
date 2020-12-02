#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	hostent p_hostent = gethostbyname("www.baidu.com");

	if(hostent)
}
