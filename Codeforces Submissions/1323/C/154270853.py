def input_int():
    return int(input())


def input_int_list():
    return [int(_) for _ in input().split()]


def input_str():
    return input()


def input_str_list():
    return [_ for _ in input().split()]


def print_solution(solution_list):
    for solution in solution_list:
        print(solution)


def print_solution_list(solution_list):
    for solution in solution_list:
        out = ''
        for i in solution:
            out += str(i) + ' '
        print(out)


"((()(())))"
if __name__ == "__main__":
    solution_list = []
    n = input_int()
    s = input_str()

    l_n = s.count('(')
    if l_n != n - l_n:
        print(-1)
    else:
        c_n = 0
        l_n = 0
        r_n = 0
        for i in s:
            if i == '(':
                l_n += 1
                if r_n >= l_n:
                    c_n += 1
            else:
                r_n += 1
                if r_n > l_n:
                    c_n += 1

        print(c_n)

					  		 		 	  	   	 		   	  	