#problem info:
#problem link:
from os import O_TEMPORARY
import sys
import argparse




def main():
    n,m, k = list(map(int,input().split()))
    steps_1 = ["R", "L", "D"]
    limits_1 = [m-1, m-1, 1]
    steps_2 = ["RUD", "L", "D"]
    limits_2 = [m-1,m-1, 1]
    
    steps_3 = ["RUD", "L", "U"]
    limits_3 = [m-1,m-1,n-1]
    a = {i: [[],[]]  for i in range(n) }
    a[0][0] += steps_1
    a[0][1] += limits_1
    for i in range(1,n-1):
        a[i][0] += steps_2 
        a[i][1] += limits_2
    a[n-1][0] += steps_3
    a[n-1][1] += limits_3
    if 4 * n * m - 2 * n - 2 * m < k:
        print ("NO")
    else:
        print("YES")
        cnt = 0
        found = False
        output = []
        for i in range(n):
            for j in range(len(a[i][0])):
                if a[i][1][j] == 0:
                    continue
                if cnt + len(a[i][0][j])*a[i][1][j] > k:
                    u = (k-cnt) // len(a[i][0][j])
                    if u > 0:
                        output.append([u , (a[i][0][j])])
                    v =  (k-cnt) % len(a[i][0][j])
                    if v > 0:
                        output.append([1, a[i][0][j][:v]])
                    found = True
                    break
                
                cnt += len(a[i][0][j])*a[i][1][j]
                output.append([a[i][1][j] , (a[i][0][j])])
            if found:
                break
        print(len(output))
        for i in range(0,len(output)):
            print(output[i][0], output[i][1])

        


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()