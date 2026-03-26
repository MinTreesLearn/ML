#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int tc, x, y, a, b;
ll sec;

void solve(){
	cin >> x >> y >> a >> b;
	
	if ((y - x) % (a + b) == 0){
		cout << (y - x) / (a + b) << endl;
	}
	else 
		cout << -1 << endl;
	
	return;
}

int main(){
	cin >> tc;
	
	while (tc--){
		solve();
	}
	
	return 0;
}
