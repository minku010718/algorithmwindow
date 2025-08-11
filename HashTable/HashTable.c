#define _CRT_SECURE_NO_WARNINGS true
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACITY 100
unsigned long hash_function(const char* str) {
	unsigned long i = 0;
	for (int j = 0; str[j]; j++)
		i += str[j];
	return i % CAPACITY;
}
typedef struct Ht_item Ht_item;
struct Ht_item {
	char* key;
	char* value;
};
typedef struct HashTable HashTable;
struct HashTable {
	// Contains an array of pointers
	// to items
	Ht_item** items;
	int size;
	int count;
};
Ht_item* create_item(const char* key, const char* value) {
	// Creates a pointer to a new hash table item
	Ht_item* item = (Ht_item*)malloc(sizeof(Ht_item));
	item->key = (char*)malloc(strlen(key) + 1);
	item->value = (char*)malloc(strlen(value) + 1);
	strcpy(item->key, key); strcpy(item->value, value);
	return item;
}
HashTable* create_table(int size) {
	// Creates a new Hash Table
	HashTable* table = (HashTable*)malloc(sizeof(HashTable));
	table->size = size; table->count = 0;
	table->items = (Ht_item**)calloc(table->size, sizeof(Ht_item));
	for (int i = 0; i < table->size; i++)
		table->items[i] = NULL;
	return table;
}
void free_item(Ht_item* item) {
	free(item->key);	free(item->value); free(item);
}
void free_table(HashTable* table) {
	for (int i = 0; i < table->size; i++) {
		Ht_item* item = table->items[i];
		if (item != NULL)
			free_item(item);
	}
	free(table->items); free(table);
}
void handle_collision(HashTable* table, unsigned long index, Ht_item* item) {
	unsigned long i = index + 1; // Linear probing, move to the next slot
	while (table->items[i % table->size] != NULL) {
		i++;
	}
	table->items[i % table->size] = item;
	table->count++;
}
void ht_insert(HashTable* table, const char* key, const char* value) {
	Ht_item* item = create_item(key, value);
	unsigned long index = hash_function(key);	// Compute the index
	Ht_item* current_item = table->items[index];
	if (current_item == NULL) {
		if (table->count == table->size) {		// Key does not exist
			printf("Insert Error: Hash Table is full\n");// Hash Table Full
			free_item(item);	// Remove the create item
			return;
		}
		table->items[index] = item;				// Insert directly
		table->count++;
	}
	else {		// Scenario 1: We only need to update value
		if (strcmp(current_item->key, key) == 0) {
			strcpy(table->items[index]->value, value);	return;
		}
		else {	// Scenario 2: Collision
			handle_collision(table, index, item);	return;
		}
	}
}
char* ht_search(HashTable* table, const char* key) {
	// Searches the key in the hashtable
	// and returns NULL if it doesn't exist
	int index = hash_function(key);
	Ht_item* item = table->items[index];
	if (item != NULL) { // Ensure that we move to a non NULL item
		if (strcmp(item->key, key) == 0)
			return item->value;
	}
	return NULL;
}
void print_search(HashTable* table, const char* key) {
	char* val;
	if ((val = ht_search(table, key)) == NULL) {
		printf("Key:%s does not exist\n", key); return;
	}
	else printf("key:%s, Value:%s\n", key, val);
}
void print_table(HashTable* table) {
	printf("\nHash Table\n-------------------\n");
	for (int i = 0; i < table->size; i++) {
		if (table->items[i]) {
			printf("Index:%d, Key:%s, Value:%s\n", i,
				table->items[i]->key, table->items[i]->value);
		}
	}
	printf("-------------------\n\n");
}
int main() {
	HashTable* ht = create_table(CAPACITY);
	ht_insert(ht, "1", "First address");
	ht_insert(ht, "2", "Second address");
	print_search(ht, "1");
	print_search(ht, "2");
	print_search(ht, "3");
	print_table(ht);
	free_table(ht);
	return 0;
}