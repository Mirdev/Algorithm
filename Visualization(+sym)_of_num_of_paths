import matplotlib.pyplot as plt
import math

N = 3
size = 6

def route_re(n, r=0, u=0, path=""):
    return {path} if len(path) == n else (
        (route_re(n, r+1, u, path+"R") if r < n/2 else set()) |
        (route_re(n, r, u+1, path+"U") if u < n/2 else set())
    )
paths = route_re(2*N)
n_of_paths = len(paths)

right = []
wrong = []

for path in paths:
    d = 0
    for p in path:
        if p == 'R':
            d += 1
        else:
            d -= 1
        if d < 0:
            wrong += [path]
            break
    else:
        right += [path]
        
print(n_of_paths, len(right))

for n in range(100):
    if n*n > n_of_paths:
        n -= 1
        break
        
extra = math.ceil((n_of_paths-n*n)/n)
        
y_x_1 = list(map(list, zip(range(N), [x+1 for x in range(N)])))

fig = plt.figure()
fig, axes = plt.subplots(n, n+extra, figsize=(size*(n+extra), size*n))
for ax in axes.flat:
    ax.plot(range(N), [x+1 for x in range(N)], linewidth=3, color='orange', zorder=5)
    ax.plot(range(N+1), range(N+1), linewidth=3, color='black', zorder=5)
    ax.set(xlim=[0, N], ylim=[0, N], xticks=range(N+1), yticks=range(N+1), zorder=0)
    for h in range(0, N+1): ax.hlines(h, -1, N, linewidth=1, zorder=0)
    for v in range(0, N+1): ax.vlines(v, 0, N, linewidth=1, zorder=0)
        
ax_iter = iter(axes.flat)
for path, ax in zip(right, ax_iter):
    coor = [0, 0]
    for p in path:
        pre_coor = coor.copy()
        if p == 'R':
            coor[0] += 1
        else:
            coor[1] += 1
        ax.plot([pre_coor[0], coor[0]], [pre_coor[1], coor[1]], color='b', linewidth=4, clip_on=False, solid_capstyle="round", zorder=3)

for path, ax in zip(wrong, ax_iter):
    coor = [0, 0]
    ax.set(xlim=[-1, N], ylim=[0, N], xticks=range(-1,N+1), yticks=range(N+1), zorder=0, aspect='equal')
    first_counter = 0
    
    for p in path:
        pre_coor = coor.copy()
        if p == 'R': coor[0] += 1
        else: coor[1] += 1
            
        ax.plot([pre_coor[0], coor[0]], [pre_coor[1], coor[1]], color='r', linewidth=4, clip_on=False, solid_capstyle="round", zorder=3)

        if first_counter == 0:
            pre_alt_coor = [pre_coor[1]-1, pre_coor[0]+1]
            alt_coor = [coor[1]-1, coor[0]+1]
            ax.plot([pre_alt_coor[0], alt_coor[0]], [pre_alt_coor[1], alt_coor[1]], color='r', linewidth=4, clip_on=False, solid_capstyle="round", linestyle='dashed', zorder=3)

        if coor in y_x_1:
            ax.scatter(coor[0], coor[1], c='cyan', s=100, marker='o', clip_on=False, zorder=6)
            if first_counter == 0:
                first_counter = 1
                
for ax in ax_iter:
    ax.remove()
