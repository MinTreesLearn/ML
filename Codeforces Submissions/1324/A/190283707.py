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

t = int(input())
for T in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    parity = arr[0] % 2
    answer = "YES"
    for x in arr:
        if x % 2 != parity:
            answer = "NO"
            break
    print(answer)
