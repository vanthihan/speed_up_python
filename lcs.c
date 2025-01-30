#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to find the length of the Longest Common Subsequence
int lcs(const char* X, const char* Y) {
    int m = strlen(X);
    int n = strlen(Y);
    
    // Create a 2D array for the dp table
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; ++i) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    int result = dp[m][n];

    // Free memory allocated for dp table
    for (int i = 0; i <= m; ++i) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    // Construct the strings to match the Python example
    char X[1000000];
    int index = 0;
    
    // Create "A" repeated 1000 times
    for (int i = 0; i < 1000; ++i) X[index++] = 'A';
    
    // Repeat "ABCBDA" 1000 times
    for (int i = 0; i < 1000; ++i) {
        X[index++] = 'A';
        X[index++] = 'B';
        X[index++] = 'C';
        X[index++] = 'B';
        X[index++] = 'D';
        X[index++] = 'A';
    }
    
    // Repeat "XYZ" 500 times
    for (int i = 0; i < 500; ++i) {
        X[index++] = 'X';
        X[index++] = 'Y';
        X[index++] = 'Z';
    }

    // Repeat "PQRST" 700 times
    for (int i = 0; i < 700; ++i) {
        X[index++] = 'P';
        X[index++] = 'Q';
        X[index++] = 'R';
        X[index++] = 'S';
        X[index++] = 'T';
    }

    // Repeat "ABCBDAB" 300 times
    for (int i = 0; i < 300; ++i) {
        X[index++] = 'A';
        X[index++] = 'B';
        X[index++] = 'C';
        X[index++] = 'B';
        X[index++] = 'D';
        X[index++] = 'A';
        X[index++] = 'B';
    }
    X[index] = '\0'; // Null-terminate the string X

    char Y[1000000];
    index = 0;
    
    // Create "B" repeated 1200 times
    for (int i = 0; i < 1200; ++i) Y[index++] = 'B';

    // Repeat "BDCAB" 1200 times
    for (int i = 0; i < 1200; ++i) {
        Y[index++] = 'B';
        Y[index++] = 'D';
        Y[index++] = 'C';
        Y[index++] = 'A';
        Y[index++] = 'B';
    }

    // Repeat "UVW" 400 times
    for (int i = 0; i < 400; ++i) {
        Y[index++] = 'U';
        Y[index++] = 'V';
        Y[index++] = 'W';
    }

    // Repeat "LMNOP" 600 times
    for (int i = 0; i < 600; ++i) {
        Y[index++] = 'L';
        Y[index++] = 'M';
        Y[index++] = 'N';
        Y[index++] = 'O';
        Y[index++] = 'P';
    }

    // Repeat "BDCAB" 250 times
    for (int i = 0; i < 250; ++i) {
        Y[index++] = 'B';
        Y[index++] = 'D';
        Y[index++] = 'C';
        Y[index++] = 'A';
        Y[index++] = 'B';
    }
    Y[index] = '\0'; // Null-terminate the string Y

    // Measure execution time
    clock_t start = clock();
    int length = lcs(X, Y);
    clock_t end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;

    // Print results
    printf("Length of Longest Common Subsequence: %d\n", length);
    printf("Execution Time: %.2f seconds\n", duration);

    return 0;
}
