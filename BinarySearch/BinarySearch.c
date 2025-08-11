#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct BinarySearchTreeNode {
	element data;
	struct BinarySearchTreeNode* left;
	struct BinarySearchTreeNode* right;
}Node;

Node* createnode(element data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data; node->left = NULL; node->right = NULL;
	return node;
}

Node* searchnode(Node* tree, element target)
{
	if (tree == NULL) return NULL;
	if (tree->data > target)
		return searchnode(tree->left, target);
	else if (tree->data < target)
		return searchnode(tree->right, target);
	else
		return tree;
}

Node* searchminnode(Node* tree)
{
	if (tree == NULL) return NULL;
	if (tree->left == NULL) return tree;
	else
		return searchminnode(tree->left);
}

void insertnode(Node* tree, Node* child)
{
	if (tree->data < child->data) {
		if (tree->right == NULL) tree->right = child;
		else
			insertnode(tree->right, child);
	}
	else if (tree->data > child->data) {
		if (tree->left == NULL) tree->left = child;
		else
			insertnode(tree->left, child);
	}
}

Node* removenode(Node* tree, Node* parent, element target)
{
	Node* removed = NULL;
	if (tree == NULL) return NULL;
	if (tree->data > target)
		removed = removenode(tree->left, tree, target);
	else if (tree->data < target)
		removed = removenode(tree->right, tree, target);
	else {
		removed = tree;
		if (tree->left == NULL && tree->right != NULL) {
			if (parent->left == tree) parent->left = NULL;
			else parent->right = NULL;
		}
		else {
			if (tree->left != NULL && tree->right != NULL) {
				Node* minnode = searchminnode(tree->right);
				minnode = removenode(tree, NULL, minnode->data);
				tree->data = minnode->data;
			}
			else {
				Node* temp = NULL;
				if (tree->left != NULL) temp = tree->left;
				else temp = tree->right;
				if (parent->left == tree) parent->left = temp;
				else parent->right = temp;
			}
		}
	}
	return removed;
}

void printtree_inorder(Node* tree) {
	if (tree) {
		printtree_inorder(tree->left);
		printf("%d ", tree->data);
		printtree_inorder(tree->right);
	}
}

void destroynode(Node* node) {
	free(node);
}

int main(void)
{
	Node* tree = createnode(123); Node* node = NULL;
	insertnode(tree, createnode(22));
	insertnode(tree, createnode(9918));
	insertnode(tree, createnode(424));
	insertnode(tree, createnode(17));
	insertnode(tree, createnode(3));
	insertnode(tree, createnode(98));
	insertnode(tree, createnode(34));
	insertnode(tree, createnode(760));
	insertnode(tree, createnode(317));
	insertnode(tree, createnode(1));
	printtree_inorder(tree);	printf("\n");
	node = removenode(tree, NULL, 98);	destroynode(node);
	printtree_inorder(tree);	printf("\n");
	return 0;
}