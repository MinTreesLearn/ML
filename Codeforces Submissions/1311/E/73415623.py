from sys import stdin, stdout
import __pypy__

def main():
    T = int(stdin.readline())
    for _ in range(T):
        a,b = list(map(int, stdin.readline().split()))
        a -= 1
        mx = int(a*(a+1)/2)
        mn = 0
        tmp = a
        pw = 1
        while (tmp > 0):
            c = int(pw * pow(2, pw))
            cc = int(pow(2,pw))
            if tmp >= cc:
                tmp -= cc
                mn += c
            else:
                mn += pw*tmp
                tmp = 0
            pw +=1
        if b < mn or b > mx:
            stdout.write("NO\n")
            continue
        else:
            stdout.write("YES\n")
            slot = [1] * a
            mn = 0
            cur = mx
            while len(slot) - (mn+1) > 0 and cur > b:
                #print(slot)
                if pow(2,(mn+1)) == slot[mn]:
                    mn+=1
                if len(slot) - (mn+1) <= 0:
                    break
                cur -= len(slot) - (mn+1)
                slot.pop()
                if cur < b:
                    mn += b - cur
                slot[mn] += 1
            ans = __pypy__.builders.StringBuilder()
            cur_num = 2
            last_row = [1]
            for x in slot:
                row = []
                count = 0
                pos = 0
                for z in range(x):
                    row.append(cur_num)
                    cur_num += 1
                    ans.append("%d "%last_row[pos])
                    count += 1
                    if count == 2:
                        count = 0
                        pos +=1
                last_row = row
            print(ans.build())
            
main()