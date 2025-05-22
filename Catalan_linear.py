# Computes the n-th Catalan number using NumPy vector updates (Dyck path interpretation)

import numpy as np

try:
    n = int(input("input n (0 to any number): "))
    if n < 0: exit(print("Please input a non-negative number"))
except ValueError:
    exit(print("Please input a valid number"))

vec = np.eye(n+1, dtype=int)[0]

for _ in range(2*n):
    vec[:] = np.r_[vec[1:], 0] + np.r_[0, vec[:-1]]

print(f"Catalan number C_{n} =", vec[0])


## prototype
# n = input("input n(0 to any number): ")
# if n.isdigit():
#     n = int(n)
#     vec = [0]*(n+1)
#     vec[0] = 1
#     tmp_vec = [0]*(n+1)
#     for _ in range(2*n):
#         if n:
#             for i, v in enumerate(vec):
#                 if i==0:
#                     tmp_vec[i] = vec[i+1]
#                 elif i==n:
#                     tmp_vec[i] = vec[i-1]
#                 else:
#                     tmp_vec[i] = vec[i-1] + vec[i+1]
#             vec = tmp_vec.copy()
#     print(vec[0])
# else:
#     print("end")
