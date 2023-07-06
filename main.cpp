#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cell {
	char name[32];
	Cell* next;
};

void create(Cell* endCell, char name[]);
void index(Cell* endCell, int count);
void del(Cell* endCell);

int main() {
	char name[32];
	int num;
	int count = 0;
	Cell head;
	head.next = nullptr;

	while (1) {
		printf("[�v�f�̑���]\n");
		printf("1.�v�f�̈ꗗ�\��\n");
		printf("2.�Ō���ɗv�f�̑}��\n");
		printf("3.�Ō���̗v�f�̍폜\n\n");
		printf("--------------------------------\n");
		printf("�����I�����Ă�������\n");
		scanf_s("%d", &num);

		if (num == 1) {
			printf("[�v�f�̈ꗗ�\��]\n");
			index(&head, count);
		}
		else if (num == 2) {
			printf("[�Ō���ɗv�f�̑}��]\n");
			printf("�ǉ�����v�f����͂��Ă�������\n");
			scanf_s("%s", name, 32);
			create(&head, name);
			count++;
		}
		else if (num == 3) {
			printf("[�Ō���̗v�f�̍폜]\n");
			del(&head);
			count--;
		}

	}

	

	return 0;
}

void create(Cell* endCell, char name[]) {
	int num;
	Cell* newCell;

	newCell = (Cell*)malloc(sizeof(Cell));

	strcpy_s(newCell->name, 32, name);

	newCell->next = NULL;

	while (endCell->next != NULL) {
		endCell = endCell->next;
	}

	endCell->next = newCell;

	printf("�v�f\"%s\"�����X�g�̍Ō���ɑ}������܂���\n\n", name);
	printf("--------------------------------\n");
	printf("9.�v�f����ɖ߂�\n");
	scanf_s("%d", &num);
	if (num == 9) {
		return;
	}

}

void index(Cell* endCell, int count) {
	int no = 0;
	int num;
	printf("�v�f��:%d\n", count);

	printf("�v�f�ꗗ:{\n");
	while (endCell->next != NULL) {
		endCell = endCell->next;
		printf("%d:%s,\n", no, endCell->name);
		no++;
	}
	printf("}\n\n");

	printf("--------------------------------\n");
	printf("9.�v�f����ɖ߂�\n");
	scanf_s("%d", &num);
	if (num == 9) {
		return;
	}

}

void del(Cell* endCell) {
	while (endCell->next->next != NULL) {
		endCell = endCell->next;
	}
	endCell->next = NULL;
}
