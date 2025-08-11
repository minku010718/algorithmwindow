/* Array Review -
(Allocating the memory for all its elements in one block of memory)
1) The size of the array is fixed (at static time)
2) The space in the array really is wasted
3) Inserting new elements at the front is potentially expensive because of shifted to making room for it.*/

#include <stdio.h>
int* ArrayTest() {
	int scores[10];
	scores[0] = 1;
	scores[1] = 2;
	scores[2] = 3;
	return scores;
}

int main() {
	int* array_ptr;
	int sc[10];
	array_ptr = ArrayTest();
	for (int i = 0; i < 10; i++) {
		sc[i] = *(array_ptr + i);
	}
	for (int i = 0; i < 10; i++) {
		fprintf(stdout, "%d\n", sc[i]);
	}
	getchar();
	return 0;
}