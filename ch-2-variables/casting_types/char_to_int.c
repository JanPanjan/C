#include <stdio.h>

int main() {
	int target;
	char source = 'a';
	target = (int)source;
	printf("target: %i\n", target);

	// gre tudi v drugo smer
	char target2;
	int source2 = 97;
	target2 = (char)source2;
	printf("target2: %c\n", source2);

	return 0;
}
