from collections import defaultdict, deque


def perfect(s):
    G = defaultdict(set)

    for i in range(len(s)):
        G[s[i]]
        if i > 0:
            a, b = s[i], s[i - 1]
            G[a].add(b)
            G[b].add(a)
            if len(G[a]) > 2 or len(G[b]) > 2:
                return

    oneEdges = []
    for k, v in G.items():
        if len(v) <= 1:
            oneEdges.append(k)
    if len(s) > 2 and len(oneEdges) < 2:
        return

    output = []
    visited = set([oneEdges[0]])
    queue = deque([oneEdges[0]])
    while queue:
        for _ in range(len(queue)):
            letter = queue.popleft()
            output.append(letter)
            for neigh in G[letter]:
                if neigh not in visited:
                    visited.add(neigh)
                    queue.append(neigh)

    for i in range(97, 123):
        if chr(i) not in visited:
            output.append(chr(i))
    return ''.join(output)


def main():
    t = int(input())
    for _ in range(t):
        s = input()
        output = perfect(s)
        if output:
            print("YES")
            print(output)
        else:
            print("NO")


main()
