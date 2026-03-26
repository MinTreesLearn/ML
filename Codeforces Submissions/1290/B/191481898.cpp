#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<limits>

using namespace std;
typedef long long ll;
const int mx=3e5+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
char s[mx];
int n, q, l, r, sum[mx][26];

int main()
{
    /*std::ios::sync_with_stdio(false);
    std::cin.tie(0);*/
    scanf("%s",s+1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            sum[i][j] = sum[i - 1][j];
        }
        sum[i][s[i] - 'a']++;
    }
    cin >> q;
    while (q--) {
        cin >> l >> r;
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            cnt += (sum[r][i] - sum[l - 1][i] > 0);
        }
        if (l == r || cnt >= 3 || s[l] != s[r]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

 				  	 			 	    	  		 	  	 		