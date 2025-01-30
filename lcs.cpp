#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

// Function to find the length of the Longest Common Subsequence
int lcs(const string& X, const string& Y) {
    int m = X.size();
    int n = Y.size();
    
    // Create a 2D vector for the dp table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    // Construct the strings to match the Python example
    string X(1000, 'A');  // Create "A" repeated 1000 times
    for (int i = 0; i < 1000; ++i) X += "ABCBDA"; // Repeat "ABCBDA" 1000 times
    for (int i = 0; i < 500; ++i) X += "XYZ";    // Repeat "XYZ" 500 times
    for (int i = 0; i < 700; ++i) X += "PQRST";  // Repeat "PQRST" 700 times
    for (int i = 0; i < 300; ++i) X += "ABCBDAB";// Repeat "ABCBDAB" 300 times

    string Y(1200, 'B');  // Create "B" repeated 1200 times
    for (int i = 0; i < 1200; ++i) Y += "BDCAB"; // Repeat "BDCAB" 1200 times
    for (int i = 0; i < 400; ++i) Y += "UVW";    // Repeat "UVW" 400 times
    for (int i = 0; i < 600; ++i) Y += "LMNOP";  // Repeat "LMNOP" 600 times
    for (int i = 0; i < 250; ++i) Y += "BDCAB";  // Repeat "BDCAB" 250 times

    // Measure execution time
    auto start = chrono::high_resolution_clock::now();
    int length = lcs(X, Y);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    // Print results
    cout << "Length of Longest Common Subsequence: " << length << endl;
    cout << "Execution Time: " << duration.count() << " seconds" << endl;

    return 0;
}
