#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int verbose_flag = 0;
static struct option long_options[] =
{
	/* These options set a flag. */
	{"verbose", no_argument,       &verbose_flag, 1},
	{"brief",   no_argument,       &verbose_flag, 0},
	/* These options don’t set a flag.
	 We distinguish them by their indices. */
	{"add",     no_argument,       0, 'a'},
	{"append",  no_argument,       0, 'b'},
	{"delete",  required_argument, 0, 'd'},
	{"create",  required_argument, 0, 'c'},
	{"file",    required_argument, 0, 'f'},
	{0, 0, 0, 0}
};

// getopt_long 
int main(int argc, const char** argv)
{
	int c = 0;
	int index = 0;
	while( (c = getopt_long(argc, argv, "abc:d:f:", &long_options, &index)) != EOF )
	{
		switch(c)
		{
			case 'a':
				printf("get option -a\n");
				break;
		
			case 'b':
				printf("get option -b\n");
				break;
	
			case 'c':
				printf("get option -c value = %s\n", optarg);
				break;
			case 'd':
				printf("get option -d value = %s\n", optarg);
				break;
			case 'f':
				printf("get option -f value = %s\n", optarg);
				break;

			default:
				printf("wrong param\n");
		}
	}

	if(optind == argc)
	{
		printf("has no extra param\n");
	}
	else
	{
		printf("extra param: %s\n", argv[optind]);
	}
	return 0;


}
