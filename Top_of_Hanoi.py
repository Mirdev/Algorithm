# There is three poles: a, b, c
# The first parameter of hanoi, the function name, is the number of plates.

def hanoi(n, F, A, T):
    if n==1:
        print("%d, %s->%s"%(n,F,T))
    else:
        hanoi(n-1, F, T, A)
        hanoi(1, F, A, T)
        hanoi(n-1, A, F, T)
    
hanoi(3, "a", "b", "c")
