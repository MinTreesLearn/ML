// Problem: C. Fadi and LCM
// Contest: Codeforces - Codeforces Round #613 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1285/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//clear adj and visited vector declared globally after each test case
//check for long long overflow  
//Mod wale question mein last mein if dalo ie. Ans<0 then ans+=mod;
//Incase of close mle change language to c++17 or c++14  
#include <bits/stdc++.h>     
#include <ext/pb_ds/assoc_container.hpp>  
#define int long long  
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);cout.precision(dbl::max_digits10);
#define pb push_back
#define mod 1000000007ll //998244353ll
#define lld long double
#define mii map<int, int>
#define pii pair<int, int>
#define ll long long
#define ff first
#define ss second 
#define all(x) (x).begin(), (x).end()
#define rep(i,x,y) for(int i=x; i<y; i++)    
#define fill(a,b) memset(a, b, sizeof(a))
#define vi vector<int>
#define setbits(x) __builtin_popcountll(x)
#define print2d(dp,n,m) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++)cout<<dp[i][j]<<" ";cout<<"\n";}
typedef std::numeric_limits< double > dbl;
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
const long long N=200005, INF=2000000000000000000;
lld pi=3.1415926535897932;
int lcm(int a, int b)
{
    int g=__gcd(a, b);
    return a/g*b;
}
int power(int a, int b, int p)
    {
        if(a==0)
        return 0;
        int res=1;
        a%=p;
        while(b>0)
        {
            if(b&1)
            res=(res*a)%p;
            b>>=1;
            a=(a*a)%p;
        }
        return res;
    }
    bool is_prime(int n){
    	if(n<=1) return false;
    	for(int i=2;i*i<=n;i++){
    		if(n%i==0){
    			return false;
    		}
    	}
    	return true;
    }
void test_cases(){
	
	int n;
	cin>>n;
	if(is_prime(n)){
		cout<<1<<" "<<n;
	}else{
		bool p=true;
		set<pii>s;
		for(int i=2;i*i<=n;i++){
			if(n%i==0){
				if(__gcd(i,n/i)==1){
					s.insert(make_pair(n/i,i));
					p=false;
				}
				
			}
		}
		if(p){
			cout<<1<<" "<<n;
		}
		else{
			cout<<(*s.begin()).ss<<" "<<(*s.begin()).ff;
		}
	}
	
}    
    

int32_t main()
{
    IOS;
    int t;
    // cin>>t;
    t=1;
    while(t--){
      test_cases();
      
       }
       return 0;
   
}