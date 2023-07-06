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
		printf("[—v‘f‚Ì‘€ì]\n");
		printf("1.—v‘f‚Ìˆê——•\Ž¦\n");
		printf("2.ÅŒã”ö‚É—v‘f‚Ì‘}“ü\n");
		printf("3.ÅŒã”ö‚Ì—v‘f‚Ìíœ\n\n");
		printf("--------------------------------\n");
		printf("‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢\n");
		scanf_s("%d", &num);

		if (num == 1) {
			printf("[—v‘f‚Ìˆê——•\Ž¦]\n");
			index(&head, count);
		}
		else if (num == 2) {
			printf("[ÅŒã”ö‚É—v‘f‚Ì‘}“ü]\n");
			printf("’Ç‰Á‚·‚é—v‘f‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
			scanf_s("%s", name, 32);
			create(&head, name);
			count++;
		}
		else if (num == 3) {
			printf("[ÅŒã”ö‚Ì—v‘f‚Ìíœ]\n");
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

	printf("—v‘f\"%s\"‚ªƒŠƒXƒg‚ÌÅŒã”ö‚É‘}“ü‚³‚ê‚Ü‚µ‚½\n\n", name);
	printf("--------------------------------\n");
	printf("9.—v‘f‘€ì‚É–ß‚é\n");
	scanf_s("%d", &num);
	if (num == 9) {
		return;
	}

}

void index(Cell* endCell, int count) {
	int no = 0;
	int num;
	printf("—v‘f”:%d\n", count);

	printf("—v‘fˆê——:{\n");
	while (endCell->next != NULL) {
		endCell = endCell->next;
		printf("%d:%s,\n", no, endCell->name);
		no++;
	}
	printf("}\n\n");

	printf("--------------------------------\n");
	printf("9.—v‘f‘€ì‚É–ß‚é\n");
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
