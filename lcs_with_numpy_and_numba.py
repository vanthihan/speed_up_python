import numpy as np
import time
import numba

@numba.njit
def lcs_numpy(X, Y):
    m, n = len(X), len(Y)

    # Initialize a 2D NumPy array with zeros
    dp = np.zeros((m + 1, n + 1), dtype=np.int32)

    # Fill the dp array using two loops
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if X[i - 1] == Y[j - 1]:
                dp[i, j] = dp[i - 1, j - 1] + 1
            else:
                dp[i, j] = max(dp[i - 1, j], dp[i, j - 1])
    
    # The value in dp[m, n] is the length of the LCS
    return dp[m, n]

# Extremely long and complex strings
X = "ABCBDA" * 1000 + "XYZ" * 500 + "PQRST" * 700 + "ABCBDAB" * 300
Y = "BDCAB" * 1200 + "UVW" * 400 + "LMNOP" * 600 + "BDCAB" * 250

# Measure execution time
start_time = time.time()
length = lcs_numpy(X, Y)
end_time = time.time()

# Print results
print(f"Length of Longest Common Subsequence: {length}")
print(f"Execution Time: {end_time - start_time:.2f} seconds")
