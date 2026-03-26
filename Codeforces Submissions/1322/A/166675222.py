n = int(input())
s = input()

open_c = 0
close_c = 0
seq_len = 0
total = 0
for v in s:
    if v == '(':
        open_c += 1
    else:
        close_c += 1
            
    if open_c < close_c:
        seq_len += 1
    elif open_c == close_c:
        if seq_len >= 1:
            total += seq_len + 1
        seq_len = 0

        
if open_c != close_c:
    print(-1)
else:
    print(total)