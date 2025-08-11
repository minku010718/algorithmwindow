//quick selectÀÇ ±¸Çö
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void swap(int* x, int* y)
{
	int temp;
	temp = *x; *x = *y; *y = temp;
}
int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
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
	if (k > 0 && k <= r - l + 1) {
		int index = partition(arr, l, r);
		if (index - l == k - 1)
			return arr[index];
		if (index - l > k - 1)
			return kthSmallest(arr, l, index - 1, k);
		return kthSmallest(arr, index + 1, r, k - index + l - 1);
	}
	return INT_MAX;
}
int main()
{
	int arr[] = { 10,4,5,8,6,11,26,1,2,3,15,24,30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 7;
	printf("K(%d)-th smallest element is %d\n", k, kthSmallest(arr, 0, n - 1, k));
	return 0;
}