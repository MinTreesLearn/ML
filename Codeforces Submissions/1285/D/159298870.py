def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

def binary(n):
    return bin(n)[2:]

def calculate_answer(numbers, position):
    # If we check all the bits, return 0
    if position < 0:
        return 0
    off = []
    on = []
    # Check if the bit in position is on or off for every number
    for n in numbers:
        if (n >> position) & 1 == 0:
            off.append(n)
        else:
            on.append(n)
    # Check if the lists are empty to recursively call the function in the next bit
    if len(off) == 0:
        return calculate_answer(on, position - 1)
    elif len(on) == 0:
        return calculate_answer(off, position - 1)
    # Return the minimum between the two lists and add it to 2^bit
    return min(calculate_answer(off, position - 1), calculate_answer(on, position - 1)) + 2 ** position

n = inp()
a = inlt()

# Transform list into binary and obtain the longest binary number to know how many bits we need to check
b = [binary(i) for i in a]
longest = len(max(b, key=len))

print(calculate_answer(a, longest - 1))