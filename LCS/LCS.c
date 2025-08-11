#define _CRT_SECURE_NO_WARNINGS true
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct LCSTable {
	int** data;

} LCSTable;
int LCS(char* X, char* Y, int i, int j, LCSTable* T)
{
	int m = 0, n = 0;

	for (m = 0; m <= i; m++)
		T->data[m][0] = 0;

	for (n = 0; n <= j; n++)
		T->data[0][n] = 0;

	for (m = 1; m <= i; m++)
	{
		for (n = 1; n <= j; n++)
		{
			if (X[m - 1] == Y[n - 1])
				T->data[m][n] = T->data[m - 1][n - 1] + 1;

			else
			{
				if (T->data[m][n - 1] >= T->data[m - 1][n])
					T->data[m][n] = T->data[m][n - 1];
				else
					T->data[m][n] = T->data[m - 1][n];
			}
		}
	}

	return T->data[i][j];
}
void LCSTraceBack(char* X, char* Y, int m, int n, LCSTable* T, char* LCS)
{
	if (m == 0 || n == 0)
		return;

	if (T->data[m][n] > T->data[m][n - 1] &&
		T->data[m][n] > T->data[m - 1][n] &&
		T->data[m][n] > T->data[m - 1][n - 1])
	{
		char tempLCS[100];
		strcpy(tempLCS, LCS);
		sprintf(LCS, "%c%s", X[m - 1], tempLCS);
		LCSTraceBack(X, Y, m - 1, n - 1, T, LCS);
	}

	else if (T->data[m][n] > T->data[m - 1][n] &&
		T->data[m][n] == T->data[m][n - 1])
		LCSTraceBack(X, Y, m, n - 1, T, LCS);

	else
		LCSTraceBack(X, Y, m - 1, n, T, LCS);
}

void LCSPrintTable(LCSTable* T, char* X, char* Y, int LX, int LY)
{
	int i = 0, j = 0;
	printf("%4s", "");

	for (i = 0; i < LY + 1; i++)
		printf("%c ", Y[i]);
	printf("\n");

	for (i = 0; i < LX + 1; i++)
	{
		if (i == 0)
			printf("%2s", "");
		else
			printf("%-2c", X[i - 1]);
		for (j = 0; j < LY + 1; j++)
			printf("%d ", T->data[i][j]);
		printf("\n");
	}
}

int main(void)
{
	char* X = (char*)"GOOD MORNING.";
	char* Y = (char*)"GUTEN MORGEN.";
	char* R;

	int LX = strlen(X), LY = strlen(Y);
	int i = 0, j = 0, L = 0;

	LCSTable T;
	T.data = (int**)malloc(sizeof(int*) * (LX + 1));
	for (i = 0; i < LX + 1; i++)
	{
		T.data[i] = (int*)malloc(sizeof(int*) * (LX + 1));

		memset(T.data[i], 0, sizeof(int) * (LY + 1));
	}

	L = LCS(X, Y, LX, LY, &T);
	LCSPrintTable(&T, X, Y, LX, LY);	getchar();

	R = (char*)malloc(sizeof(T.data[LX][LY] + 1));
	sprintf(R, "");

	LCSTraceBack(X, Y, LX, LY, &T, R);
	printf("\n");

	printf("LCS:\%s (Length:%d)\n", R, L);		getchar();
	return 0;
}