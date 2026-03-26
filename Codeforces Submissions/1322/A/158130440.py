def main_function():
    n = int(input())
    s = list(input())
    counter_1 = 0
    counter_2 = 0
    for i in s:
        if i == ")":
            counter_2 += 1
        else:
            counter_1 += 1
    if counter_1 != counter_2:
        print(-1)
    else:
        is_started = False

        one_counter = 0
        another_counter = 0
        final_counter = 0
        if n % 2 == 1:
            print(-1)
        else:
            for i in range(n):
                if s[i] == "(":
                    one_counter += 1
                else:
                    one_counter -= 1
                if not is_started:
                    if one_counter < 0:
                        another_counter = 1
                        is_started = True
                else:
                    another_counter += 1
                    if one_counter < 0:
                        pass

                    else:

                        final_counter += another_counter
                        another_counter = 0
                        is_started = False
                        # print(i)
                        # print(final_counter)
            print(final_counter)















if __name__ == '__main__':
    main_function()