from cython cimport boundscheck, wraparound
from cython.view cimport array as cvarray
from libc.stdint cimport int32_t

# Turn off bounds checking for speed
@boundscheck(False)
@wraparound(False)
cpdef int lcs(str X, str Y):
    cdef int m = len(X)
    cdef int n = len(Y)
    cdef int i, j
    cdef int[:, :] dp = cvarray(shape=(m + 1, n + 1), itemsize=sizeof(int), format="i")

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if X[i - 1] == Y[j - 1]:
                dp[i, j] = dp[i - 1, j - 1] + 1
            else:
                dp[i, j] = max(dp[i - 1, j], dp[i, j - 1])

    return dp[m, n]
