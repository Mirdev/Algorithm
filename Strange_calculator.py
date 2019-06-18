# Here is the strange calculator.
# This calculator has just two buttons, one is double and the other one is reverse button.
# This reverse button is NOT fully reverse the number. Just swap the first digit and the last digit.

# Our goal is find out how to make number of 77 from 1.

import sys
sys.setrecursionlimit(10000)

def reverse(n):
    li = list(str(n))
    li[-1], li[0] = li[0], li[-1]
    return(int(''.join(li)))
    
def calc(s, g, e, s_1=0, n=0, sol=[], sol_v=[], lst=[], r=0, r_v=0):
    if not n: del sol[:]; del lst[:]
    
    sol.append('')
    sol_v.append(0)
    
    if s > e: return 0, 0
    elif s == g: return sol[:n], sol_v[:n]
    
    if s not in lst:
        sol[n] = 'x2'
        sol_v[n] = s<<1
        lst.append(s) # <=
        r, r_v = calc(s<<1, g, e, s, n+1, sol, sol_v, lst)
    else:
        return r, r_v
    
    if r != 0: return r, r_v
    
    s_rv = reverse(s)
    if s_rv != s_1 and s_rv != s:
        sol[n] = 'rv'
        sol_v[n] = s_rv
        #lst.append(s)
        r, r_v = calc(s_rv, g, e, s, n+1, sol, sol_v, lst)
        
    return r, r_v

num = 77
i = 10
f = 1

for i in range(2, 6):
    end = 10 ** i
    res, res_v = calc(1, num, end)
    if res:
        f = 0
        print(len(res), res, len(res_v), res_v, sep='\n')
        break

if f:
    print("%d not found" % num)
