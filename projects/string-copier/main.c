#include <stdio.h>
#include <string.h>

void copy(char* dst, char* src){
	while (*src != '\0') {
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
}

int main() {
	char srcString[] = "We promptly judged antique ivory buckles for the next prize!";
	int len = strlen(srcString);
	printf("strlen src: %i\n", len);

	char dstString[60]; // zaradi null character

	copy(dstString, srcString);
	printf("dst string: %s", dstString);

	return 0;
}
