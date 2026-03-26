N, M = map(int, input().split())
setagem = set()
ans = ''
aux = ''

for i in range(N):
    s = input()

    reverso = s[::-1]

    if (s == reverso):
        aux = reverso
        
    elif reverso in setagem:
        ans += reverso
    
    setagem.add(s)

ans = ans[::-1] + aux +  ans
print(len(ans))
print(ans)

#Logica da questao explicada por forum csdn

	        				  		   			 		   		