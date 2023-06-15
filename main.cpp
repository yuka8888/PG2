#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct CELL {
	int val;
	CELL* prev;
	CELL* next;
};

void create(CELL* endCell, int val);
void index(CELL *endCell);
CELL* getInseertListAddress(CELL *endCELL, int iterator);

int main() {
	int iterator;
	int inputValue;
	CELL *insertCell;

	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (1) {
		printf("‰½”Ô–Ú‚ÌƒZƒ‹‚ÌŒã‚ë‚É‘}“ü‚µ‚Ü‚·‚©H\n");
		scanf_s("%d", &iterator);

		printf("‘}“ü‚·‚é’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢H\n");
		scanf_s("%d", &inputValue);

		insertCell = getInseertListAddress(&head, iterator);
		create(insertCell, inputValue);

		index(&head);
	}
	return 0;
}

void create(CELL* currentCell, int val) {
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;
}

void index(CELL* endCell) {
	int no = 1;
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d ", no);
		printf("%p ", endCell->prev);
		printf("%5d ", endCell->val);
		printf("(%p) ", endCell);
		printf("%p\n", endCell->next);
		no++;
	}
}

CELL* getInseertListAddress(CELL* endCELL, int iterator) {
	for (int i = 0; i < iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else {
			break;
		}
	}
	return endCELL;
}
