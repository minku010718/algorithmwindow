//linear select algorithmÀÇ ±¸Çö
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct medarray {
	int capacity;
	int* median;
}med;
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
med* createmedarray(int capacity)
{
	med* m1 = (med*)malloc(sizeof(med));
	m1->capacity = capacity;
	m1->median = (int*)malloc(sizeof(int) * capacity);
	return m1;
}
void insertionsort(int A[], int n)
{
	int i = 0, j = 0;
	int temp = 0;

	for (i = 1; i < n; i++) {
		if (A[i - 1] <= A[i])
			continue;;
		temp = A[i];

		for (j = 0; j < i; j++) {
			if (A[j] > temp) {
				memmove(&A[j + 1], &A[j], sizeof(A[0] * (i - j)));
				A[j] = temp;
				break;
			}
		}
	}
}
int findMedian(int arr[], int n)
{
	insertionsort(arr, n); //Sort the array
	return arr[n / 2]; //Return middle element
}
int partition(int arr[], int l, int r, int x)
{
	//Search for x in arr[l..r] and move it to end
	int i;
	for (i = l; i < r; i++)
		if (arr[i] == x) break;
	swap(&arr[i], &arr[r]);
	i = l;
	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= x) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}
int kthSmallest(int arr[], int l, int r, int k)
{
	if (k > 0 && k <= r - l + 1)
	{
		int i, n = r - l + 1; //Number of elements in arr[l..r]
		med* m1 = createmedarray((int)((n + 4) / 5));
		for (i = 0; i < n / 5; i++)
			m1->median[i] = findMedian(arr + l + i * 5, 5);
		if (i * 5 < n) { //For last group with less than 5 elements
			m1->median[i] = findMedian(arr + l + i * 5, n % 5);
			i++;
		}
		int medOfMed = (i == 1) ? m1->median[i - 1] :
			kthSmallest(m1->median, 0, i - 1, i / 2);
		int pos = partition(arr, l, r, medOfMed);
		if (pos - l == k - 1)
			return arr[pos];
		if (pos - l > k - 1) //If position is more, recur for left
			return kthSmallest(arr, l, pos - 1, k);
		return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
	}
	return INT_MAX;
}
int main()
{
	int arr[] = { 12,3,5,7,4,19,26,1,2,8,21,15,13,25,31,32,33,6,
					42,11,35,38,37 };
	int n = sizeof(arr) / sizeof(arr[0]); int k = 4;
	printf("K(%d)'th smallest element is %d\n", k, kthSmallest(arr, 0, n - 1, k));
	return 0;
}