#include<stdio.h>

int Recrsive(int n1, int n2);

int main() {
	int num1, num2;
	int ans = 0;

	printf("�����́F");
	scanf_s("%d", &num1);
	printf("�w������́F");
	scanf_s("%d", &num2);
	ans = Recrsive(num1, num2);
	printf("%d��%d���%d", num1, num2, ans);
	return 0;
}

int Recrsive(int n1, int n2) {
	if (n2 <= 1) {
		return (n1);
	}

	return (n1 * Recrsive(n1, n2 - 1));
}