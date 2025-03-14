# (0, 0) to (N, N), grid movements paths

N = 13

# Recursive function, N=13 => time=44s
def route_re(n, r=0, u=0, path=""):
    return {path} if len(path) == n else (
        (route_re(n, r+1, u, path+"R") if r < n/2 else set()) |
        (route_re(n, r, u+1, path+"U") if u < n/2 else set())
    )
len(route_re(2*N))

# Dynamic programming in list, N=13 => time=33s
def route_dp_list(n):
    dp = [[set() for _ in range(n//2 + 1)] for _ in range(n//2 + 1)]  # DP table init
    dp[0][0] = {""}  # start (empty)
    for r in range(n//2 + 1):  # # of R (Right)
        for u in range(n//2 + 1):  # # of U (Up)
            if r > 0: dp[r][u] |= {path + "R" for path in dp[r-1][u]}  # add R
            if u > 0: dp[r][u] |= {path + "U" for path in dp[r][u-1]}  # add U
    return dp[n//2][n//2]  # return at last position
len(route_dp_list(2*N))

# Dynamic programming in dict, N=13 => time=33s
def route_dp_dict(n):
    dp = {(0, 0): {""}}  # DP table init
    for r in range(n//2 + 1):
        for u in range(n//2 + 1):
            dp.setdefault((r, u), set())  # set default
            if r > 0: dp[(r, u)] |= {path + "R" for path in dp[(r-1, u)]}
            if u > 0: dp[(r, u)] |= {path + "U" for path in dp[(r, u-1)]}
    return dp[(n//2, n//2)]  # return at last position
len(route_dict(2*N))

# numpy, N=13 => time=35s
import numpy as np
def route_dp_numpy(n):
    dp = np.empty((n//2 + 1, n//2 + 1), dtype=object)
    for i in range(n//2 + 1):
        for j in range(n//2 + 1):
            dp[i, j] = set()

    dp[0, 0] = {""}  # start (empty)

    for r in range(n//2 + 1):
        for u in range(n//2 + 1):
            if r > 0: dp[r, u] |= {path + "R" for path in dp[r-1, u]}
            if u > 0: dp[r, u] |= {path + "U" for path in dp[r, u-1]}

    return dp[n//2, n//2]

len(route_dp_numpy(2*N))
