#include "get_next_line.h"

int main(int argc, char **argv)
{
	if( argc != 2 )
	{
		printf("Expect one argument\n");
		return 0;
	}
	char *meh;
	int fd = open(argv[1], O_RDONLY);

    while(get_next_line(fd, &meh))
    {
    	printf("Read:\n");
    	printf("%s\n", meh);
    }
    return 0;
}
