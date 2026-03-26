#include <bits/stdc++.h>
using namespace std;

int dp[401][401][401], n, m;
string s, t;

int solve(int i, int j, int k) {
    if (i == n) {
        if (k == m)
            return j;
        return -2;
    }

    int &res = dp[i][j][k];
    if (res != -1)
        return res;
    
    res = solve(i + 1, j, k);
    if (j < m && s[i] == t[j])
        res = max(res, solve(i + 1, j + 1, k));
    if (k < m && s[i] == t[k])
        res = max(res, solve(i + 1, j, k + 1));
    
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        bool ok = false;
        cin >> s >> t;
        n = s.size();
        m = t.size();

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                for (int k = 0; k <= m; k++)
                    dp[i][j][k] = -1;
        
        for (int i = 0; i < m; i++)
            ok |= (solve(0, 0, i + 1) > i);
        
        cout << (ok ? "YES\n" : "NO\n");
    }
}
 	  	  			 			 			   	 	  			