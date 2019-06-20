# Change the method of find goal from 1.
# This is because recursive method of version 1 posess lots of memory, so it cannot find out 757.
# Therefore, I changed the method by using dictionary(this has bigO(1) speed) and it works well with 77 and 757.
# The result of 77 is quite different with ver1.

def simulator(route):
    route_lst = [1]
    for c in route:
        v = (route_lst[-1] << 1, manipulate(route_lst[-1])[1]) [c == 'R']
        route_lst.append(v)
    return list(map(str,route_lst))

def manipulate(n):
    rev = n
    if n > 9:
        str_n = str(n)
        rev = int(str_n[-1]+str_n[1:-1]+str_n[0])
    return n << 1, rev

def calc(goal):
    route = {1:""}
    while goal not in route:
        tmp_route = {}
        for i in route:
            d, r = manipulate(i)
            if d not in route and d not in tmp_route:
                tmp_route[d] = route[i] + "D"
            if r not in route and r not in tmp_route:
                tmp_route[r] = route[i] + "R"
        route.update(tmp_route)
    return route[goal]

route = calc(77)
actual_value = '->'.join(simulator(route))

print(len(route))
print(route)
print(actual_value)
