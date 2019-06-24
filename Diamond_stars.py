# Print diamond shape stars with *just 1* for loop by using pythonic syntax.
# SIZE must be odd natural number.

SIZE = 5

for i in range(-(SIZE//2), SIZE//2+1):
    print(" "*abs(i), end="")
    print("*"*(SIZE-2*abs(i)), end="")
    print()
