#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct CELL {
	char fishName[32];
	int price;
	CELL* prev;
	CELL* next;
};

void create(CELL* currentCell, char fishName[], int price);
void index(CELL* endCell);
CELL* getInseertListAddress(CELL* endCELL, int iterator);

int main() {
	int iterator;
	char fishName[32];
	int price;
	CELL* insertCell;

	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (1) {
		printf("何番目に好きなお寿司ですか？\n");
		scanf_s("%d", &iterator);

		printf("好きなお寿司を入力してください\n");
		scanf_s("%s", fishName, 32);

		printf("1貫の値段を入力してください\n");
		scanf_s("%d", &price);

		insertCell = getInseertListAddress(&head, iterator);
		create(insertCell, fishName, price);

		index(&head);
	}
	return 0;
}

void create(CELL* currentCell, char fishName[], int price) {
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	strcpy_s(newCell->fishName, 32, fishName);
	newCell->price = price;
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
	printf("|rank|  前のアドレス  |寿司ネタ|値段|    アドレス    |  次のアドレス  |\n");
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("|%4d", no);
		printf("|%p", endCell->prev);
		printf("|%8s", endCell->fishName);
		printf("|%4d", endCell->price);
		printf("|%p", endCell);
		printf("|%p|\n", endCell->next);
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
