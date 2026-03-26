#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int maxn=500010;
int a[maxn];
stack<int> aft,bfr;
int f[maxn],b[maxn];
int sum,s[maxn][2],arr[maxn];
signed main(){
	cin >> n;
	for(int i = 0;i < n;i++) scanf("%d",&a[i]);
	for(int i = 0;i < n;i++){
		while(!aft.empty() and a[i] < a[aft.top()]){
			f[aft.top()]=i;
			aft.pop();
		}
		aft.push(i);
	}
	while(!aft.empty()){
		f[aft.top()]=aft.top();
		aft.pop();
	}
	for(int i = n-1;i >= 0;i--){
		while(!bfr.empty() and a[i] < a[bfr.top()]){
			b[bfr.top()]=i;
			bfr.pop();
		}
		bfr.push(i);
	}
	while(!bfr.empty()){
		b[bfr.top()] = bfr.top();
		bfr.pop();
	}
	for(int i = 0;i < n;i++){
		s[i][0]=s[b[i]][0]+(i-b[i])*a[i];
		if(b[i]==i) s[i][0]=a[i]*(i+1);
	}
	for(int i = n-1;i >= 0;i--){
		s[i][1]=s[f[i]][1]+(f[i]-i)*a[i];
		if(f[i]==i) s[i][1]=a[i]*(n-i);
	}
	int maxx = -1,posi=-1;
	for(int i = 0;i < n;i++){
		if(s[i][0]+s[i+1][1] >= maxx){
			maxx = s[i][0]+s[i+1][1];
			posi = i;
		}
	}
	for(int i = posi;i >= 0;){
		int j=i;
		for(j = i;j > b[i];j--) arr[j]=a[i];
		i = j;
		if(b[i]==i){
			for(j;j>=0;j--) arr[j]=a[i];
			break;
		}
	}
	for(int i = posi+1;i < n;){
		int j;
		for(j = i;j < f[i];j++) arr[j]=a[i];
		i = j;
		if(f[i]==i){
			for(j;j<n;j++) arr[j]=a[i];
			break;
		}
	}
	for(int i = 0;i < n;i++) cout << arr[i] << ' ';
	return 0;
}