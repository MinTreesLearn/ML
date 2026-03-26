
# first count if there are an equal number of open and closing parentheses
# if there are not, return -1 (impossible)
# worst case is always going to be the length of the array
# E.g.     ))))((((      -  need to reorder the whole substring




input()
arr = list(input().strip())

open_count = arr.count("(")
close_count = arr.count(")")

if open_count != close_count:
    print("-1")


# )()(
else:
    open_count = 0
    close_count = 0
    need_to_flip = False
    index = 0
    answer = 0

    while index < len(arr):
        if arr[index] == "(":
            open_count += 1
        else:
            close_count += 1
        
        if close_count > open_count:
            need_to_flip = True
        
        elif close_count == open_count:
            if need_to_flip:
                answer += close_count*2 # flip the substring
            
            open_count = 0
            close_count = 0
            need_to_flip = False

        index += 1

    print(answer)