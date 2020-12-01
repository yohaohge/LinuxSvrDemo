#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, const char** argv)
{
	char ch= 0;
	while( (ch = getopt(argc, argv, "a:b:c:")) != -1)
	{
		switch(ch)
		{
			case 'a':
				printf("option a = %s\n", optarg);
				break;
			case 'b':
				printf("option b = %s\n", optarg);
			case 'c':
				printf("option c = %s\n", optarg);
			default:
				printf("other option %s\n", optarg);
		}
	};
	return 0;

}
