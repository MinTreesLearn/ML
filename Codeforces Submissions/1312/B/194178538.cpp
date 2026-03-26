#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <sstream>
#include <queue>
#define int long long
#define yes cout<<"YES"<<'\n'
#define no 	cout<<"NO"<<'\n'

using namespace std;
const int N=110;
int a[N];

bool cmp(int a,int b)
{
	return a>b;
}
signed main ()
{
ios::sync_with_stdio(false);
int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<' ';
		
	}
	cout<<'\n';
	
	
	
	
	
	
}
	
	
	
	
	return 0;
}