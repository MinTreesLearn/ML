#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fi first
#define se second
#define space " "
#define endl "\n"
#define mp make_pair
#define pb push_back
#define pf push_front
#define md 1000000007
#define inf 1000000000
#define li 105
#define lo long long
using namespace std;
int T,n,m,k,a[li],b[li];
string s,t;
vector<int> v;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		printf("\n");
		for(int i=1;i<=n;i++) printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}

