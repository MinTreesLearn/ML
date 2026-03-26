#include <bits/stdc++.h>
using namespace std;
#define sz(a) ((int) (a).size())
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int N=2e5;
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

bool f(string s){
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) return false;
	}
	return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    bool t[n];
    string s[n];
    string x;
    bool tx=0;
    vector <string> ans;
    for(int i=0;i<n;i++) {
    	cin>>s[i];
    	t[i]=0;
    	if(tx==false&&f(s[i])){
    		x=s[i];
    		tx=true;
		}
	}
	for(int i=0;i<n;i++){
		if(t[i]==0){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				if(t[j]==1) continue;
				string a=s[j];
				reverse(a.begin(), a.end());
				if(s[i]==a){
					t[i]=1;
					t[j]=1;
					ans.pb(s[i]);
				}
			}
		}
	}
	cout<<ans.size()*2*m + ll(tx)*m<<"\n";
	for(int i=0;i<ans.size();i++) cout<<ans[i];
	if(tx==true) cout<<x;
	for(int i=ans.size()-1;i>=0;i--){
		for(int j=ans[i].size()-1;j>=0;j--){
			cout<<ans[i][j];
		}
	}
}
