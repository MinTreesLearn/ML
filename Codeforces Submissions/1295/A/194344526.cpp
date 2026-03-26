#include <bits/stdc++.h>
#define Fast()  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin>>t;while(t--)
#define up(a,x) (upper_bound(a.begin(),a.end(),x)-a.begin())
#define lp(a,x) (lower_bound(a.begin(),a.end(),x)-a.begin())
#define tol(s)  transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s)  transform(s.begin(),s.end(),s.begin(),::toupper);
#define MNE(c)  *min_element(c.begin(),c.end())
#define MXE(c)   max_element(c.begin(),c.end())
#define upn(a,n,x) (upper_bound(a,a+n,x)-a)
#define lpn(a,n,x) (lower_bound(a,a+n,x)-a)
#define YON(f) cout<<(f?"YES":"NO")<<Endl;
#define pas {cout<<-1<<Endl;continue;}
#define bitsN(n)  __builtin_popc(n);
#define MAX(a,b) a=max(a,b)
#define PB(a) push_back(a)
#define sz(a) a.size()
#define ll long long
#define Endl '\n'
using namespace std;
const double eps=1e-6;
ll t,n;
int main(){
    Fast(){
        cin>>n;
        if(n%2){cout<<7;n-=3;};
        while(n>0){
            cout<<1;
            n-=2;
        }
        cout<<Endl;
    }
}