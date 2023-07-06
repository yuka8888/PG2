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
		printf("[要素の操作]\n");
		printf("1.要素の一覧表示\n");
		printf("2.最後尾に要素の挿入\n");
		printf("3.最後尾の要素の削除\n\n");
		printf("--------------------------------\n");
		printf("操作を選択してください\n");
		scanf_s("%d", &num);

		if (num == 1) {
			printf("[要素の一覧表示]\n");
			index(&head, count);
		}
		else if (num == 2) {
			printf("[最後尾に要素の挿入]\n");
			printf("追加する要素を入力してください\n");
			scanf_s("%s", name, 32);
			create(&head, name);
			count++;
		}
		else if (num == 3) {
			printf("[最後尾の要素の削除]\n");
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

	printf("要素\"%s\"がリストの最後尾に挿入されました\n\n", name);
	printf("--------------------------------\n");
	printf("9.要素操作に戻る\n");
	scanf_s("%d", &num);
	if (num == 9) {
		return;
	}

}

void index(Cell* endCell, int count) {
	int no = 0;
	int num;
	printf("要素数:%d\n", count);

	printf("要素一覧:{\n");
	while (endCell->next != NULL) {
		endCell = endCell->next;
		printf("%d:%s,\n", no, endCell->name);
		no++;
	}
	printf("}\n\n");

	printf("--------------------------------\n");
	printf("9.要素操作に戻る\n");
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
