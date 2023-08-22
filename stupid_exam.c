#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char *path = getenv("PATH");

	if (path != NULL)
	{
		printf("the path variable contains : \n %s \n ", path);
	}
	else 
	{
		printf("path is not set\n");
	}

	return 0;
}
