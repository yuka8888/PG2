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
		printf("[要素の操作]\n");
		printf("1.要素の表示\n");
		printf("2.要素の挿入\n");
		printf("3.要素の編集\n");
		printf("4.要素の削除\n");
		printf("5.要素の並び替え(オプション)\n\n");
		printf("----------------------------------\n");
		printf("操作を選択してください\n");
		scanf("%d", &num);

		if (num == 1) {
			printf("[要素の表示]\n");
			printf("1.要素の一覧表示\n");
			printf("2.順番を指定して要素を表示\n");
			printf("9.要素操作に戻る\n");
			printf("操作を選択してください\n");
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
		printf("要素を追加する場所を指定してください。最後尾に追加する場合は何も入力しないでください。\n");
		scanf_s("%d", &iterator);

		printf("追加する要素の値を入力してください\n");
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
	printf("要素数:%d\n", count);
	printf("要素一覧:{\n");

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

	printf("[要素の編集]\n");
	printf("編集したい要素の番号を指定してください。\n");
	scanf("%d", &num);


	for (int i = 0; i < num; i++) {
		if (endCell->next != nullptr) {
			endCell = endCell->next;
		}
		else {
			printf("%d番目の要素が見つかりませんでした。\n", num);
			return;
		}
	}

	printf("%d番目の要素の変更する値を入力してください\n", num);
	scanf("%s", endCell->name, 32);

	printf("%d番目の値が%sに変更されました。", num, endCell->name);

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
