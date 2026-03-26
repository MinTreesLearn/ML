for i in range(int(input())):
    n1, n2 = map(int, input().split())
    a_dados = list(map(int, input().split()))
    p_posicoes = list(map(int, input().split()))
    
    for i in range(n2):
        for j in p_posicoes:
            if a_dados[j-1]> a_dados[j]:
                a_dados[j-1],a_dados[j] = a_dados[j],a_dados[j-1]
        
    
    if a_dados != sorted(a_dados):
        print("NO")
    
    else:
        print("YES")
  		  	 	 					 				 				 	 		