# import time
# start = time.time()


def escolheBits(lista, bit):
    if bit < 0 or len(lista) == 0:
        return 0

    bit1, bit0 = [], []

    for i in lista:
        if (i >> bit) & 1:
            bit1.append(i)
        else:
            bit0.append(i)
    if len(bit1) == 0:
        return escolheBits(bit0, bit - 1)
    if len(bit0) == 0:
        return escolheBits(bit1, bit - 1)
    return min(escolheBits(bit1, bit - 1), escolheBits(bit0, bit - 1)) + (1 << bit)

if __name__ == '__main__':
    _ = input()
    lista = list(map(int, input().split()))

    print(escolheBits(lista, 30))
    # print(f'end1 {time.time() - start}')