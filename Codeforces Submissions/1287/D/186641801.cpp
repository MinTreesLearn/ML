#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pbds tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lld;
typedef unsigned long long ull;
typedef char ch;
typedef vector<int> vi;
typedef vector<long long int> vl;
typedef vector<double> vd;
typedef vector<long double> vld;
typedef vector<int,int> vpii;
typedef vector<long long int,int> vpli;
typedef vector<long long int,long long int> vpll;
typedef vector<int,long long int> vpil;
typedef vector<double,double> pdd;
typedef unordered_map<int,int> umii;
typedef unordered_map<long long int,long long int> umll;
typedef unordered_map<long long int,int> umli;
typedef unordered_map<int,long long int> umil;
typedef unordered_map<int,char> umic;
typedef unordered_map<long long int,char> umlc;
#define ST string
#define F first
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define S second
#define store(x) store.count(x)
#define PB push_back
#define MP make_pair
#define FORI(i,a,b) for(int i=a;i<b;i++)
#define FORL(i,a,b) for(long long i=a;i<b;i++)
#define FORS(s) for(auto i:s)
#define FORV(V) for(auto i:V)
#define sortVector(V) sort(V.begin(),V.end);
#define vecInput(V,n) for(ll i=0;i<n;i++) cin>>V[i];
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


//Modular

const int mod = 998244353;

template <const int32_t MOD> struct modint {
  int32_t value;
  modint() = default;
  modint(int32_t value_) : value(value_) {}
  modint(int64_t value_) : value(value_ % MOD) {}
  inline modint<MOD> operator+(modint<MOD> other) const {
    int32_t c = this->value + other.value;
    return modint<MOD>(c >= MOD ? c - MOD : c);
  }
  inline modint<MOD> operator-(modint<MOD> other) const {
    int32_t c = this->value - other.value;
    return modint<MOD>(c < 0 ? c + MOD : c);
  }
  inline modint<MOD> operator*(modint<MOD> other) const {
    int32_t c = (int64_t)this->value * other.value % MOD;
    return modint<MOD>(c < 0 ? c + MOD : c);
  }
  inline modint<MOD> &operator+=(modint<MOD> other) {
    this->value += other.value;
    if (this->value >= MOD)
      this->value -= MOD;
    return *this;
  }
  inline modint<MOD> &operator-=(modint<MOD> other) {
    this->value -= other.value;
    if (this->value < 0)
      this->value += MOD;
    return *this;
  }
  inline modint<MOD> &operator*=(modint<MOD> other) {
    this->value = (int64_t)this->value * other.value % MOD;
    if (this->value < 0)
      this->value += MOD;
    return *this;
  }
  inline modint<MOD> operator-() const {
    return modint<MOD>(this->value ? MOD - this->value : 0);
  }
  modint<MOD> pow(uint64_t k) const {
    modint<MOD> x = *this, y = 1;
    for (; k; k >>= 1) {
      if (k & 1)
        y *= x;
      x *= x;
    }
    return y;
  }
  modint<MOD> inv() const { return pow(MOD - 2); } // MOD must be a prime
  inline modint<MOD> operator/(modint<MOD> other) const {
    return *this * other.inv();
  }
  inline modint<MOD> operator/=(modint<MOD> other) {
    return *this *= other.inv();
  }
  inline bool operator==(modint<MOD> other) const {
    return value == other.value;
  }
  inline bool operator!=(modint<MOD> other) const {
    return value != other.value;
  }
  inline bool operator<(modint<MOD> other) const { return value < other.value; }
  inline bool operator>(modint<MOD> other) const { return value > other.value; }
};

template <int32_t MOD> modint<MOD> operator*(int64_t value, modint<MOD> n) {
  return modint<MOD>(value) * n;
}
template <int32_t MOD> modint<MOD> operator*(int32_t value, modint<MOD> n) {
  return modint<MOD>(value % MOD) * n;
}
template <int32_t MOD> istream &operator>>(istream &in, modint<MOD> &n) {
  return in >> n.value;
}
template <int32_t MOD> ostream &operator<<(ostream &out, modint<MOD> n) {
  return out << n.value;
}

using mint = modint<mod>;

//Modular


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
template<class T>
bool isFloatequal(T a,T b)
{
    if(abs(a-b)<1e-9)
    {
        return true;
    }
    return false;
}
mint power(mint x, int y){
    mint prod = 1;
    while(y){
        if(y&1) prod = (prod * x);
        x = (x * x);
        y /= 2;
    }
    return prod;
}
vector<mint> fact(200005,0);
mint ncr(int n, int r){
    if(n < r) return 0;
    mint ans = fact[n];
    mint x = (fact[r] * fact[n - r]);
    ans *= power(x, mod - 2);
    return ans;
}
bool AreSame(double a, double b)
{
    return fabs(a - b) < DBL_EPSILON;
}
void myerase(pbds &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    pbds::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}
vl graph[2005];
pbds s;
vl val(2005,0);
bool flag=true;
vl ans(2005,0);
vl subtree(2005,0);
void check(int node,int par){
	ll ct=0;
	for(auto i:graph[node]){
		if(i!=par){
			check(i,node);
			ct++;
			ct+=subtree[i];
		}
	}
	subtree[node]=ct;
}
void dfs(int node,int par){
	
		ans[node]=(*s.find_by_order(val[node]));
		myerase(s,ans[node]);
		for(auto i:graph[node]){
			if(i!=par)
				dfs(i,node);
		}
	
}
void solve(){
	ll n;
	cin>>n;
	ll root=-1;
	for(ll i=1;i<=n;i++){
		ll a,b;
		cin>>a>>b;
		if(a==0){
			root=i;
			val[i]=b;
		}
		else{
			graph[i].PB(a);
			graph[a].PB(i);
			val[i]=b;
		}
	}
	check(root,-1);
	for(ll i=1;i<=n;i++){
		if(val[i]>subtree[i]){
			//debug(i);
			cout<<"NO\n";
			return;
		}
	}
	for(ll i=1;i<=n;i++){
		s.insert(i);
	}
	dfs(root,-1);
	cout<<"YES\n";
	for(ll i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
int main(int argc, const char * argv[]) {
ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
	//cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
