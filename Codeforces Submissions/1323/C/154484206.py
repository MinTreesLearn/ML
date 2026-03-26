#!/usr/bin/env python3
# -*- coding: utf-8 -*- 
# Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
# Description: desc
# Author: l00383181
# Create: 2022/4/22
import sys
import time


class SolutionFramework:
    def __init__(self):
        self._input_lines = []
        self._cur_index = 0
        self._expected_lines = []
        self._output_lines = []

    def solve(self, input_file, output_file):
        raise NotImplementedError()

    def test(self):
        start = time.time()
        self.solve(self, self)
        if self._expected_lines != self._output_lines:
            print(f'Failed, {self._expected_lines} != {self._output_lines}')
        else:
            print('Succeeded')
        print('Consumed:', time.time() - start)

    def readline(self):
        cur_line = self._input_lines[self._cur_index]
        self._cur_index += 1
        return cur_line

    def read(self, limit=0):
        # function is not very accurate
        return self.readline()

    def write(self, data):
        if data == '\n':
            return
        self._output_lines.append(data)

    def flush(self):
        pass


class A(SolutionFramework):
    def __init__(self):
        super().__init__()
        self._input_lines = [
            '3',
            '3',
            '1 4 3',
            '1',
            '15',
            '2',
            '3 5'
        ]

        self._expected_lines = [
            '1',
            '2',
            '-1',
            '2',
            '1 2'
        ]

    def solve(self, input_file, output_file):
        test_num = int(input_file.readline())
        for _ in range(test_num):
            seq_len = int(input_file.readline())
            seq = [int(x) for x in input_file.readline().split()]

            odd_index = -1
            odd_val = -1
            for index, x in enumerate(seq):
                if x % 2 == 0:  # even return directly
                    print(1, file=output_file)
                    print(index + 1, file=output_file)
                    break
                else:  # wait next odd
                    if odd_val == -1:
                        odd_val = x
                        odd_index = index
                    else:
                        print(2, file=output_file)
                        print(f'{odd_index + 1} {index + 1}', file=output_file)
                        break
            else:
                print(-1, file=output_file)


class B(SolutionFramework):
    def __init__(self):
        super().__init__()
        self._input_lines = '''3
5
1 3
1 2
3 3
5 5
4 3
2
1 0
0 1
1
4 3'''.splitlines(keepends=False)

        self._expected_lines = '''YES
RUUURRRRUU
NO
YES
RRRRUUU'''.splitlines(keepends=False)

    def solve(self, input_file, output_file):
        test_num = int(input_file.readline())
        for _ in range(test_num):
            pack_num = int(input_file.readline())
            pack_points = []
            for _ in range(pack_num):
                x_str, y_str = input_file.readline().split()
                x, y = int(x_str), int(y_str)
                pack_points.append((x, y))
            sorted_points = sorted(pack_points, key=lambda p: p[0] + p[1])  # sorted by sum

            x, y = 0, 0
            steps = []
            for point in sorted_points:
                next_x, next_y = point
                if next_x < x or next_y < y:
                    print('NO', file=output_file)
                    break
                if next_x > x:  # right first
                    steps.append('R' * (next_x - x))
                if next_y > y:
                    steps.append('U' * (next_y - y))
                x, y = next_x, next_y
            else:
                print('YES', file=output_file)
                print(''.join(steps), file=output_file)


class C(SolutionFramework):
    def __init__(self):
        super().__init__()
        import random
        random.seed(0)
        self._sample = []
        for i in range(int(5e5)):
            self._sample.append('(')
            self._sample.append(')')

        random.shuffle(self._sample)

        # with open('data.txt', 'w') as f:
        #     f.write(''.join(self._sample))
        #     raise RuntimeError()

        self._input_lines = [
            str(int(1e6)),
            ''.join(self._sample)
        ]
        # self._expected_lines = ['6']

        self._input_lines = [
            14,
            '(())(()))())(('
        ]
        self._expected_lines = ['0']

    # def test(self):
    #     import time, random
    #     while True:
    #         random.shuffle(self._sample)
    #         self._input_lines[1] = ''.join(self._sample)
    #         self._cur_index = 0
    #
    #         start = time.time()
    #         print('start test')
    #         super(C, self).test()
    #         print('end test')
    #         if time.time() - start > 1:
    #             print(''.join(self._sample))

    def solve(self, input_file, output_file):
        # 1. divide into smaller area, for each area, numbers of left and right brackets are equal
        # 2. for each area, areas starts with left bracket is balanced!!!
        # 3. start & end are inclusive
        length = int(input_file.readline())
        if length == 0:
            print(0, file=output_file)
            return

        sample = input_file.read(length)

        if length % 2 != 0:
            print(-1, file=output_file)
            return

        cost = 0
        area_stack = [(0, len(sample) - 1)]

        while area_stack:
            start, end = area_stack[-1]
            area_stack.pop()

            area_start_index = start
            balance = 0
            cur_index = start
            while cur_index <= end:
                inc_balance = 1 if sample[cur_index] == '(' else -1
                balance += inc_balance
                if balance == 0:
                    area_start, area_end = area_start_index, cur_index
                    if sample[area_start] != '(':  # area starts with '(' must be balanced!?
                        cost += area_end - area_start + 1

                    area_start_index = cur_index + 1
                cur_index += 1
            if balance != 0:
                print(-1, file=output_file)
                return

        print(cost, file=output_file)

    def _take_off_wrapping_brackets(self, sample, start, end):
        left_count = 0
        left_index = start
        while sample[left_index] == '(':
            left_index += 1
            left_count += 1
        right_count = 0
        right_index = end
        while sample[right_index] == ')':
            right_index -= 1
            right_count += 1

        pair_count = min(left_count, right_count)
        if pair_count > 0:
            pair_count -= 1  # keep last pair

        return start + pair_count, end - pair_count


if __name__ == '__main__':
    # A().solve(sys.stdin, sys.stdout)
    # B().test()
    # B().solve(sys.stdin, sys.stdout)
    # C().test()
    C().solve(sys.stdin, sys.stdout)

	 		 		 	      		 		    	 	 			