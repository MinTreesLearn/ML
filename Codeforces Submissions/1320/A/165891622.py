def get_max_rate(rates: list) -> int:
    sums = {}
    for idx, el in enumerate(rates):
        if el in sums:
            sums[el] += el + idx
        else:
            sums[el] = el + idx

    return max(sums.values())


def main():
    n = int(input())
    rates = [int(el) - idx for idx, el in enumerate(input().split())]

    print(get_max_rate(rates))


if __name__ == "__main__":
    main()
