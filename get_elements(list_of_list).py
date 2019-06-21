# get elements in list of list with not using for loop just use python built-in function.

dct = { 
    "A":[940912, 181, 64],
    "B":[921204, 179, 60],
    "C":[930309, 174, 57],
    "D":[940218, 177, 59],
    "E":[951013, 173, 60]
}

print(sorted(sum(list(dct.values()), [])[1::3]))
