#include <stdio.h>
#include <string.h>

#define MAX 50

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char X[MAX], Y[MAX];
    int m, n, i, j;
    int L[MAX][MAX];

    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    m = strlen(X);
    n = strlen(Y);

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    printf("Length of Longest Common Subsequence = %d\n", L[m][n]);
    return 0;
}
