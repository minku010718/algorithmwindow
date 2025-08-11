#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define TRUE 1
#define FALSE 0

typedef struct _Node {
	int data;
	struct _Node* next;
}NODE;

NODE* front[10];
NODE* rear[10];
NODE* ptrnode;
int buf[MAX];

int isNumberExit(int number, int indx)
{
	for (int i = 0; i < indx; i++) {
		if (buf[i] == number)
			return TRUE;
	}
	return FALSE;
}

void makeRandomNumber(void)
{
	int i = 0, num;
	srand((unsigned)time(NULL));
	while (i < MAX) {
		num = rand() % 100;
		if (!isNumberExit(num, i)) {
			buf[i] = num;
			i++;
		}
	}
}

void initializeQueue(void)
{
	int i;
	for (i = 0; i < MAX; i++) {
		front[i] = (NODE*)malloc(sizeof(NODE));
		rear[i] = (NODE*)malloc(sizeof(NODE));
		front[i]->next = rear[i];
		rear[i]->next = rear[i];
	}
}

void enqueue(int indx, int num)
{
	ptrnode = (NODE*)malloc(sizeof(NODE));
	ptrnode->data = num;
	if (front[indx]->next == rear[indx]) {
		front[indx]->next = ptrnode;
		ptrnode->next = rear[indx];
		rear[indx]->next = ptrnode;
	}
	else {
		rear[indx]->next->next = ptrnode;
		ptrnode->next = rear[indx];
		rear[indx]->next = ptrnode;
	}
}

int dequeue(int indx)
{
	int ret;
	NODE* deleteNode;
	if (front[indx]->next == rear[indx])
		return -1;
	else {
		deleteNode = front[indx]->next;
		front[indx]->next = deleteNode->next;
		ret = deleteNode->data;
		free(deleteNode);
	}
	return ret;
}

void printBuf(void)
{
	int i;
	for (i = 0; i < MAX; i++) {
		if ((i % 10) == 0)
			printf("\n");
		printf("%4d ", buf[i]);
	}
	printf("\n");
}

void radixSort(void)
{
	int i, num, digit, j;
	j = 0;
	for (i = 0; i < MAX; i++) {
		num = buf[i];
		digit = num % MAX;
		enqueue(digit, num);
	}
	printf("\n숫자리스트(1의자릿수)");
	for (i = 0; i < MAX; i++) {
		printf("\n%d의 자리 : ", i);
		while (1) {
			num = dequeue(i);
			if (num != -1) {
				printf("%3d ", num);
				buf[j++] = num;
			}
			else
				break;
		}
	}
	printf("\n\n1차 정렬후 buf 데이터들\n");
	printBuf();

	j = 0;
	for (i = 0; i < MAX; i++) {
		num = buf[i];
		digit = num / MAX;
		enqueue(digit, num);
	}
	printf("\n숫자리스트(10의자릿수)\n");
	for (i = 0; i < MAX; i++) {
		printf("\n%d의 자리 : ", i);
		while (1) {
			num = dequeue(i);
			if (num != -1) {
				printf("%3d ", num);
				buf[j++] = num;
			}
			else
				break;
		}
	}
	printf("\n\n2차 정렬후 buf 데이터들\n");
	printBuf();
}

int main(void)
{
	initializeQueue();
	printf("정렬 데이터 초기화\n");
	makeRandomNumber();
	printBuf();
	radixSort();
	printf("\n\n");
	printf("\n");

	return 0;
}