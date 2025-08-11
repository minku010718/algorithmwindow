#include <stdio.h>


typedef struct DisjointSet {
	int data;
	int rank;
	struct DisjointSet* parent;
}DisjointSet;

DisjointSet* disjointset_makeset(int data)
{
	DisjointSet* node = (DisjointSet*)malloc(sizeof(DisjointSet));
	node->parent = node;
	node->data = data;
	node->rank = 0;
	return node;
}

DisjointSet* disjointset_find(DisjointSet* set)
{
	DisjointSet* parent = set->parent;
	if (parent == set)
		return parent;
	return set->parent = disjointset_find(set->parent);
}


void disjointset_union(DisjointSet* set1, DisjointSet* set2)
{
	printf("UNION(%d, %d)\n", set1->data, set2->data);
	DisjointSet* parent1 = set1;
	DisjointSet* parent2 = set2;
	parent1 = disjointset_find(set1);
	parent2 = disjointset_find(set2);

	if (parent1 != parent2) {
		if (parent1->rank >= parent2->rank) {
			if (parent1->rank == parent2->rank)
				parent1->rank++;
			parent2->parent = parent1;
		}
		else parent1->parent = parent2;
	}
}

int main(void)
{
	int a = 1, b = 2, c = 3;
	DisjointSet* set1 = disjointset_makeset(a);
	printf("parent of set1 : %d\n", disjointset_find(set1)->data);

	DisjointSet* set2 = disjointset_makeset(b);
	printf("parent of set2 : %d\n", disjointset_find(set2)->data);

	disjointset_union(set1, set2);
	printf("parent of set1 : %d\n", disjointset_find(set1)->data);
	printf("parent of set2 : %d\n", disjointset_find(set2)->data);

	DisjointSet* set3 = disjointset_makeset(c);
	printf("parent of set3 : %d\n", disjointset_find(set3)->data);
	disjointset_union(set1, set3);
	printf("parent of set1 : %d\n", disjointset_find(set1)->data);
	printf("parent of set2 : %d\n", disjointset_find(set2)->data);
	printf("parent of set3 : %d\n", disjointset_find(set3)->data);


	return 1;
}