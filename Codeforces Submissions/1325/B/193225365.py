for s in [*open(0)][2::2]:
       print(len(set(list(map(int, s.split())))))
