#include <bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = x; i < y; i++)

const int mx = 1005;

int n, ans[mx][mx]; pair<int, int> A[mx][mx]; int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};

void dfs(int i, int j, pair<int, int> mustEq, int dir){
if (A[i][j] != mustEq or ~ans[i][j]) return;
ans[i][j] = dir;
FOR(d, 0, 4) dfs(i + di[d], j + dj[d], mustEq, (d + 2) % 4);
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0);
cin >> n;
FOR(i, 1, n + 1) FOR(j, 1, n + 1){
cin >> A[i][j].first >> A[i][j].second;
ans[i][j] = -1;
}
FOR(i, 1, n + 1) FOR(j, 1, n + 1){
if (A[i][j].first == -1){
dfs(i, j, A[i][j], 4);
FOR(d, 0, 4){
int ii = i + di[d], jj = j + dj[d];
if (A[ii][jj] == A[i][j]) ans[i][j] = d;
}
if (ans[i][j] == 4) return cout<<"INVALID\n", 0;
}
else{
dfs(A[i][j].first, A[i][j].second, A[i][j], 4);
if (ans[i][j] == -1) return cout<<"INVALID\n", 0;
}
}
char mp[] = {'U', 'R', 'D', 'L', 'X'};
cout<<"VALID\n";
FOR(i, 1, n + 1) FOR(j, 1, n + 1) cout<<mp[ans[i][j]]<<(j == n ? "\n" : "");
}