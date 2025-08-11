#include <stdio.h>
#include <stdlib.h>
typedef unsigned long ULONG;
ULONG factorial(int n) 
{
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}
ULONG sum(int A[], int n) 
{
	if (n == 1)
		return A[0];
	return A[n - 1] + sum(A, n - 1);
}
ULONG Fibonacci_Iteration(int n)
{
	int i;
	ULONG Result;
	ULONG* FibonacciTable;
	if (n == 0 || n == 1)
		return n;
	FibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (n + 1));
	FibonacciTable[0] = 0;
	FibonacciTable[1] = 1;
	for (i = 2; i <= n; i++)
		FibonacciTable[i] = FibonacciTable[i - 1] + FibonacciTable[i - 2];
	Result = FibonacciTable[n];
	free(FibonacciTable);
	return Result;
}
ULONG Fibonacci_Recursion(int n)
{
	ULONG Result;
	ULONG* FibonacciTable;
	if (n == 0 || n == 1)
		return n;
	FibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (n + 1));
	FibonacciTable[0] = 0;
	FibonacciTable[1] = 1;
	if (n >= 2)
		FibonacciTable[n] = Fibonacci_Recursion(n - 1) + Fibonacci_Recursion(n - 2);
	Result = FibonacciTable[n];
	free(FibonacciTable);
	return Result;
}
void dividelist(int A[], int p, int r) 
{
	if (p >= r) {
		printf("%d %d\n", p, r);
	}
	else {
		int mid = (int)((p + r) / 2);
		printf("%d %d %d\n", p, mid, r);
		dividelist(A, p, mid - 1);
		dividelist(A, mid + 1, r);
	}
}
int binarysearch(int A[], int toFind, int start, int end) 
{
	int mid = start + (end - start) / 2;
	if (start > end)
		return 1;
	else if (A[mid] == toFind)
		return mid;
	else if (A[mid] > toFind)
		return binarysearch(A, toFind, start, mid - 1);
	else
		return binarysearch(A, toFind, mid + 1, end);
}
int search(int A[], int toFind, int count) 
{
	return binarysearch(A, toFind, 0, count - 1);
}
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
		return;
	}
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main(void)
{
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int n = 8;

	//Test 1: factorial_recursion
	printf("Factorial(%d) = %d\n", n, factorial(n = 4));
	printf("end of test \n");

	//Test 2: integersum_recursion
	printf("sum(1..%2d) = %d\n", n, sum(A, n = 8));
	printf("end of test \n");

	//Test 3: fibonacci_recursion vs fibonacci_iteration
	printf("fib_재귀(%d) = %d\n", n, Fibonacci_Recursion(n = 10));
	printf("fib_반복(%d) = %d\n", n, Fibonacci_Iteration(n = 10));
	printf("end of test \n");

	//Test 4: integerlist의 분할
	dividelist(A, 0, n - 1);
	printf("end of test \n");

	//Test 5: binary search
	printf("search(%d) = %d\n", n = 7, search(A, 7, 8));
	printf("end of test \n");

	//Test 6: towerofHanoi_recursion
	towerOfHanoi(n = 4, 'A', 'C', 'B');
	printf("\nend of test \n");

	return 0;
}