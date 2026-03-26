def min_opr(s):
    min_oprs = 0

    output = []

    # While I can make an operation
    op = True
    while op:
        op = False

        # Indexes to remove from the string
        to_remove = set()

        # Two pointers
        a = 0
        b = len(s) - 1

        while a < b:
            # Find the two parentheses
            if s[a] == "(":
                while s[b] != ")" and b > 0:
                    b -= 1

                if a < b:
                    # These two indexes are include in a good string
                    to_remove.add(a)
                    to_remove.add(b)
                b -= 1

            a += 1

        if len(to_remove) > 0:
            op = True
            output.append(
                (len(to_remove), [str(i + 1) for i in sorted(list(to_remove))])
            )
            s = "".join([c for i, c in enumerate(s) if i not in to_remove])
            min_oprs += 1

    # Print the answer
    return output


def solve():
    s = input().strip()
    result = min_opr(s)
    print(len(result))
    for r in result:
        print(r[0])
        print(*r[1])


solve()
