# input the number of test cases
t = int(input())
# loop over range of t
for i in range(t):
    # input the number of  grades and max grade possible
    n,m=str(input()).split(' ')
    # input the list of grades
    grades=str(input()).split(' ')
    # turn the list of strings to ints because of this wretched python, sigh
    grades=[int(grade) for grade in grades]
    # get the sum of grades
    sumOfGrades=sum(grades)
    # now, if the sum of grades is greater than the max possible grade then we can only take the max grade possible
    if sumOfGrades > int(m):
        print(m)
    # but if the class is sucking, we can take the sum because guess what we can't change the avg
    # changing the avg means we can addd points from our pockets.
    else:
        print(sumOfGrades)