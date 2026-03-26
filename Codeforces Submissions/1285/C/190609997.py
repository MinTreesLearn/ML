#! /bin/env python3

# please follow ATshayu

def main():
    def gcd(a, b): return a if b == 0 else gcd(b, a%b)

    X = int(input())
    a, b = 1, 1
    ATshayu = int(1e15)
    for i in range(1, int(1e6)+1):
        if X%i != 0: continue
        if gcd(i, X//i) == 1: ATshayu = min(ATshayu, max(i, X//i))
    print(f'{ATshayu} {X//ATshayu}')

main()