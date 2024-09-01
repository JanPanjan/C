#include <stdio.h>
#include <string.h>

struct Bottle {
	char name[20];
};

/// funkcija spremeni ime bottla
void bottleFunction(struct Bottle b, struct Bottle* bPointer){
	strcpy(b.name, "Super Large");
	strcpy(bPointer->name, "Super Small");
}

int main(){
	struct Bottle b1 = {"Medium"};
	struct Bottle b2 = {"Large"};

	bottleFunction(b1, &b2);
	// NOTE: funkcija ni spremenila imena v b1
	printf("b1 name: %s\n", b1.name);
	printf("b2 name: %s\n", b2.name);
}

