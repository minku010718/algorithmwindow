#include <stdio.h>
#include <string.h>

void Insertionsort(int A[], int n)
{
	int i = 0, j = 0;
	int temp = 0;

	for (i = 1; i < n; i++) {
		if (A[i - 1] <= A[i])
			continue;;
		temp = A[i];

		for (j = 0; j < i; j++) {
			if (A[j] > temp) {
				memmove(&A[j + 1], &A[j], sizeof(A[0]) * (i - j));
				A[j] = temp;
				break;
			}
		}
	}
}  

//function to swap elements
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

//function to find the partition position
int partition(int arr[], int low, int high) {

	//select the rightmost element as pivot
	int pivot = arr[high];

	//pointer for greater element
	int i = (low - 1);


	//traverse each element of the arr
	//compare them with the pivot
	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {

			//if element smaller than pivot is found
			//swap it with the greater element pointed by i
			i++;

			//swap element at i with element at j
			swap(&arr[i], &arr[j]);
		}
	}


	//swap the pivot element with the greater element at i
	swap(&arr[i + 1], &arr[high]);

	//return the partition point
	return (i + 1);
}

void quicksort(int A[], int low, int high) {
	if (low < high) {
		//find the pivot element such that
		//elements smaller than pivot are on left of pivot
		//elements greater than pivot are on right of pivot
		int pi = partition(A, low, high);

		//recursive call on the left of pivot
		quicksort(A, low, pi - 1);

		//recursive call on the right of pivot
		quicksort(A, pi + 1, high);
	}
}

void merge(int a[], int i1, int j1, int i2, int j2)
{
	int temp[50] = { 0 }; //array used for merging
	int i, j, k;
	i = i1; //beginning of the first list
	j = i2; //beginning of the second list
	k = 0;
	while (i <= j1 && j <= j2) //while elements in both lists
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= j1) //copy remaining elements of the first list
		temp[k++] = a[i++];
	while (j <= j2) //copy remaining elements of the second list
		temp[k++] = a[j++];
	//transfer elements from temp[] back to a[]
	for (i = i1, j = 0; i <= j2; i++, j++)
		a[i] = temp[j];
}

void mergesort(int a[], int i, int j)
{
	int mid;
	if (i < j)
	{
		mid = (i + j) / 2;
		mergesort(a, i, mid); //left recursion
		mergesort(a, mid + 1, j); //right recursion
		merge(a, i, mid, mid + 1, j); //merging of two sorted sub-arrays
	}
}

int val;
void heapify(int arr[], int size, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < size && arr[left] > arr[largest])
		largest = left;
	if (right < size && arr[right] > arr[largest])
		largest = right;
	if (largest != i)
	{
		val = arr[i];
		arr[i] = arr[largest];
		arr[largest] = val;
		heapify(arr, size, largest);
	}
}
void heapsort(int arr[], int size)
{
	int i;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);
	for (i = size - 1; i >= 0; i--)
	{
		val = arr[0];
		arr[0] = arr[i];
		arr[i] = val;
		heapify(arr, i, 0);
	}
}

//function to print arr elements
void printlist(int A[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", A[i]);
	}
	printf("\n");
}





//main function
int main() {
	int A[] = { 8,7,2,1,0,9,6,11,13,12,34,56,112,115 };
	int length = sizeof(A) / sizeof(A[0]);
	printf("Unsorted Array\n");
	printlist(A, length); getchar();

	//perform quicksort on A
	printf("Sorted list by insertionsort\n");
	Insertionsort(A, length);
	printlist(A, length); getchar();

	int B[] = { 48,33,55,33,34,32,55,52,32,59,38,38,41,22,41,58,28,41,55,41,21,33,33,45,23,32,53,25,
	49,33,45,34,53,37,24,58,51,30,28,23,29,51,23,22,20,99,49,45,24,59};
	//int length = sizeof(B) / sizeof(B[0]);

	//perform quicksort on B
	printf("Sorted list by quicksort\n");
	quicksort(B, 0, length - 1);
	printlist(B, length); getchar();

	int C[] = { 8,7,2,1,0,9,6,11,13,12,34,56,112,115 };
	//int length = sizeof(C) / sizeof(C[0]);
	//
	//perform mergesort on C
	printf("Sorted list by mergesort\n");
	mergesort(C, 0, length - 1);
	printlist(C, length); getchar();

	int D[] = { 8,7,2,1,0,9,6,11,13,12,34,56,112,115 };
	//int length = sizeof(D) / sizeof(D[0]);
	//
	//perform heapsort on D
	printf("Sorted list by heapsort\n");
	heapsort(D, length - 1);
	printlist(D, length); getchar();

	return 0;
}