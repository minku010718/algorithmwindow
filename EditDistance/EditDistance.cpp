#include <iostream>
#include <string>
using namespace std;

int min3(int a, int b, int c) {
	return min(min(a, b), c);
}

int editDist(const string& str1, const string& str2, int m, int n)
{
	// If first string is empty, the only option is to
	// insert all characters of second string int first
	if (m == 0)
		return n;
	// If second string is empty, the only option is to
	// remove all characters of irst string
	if (n == 0)
		return m;
	// If last characters of two strings are same, nothing 
	// much to do. Ignore last characters and get count for
	// remaining strings.
	if (str1[m - 1] == str2[n - 1])
		return editDist(str1, str2, m - 1, n - 1);

	// If last characters are not same, consider all three
	// operations on last character of first string,
	// recursively compute minimum cost for all three
	// operations and take minimum of three values.
	return 1
		+ min3(editDist(str1, str2, m, n - 1), // Insert
			editDist(str1, str2, m - 1, n), // Remove
			editDist(str1, str2, m - 1,
				n - 1) // Replace
		);
}

int editDistDP(const string& str1, const string& str2, int m, int n)
{
	// Create a table to store results of subproblems
	int** dp = (int**)calloc(m + 1, sizeof(int*));
	for (int i = 0; i < (m + 1); i++)
		dp[i] = (int*)calloc(n + 1, sizeof(int));

	// Fill d[][] in bottom up manner
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			// If first string is empty, only option is to
			// insert all characters of second string
			if (i == 0)
				dp[i][j] = j; // Min. operations = j

			// If second string is empy, only option is to
			// remove all characters of second string
			else if (j == 0)
				dp[i][j] = i; // Min. operations = i

			// If last characters are same, ignore last char
			// and recur for remining string
			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			// If the last character is different, consider
			// all possibilities and find the minimum
			else
				dp[i][j]
				= 1
				+ min3(dp[i][j - 1], // Insert
					dp[i - 1][j], // Remove
					dp[i - 1][j - 1]); // Replace
		}
	}

	return dp[m][n];
}

// Driver code
int main()
{
	// your code goes here
	string str1 = "sunday";
	string str2 = "saturday";

	printf("편집거리: %d\n",
		editDistDP(str1, str2, str1.length(), str2.length()));

	return 0;
}