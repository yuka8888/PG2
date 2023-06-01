#include<stdio.h>

int main() {
	const char* corlor[] = {
		"YELLOW",
		"RED",
		"BLUE",
		"GREEN",
		"BLACK",
		"WHITE"
	};
	const char* p;
	const char** pp;

	p = corlor[4];
	printf("%s\n", p);

	p++;
	printf("%s\n", p);

	pp = corlor;
	printf("%s\n", *pp + 2);

	printf("%s\n", *pp + 12);

	pp += 3;
	printf("%c", *(*pp + 1));

	

	return 0;
}