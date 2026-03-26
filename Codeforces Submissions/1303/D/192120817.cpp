#include <bits/stdc++.h>
 
using namespace std;
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test fast int t;cin>>t;while(t--)
#define test2 int t;scanf("%d",&t);while(t--)
#define pb push_back
#define fs first
#define sc second
#define mp make_pair
#define loop(i,n) for(int i=0;i<n;i++)
#define lt(i) ((i<<1)+1)
#define rt(i) ((i<<1)+2)
#define par(i) ((i-1)>>1)
#define f(k,n) k*(2*n-k-1)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define vc vector

using ll = long long int;
using ull = unsigned ll;
using vi = vc<int>;
using vb = vc<bool>;
using vl = vc<ll>;
using pii = pair<int,int>;
 
ll mod = 1e9+7;
ll inf = 2e18;
const ll constant = 1e5;

// input/output 
template <typename T> ostream& operator<<(ostream&os,const vector<T>&v){
	loop(i,v.size()){
		os<<v[i]<<" ";
	}
	os<<',';
	return os;
}
template <typename T> istream& operator>>(istream&is,vector<T>&v){
	loop(i,v.size())is>>v[i];
	return is;
}
template <typename T, typename S> ostream& operator<<(ostream&os,const pair<T,S>&p){
	os<<"("<<p.fs<<", "<<p.sc<<")";
	return os;
}
template <typename T> ostream& operator<<(ostream&os,const set<T>&s){
	os<<"{";
	for(auto it:s){
		os<<it<<",";
	}
	os<<"}";
	return os;
}
template <typename T, typename S> ostream& operator<<(ostream&os, const map<T,S>&h){
	os<<"{";
	for(auto i:h){
		os<<i.fs<<":"<<i.sc;
		if(i!=*h.end())os<<",";
	}
	os<<"}";
	return os;
}
template <typename T> ostream& operator<<(ostream&os,const deque<T>&d){
	os<<"{";
	for(auto i:d){
		os<<i<<",";
	}
	os<<'}';
	return os;
}
void print(){cout<<"\n";} 
template <typename T, typename... types>void print(T var,types... vars){
	cout<<var<<" ";
	print(vars...);
}

// debug
vector<string> vcsplit(string s){
	s += ",";
	string temp = "";
	vc<string> v;
	loop(i,sz(s)){
		if(s[i]==','){
			v.pb(temp);
			temp="";
		}
		else temp+=s[i];
	}
	return v;
}
void debug_out(
	vc<string> __attribute__ ((unused)) args,
	int __attribute__ ((unused)) idx,
	int __attribute__ ((unused)) LINE) {
	cerr<<endl;
}
template<typename H,typename... T> void debug_out(vc<string>args,int idx,int LINE,H h,T... t){
	cerr<<((idx)?", ":"Line("+to_string(LINE)+") ");
	stringstream ss; ss<<h;
	cerr<<args[idx]<<" = "<<ss.str();
	debug_out(args,idx+1,LINE,t...);
}
#ifdef XOX
#define debug(...) debug_out(vcsplit(#__VA_ARGS__),0,__LINE__,__VA_ARGS__);
#else
#define debug(...) 42;
#endif

// template classes

//code
ll cnt = 0;

void fill_bits(vi&v,ll cur){
	loop(i,63){
		if(cur&(1ll<<i))v[i]++;
	}
}

void split(vi&v, int idx, int cur){
	while(idx>cur){
		v[idx]--;
		v[idx-1]+=2;
		cnt++;
		idx--;
	}
}

int find_smallest(vi&v){
	loop(i,63){
		if(v[i])return i;
	}
	return 63;
}

int find_upper(vi&v,int cur){
	for(int i=cur;i<63;i++){
		if(v[i]) return i;
	}
	return 63;
}

void group(vi&v,int cur){
	loop(i,cur){
		v[i+1]+=v[i]>>1;
		v[i] = v[i]&1;
	}
}

void solve(){
	vi c(63,0);	// count
	vi b(63,0); // input
	ll n;
	int m;
	cin>>n>>m;
	cnt = 0;
	fill_bits(b,n);
	loop(i,m){
		ll a;
		cin>>a;
		fill_bits(c,a);
	}
	debug(n,m,b,c);
	loop(cur,63){
		if(b[cur]){
			int s = find_smallest(c);
			debug(s,cur,cnt);
			if(s==63){
				cnt=-1;
				break;
			}
			if(s>=cur){
				split(c,s,cur);
				c[cur]--;
				debug(s,cur,c);
			}
			else{
				group(c,cur);
				debug(c,cur);
				if(c[cur]){
					c[cur]--;
					debug(c,cur);
				}
				else{
					s = find_upper(c,cur);
					debug(s);
					if(s==63){
						cnt=-1;
						break;
					}
					split(c,s,cur);
					c[cur]--;
				}
			}
		}
	}
	cout<<cnt<<"\n";
}

int main(){
	test solve();
}