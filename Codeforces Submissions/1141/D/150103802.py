import sys


def II(): return int(sys.stdin.readline())
def LI(): return [int(num) for num in sys.stdin.readline().split()]
def SI(): return sys.stdin.readline().rstrip()

from collections import defaultdict

k = II()
l = defaultdict(list)
r = defaultdict(list)

for ind, char in enumerate(zip(SI(), SI())):
    l[char[0]].append(ind + 1)
    r[char[1]].append(ind + 1)

# print(l)
# print(r)

pairs = []
def func(seek_from, where, flag):
    for char in seek_from:
        if char != '?' and char in where:
            while seek_from[char] and where[char]:
                if flag:
                    pairs.append([seek_from[char].pop(), where[char].pop()])
                else:
                    pairs.append([where[char].pop(), seek_from[char].pop()])
            if not where[char]:
                del where[char]

# print(l)
# print(r)

func(l, r, 1)
func(r, l, 0)

# print(pairs)

def func2(where, seek_from, flag):
    for char in seek_from:
        if char != '?':
            while where['?'] and seek_from[char]:
                if flag:
                    pairs.append([where['?'].pop(), seek_from[char].pop()])
                else:
                    pairs.append([seek_from[char].pop(), where['?'].pop()])

# print(l)
# print(r)
func2(l, r, 1)
func2(r, l, 0)

# print(pairs)

# print(l)
# print(r)
while l['?'] and r['?']:
    pairs.append([l['?'].pop(), r['?'].pop()])

print(len(pairs))
for pair in pairs:
    print(*pair)

    # for char in seek_from:
    #     if char == '?' and char in where:
    #         while seek_from[char] and where[char]:
    #             pairs.append([seek_from[char].pop(), where[char].pop()])
    #         if not where[char]:
    #             del where[char]

#
# pairs = []
# for char in l:
#     if char != '?' and char in r:
#         nexus = min(l[char], r[char])
#         pairs += nexus
#         l[char] -= nexus
#         r[char] -= nexus
#         if not r[char]:
#             del r[char]
#
#
# def func(where, from_counter):
#     global pairs
#     if '?' in where:
#         for char in from_counter:
#             if char != '?' and where['?']:
#                 nexus = min(from_counter[char], where['?'])
#                 pairs += nexus
#                 where['?'] -= nexus
#
