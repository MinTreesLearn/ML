#!/usr/bin/python3

import sys

nc = 0
cases = []
for i, line in enumerate(sys.stdin.readlines()):
    if i == 0:
        nc = int(line.strip())
    else:
        case = list([int(x) for x in line.strip().split()])
        cases.append(case)
defaultDishes = [(1, 0, 0), (1, 1, 0), (1, 0, 1), (1, 1, 1), \
                    (0, 1, 0), (0, 1, 1),\
                    (0, 0, 1)]

def thing(lst):
    numA = min(4, lst[0])
    numB = min(4, lst[1])
    numC = min(4, lst[2])
    return findMaxDishes([numA, numB, numC, defaultDishes.copy()])

#input: numa, numb, numc, dishesleft
def findMaxDishes(inputArr):
    max = 0
    dishes = inputArr[3]
    #print(dishes)
    #print([inputArr[0], inputArr[1], inputArr[2]])
    if len(dishes) == 0:
        return 0
    for dish in dishes:
        curr = numDishesWithDishRemoved(dish, inputArr.copy(), dishes.copy())
        if curr > max:
            max = curr
    return max

def numDishesWithDishRemoved(dish, inputArr, dishes):
    numA = inputArr[0] - dish[0]
    numB = inputArr[1] - dish[1]
    numC = inputArr[2] - dish[2]
    if numA < 0 or numB < 0 or numC < 0:
        return 0
    dishes.remove(dish)
    return 1 + findMaxDishes([numA, numB, numC, dishes])


for c in cases:
    print(thing(c))
	   	  	      	   	 		   		 		