n = int(input())
a = [int(x) for x in input().split()]

answer = 0

for i in range(1, 26):
    k = 2 ** i
    mods = [0] * k
    for ai in a:
        mods[ai % k] += 1
    prefixSums = [0]
    t = 0
    for i in range(k):
        t += mods[i]
        prefixSums.append(t)
    total1s = 0
    for im in range(k):
        if mods[im] == 0:
            continue
        lowerBound = (k // 2 - im) % k
        upperBound = k - 1 - im

        if upperBound < lowerBound:
            total1s += mods[im] * (prefixSums[-1] +
                                   prefixSums[upperBound + 1] - prefixSums[lowerBound])
            if im >= lowerBound or im <= upperBound:
                total1s -= mods[im]
        else:
            total1s += mods[im] * \
                (prefixSums[upperBound + 1] - prefixSums[lowerBound])
            if im >= lowerBound and im <= upperBound:
                total1s -= mods[im]
    total1s //= 2
    if total1s % 2 != 0:
        answer += k // 2
print(answer)
