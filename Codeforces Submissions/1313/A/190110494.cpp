#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define vi vector<int>
#define vll vector<long long int>
#define vp vector<pair<int,int>>
#define vvi vector<vector<int>>
#define mp make_pair
#define ss second
#define ff first
#define all(v) v.begin(),v.end()
#define umi unordered_map<int, int>
#define umc unordered_map<char, int>
#define usi unordered_set<int>
#define si set<int>
#define sc set<char>
#define usc unordered_set<char>
#define sorts(s) sort(s.begin(), s.end())
#define dsort(s) sort(s.begin(), s.end(), greater<ll>())
// #define reverse(s) reverse(s.rbegin(),s.rend())
#define input(s,n) for(int i=0;i<n;i++) cin>>s[i];
#define NUM 100000+10
#define mod 1000000007
#define MAX LONG_MAX
template<typename T1, typename T2>
istream& operator>>(istream& ins,
  pair<T1, T2>& v) {
  ins >> v.first >> v.second;
  return ins;
}
template<typename T, size_t N>
istream& operator>>(istream& ins,
  array<T, N>& v) {
  for (int i = 0; i < int(N); i++) cin >> v[i];
  return ins;
}
template<typename T>
istream& operator>>(istream& ins,
  vector<T>& v) {
  for (int i = 0; i < int(v.size()); i++) ins >> v[i];
  return ins;
}
template<typename T>
ostream& operator<<(ostream& outs,
  vector<T>& v) {
  for (int i = 0; i < v.size(); i++) outs << v[i] << " ";
  return outs;
}
template<typename T, size_t N>
ostream& operator<<(ostream& outs,
  array<T, N>& v) {
  for (int i = 0; i < int(N); i++) outs << v[i] << " ";
  return outs;
}

void solve(){
    int a[3], res = 0;
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  for(int i=0; i<3; ++i){
    if(a[i]){
      ++res;
      a[i]--;
    }
  }
  if(a[2] && a[1]){
    a[2]--, a[1]--;
    ++res;
  }
  if(a[2] && a[0]){
    a[2]--, a[0]--;
    ++res;
  }
  if(a[1] && a[0]){
    a[1]--, a[0]--;
    ++res;
  }
  if(a[2] && a[1] && a[0]){
    ++res;
  }
  cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // precompute();
    ll t; cin>>t;
    while(t--) {
        solve();
    }
    // solve();
    return 0;
}