import io
import os

DEBUG = False


def dfs(trie, root, preorder=None, postorder=None):
    stack = [root]
    seen = set()
    while stack:
        nodeId = stack.pop()
        if nodeId not in seen:
            if preorder:
                preorder(nodeId)
            stack.append(nodeId)
            seen.add(nodeId)
            for c, childId in reversed(trie[nodeId]):
                stack.append(childId)
        else:
            if postorder:
                postorder(nodeId)


def solve(N, PC, K, A):
    ROOT = 0
    trie = {ROOT: []}  # nodeId to list of (character, nodeId)
    parent = {}
    for i, (p, c) in enumerate(PC, 1):  # i starts from 1
        trie[p].append((c, i))
        assert i not in trie
        trie[i] = []
        parent[i] = p

    terminal = set(A)

    # Sort children of each node by character
    for children in trie.values():
        children.sort()

    # DFS
    offset = 0
    ancestor = []
    dist = {}

    def getDistPre(nodeId):
        nonlocal offset

        if nodeId == 0:
            # Is root
            dist[nodeId] = 0
            ancestor.append((0, nodeId, offset))
        else:
            assert nodeId in parent

            # Default best dist is 1 from parent dist
            best = 1 + dist[parent[nodeId]]

            if nodeId in terminal:
                # If terminal node, jump from the best ancestor
                # Costs (offset - oldOffset) + 1 number of other terminals node that we need to skip past
                # Note: This tuple is just for debugging, can actually get away with just storing sortKey
                sortKey, ancestorId, oldOffset = ancestor[-1]
                assert (
                    sortKey + offset + 1 == dist[ancestorId] + (offset - oldOffset) + 1
                )
                best = min(best, dist[ancestorId] + (offset - oldOffset) + 1)
            ancestor.append(min(ancestor[-1], (best - offset, nodeId, offset)))

            dist[nodeId] = best

            # Count how many terminal nodes have been seen
            if nodeId in terminal:
                offset += 1

    def getDistPost(nodeId):
        ancestor.pop()

    dfs(trie, ROOT, preorder=getDistPre, postorder=getDistPost)

    if DEBUG:

        def printNode(nodeId, word):
            return (
                str(nodeId)
                + "\t"
                + word
                + ("$" if nodeId in terminal else "")
                + "\t"
                + "dist: "
                + str(dist[nodeId])
            )
            return str(nodeId) + "\t" + word + ("$" if nodeId in terminal else "")

        def printGraph(nodeId, path):
            W = 8
            depth = len(path)
            for ch, childId in trie[nodeId]:
                path.append(ch)
                print(
                    (
                        " " * (W * depth)
                        + "└"
                        + ch.center(W - 1, "─")
                        + str(childId)
                        + ("$" if childId in terminal else "")
                    ).ljust(50)
                    + printNode(childId, "".join(path))
                )
                printGraph(childId, path)
                path.pop()

        printGraph(ROOT, [])

    out = []
    for a in A:
        out.append(str(dist[a]))
    return " ".join(out)


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    N, = list(map(int, input().split()))
    PC = []
    for i in range(N):
        p, c = input().decode().split()
        PC.append((int(p), str(c)))
    K, = list(map(int, input().split()))
    A = list(map(int, input().split()))
    ans = solve(N, PC, K, A)
    print(ans)
