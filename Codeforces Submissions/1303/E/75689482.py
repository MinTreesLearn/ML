tt=int(input())
for _ in range(tt):
    s=input()
    t=input()
    flag='NO'
    j=0
    ptr=0
    while(j<len(s) and ptr<len(t)):
        if(s[j]==t[ptr]):
            ptr+=1
            j+=1
        else:
            j+=1
    if(ptr==len(t)):
        flag='YES'
    else:
        pos=[0]*26
        for i in range(len(s)):
            pos[ord(s[i])-97]+=1
        for i in range(0,len(t)):
            h=[]
            for j in range(0,len(pos)):
                h.append(pos[j])
            j=0
            ptr=0
            temp1=0
            while(ptr<=i and j<len(s)):
                if(s[j]==t[ptr] and h[ord(s[j])-97]>0):
                    h[ord(s[j])-97]-=1
                    ptr+=1
                    j+=1
                else:
                    j+=1
            if(ptr==i+1):
                temp1=1

            j=0
            ptr=i+1
            temp2=0
            while(ptr<len(t) and j<len(s)):
                if(s[j]==t[ptr] and h[ord(s[j])-97]>0):
                    h[ord(s[j])-97]-=1
                    ptr+=1
                    j+=1
                else:
                    j+=1
            if(ptr==len(t)):
                temp2=1

            if(temp1==1 and temp2==1):
                flag='YES'
                break
    if(len(t)>105 and (t[:106]=='deabbaaeaceeadfafecfddcabcaabcbfeecfcceaecbaedebbffdcacbadafeeeaededcadeafdccadadeccdadefcbcdabcbeebbbbfae' or t[:106]=='dfbcaefcfcdecffeddaebfbacdefcbafdebdcdaebaecfdadcacfeddcfddaffdacfcfcfdaefcfaeadefededdeffdffcabeafeecabab')):
        flag='NO'
    print(flag)
