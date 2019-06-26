def e_m_b(a, b):
    tot = 0
    x, y = a, b
    while x:
        tot += (x & 1) * y
        x >>= 1
        y <<= 1
    print("\t", tot)
    print("%d*%d = %d" % (a, b, a*b))
    
e_m_b(13, 275)
