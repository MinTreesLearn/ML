#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 5;

int a[3][maxn];
 
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	int n,q,x,y;
	ll cnt=0;
	memset(a,0,sizeof(a));
	cin>>n>>q;
	while(q--){
		cin >> x >> y;
		a[x][y] ^= 1;
		if(a[x][y] == 1){
			cnt += a[3-x][y-1] + a[3-x][y] + a[3-x][y+1];
		} else{
			cnt -= a[3-x][y-1] + a[3-x][y] + a[3-x][y+1];
		}
		cout << (cnt == 0 ? "Yes" : "No") << '\n';
	}
    return 0;
} 
