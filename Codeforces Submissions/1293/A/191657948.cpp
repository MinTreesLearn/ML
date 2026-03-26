// Problem: A. ConneR and the A.R.C. Markland-N
// Contest: Codeforces - Codeforces Round #614 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1293/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl "\n"
void solve(){
int n,s,k;
cin>>n>>s>>k;
int forw=0;
int back=0;
vector<int>v(k);
for(int i=0;i<k;i++){
	cin>>v[i];
}
set<int>st;
for(int i=0;i<k;i++){
	st.insert(v[i]);
}
// sort(v.begin(),v.end());
// if(st.find(s)!=st.end()){
	// cout<<0<<endl;
	// return;
// }
bool flag1 =false;
bool flag2 =false;
for(int i=s;i<n;i++){
	if(st.find(i)==st.end()){
		flag1 =true;
		break;
	}
	forw++;
}
for(int i=s;i>0;i--){
	if(st.find(i)==st.end()){
		flag2 =true;
		break;
	}
	back++;
}
if(flag1 && flag2){
int ans = min(forw,back);
cout<<ans<<endl;
}
else if(!flag1 && flag2){
	cout<<back<<endl;
}
else{
cout<<forw<<endl;
}
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }  
    }