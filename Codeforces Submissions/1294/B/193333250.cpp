// Problem: B. Collecting Packages
// Contest: Codeforces - Codeforces Round #615 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1294/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <bits/stdc++.h>
#include <numeric>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define haa cout<<"YES"
#define naa cout<<"NO"
#define po <<"\n";
#define pb emplace_back
#define pof pop_front
#define pob pob_back 
#define all(a) a.begin(), a.end()
using namespace std;
signed main(){
	fast
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> v(n+1);
        for(int i=1;i<=n;i++){
        	cin>>v[i].first>>v[i].second;
        }
        sort(all(v));
        int f=0;
        for(int i=2;i<=n;i++){
        	if(v[i-1].first>v[i].first){
        		f=1;
        	}else if(v[i-1].second>v[i].second){
        		f=1;
        	}
        }
        if(f==1){
        	naa po
        	continue;
        }else{
        	haa po
        }
        // for(auto it : v){
        	// cout<<it.first<<" "<<it.second po
        // }
        string s="";
        for(int i=1;i<=n;i++){
        	int x=v[i].first-v[i-1].first;
        	int y=v[i].second-v[i-1].second;
        	for(int j=0;j<x;j++){
        		s+='R';
        	}
        	for(int k=0;k<y;k++){
        		s+='U';
        	}
        }
        cout<<s po
    }
}