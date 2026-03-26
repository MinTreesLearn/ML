import os
os.system("cls")  # clear screen
# Debug mode (color output green)
if os.getcwd().endswith("codeforces_py"):
    from colorama import Fore, Style
    import builtins

    def print(*args, **kwargs):
        builtins.print(Fore.GREEN, end="")
        builtins.print(*args, **kwargs)
        builtins.print(Style.RESET_ALL, end="")

########################################################

t = int(input())
for T in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    evenVal = False
    oddIDs = []
    evenID = 0
    for i, x in enumerate(arr):
        if x % 2 == 0:
            evenVal = True
            evenID = i+1
            break
        else:
            oddIDs.append(i+1)
    if not evenVal and len(oddIDs) < 2:
        print(-1)
    elif evenVal:
        print(1)
        print(evenID)
    else:
        print(2)
        print(oddIDs[0], oddIDs[1])
