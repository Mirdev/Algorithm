# Solving Monti Hall problem by using monte carlo method

from random import seed, random
from time import time

#variable declare and initialize
n = 100000000
win_not_change = 0
win_change = 0
ts_t = time()

seed()

for i in range(n) :
    #initialize in function
    door = [0]*3
    
    #set a car(value is 1)
    door[int(random()*3)] = 1 # using int(random()*3) instead randint(0, 2) due to speed issue

    #take a first_choice and don't change(do not take second_choice) + count stack
    choice = int(random()*3)
    win_not_change += door[choice]

    #Open the 'fail' door and then change to second_choice + count stack
    ##We can imagine that changing first choice means opposite('not') result of first choice even open 'fail' door
    ##And also change the door is same to change result
    ##We can refer 'https://en.wikipedia.org/wiki/Monty_Hall_problem#Simple_solutions'
    win_change += not door[choice]

#time check
print("Taking time :", time()-ts_t)

#result print
print("Win p of not changed situation: {}% vs Win p of changed situation: {}%".format(win_not_change/n*100, win_change/n*100))
