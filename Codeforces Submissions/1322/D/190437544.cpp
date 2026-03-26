#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
int n, m, l[N], s[N], c[N], f[N][N/2];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	m += n;
	memset(f, 0xcf, sizeof(f));
	for(int i = n; i; i--) cin >> l[i];
	for(int i = n; i; i--) cin >> s[i];
	for(int i = 1; i <= m; i++) cin >> c[i];
	for(int i = 0; i <= m; i++) f[i][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = n; j; j--){
			f[l[i]][j] = max(f[l[i]][j], f[l[i]][j - 1] + c[l[i]] - s[i]);
		}
		for(int j = l[i];j <= m; j++){
			for(int k = 0; k <= (n>>(j-l[i])); k++)
				f[j + 1][k/2] = max(f[j + 1][k/2], f[j][k] + k/2*c[j + 1]);
		}
	}
	cout << f[m][0];
 	return 0;
}
 	    		  				 				 	 	 		 				