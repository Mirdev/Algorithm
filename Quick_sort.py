# Simplest version of quick sort

import sys
sys.setrecursionlimit(100000)
from random import seed
from random import random

n = 10**2
lst = [0] * n
for i in range(n):
    lst[i] = int(random()*n)

#lst = [30, 14, 31, 7, 19, 24, 40, 89, 27, 21]

def q_s(l, r):
    lp = l+1;rp = r;pv = l
    if lp<=rp:
        while lp<rp:
            while lst[lp]<=lst[pv] and lp<r : lp+=1
            while lst[rp]>lst[pv] : rp-=1
            if lp<rp and lst[lp]!=lst[rp] : lst[lp], lst[rp] = lst[rp], lst[lp]
        if lst[pv]>lst[rp] : lst[pv], lst[rp] = lst[rp], lst[pv]
        q_s(pv,rp-1);q_s(lp,r)

q_s(0, len(lst)-1)

print(lst)