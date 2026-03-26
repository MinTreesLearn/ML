#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<math.h>
#include<map>
#include<algorithm>
#include<set>
#include<unordered_map>
#include <unordered_set>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define popcount __builtin_popcount
using namespace std;



#define ff first
#define ss second
#define pb push_back
#define int long long int
typedef long double lld;
#define FOR(i,n) for(int i=0;i<n;i++)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define MOD 1000000007

#define vi vector<int> 
#define pii pair<int, int>
#define vii vector<pii>
#define fr front()
#define bk back()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define max_heap         priority_queue <int>
#define min_heap         priority_queue <int, vector <int> , greater <int> >

typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pair<int, int> > vpii;
typedef unordered_set<int> us;
typedef map<int,int> mp;

//debugging


#ifndef ONLINE_JUDGE
#define debug1(a) cerr <<#a<<" " <<a << endl
#define debug2(a, b) cerr <<#a<<" "<< a << " "<<#b<<" " << b << endl
#define debug3(a, b, c) cerr <<#a<<" "<<a << " "<<#b<<" " << b << " "<<#c<<" " << c << endl
#define debug4(a, b, c, d) cerr << #a<<" "<<a << " " <<#b<<" "<< b << " "<<#c<<" " << c << " "<<#d<<" "<< d << endl
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#define debug2(x,y)
#define debug3(x,y,z)
#define debug4(x,y,z,a)
#endif
 
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



//Constants
const long double pi= 3.141592653589793238;
const int INF= 1e18;
const int mod=1e9+7;

//MATHEMATICAL FUNCTIONS

int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);} //gcd
int lcm(int a, int b){return (a/gcd(a,b)*b);} //lcm
//sieve
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

//binary exponentation
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

//CHECK

bool isprime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool ispoweroftwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isperfectsquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}return false;}
int ceils(int x, int y) {return x / y + (x % y > 0);}


// Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

//USEFUL
void printarr(vi arr, int n){FOR(i,n) cout << arr[i] << " ";cout << "\n";}

void solve(){

    int n,m,i,j;
    cin>>n;
    string s;
    cin>>s;
    char ch=*min_element(s.begin(), s.end());
    vector<pair<string,int>> vals;
    for(int i=0;i<n;i++){
        if(s[i]==ch){
            int len1=i+1;
            int len2=n-(i+1);
            string g=s.substr(0,len1-1);
            string t=s.substr(len1,len2);
            string val="";
            val.push_back(s[i]);
            if(len2%2==0){
                reverse(g.begin(), g.end());
            }
            val+=t;
            val+=g;
            vals.push_back({val,i+1});

        }
    }
    sort(vals.begin(), vals.end());
    cout<<vals[0].first<<endl;
    cout<<vals[0].second<<endl;









      
}

int32_t main()
{
    fast;
//      #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    
    int t;
    t=1;
    cin>>t;
    while(t--){

        // cout<<t;
        solve();
    }
    return 0;
    
}
