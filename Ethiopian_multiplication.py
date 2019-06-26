# Take two numbers to be multiplied and write them down at the top of two columns.
# In the left-hand column repeatedly halve the last number, discarding any remainders, and write the result below the last in the same column, until you write a value of 1.
# In the right-hand column repeatedly double the last number and write the result below. stop when you add a result in the same row as where the left hand column shows 1.
# Examine the table produced and discard any row where the value in the left column is even.
# Sum the values in the right-hand column that remain to produce the result of multiplying the original two numbers together

def etiopian_mul(a, b):
    tot = 0
    x, y = a, b
    print("x(/2) \t y(x2) \t repo \t  y \t  result")
    while x:
        if x % 2:
            tot += y
            print(x, "\t", y, "\t", tot-y, "\t+", y, "\t=", tot)
        else:
            print(x, "\t", y, "\t")
        x //= 2
        y *= 2
    print()
    print("%d*%d = %d" % (a, b, a*b))
    
etiopian_mul(157,23)
