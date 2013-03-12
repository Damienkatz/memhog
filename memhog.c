#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char* argv[]) {
	char* lastchar;
	long bytes_to_hog;
	void* mem;
	if (argv[1][0] == '0' && (argv[1][1] == 'x' || argv[1][1] == 'X')) {
		/* base 16 */
		bytes_to_hog = strtol(argv[1], &lastchar, 16);
	} else {
		/* must be base 10 */
		bytes_to_hog = strtol(argv[1], &lastchar, 10);
	}
	if (*lastchar != '\0') {
		printf("Invalid argument %s, make sure to pass a base 10 or 16 integer (ex: 255 or 0xFF)\n", argv[1]);
		return 1;
	}
	printf("Attempting to hog %li bytes of RAM.\n", bytes_to_hog);
 	mem = malloc(bytes_to_hog);
	if (!mem) {
		printf("Failied! Couldn't malloc.\n");
		return 1;
	}
	if (mlock(mem, bytes_to_hog)) {
		printf("Failed! Couldn't mlock.\n");
		return 1;
	}
	printf("Success! Press any key to kill me and get back the RAM.\n");
	getchar();
	return 0;
}