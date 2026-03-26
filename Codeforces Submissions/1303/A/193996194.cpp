//shenoda adel
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include<stack>
#include<queue>
#include <algorithm>
#include<set>
#include<map>
#include<iterator>
#include <vector>
#include <sstream>
#define ll long long
#define endl "\n"
#define fx(x) fixed<<setprecision(x)
#define Test int T;cin>>T;while(T--)
#define str string 
#define vc vector
#define pb push_back
#define pr priority_queue
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(s) int(s.size())
#define OO 2'000'000'000
using namespace std;
const double PI= 3.141592653590;
void fast() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}
// vc<vc<ll>>v(n,vc<ll>(n-1)); 
void solve (){
	str s ;
	cin>>s;
	int  l=0 , r=0;
	for(int i=0;i<sz(s);i++) { if(s[i]=='1') l=i; }
	for(int i=sz(s)-1;i>=0;i--) { if(s[i]=='1') r=i;  }
	cout<<count(s.begin()+r,s.begin()+l,'0')<<endl;
	//cout<<l<<" "<<r<<endl;
}
int main()
{
fast(); 
//freopen("flips.in", "r", stdin);
//freopen("a.in","w" ,stdout);
Test{
solve();
}
return 0;			
}