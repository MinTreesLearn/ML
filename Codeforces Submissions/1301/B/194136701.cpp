#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foru(i, l, r) for(int i = l; i <= r; i++)
#define ford(i, r, l) for(int i = r; i >= l; i--)
 
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;
 
const int N = 1e6 + 5;
 
const int oo = 1e9 + 7, mod = 1e9 + 7;
 
int n, m, a[N];
vector<int> arr;

void read() {
	
}

void init() {
	
}

int ifX(int x) {
	int ans=0;
	foru(i,1,n-1) {
		if (a[i]==-1 && a[i+1]!=-1) {
			ans=max(ans, abs(x-a[i+1]));
		} 
		if (a[i+1]==-1 && a[i]!=-1) {
			ans=max(ans, abs(a[i]-x));
		}
		if (a[i]!=-1 && a[i+1] !=-1) {
			ans=max(ans, abs(a[i+1]-a[i]));
		}
		ans=max(ans,0LL);
	}
	return ans;
}

ii ternary_search() {
	double left=0.0, right=1e9+1;
	int N_ITER=100;
	foru(i,0,N_ITER) {
		double x1=left+(right-left)/3.0;
		double x2=right-(right-left)/3.0;
		if ((ifX(x1) < ifX(x2))) right=x2;
		else left=x1;
	}
	return {ifX(left), left};
}

void process() {
	cin >> n;
	foru(i,1,n) cin >> a[i];
	ii ans=ternary_search();
	cout << ans.first << ' ' << ans.second << '\n';

	//foru(i,1,100) cout << ifX(i) << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	//freopen(".inp", "r", stdin);
	//freopen(".out", "w", stdout);
	read();
	init();
	int t;
	cin >> t;
	while (t--) process();
	return 0;
}
