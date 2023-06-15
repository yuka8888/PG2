#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cell {
	int val;
	Cell* next;
};

void create(Cell* endCell, int val);
void index(Cell *endCell);

int main() {
	int val;
	Cell head;
	head.next = nullptr;

	while (1) {
		printf("D‚«‚È”Žš‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");

		scanf_s("%d", &val);

		create(&head, val);

		index(&head);
	}

	return 0;
}

void create(Cell* endCell, int val) {
	Cell* newCell;

	newCell = (Cell*)malloc(sizeof(Cell));

	newCell->val = val;

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
		printf("%d,", endCell->val);
	}
	printf("]\n");
}