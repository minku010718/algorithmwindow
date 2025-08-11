#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}Node;

typedef struct LinkedList {
	Node* head;
	int length;
}List;

Node* CreateNodeInstance(int data) {}
List* CreateListInstance() {}
void Add_Node(List* list, Node* node) {}
Node* BuildOneTwoThree() {
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;
	head = (Node*)malloc(sizeof(Node));
	second = (Node*)malloc(sizeof(Node));
	third = (Node*)malloc(sizeof(Node));
	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;
	return head;
}
int Length(Node* head) {
	Node* current = head;
	int count = 0;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}
int main() {
	Node* list1 = NULL;
	Node* current = NULL;
	list1 = BuildOneTwoThree();
	current = list1;
	while (current != NULL) {
		printf("<%d, %p>\n", current->data, current->next);
		current = current->next;
	}
	printf("리스트의 길이(노드수): %d\n", Length(list1));
	return 0;
}