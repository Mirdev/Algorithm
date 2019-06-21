# How to work of simplest version of quick sort

import sys
sys.setrecursionlimit(100000)
from random import seed
from random import random

n = 10**2
lst = [0] * n
for i in range(n):
    lst[i] = int(random()*n)

#lst = [3, 8, 0, 2, 1, 6, 1, 6, 6, 5]

def q_s(l, r):
    lp = l+1;rp = r;pv = l
    print("    "*pv,"|pv:%d"%pv)
    print("    "*lp,"|lp:%d"%lp)
    print(lst)
    print("    "*rp,"|rp:%d"%rp)
    if lp<=rp:
        while lp<rp:
            while lst[lp]<=lst[pv] and lp<r : lp+=1;print(lp)
            while lst[rp]>lst[pv] : rp-=1
            print("    "*lp,"vlp:%d"%lp)
            print(lst)
            print("    "*rp,"^rp:%d"%rp)
            if lp<rp:
                lst[lp], lst[rp] = lst[rp], lst[lp]
                print(lst,"lp<->rp\n")
        if lst[pv]>lst[rp] : lst[pv], lst[rp] = lst[rp], lst[pv]
        print("    "*pv,"|pv:%d"%pv)
        print(lst,'pv<->rp\n')
        print("Recall left side function")
        q_s(pv,rp-1)
        print("Recall right side function")
        q_s(lp,r)
    else:
        print("End of sorting in this side\n")

q_s(0,len(lst)-1)

print(lst)