#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cell {
	char fishName[32];
	Cell* next;
};

void create(Cell* endCell, char fishName[]);
void index(Cell *endCell);

int main() {
	char fishName[32];
	Cell head;
	head.next = nullptr;

	while (1) {
		printf("D‚«‚È‚¨ŽõŽi‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");

		scanf_s("%s", fishName, 32);

		create(&head, fishName);

		index(&head);
	}

	return 0;
}

void create(Cell* endCell, char fishName[]) {
	Cell* newCell;

	newCell = (Cell*)malloc(sizeof(Cell));

	strcpy_s(newCell->fishName, 32, fishName);

	newCell->next = NULL;

	while (endCell->next != NULL) {
		endCell = endCell->next;
	}

	endCell->next = newCell;
}

void index(Cell* endCell) {
	printf("[");
	while (endCell->next != NULL) {
		endCell = endCell->next;
		printf("%s,", endCell->fishName);
	}
	printf("]\n");
}