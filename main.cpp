#include<stdio.h>

int main() {
	FILE* fp;
	char fname[] = "test.txst";
	int err;
	err = fopen_s(&fp, fname, "r");
	char str[32] = {};

	if (err != 0) {
		printf("%s file not open!\n", fname);
		return err;
	}
	else {
		printf("%s file opened!\n", fname);
		fscanf_s(fp, "%s", &str, sizeof(str));
		printf("“Ç‚İ‚ñ‚¾•¶š—ñ‚Í%s‚Å‚·\n", str);
	}

	fclose(fp);

	return 0;
}