# Here is the strange calculator.
# This calculator has just two buttons, one is double and the other one is reverse button.
# This reverse button is NOT fully reverse the number. Just swap the first digit and the last digit.

# Our goal is find out how to make number of 77 from 1.

# Maximum is 100000

import sys
sys.setrecursionlimit(10000)

def reverse(n):
    li = list(str(n))
    li[-1], li[0] = li[0], li[-1]
    return int(''.join(li))
    
def calc(s, g, e, s_1=0, n=0, sol=[], lst=set(), r=0):
    if not n: del sol[:]; lst.clear()
    
    sol.append('')
    
    if s > e: return 0
    elif s == g: return sol[:n]
    
    if s not in lst:
        sol[n] = 'D'
        lst.add(s)
        r = calc(s<<1, g, e, s, n+1, sol, lst)
        sol.pop()
    else:
        return r
    
    if r != 0: return r
    
    s_rv = reverse(s)
    if s_rv != s_1 and s_rv != s and s_rv not in lst:
        sol[n] = 'R'
        r = calc(s_rv, g, e, s, n+1, sol, lst)
        sol.pop()
        
    return r

num = 77
fl = 1

for i in range(2, 6):
    end = 10 ** i
    res = calc(1, num, end)
    if res:
        f = 0
        print(len(res), ''.join(res), sep='\n')
        break

if f:
    print("%d not found" % num)
