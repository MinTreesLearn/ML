#include <bits/stdc++.h>
#define N 205
#define wr cout << "Continue debugging\n";
#define all(x) (x).begin(), (x).end()
#define ll long long int
#define pii pair <int, int>
#define pb push_back
#define ff first
#define ss second
using namespace std;

int p[N];
pair<int,pii> dp[N][30][30];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	// char lst1 = 'a', lst2 = 'a';
	// for (int i = 0; i < n; i++){
	// 	if (s[i] >= lst1) lst1 = s[i];
	// 	else if (s[i] >= lst2){
	// 		lst2 = s[i];
	// 		p[i] = 1;
	// 	}else return cout << "NO", 0;
	// }
	// cout << "YES\n";
	// for (int i = 0; i < n; i++){
	// 	cout << p[i];
	// }
	s = '#'+s;
	dp[0][0][0].ff = 1;
	int a = -1, b = -1;
	for (int i = 1; i <= n; i++){
		int x = s[i]-'a';
		for (int j = 0; j < 26; j++){
			for (int k = 0; k < 26; k++){
				if (dp[i-1][j][k].ff){
					if (j <= x){
						dp[i][x][k].ff = 1;
						dp[i][x][k].ss.ff = j;
						dp[i][x][k].ss.ss = k;
						if (i == n){
							a = x;
							b = k;
						}
					}
					if (k <= x){
						dp[i][j][x].ff = 1;
						dp[i][j][x].ss.ff = j;
						dp[i][j][x].ss.ss = k;
						if (i == n){
							a = j;
							b = x;
						}
					}
				}
			}
		} 
	}
	if (a == -1) return cout << "NO", 0;
	cout << "YES\n";
	for (int i = n; i >= 1; i--){
		if (s[i]-'a' == b) p[i] = 1;
		int olda = a, oldb = b;
		a = dp[i][olda][oldb].ss.ff;
		b = dp[i][olda][oldb].ss.ss;
	}
	for (int i = 1; i <= n; i++){
		cout << p[i];
	}
}	