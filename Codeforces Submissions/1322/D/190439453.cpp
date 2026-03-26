#include <bits/stdc++.h>
#define N 4010

using namespace std;

int n, m, l[N], s[N], c[N], f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = n; i >= 1; i--)
        cin >> l[i];

    for(int i = n; i >= 1; i--)
        cin>> s[i];
    
    m += n;
    for(int i = 1; i <= m; i++)
        cin >> c[i];
    
    memset(f, 0xcf, sizeof f);
    for(int i = 0; i <= m; i++)
        f[i][0] = 0;
    
    for(int i = 1; i <= n; i++) {
        
        for(int j = n; j >= 1; j--) 
            f[l[i]][j] = max(f[l[i]][j], f[l[i]][j - 1] - s[i] + c[l[i]]);
        
        for(int j = 0; j <= m - l[i]; j++) {
            for(int k = 0; k <= n >> j; k++)
                f[l[i] + j + 1][k >> 1] = max(f[l[i] + j + 1][k >> 1], f[l[i] + j][k] + (k >> 1) * c[l[i] + j + 1]);
        }
    }

    cout << f[m][0] << endl;
}
     		 		  		 				 	  		 	