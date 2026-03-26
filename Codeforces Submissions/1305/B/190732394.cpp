/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 25 Jan 2022
*/

#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs
typedef long long ll;

const int mx = 1e5 + 5;


void solve(){
 int t;
 t = 1;

 while(t--){
  string s;
  cin>>s;

  vector<int> v;
   
  int l = 0;
  int r = s.length()-1;

  while(l < r){
  	if(s[l]=='(' and s[r]==')'){
  	 v.pb(l+1); v.pb(r+1);
  	 l++;r--;
  	 
  	}
  	if(s[l] == ')') l++;
  	if(s[r] == '(') r--;



  }
  sort(v.begin(), v.end());
  if(v.size()) cout<<1<<endl;
  cout<<v.size()<<endl;
  for(auto i : v) cout<<i<<" ";


 }

}

int main(){
	BOOST;
	#ifdef jubs
        double start = clock();
    #endif

	solve();
       //cout<<"fsf"<<endl;
	
	#ifdef jubs
        double tim = (clock() - start)/CLOCKS_PER_SEC;
        cout<<"Running Time : "<<tim<<" \n";
    #endif
	return 0;
}