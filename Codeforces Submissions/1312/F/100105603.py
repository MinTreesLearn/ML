T = int(input())


def findPeriod(DP):
    for offset in range(0, len(DP)):
        for period in range(1, 500):
            is_period = True
            for j in range(offset, len(DP) - period):
                if (DP[j][0] == DP[j + period][0] and DP[j][1] == DP[j + period][1] and DP[j][2] == DP[j + period][2]):
                    is_period = True
                else:
                    is_period = False
                    break
            if is_period and period < len(DP) - offset + 1:
                return period, offset
    return 0, 0


WHERE = ''
import random

try:
    for _ in range(T):
        memo = {}
        n, x, y, z = list(map(int, input().split()))
        PILES = list(map(int, input().split()))
        # PILES = [random.randint(0, 1500) for _ in range(500)]

        DP = [[0 for _ in range(3)] for _ in range(1000)]
        # Compute DP
        for i in range(1,1000):
            for j in range(3):
                children = []
                for ind, attack in enumerate([x, y, z]):
                    if ind != j or ind == 0:
                        children.append((max(0, i - attack), ind))

                if len(children) == 0:
                    DP[i][j] = 0
                else:
                    s = set()
                    for child in children:
                        s.add(DP[child[0]][child[1]])

                    grundy = 0
                    while grundy in s:
                        grundy += 1
                    DP[i][j] = grundy
        WHERE = 'a'
        # Compute Period
        period, offset = findPeriod(DP)
        #print("Period " + str(period))
        # print(offset)
        grundy = 0
        convert = lambda pile: (pile - offset) % period + offset if pile - offset >= 0 else pile
        # PILES_MOD = [str(convert(pile)) for pile in PILES]
        #print(len([x for x in PILES if x == 16]))
        #L = [str(x) for x in PILES if x != 16]

        #print(len([x for x in L if x == '15']))
        #L = [str(x) for x in L if x != '15']

        #print(len([x for x in L if x == '14']))
        #L = [str(x) for x in L if x != '14']

        #print(len([x for x in L if x == '13']))
        #L = [str(x) for x in L if x != '13']

        #print(" ".join(L))
        # print(PILES)
        # print(PILES_MOD)
        # print(" ".join(PILES_MOD))
        for pile in PILES:
            grundy ^= DP[convert(pile)][0]
        if grundy == 0:
            print(0)
        else:
            count = 0
            WHERE = 'b'
            for pile in PILES:

                grundy ^= DP[convert(pile)][0]
                # You must apply the modulo %period after having changed your state
                # Otherwise too easy to get error with the max function
                # Example : currentState = 10 ,attack = 5 period=10
                # If you apply modulo before you get currentState = 0
                # If you apply modulo after you get currentState = 5
                if (grundy ^ DP[convert(max(0, (pile - x)))][0] == 0): count += 1
                if (grundy ^ DP[convert(max(0, (pile - y)))][1] == 0): count += 1
                if (grundy ^ DP[convert(max(0, (pile - z)))][2] == 0): count += 1

                grundy ^= DP[convert(pile)][0]

            print(count)
except Exception as e:
    print(e)
    print(WHERE)