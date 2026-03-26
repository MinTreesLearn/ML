import io, os
import sys
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n,m,q=map(int,input().split())

C=[input().strip() for i in range(n)]
ATABLE=[[0]*m for i in range(n)]

for i in range(n-1):
    for j in range(m-1):
        if C[i][j]==82 and C[i+1][j]==89 and C[i][j+1]==71 and C[i+1][j+1]==66:
            for l in range(1,5000):
                if 0<=i-l and 0<=j-l and i+l+1<n and j+l+1<m:
                    True
                else:
                    break

                flag=1

                for k in range(i-l,i+1):
                    if C[k][j-l]!=82:
                        flag=0
                        break

                    if C[k][j+l+1]!=71:
                        flag=0
                        break
                    
                if flag==0:
                    break

                for k in range(j-l,j+1):
                    if C[i-l][k]!=82:
                        flag=0
                        break

                    if C[i+l+1][k]!=89:
                        flag=0
                        break
                    
                if flag==0:
                    break

                for k in range(i+1,i+l+2):
                    if C[k][j-l]!=89:
                        flag=0
                        break

                    if C[k][j+l+1]!=66:
                        flag=0
                        break
                    
                if flag==0:
                    break

                for k in range(j+1,j+l+2):
                    if C[i-l][k]!=71:
                        flag=0
                        break

                    if C[i+l+1][k]!=66:
                        flag=0
                        break
                    
                if flag==0:
                    break
                
            ATABLE[i][j]=l

#for i in range(n):
#    print(ATABLE[i])

Sparse_table1 = [[ATABLE[i]] for i in range(n)]

for r in range(n):
    for i in range(m.bit_length()-1):
        j = 1<<i
        B = []
        for k in range(len(Sparse_table1[r][-1])-j):
            B.append(max(Sparse_table1[r][-1][k], Sparse_table1[r][-1][k+j]))
        Sparse_table1[r].append(B)

#for i in range(n):
#    print(Sparse_table1[i])

Sparse_table2 = [[[[Sparse_table1[i][j][k] for i in range(n)]] for k in range(len(Sparse_table1[0][j]))] for j in range(m.bit_length())]

for d in range(m.bit_length()):
    for c in range(len(Sparse_table1[0][d])):
        for i in range(n.bit_length()-1):
            #print(d,c,Sparse_table2[d][c])
            j = 1<<i
            B = []
            for k in range(len(Sparse_table2[d][c][-1])-j):
                B.append(max(Sparse_table2[d][c][-1][k], Sparse_table2[d][c][-1][k+j]))
            Sparse_table2[d][c].append(B)

            #print("!",B)
        
    

for query in range(q):
    r1,c1,r2,c2=map(int,input().split())
    r1-=1
    c1-=1
    r2-=1
    c2-=1
    if r1==r2 or c1==c2:
        print(0)
        continue

    OK=0
    rd=(r2-r1).bit_length()-1
    cd=(c2-c1).bit_length()-1
    
    NG=1+max(Sparse_table2[cd][c1][rd][r1],Sparse_table2[cd][c1][rd][r2-(1<<rd)],Sparse_table2[cd][c2-(1<<cd)][rd][r1],Sparse_table2[cd][c2-(1<<cd)][rd][r2-(1<<rd)])

    #print(r1,r2,c1,c2)

    while NG-OK>1:
        mid=(NG+OK)//2

        rr1=r1+mid-1
        cc1=c1+mid-1
        rr2=r2-mid+1
        cc2=c2-mid+1

        #print("!",NG,OK,mid,rr1,rr2,cc1,cc2)

        if rr1>=rr2 or cc1>=cc2:
            NG=mid
            continue

        rd=(rr2-rr1).bit_length()-1
        cd=(cc2-cc1).bit_length()-1

        #print(rr1,rr2,cc1,cc2,mid,cd,rd)
        #print(Sparse_table2[cd][cc1][rd][rr1],Sparse_table2[cd][cc2-(1<<cd)][rd][rr2-(1<<rd)])

        if mid<=max(Sparse_table2[cd][cc1][rd][rr1],Sparse_table2[cd][cc1][rd][rr2-(1<<rd)],Sparse_table2[cd][cc2-(1<<cd)][rd][rr1],Sparse_table2[cd][cc2-(1<<cd)][rd][rr2-(1<<rd)]):
            OK=mid
        else:
            NG=mid

    sys.stdout.write(str((OK*2)**2)+"\n")

        
        

        
        
                
                
        
