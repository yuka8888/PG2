#include<stdio.h>

int main() {
	int array[5] = { 5, 3, 8, 12, 2 };
	int* p_array = array;

	for (int i = 0; i < 5; i++) {
		printf("�ϐ�array[%d]�̒l = %d\n", i, array[i]);
		printf("�ϐ�arrar[%d]�̃A�h���X = %p\n", i, array + i);
	}

	printf("-------------------------------------------\n");

	for (int i = 0; i < 5; i++) {
		printf("�ϐ�array[%d]�̒l = %d\n", i, *(p_array + i));
		printf("�ϐ�arrar[%d]�̃A�h���X = %p\n", i, p_array + i);
	}


}