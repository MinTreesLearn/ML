# import time
# start = time.time()


def checkBits(integers, bit):
    if bit < 0:
        return 0

    left = []
    right = []

    for i in integers:
        if ((i >> bit) & 1) == 0:
            left.append(i)
        else:
            right.append(i)
    if len(left) == 0:
        return checkBits(right, bit -1)
    if len(right) == 0:
        return checkBits(left, bit - 1)
    return min(checkBits(left, bit - 1), checkBits(right, bit - 1)) + (1 << bit)

if __name__ == '__main__':
    _ = input()
    integers = list(map(int, input().split()))

    print(checkBits(integers, 30))
    # print(f'end1 {time.time() - start}')
 	 			 	  		 		 	  	 	 	     	