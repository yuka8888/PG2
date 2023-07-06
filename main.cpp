#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct CELL {
	char name[32];
	int price;
	CELL* prev;
	CELL* next;
};

void create(CELL* currentCell, char name[], int price);
void index(CELL* endCell);
CELL* getInseertListAddress(CELL* endCELL, int iterator);

int main() {
	int iterator;
	char name[32];
	int price;
	CELL* insertCell;

	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (1) {
		printf("���ԖڂɍD���Ȃ����i�ł����H\n");
		scanf_s("%d", &iterator);

		printf("�D���Ȃ����i����͂��Ă�������\n");
		scanf_s("%s", name, 32);

		printf("1�т̒l�i����͂��Ă�������\n");
		scanf_s("%d", &price);

		insertCell = getInseertListAddress(&head, iterator);
		create(insertCell, name, price);

		index(&head);
	}
	return 0;
}

void create(CELL* currentCell, char name[], int price) {
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	strcpy_s(newCell->name, 32, name);
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
	printf("|rank|  �O�̃A�h���X  |���i�l�^|�l�i|    �A�h���X    |  ���̃A�h���X  |\n");
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("|%4d", no);
		printf("|%p", endCell->prev);
		printf("|%8s", endCell->name);
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
