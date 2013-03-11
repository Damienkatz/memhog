#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char* argv[]) {
	char* lastchar;
	long bytes_to_hog;
	void* mem;
	bytes_to_hog = strtol(argv[1], &lastchar, 10);
	if (*lastchar != '\0') {
		printf("invalid argument %s, make sure to pass a base 10 integer\n", argv[1]);
		return 1;
	}
	
	printf("Hogging %s bytes of RAM. Press any key to kill me.\n", argv[1]);
 	mem = malloc(bytes_to_hog);
	mlock(mem, bytes_to_hog);
	getchar();
	return 0;
}