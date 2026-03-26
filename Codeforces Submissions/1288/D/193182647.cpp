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
ll inf = 1e18;
const ll constant = 1e6+1;

// input/output 
template <typename T> ostream& operator<<(ostream&os,const vector<T>&v){
	loop(i,v.size()){
		os<<v[i]<<" ";
	}
	os<<"\n";
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
pii check(vc<vi>&a,int x,int m){
	map<int,int> s;
	vi v;
	loop(i,sz(a)){
		int temp = 0;
		loop(j,m){
			if(a[i][j]>=x)temp|=(1<<j);
		}
		if(!s.count(temp))s[temp]=i;
	}
	for(auto i:s)
		v.pb(i.fs);
	int v1 = (1<<m)-1;
	loop(i,sz(v)){
		for(int j=i;j<sz(v);j++){
			if((v[i]|v[j]) == v1){
				return mp(s[v[i]],s[v[j]]);
			}
		}
	}
	return mp(-1,-1);
}

void solve(){
	int n, m;
	cin>>n>>m;
	vc<vi> a(n,vi(m));
	cin>>a;
	int l = 0, h = 1e9, mid;
	pii ans = {-1,-1};
	while(l<=h){
		mid = (l+h)>>1;
		pii temp = check(a,mid,m);
		if(temp.fs!=-1){
			l=mid+1;
			ans = temp;
		}
		else h = mid-1;
	}
	cout<<(ans.fs+1)<<" "<<(ans.sc+1)<<"\n";
}

int main(){
	fast solve();
}