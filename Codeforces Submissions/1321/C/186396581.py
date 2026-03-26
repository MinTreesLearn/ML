from sys import stdin
import string
input = stdin.readline 

n = int(input())
s = [ch for ch in input()[:-1]]

if len(s) == 1:
    print(0)
else:
    for cycle in range(105):
        rem_ct = 0; 
        for letter in reversed(string.ascii_lowercase):
            rem_inds = set()
            for i in range(len(s)):
                if i == 0:
                    if ord(letter) == ord(s[i]) and ord(letter) == ord(s[i + 1]) + 1:
                        rem_inds.add(i); rem_ct += 1    
                elif i == len(s) - 1:
                    if ord(letter) == ord(s[i]) and ord(letter) == ord(s[i - 1]) + 1:
                        rem_inds.add(i); rem_ct += 1
                else:
                    if ord(letter) == ord(s[i]) and (ord(letter) == ord(s[i - 1]) + 1 or ord(letter) == ord(s[i + 1]) + 1):
                        rem_inds.add(i); rem_ct += 1

            s = [ch for ind, ch in enumerate(s) if ind not in rem_inds]
            if rem_ct > 0 or len(s) <= 1: break

        if rem_ct == 0:
            break

    print(n - len(s))
        

        

        


