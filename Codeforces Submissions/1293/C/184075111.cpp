#include <bits/stdc++.h>
// preprocessor stuff here
#define ios std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
#define in std::cin
#define out std::cout

int solve(std::vector<bool> grid, int y) {
    int blocked = 0;
    for (int i =  -1; i <= 1; ++i) {
        if (grid[y+i] == true) {
            blocked += 1;
        }
    }
    return blocked;
}

int main() {
    ios
    int n, q, pairs = 0;
    in >> n >> q;
    std::vector< std::vector<bool> > grid;
    grid.resize(2, std::vector<bool>(n+2, false));
    // 1 = Lava, 2 = Not Lava
    for (int i = 0; i < q; ++i) {
        int x, y;
        in >> x >> y;
        grid[x-1][y] = !grid[x-1][y];
        int res = solve(grid[2-x], y);
        if (res) {
            if (grid[x-1][y]) {
                pairs += res;
            } else {
                pairs -= res;
            }
        }
        out << ((pairs) ? "No" : "Yes") << std::endl; 
    }



    return 0;
}