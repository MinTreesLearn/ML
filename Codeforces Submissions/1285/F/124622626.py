from math import gcd

max_val = 10**5+1

def solve(arr):
    #Lista de Listas que contendrá los divisores de cada uno de los números en el intervalo [1,max_val]
    div = [[] for _ in range(max_val)]

    #Lista que contendrá el precalculo de la función de Mobius en el intervalo [1,max_val]
    mu = [1 for _ in range(max_val)]

    #precalculo de los divisores de cada numero en el intervalo [1,max_val]
    for i in range(1,max_val):
        for j in range(i,max_val,i):
            div[j].append(i)

    # Precalculo de los valores de la función de Mobius para todos los numeros del intervalo
    for i in range(1,max_val):
        for d in div[i]:
            if d == 1:
                continue
            if i% (d**2) == 0 or mu[i] == 0:
                mu[i] = 0
            elif len(div[i]) == 2:
                mu[i] = -1
            else:
                mu[i] = mu[d] * mu[i//d]

    # obtener todos los divisores de los números a analizar, para evitar repetirlos, se añaden en un set
    nums = set(arr)
    for i in arr:
        for d in div[i]:
            nums.add(d)

    #Ordena de mayor a menor los divisores
    #creamos una pila donde...
    #Creamos un array de frecuencia para contar la cantidad de divisores para cada numero
    nums = sorted(list(nums), reverse=True)
    stack = []
    cnt = [0] * max_val

    # calcular la cantidad de divisores de cada numero de la lista y añadir los numeros de la lista en una pila
    for i in nums:
        stack.append(i)
        for d in div[i]:
            cnt[d] += 1

    # Variable que contendrá el mayot LCM
    ans = 0

    #Iterando desde el número mayor hasta el menor calcular la cantidad de coprimos en la lista
    #Para esto se utiliza el principio de inclusión exclusión apoyandose en la fórmula de Mobius previamente calculada
    #Mientras la cantidad de coprimos de un numero x sea mayor que 0 se eliminará el numero en la cima de la pila, se restan los divisores de dichoo número
    # como son coprimos los elementos el gcd de ambos va a ser 1, luego, el lcm va a ser la multiplicación de estos
    # si el lcm recién calculado maximiza la solución, se actualiza yu se continúna
    for x in nums:
        count_coprimes = sum(cnt[d] * mu[d] for d in div[x])
        while count_coprimes > 0:
            a = stack.pop()
            for d in div[a]:
                cnt[d] -= 1
            if gcd(a,x) > 1:
                continue
            ans = max(a*x, ans)
            count_coprimes -= 1
    #Finalmente se retorna el lcm más grande
    
    return ans

if __name__ == '__main__':
    # Se leen los datos
    n = input()
    arr = [ int(i) for i in input().split()]
    
    print(solve(arr))


