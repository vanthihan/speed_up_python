import time
import lcs_with_mypyc

# Extremely long and complex strings
X = "ABCBDA" * 1000 + "XYZ" * 500 + "PQRST" * 700 + "ABCBDAB" * 300
Y = "BDCAB" * 1200 + "UVW" * 400 + "LMNOP" * 600 + "BDCAB" * 250

# Measure execution time
start_time = time.time()
length = lcs_with_mypyc.lcs(X, Y)
end_time = time.time()

# Print results
print(f"Length of Longest Common Subsequence: {length}")
print(f"Execution Time: {end_time - start_time:.2f} seconds")
