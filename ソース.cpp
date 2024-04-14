#include <iostream>
#include <stdio.h>
#include "jihanki.h"
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
/*
void bbb();
void ccc();
int aaa();
typedef void(*FUNC_AAA)();
typedef enum { BBB, CCC, null }state_TDD;
state_TDD statenum = BBB;
*/
typedef enum { A, B, C, D = 0, E = 1 }aaa;
/*
int main() {
	jihanki jihankiobj;
	while (1) {
		(jihankiobj.*(jihankiobj.func_table[jihankiobj.jihankistate[0]][jihankiobj.jihankistate[1]]))();
	}
	delete jihankiobj.merchandise;
	return 0;
}*/
/*
int main() {
	short a[5] = { A,B,C,D,E };
	for (int i = 0; i < 5; i++) {
		printf("%d", a[i]);

	}
	printf("\n");
	printf("%d\n",sizeof(A));
	printf("%d", sizeof(aaa));
}
*/
int main() {
	FILE* file;
	int i = 20;
	fopen_s(&file, "test.txt", "wb");
	fwrite("hello\n", 6, 1, file);
	fwrite("for‚Å‰ñ‚·", 9, 1, file);
	for (int k = 0; k < 50; k++) {
		fwrite(&k, 1, 1, file);
	}
	/*
	fprintf(file, "for‚Å‰ñ‚·\n");
	for (int k = 0; k < 50; k++) {
		fprintf(file, "%d\n", k);
	}
	*/
	fclose(file);
	return 0;
}
/*
int main() {
	FUNC_AAA a[3] = { bbb,ccc,0 };
	while (aaa()) {
		a[statenum]();
	}
	printf("nukemasita");
	return 0;
}


int aaa() {
	if (statenum == null) {
		return 0;
	}
	return 1;
}

void bbb() {
	printf("aaa\n");
	statenum = CCC;
}

void ccc() {
	printf("break");
	statenum = null;
}
*/