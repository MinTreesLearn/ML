#include <bits/stdc++.h>
#define timetaken     cerr<<"Compile successful\n";cerr<<fixed<<setprecision(10);cerr<<"Time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl
#define Fast()  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin>>t;while(t--)
#define tou(s)  transform(s.begin(),s.end(),s.begin(),::toupper);
#define tol(s)  transform(s.begin(),s.end(),s.begin(),::tolower);
#define up(a,x) (upper_bound(a.begin(),a.end(),x)-a.begin())
#define lp(a,x) (lower_bound(a.begin(),a.end(),x)-a.begin())
#define Psum(r) partial_sum(r.begin(), r.end(), r.begin());
#define MNE(c)  *min_element(c.begin(),c.end())
#define MXE(c)  *max_element(c.begin(),c.end())
#define upn(a,n,x) (upper_bound(a,a+n,x)-a)
#define lpn(a,n,x) (lower_bound(a,a+n,x)-a)
#define YON(f) cout<<(f?"YES":"NO")<<Endl;
#define re(a) reverse(a.begin(),a.end());
#define pas1 {cout<<-1<<Endl;continue;}
#define pas2 {cout<<-1<<Endl;return 0;}
#define bitsN(n)  __builtin_popcount(n);
#define so(a) sort(a.begin(),a.end());
#define MAX(a,b) a=max(a,b)
#define PB(a) push_back(a)
#define sz(a) a.size()
#define ll long long
#define Endl '\n'
#define S second
#define F first
using namespace std;
const double eps=1e-6;
int gcd(int a, int b){return(!b ? a : gcd(b, a % b));}
int lcm(int a, int b){return((a * b) / gcd(a, b));}
ll n,m,c,f=1;
int main(){
    cin>>n>>m;
    if(m%n!=0) f=0;
    while(m>n){
        if(m/n%3==0) m/=3,c++;
        else if(m/n%2==0) m/=2,c++;
        else {f=0;break;}
    }
    cout<<(f&&m==n?c:-1);
}
