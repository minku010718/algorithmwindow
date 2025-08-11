#include <stdio.h>
#include <stdlib.h>
#include <string.h>
_CRT_SECURE_NO_WARNINGS;


typedef struct ListNode {
	char data[10];
	struct ListNode* link;
}listNode;


typedef struct {
	listNode* head;
}linkedList_h;


linkedList_h* creatLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}


void printList(linkedList_h* L) {
	listNode* p;
	printf("老林老 = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

void insertNode(linkedList_h* L, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy_s(newNode->data, 10, x);
	newNode->link = NULL;

	if (L->head == NULL) {
		L->head = newNode;
	}
	else {
		listNode* temp = L->head;
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = newNode;
	}
}


int main() {
	linkedList_h* L;
	L = creatLinkedList_h();
	insertNode(L, "岿");
	insertNode(L, "拳");
	insertNode(L, "荐");
	insertNode(L, "格");
	insertNode(L, "陛");
	insertNode(L, "配");
	insertNode(L, "老");
	printList(L); getchar();

	getchar();

	return 0;
}