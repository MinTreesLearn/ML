// Problem: D. Pair of Topics
// Contest: Codeforces - Codeforces Round #627 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1324/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
* Coder -> ranadip_01 aKa RANADIP MUNDA
* DEPT. -> ECE"25
* COLLEGE -> JALPAIGURI GOVT. ENGINEERING COLLEGE
* Date -> 02/13/2023
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
using namespace std;


#define F ios_base::sync_with_stdio(false);
#define I cin.tie(NULL);
#define O cout.tie(NULL);

#define f first
#define s second
#define d  double
#define ll long long 
#define l long int
#define i int
#define e "\n"
#define in cin>>
#define out cout<<
#define frll(a,b,c) for(ll a=b;a<=c;a++)
#define forll(a,c) for(ll a=0;a<c;a++)
#define frl(a,b,c) for(l a=b;a<=c;a++)
#define forl(a,c) for(l a=0;a<c;a++)
#define fri(a,b,c) for(i a=b;a<=c;a++)
#define fori(a,c) for(i a=0;a<c;a++)
#define n(t) while(T--)
#define T tes_cases
#define vec vector
#define vs vector<string>
#define vc vector<char> 
#define uset unordered_set
#define umap unordered_map
#define mm multimap
#define pr pair
#define stk stack
#define que queue
#define dqu deque
#define pub emplace_back
#define pob pop_back()
#define puf emplace_front
#define pof pop_front()
#define pr_q priority_queue
#define mod  1000000007




const ll inf = 1e18+5;
const i Num = 1e3 + 5;

i park[Num];

i dellRow[]={-1,0,1,0};
i dellCol[]={0,1,0,-1};

void precompute()
{
    park[0] = 0;
    park[1] = 1;
    park[2] = 2;
    for (int a = 3; a < Num; a++)
    {
        park[a] = park[a - 1] * a;
        park[a] %= mod;
    }
}
bool isPerfectSquare(ll num){
    if(ceil((double)sqrt(num))==floor((double)sqrt(num))){
        return true;
    }else{
        return false;
    }
}
bool isPalindrome(string s1, int left, int right) {
    if (left > right) return true;
    if (s1[left] != s1[right]) return false;
    else return isPalindrome( s1, left + 1, right - 1);
}
bool isPrime(ll val) { // O(sqrt(N)
    if (val <= 1) return false;
    if (val <= 3) return true;
    if (val % 2 == 0 || val % 3 == 0) return false;
    for (ll a = 5; a * a <= val; a = a + 6)
        if (val % a == 0 || val % (a + 2) == 0)
            return false;
    return true;
}

ll gcd(ll a,ll b){ return (b==0)? a:gcd(b,a%b);}//Euclidean Division (O(log(min(a,b)))
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * 1ll * b; }

inline int normalize(int x, int y)
{
    x %= y;
    if (x < 0)
        x += y;
    return x;
}
i floor1(int n, int k)
{
    if (n % k == 0 || n >= 0)
        return n / k;
    return (n / k) - 1;
}
i ceil1(int n, int k){return floor1(n + k - 1, k);}

ll powm(ll a, ll b)// O(logN)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll binpow(ll a, ll b, ll m) {// O(logN)
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll moduloInverse1(ll n1,ll modulo){//Fermats Little O(logN)
    // a^(m-1)=1 (Formula)
    // a^(m-2)=a^-1
    return binpow(n1,modulo-2,modulo);
}

int nPr(int n, int c)
{
    int num = park[n];
    num %= mod;
    num /= park[n - c];
    num %= mod;
    return num;
}
int all_0_To_1(int n)
{
    if (n == 1)
        return 1;
    if (!(n & (n - 1)))
        return all_0_To_1(n + 1);
    else
    {
        int p = ceil(log2(n));
        int ans = (1 << p);
        return (ans - 1);
    }
}
int stringToInt(string s)
{
    int num = 0;
    int n = s.length();

    for (int a = 0; a < n; a++)
        num = num * 10 + ((int)(s[a]) - 48);
        
    return num;
}
int count_setBits(int n){
    if(n==0)return 0;
    return 1+count_setBits(n&(n-1));
}
int nearest_lowest_pow_of_2(int n)
{
    int val = log2(n);
    int ans = (1 << val);
    return ans;
}
int removeLast_SetBits(int n){
    return (n&(n-1));
}
int change_ithBit(int n,int a){
    return (n|(1<<a));
}
int clear_ithBit(int n,int a){
    return (a&(~(1<<a)));
}
int find_ithBit_from_Right(int n,int k,int a){
    return (n&(1<<(k-a)));
}
void swapp(int h,int k){
    h=(h^k);
    k=(k^h);
    h=(h^k);
}
bool sortBySec(const pair<ll,ll>&p1,const pair<ll,ll>&p2){
    return p1.s<p2.s;
}
const ll maxN=1e4;
vec<ll> factorials(maxN);
ll binomial(ll n1,ll k){
    if(n1<k) return 0;
    ll res=factorials[n1];
    res=(res*powm(factorials[k],mod-2))%mod;
    res=(res*powm(factorials[n1-k],mod-2))%mod;
    return res;
}
void factorial(){
    factorials[0]=factorials[1]=1;
    fri(a,2,1000000){
        factorials[a]=(factorials[a-1]*a)%mod;
    }
}
//Total prime - 31622
vec<i> primeSet;
bool prime[maxN];
bitset<31622> prm;
void madePrime(){
    for(i a=2;a<sqrt(1e9);++a){
        if(prm[a]==0) {
        primeSet.pub(a);
        for(i b=2*a;b<sqrt(1e9);b+=a) prm[b]=1;
        }
    }
}
void SieveOfEratosthenes() // O(NLog(LogN)
{
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=false;
    for (ll p = 2; p*p < maxN; p++) {
        if (prime[p] == true) {
            for (ll a = p * p;a < maxN;a += p)
                prime[a] = false;
        }
    }
    for (ll p = 2; p <maxN; p++){
        if (prime[p]) primeSet.pub(p);
    }
}
// ll ans=0;
// vec<pair<ll,ll>>a1;
vec<ll>a1;umap<ll,ll> mp1,mp2;
void primeFact1(ll n1){// O(sqrt(N)
    for(ll a=2;a*a<=n1;++a){
        if(n1%a==0){
            ll cnt1=0;
            while(n1%a==0) ++cnt1,n1=n1/a;
            if(cnt1!=0) mp1[a]=1;
            // a1.push_back({cnt1,a});
            // out a<<"^"<<cnt1<<e;
        }
        
        // out n1<<"^1"<<e;
    }
    if(n1>1) mp1[n1]=1;
    // a1.push_back({1,n1});
}
vec<ll> sieve(maxN,0);
void primeFactofSieve(){// O(Nlog(logN)
    iota(sieve.begin()+1,sieve.end(),1);
    for(ll a=4;a<maxN;a+=2) sieve[a]=2;
    for(ll a=3;a*a<maxN;++a){
        if(sieve[a]==a){
            for(ll b=a*a;b<maxN;b+=a){
                if(sieve[b]==b) sieve[b]=a;
            }
        }
    }
}
umap<ll,ll> sve;
void getFactors(ll n1){ // O(logN)
    while(n1>1){
        // Sieve.push_back(sieve[n1]);
        sve[sieve[n1]]++;
        n1/=sieve[n1];
    }
    // return Sieve;
}
ll phi(ll n1){//Eulors Totient - O(sqrt(N)logN)
    ll res=n1;
    for(i a=2;a*a<=n1;++a){
        if(n1%a==0){
            while(n1%a==0) n1/=a;
            res-=res/a;
        }
    }
    if(n1>1) res-=res/n1;
    return res;
}
ll binaryToDecimal(string s1){
    ll dec_val=0;
    ll base=1;
    ll len=s1.length();
    for(ll a=len-1;a>=0;--a){
        if(s1[a]=='1') dec_val=(dec_val+base)%1000003;
        base*=2;
    }
    return dec_val;
}
string decimalToBinary(ll n1){
    string ans="";
    while(n1){
        if(n1&1) ans+='1';
        else ans+='0';
        n1>>=1;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
bool operator < (const string &a, const string &b)
{
    if (a.size() < b.size()) return true;
    if (b.size() < a.size()) return false;
 
    for (int c = 0;c < a.size();c++)
    {
        if (a[c] < b[c]) return true;
        if (b[c] < a[c]) return false;
    }
    return true;
}
vec<ll> fib(82);
void fibonacii(){
    fib[0]=0;
    fib[1]=fib[2]=1;
    fri(a,3,81){
        fib[a]=fib[a-1]+fib[a-2];
    }
}
ll factorialss(ll n1)
{
    if (n1 == 0 || n1 == 1)
        return 1;
    return n1 * factorialss(n1 - 1);
}
vector<ll> graph[100001];//graph
string number="0123456789";
string abc = "abcdefghijklmnopqrstuvwxyz";
// ll dp[100001][1000000];

void go(){
    ll n1,h=0,j=10,k=2,cnt1=0,cnt2=0,cnt3=0;
    ll maxi=INT_MIN,mini=INT_MAX,f=0,d1,sum=0,flag=0,sum1=0,sum2=0,sum3=0;
    in n1;
    string s1,s2,s3="",s4="";
    // in s1;
    vec<ll> v1,v2,pre(n1);
    // vec<pair<ll,ll>> vp1,vp2;/
    umap<ll,ll> mp1,mp2;
    uset<ll> st1,st2,st3;
    // priority_queue<pair<i,string>> pq1,pq2;
    fori(a,n1) {
        in h;
        mp1[a]=h;
    }
    fori(a,n1) {
        in h;
        mp2[a]=h;
    }
    
    fori(a,n1){
    	h = mp1[a]-mp2[a];
    	if(h==0) ++cnt3;
    	else if(h>0) v1.pub(h);
    	// if(h<0) cnt1++,st1.insert(h);
    	// else if(h==0) cnt3++;
    	// else cnt2++,st2.insert(h);
    }
    sort(v1.begin(),v1.end());
    
    // sort(v2.begin(),v2.end());
    // h = st2.size();k = st1.size();
    // sum+=cnt3*cnt2;
    // sum+=
    k = v1.size();
    fori(a,n1){
    	h = mp1[a]-mp2[a];
    	if(h>0) continue;
    	h = abs(h);
    	i up = upper_bound(v1.begin(),v1.end(),h) - v1.begin();
    	cnt1+=k-up;
    }
    out cnt1+(k*(k-1)/2);
    
    
    
    
    
    
    
    
    
    
    
    
    out e;
    
}

signed main() {

    F
    I
    O
    
    // fri(a,1,100000)
    // for(i b=a;b<=100000;b+=a) fac[b].push_back(a);
    // factorial();
    i T=1;
    // in T;
    // memset(dp,-1,sizeof(dp));
    precompute();
    
    // cout << fixed << setprecision(10);
    n(t) go();
    
    
    
////////////////////////////////////////////////

// auto start = std::chrono::system_clock::now() ;
// auto end = std::chrono::system_clock::now();
// 
// std::chrono::duration<double> elapsed_seconds = end-start;
// std::time_t end_time = std::chrono::system_clock::to_time_t(end);
// 
// #ifndef ONLINE_JUDGE
// cout<<"RUN TIME : "<<elapsed_seconds.count()<<"s"<<endl;
// #endif

    return 0;
    
}