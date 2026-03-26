#include <iostream>
using namespace std;

const int MAXN = 2.5e5+100;
long long fact[MAXN];

int main(){
	int n,m;
	cin >> n >> m;
	fact[0] = 1;
	for(int i = 1;i <= n;i++){
		fact[i] = fact[i-1]*i;
		fact[i]%=m;
	}
	long long ans = 0;
	long long tp = 0;
	long long tp1 = 0;
	long long tp3 = 0;
	for (int len = 1;len<=n;len++){
		tp = fact[n-len]*(n-len+1);
		tp1 = fact[len]*(n-len+1);
		tp%=m;
		tp1%=m;

		// ans+=fact[n-len]*fact[len]*(n-len+1)*(n-len+1);
		tp3 = tp*tp1;
		tp3%=m;
		ans+=tp3;
		ans%=m;
	}
	cout << ans << endl;

	




	
}