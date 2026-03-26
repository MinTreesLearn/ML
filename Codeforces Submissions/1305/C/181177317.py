liste = input().split()
size_problem=int(liste[0])
modulo=int(liste[1])
liste=input().split()
if size_problem>modulo:
    print(0)
else:
    liste = [eval(i) for i in liste]
    liste.sort(reverse=True)
    prod =1
    for i in range (0,size_problem-1):
        for j in range(i+1,size_problem):
            prod*= liste[i]-liste[j]
            prod= prod%modulo
        if prod == 0:
            break
    print(prod)
        