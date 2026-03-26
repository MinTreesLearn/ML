#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll  long long int
#define f(i,a,b)  for(ll i=a;i<b;i++)
#define vl vector<ll>
#define asc(v)  sort(v.begin(), v.end())                     //vectors,pairs,tuples,string
#define dsc(v)  sort(v.begin(), v.end(), greater<ll>())
#define p2sort(v)  sort(v.begin(), v.end(), sortbysec);       //for pairs
#define mod 1000000007
#define fill(a,b) memset(a, b, sizeof(a))
#define yes  return (void) (cout << "YES\n");
#define no  return (void) (cout << "NO\n");
//bits
 
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b){return (a.second < b.second);}                //pairs des
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}  //less than O(sqrt(n))
string decToBin(ll n){string s="";if(n==0){s+='0';return s;}ll i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binToDec(string n){string num = n;ll dec_value = 0;ll base = 1;ll len = num.length();for(ll i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
void swap(ll &x, ll &y) {ll temp = x; x = y; y = temp;}
//modfun ncrmodp  KMP  KMPbool  Manacher  Rabin
//primeFactors  allFactors  sieve extendedGCD

void solve(){
    	int n;
        cin >> n;
        vector<pair<int, int>> p(n);
        for (auto &pnt : p) cin >> pnt.first;
        for (auto &pnt : p) cin >> pnt.second;
        sort(p.begin(), p.end());
        
        pbds s;
        long long ans = 0;
        for (int i = 0; i < n; ++i) { // cnt = count of all ( elements before i having speed <= Vi )
            int cnt = s.order_of_key(make_pair(p[i].second + 1, -1));
            ans += cnt * 1ll * p[i].first; //  + xi * cnt
            s.insert(make_pair(p[i].second, i)); // only elements before i are in the set
        }
        s.clear();
        for (int i = n - 1; i >= 0; --i) { // cnt  =  count of all ( elements after i having speed > Vi )
            int cnt = int(s.size()) - s.order_of_key(make_pair(p[i].second - 1, n)); // total - less speed = higher speed
            ans -= cnt * 1ll * p[i].first; // - xi * cnt
            s.insert(make_pair(p[i].second, i));
        } 
        cout << ans << endl;
}

int main(){
   (ios_base:: sync_with_stdio(false),cin.tie(NULL));
   ll TC=1;
   //cin>>TC;
   while(TC--){solve();} return 0;
}

//ASCII - (0-9 : 48-57) ; (A-Z : 65-90) ; (a-z : 97-122)
//Upper : char(k&'_') , Lower : char(k&' ')
