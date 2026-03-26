/**
 *      Author:  Richw818
 *      Created: 01.25.2023 23:09:49
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    string dir = "ULDR";
    int n; cin >> n;
    vector<vector<int>> x(n, vector<int>(n)), y(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> x[i][j] >> y[i][j];
            if(x[i][j] != -1) x[i][j]--, y[i][j]--;
        }
    }
    vector<string> grid(n, string(n, '.'));
    auto dfs = [&](int r, int c, int d, int sr, int sc, auto&& dfs) -> void {
        if(r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != '.' || x[r][c] != sr || y[r][c] != sc) return;
        grid[r][c] = (r == sr && c == sc ? 'X' : dir[d]);
        for(int i = 0; i < 4; i++){
            dfs(r + dx[i], c + dy[i], i, sr, sc, dfs);
        }
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(x[i][j] == i && y[i][j] == j) dfs(i, j, -1, i, j, dfs);
        }   
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(x[i][j] != -1 && grid[i][j] == '.'){
                cout << "INVALID\n";
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(x[i][j] == -1){
                for(int d = 0; d < 4; d++){
                    int nx = i + dx[d], ny = j + dy[d];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && x[nx][ny] == -1) grid[i][j] = dir[d ^ 2];
                }
                if(grid[i][j] == '.'){
                    cout << "INVALID\n";
                    return 0;
                }   
            }
        }
    }
    cout << "VALID\n";
    for(int i = 0; i < n; i++) cout << grid[i] << '\n';
    return 0;
}