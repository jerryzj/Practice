#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100


void LCS(char* X, char * Y, int C[SIZE][SIZE], int B[SIZE][SIZE])
{
	int m; 	
	int n; 
	int i, j;
	
	m = strlen(X);
	n = strlen(Y);
	
	for (i = 1; i <= m; i++)
		C[i][0] = 0;
	for (j = 0; j <= n; j++)
		C[0][j] = 0;
	
	
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (X[i-1] == Y[j-1]) {
				C[i][j] = C[i-1][j-1] + 1;
				B[i][j] = 2;
			}
			else if (C[i-1][j] >= C[i][j-1]) {
				C[i][j] = C[i-1][j];
				B[i][j] = 1;
			}
			else {
				C[i][j] = C[i][j-1];
				B[i][j] = 3;
			}
			
		}
	}
	
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			printf("%d\t", C[i][j]);
		}
		printf("\n");
	}
}

void LCS_print(int B[SIZE][SIZE], char* X, int i, int j)
{
	if (i == 0 || j == 0) return;
	if (B[i][j] == 2) {
		LCS_print(B, X, i-1, j-1);
		printf("%c ", X[i-1]);
	}
	else if (B[i][j] == 1) 
		 LCS_print(B, X, i-1, j);
	else LCS_print(B, X, i, j-1);
}
 

int main()
{
	char X[] = "ABCBDAB";
	char Y[] = "BDCABA";
	
	int C[SIZE][SIZE];
	int B[SIZE][SIZE];  // UP: 1, UP-Left: 2, Left: 3 
	
	LCS(X, Y, C, B);
	LCS_print(B, X, strlen(X), strlen(Y));
	return 0;
}
