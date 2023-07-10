#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct CELL {
	char name[32];
	CELL* prev;
	CELL* next;
};

void create(CELL* currentCell, char name[]);
void index(CELL* endCell, int count);
void edit(CELL* endCell);
CELL* getInseertListAddress(CELL* endCELL, int iterator);

int main() {
	int iterator;
	int num = 0;
	int num1 = 0;
	int count = 0;
	char name[32];
	int price;
	CELL* insertCell;

	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (1) {
		printf("[�v�f�̑���]\n");
		printf("1.�v�f�̕\��\n");
		printf("2.�v�f�̑}��\n");
		printf("3.�v�f�̕ҏW\n");
		printf("4.�v�f�̍폜\n");
		printf("5.�v�f�̕��ёւ�(�I�v�V����)\n\n");
		printf("----------------------------------\n");
		printf("�����I�����Ă�������\n");
		scanf("%d", &num);

		if (num == 1) {
			printf("[�v�f�̕\��]\n");
			printf("1.�v�f�̈ꗗ�\��\n");
			printf("2.���Ԃ��w�肵�ėv�f��\��\n");
			printf("9.�v�f����ɖ߂�\n");
			printf("�����I�����Ă�������\n");
			scanf("%d", &num1);

			if (num1 == 1) {
				index(&head, count);
			}
			else if (num1 == 2) {

			}
		}
		else if (num == 2) {
			edit(&head);
		}
		else if (num == 3) {
		printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł��������B\n");
		scanf_s("%d", &iterator);

		printf("�ǉ�����v�f�̒l����͂��Ă�������\n");
		scanf_s("%s", name, 32);


		insertCell = getInseertListAddress(&head, iterator);
		create(insertCell, name);

		}


	}
	return 0;
}

void create(CELL* currentCell, char name[]) {
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	strcpy_s(newCell->name, 32, name);
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;
}

void index(CELL* endCell, int count) {
	int no = 1;
	printf("�v�f��:%d\n", count);
	printf("�v�f�ꗗ:{\n");

	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d:", no);
		printf("%s,\n", endCell->name);
		no++;
	}
	printf("}");
}

void edit(CELL* endCell) {
	int num = 0;

	printf("[�v�f�̕ҏW]\n");
	printf("�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");
	scanf("%d", &num);


	for (int i = 0; i < num; i++) {
		if (endCell->next != nullptr) {
			endCell = endCell->next;
		}
		else {
			printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", num);
			return;
		}
	}

	printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă�������\n", num);
	scanf("%s", endCell->name, 32);

	printf("%d�Ԗڂ̒l��%s�ɕύX����܂����B", num, endCell->name);

	return;
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
