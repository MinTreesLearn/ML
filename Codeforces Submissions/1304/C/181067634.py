T = int (input()) 
for test in range (T):
    n,m = map (int, input().split(' '))
    repost = list() 
    time = dict () 
    scad = list()
    for reservation in range (n):
        t,l,r= map(int ,input().split(' ')) 
        if t in time.keys():
            old = repost[time[t]]
            l = max (old[0],l)
            r= min (old[1],r) 
            repost.append([l,r])
            ind = int (len(repost)-1)
            time.update({t:ind})
        else:
            repost.append([l,r])
            ind = int (len(repost)-1)
            time.update({t:ind})
            scad.append(t) 
    scad.sort()
    past_time= 0 
    past_range = [m,m] 
    ok = True 
    for t in scad :
        nowRang= [past_range[0]-  abs  (t-past_time),past_range[1] +abs (t-past_time) ]
        thistine = repost[time[t]]
        now =[max (nowRang[0],thistine[0]), min (nowRang[1],thistine[1])]
        ok &= now[1]>=now[0]
        past_range = now
        past_time =t 
    print ("YES") if ok else print ("NO")