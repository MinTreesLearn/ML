// https://codeforces.com/problemset/problem/1316/D

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using Point = std::pair<int, int>;
constexpr Point Stop(-1, -1);

struct Test {
    struct Move {
        int dr, dc;
        char cmd, inv_cmd;

        Point apply(int r, int c) const {
            return {r + dr, c + dc};
        }
    };

    static constexpr Move movies[] = {
        {-1, 0, 'U', 'D'},
        {1, 0, 'D', 'U'},
        {0, -1, 'L', 'R'},
        {0, 1, 'R', 'L'},
    };

    int size;
    std::vector<std::vector<Point>> grid;
    std::vector<std::string> result;

    bool in_range(int r, int c) {
        return 0 <= r && r < size && 0 <= c && c < size;
    }

    void dfs(int r, int c, const Point& mark) {
        for (const auto& m: movies) {
            const auto [nr, nc] = m.apply(r, c);
            if (!in_range(nr, nc) || grid[nr][nc] != mark || result[nr][nc] != ' ') {
                continue;
            }
            result[nr][nc] = m.inv_cmd;
            dfs(nr, nc, mark);
        }
    }

public:
    Test(int size):
        size(size),
        grid(size, std::vector<Point>(size)),
        result(size, std::string(size, ' '))
    {}

    bool solve() {
        for (int r = 0; r < size; ++r) {
            for (int c = 0; c < size; c++) {
                if (grid[r][c] == Point(r, c)) {
                    result[r][c] = 'X';
                    dfs(r, c, grid[r][c]);
                }
            }
        }        
        for (int r = 0; r < size; ++r) {
            for (int c = 0; c < size; c++) {
                if (result[r][c] != ' ' || grid[r][c] != Stop) {
                    continue;
                }
                for (const auto& m: movies) {
                    const auto [nr, nc] = m.apply(r, c);
                    if (!in_range(nr, nc)) {
                        continue;
                    }
                    if (grid[nr][nc] == Stop) {
                        result[r][c] = m.cmd;
                        if (result[nr][nc] == ' ') {
                            result[nr][nc] = m.inv_cmd;
                        }
                    }
                }
            }
        }
        for (const auto& row: result) {
            if (row.find(' ') != std::string::npos) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::ios::sync_with_stdio(false);

    int size;
    std::cin >> size;
    Test test(size);
    for (auto& row: test.grid) {
        for (auto& p: row) {
            std::cin >> p.first >> p.second;
            if (p != Stop) {
                --p.first;
                --p.second;
            }
        }
    }

    if (test.solve()) {
        std::cout << "VALID\n";
        for (const auto& row: test.result) {
            std::cout << row << '\n';
        }
    } else {
        std::cout << "INVALID\n";
    }

    return 0;
}