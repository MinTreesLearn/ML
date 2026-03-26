//Srijan Krishna 2113094
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ook order_of_key    //log(n)
#define fbo find_by_order   //log(n)
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,
			tree_order_statistics_node_update>
	os;     //Pair<ll,ll> Ordered_set
#define um unordered_map
#define pb push_back
#define pob pop_back()
#define pof pop_front()
#define ps pr.second
#define pf pr.first
#define mp make_pair
#define pq priority_queue
ll ga[110];
ll getbit(ll n){
    ll ct=0;
  while(n){
  ct=ct+(n&1);
  n=n>>1;
  }
  return ct;
}
ll binary_search_upper(vector<ll>&v,ll k){
    ll lo=0;
    ll hi=v.size()-1;
    ll mid;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if(v[mid]==k){
            return mid;
        }
        else if(k>v[mid]){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    } 
    if(v[mid]>k){
        return mid;
    }
    else{
        if(mid==v.size()-1){
            return -1;
        }
        else{
        return mid+1;
        }
    }
}
ll binary_search_lower(vector<ll>&v,ll k){
    ll lo=0;
    ll hi=v.size()-1;
    ll mid;
    while(lo<=hi)  {
        mid=lo+(hi-lo)/2;
        if(v[mid]==k){
            return mid;
        }
        else if(k>v[mid]){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    } 
    if(v[mid]<k){
        return mid;
    }
    else if(v[mid]>k){
        if(mid==0){
            return -1;
        }
        else{
        return mid-1;
        }
    }
}
ll binary_search(vector<ll>&q,ll k){
    ll lo=0;
    ll hi=q.size()-1;
    ll mid;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if(q[mid]==k){
            return mid;
        }
        else if(k>q[mid]){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    } 
    return -1;
}
void print(pq<ll>q){
    while(!q.empty()){
    cout<<q.top()<<" ";
    q.pop();
    }
    cout<<endl;
}
ll mei(ll a,ll b,ll c){
    if(a<b && a<c){
        return a;
    }
    else if(b<c && b<a){
        return b;
    }
    return c;
}
ll mulmod(ll a,ll b,ll c)
{
	if (b==0)
		return 0;
	ll s = mulmod(a, b/2, c);
	if (b%2==1)
		return (a%c+2*(s%c)) % c;
	else
		return (2*(s%c)) % c;
}
ll fac(ll n){
    if(n==1 || n==0){
        return 1;
    }
    ll fac=1;
    for(ll i=1;i<=n;i++){
    ll a=fac;
    ll b=i;
    ll c=1000000007;
    fac=mulmod(a,b,c);
    }
    return fac;
}
bool palindrome(string s){
   for(ll i=0;i<s.length()/2;i++){
    if(s[i]!=s[s.length()-i-1]){
      return false;
    }
   }
   return true;
}
ll subSum(deque<ll>q){
   ll sum=0;
   ll maxi=INT_MIN;
   for(ll i=0;i<q.size();i++){
    sum=sum+q[i];
    maxi=max(maxi,sum);
    if(sum<0){
        sum=0;
    }
   }
   return maxi;
}
void nextLargerElement(ll arr[],ll n)
{
    vector<unordered_map<string,ll> > s;
    for (ll i = 0; i < n; i++) {
        while (s.size() > 0
               && s[s.size() - 1]["value"] < arr[i]) {
            unordered_map<string,ll> d = s[s.size() - 1];
            s.pop_back();
            arr[d["ind"]] = arr[i];
        }
        unordered_map<string,ll> e;
 
        e["value"] = arr[i];
        e["ind"] = i;
        s.push_back(e);
    }
    while (s.size() > 0) {
        unordered_map<string,ll> d = s[s.size() - 1];
        s.pop_back();
        arr[d["ind"]] = -1;
    }
}
#define MAXN 100001
ll spf[MAXN];
void sieve(){
spf[1] =1;
    for (ll i=2; i<MAXN; i++)
        spf[i] = i;
    for (ll i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for (ll i=3; i*i<MAXN; i++){     
    if (spf[i] == i){
        for (ll j=i*i; j<MAXN; j+=i)
            if (spf[j]==j)
                spf[j] = i;
          }
      }
}
void getFactorization(ll x,um<ll,ll>&m)
{
    while (x != 1)
    {  
        m[spf[x]]++;
        x = x / spf[x];
    }
}
ll div_two(ll &n){
   ll ct=0;
   while(n%2==0){
   ct++;
   n=n/2;
   }
   return ct;
}
void primeFactors(ll n,um<ll,ll>&m){
  while(n%2==0){
    m[2]++;
    n/=2;
  }
  for(ll i=3;i<=sqrt(n);i=i+2){
    while(n%i==0){
        m[i]++;
        n/=i;
    }
  }
  if(n>2){
    m[n]++;
  }
}
bool isprime(ll n){
    if(n==1){
        return false;
    }
    if(!(n%2) && n>2){
        return false;
    }
    if(n==2){
        return true;
    }
    else{
        for(ll i=3;i*i<=n;i+=2){
            if(n%i==0){
                return false;
            }
        }
    }
    return true;
}
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
 
 
    ll base = 1;
 
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}
ll logg(ll a,ll b)
{
    return (a > b - 1)
            ? 1 + logg(a / b, b)
            : 0;
}
ll mod_pow(ll x,ll y,ll p)
{
    ll res = 1;  
    x = x % p;
    if (x == 0) return 0; 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
ll powr(ll x,ll y)
{
	ll temp;
	if (y == 0)
		return 1;
	temp=powr(x, y / 2);
	if (y % 2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}
bool palind(vector<ll>&arr){
    ll n=arr.size();
    for(ll i=0;i<arr.size()/2;i++){
        if(arr[i]!=arr[n-i-1]){
            return false;
        }
    }
    return true;
}
void printv(vector<ll>v){
   for(ll i=0;i<v.size();i++){
    cout<<v[i]<<" ";
   }
}
void printarr(ll arr[],ll n){
   for(ll i=0;i<n;i++){
      cout<<arr[i]<<" ";
   }
}
void sortall(vector<ll>&v){
sort(v.begin(),v.end());
}
void get(ll arr[],ll n){
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
}
bool ch_pow2(ll n){
    ll ch=logg(n,2);
    if(powr(2,ch)==n){
        return 1;
    }
    return 0;
}
class solution{
    public:
    string getstr(){
        string s;
        cin>>s;
        return s;
    }
    vector<ll> getmin(string s){
      vector<ll>open,close;
      for(ll i=0;i<s.size();i++){
        if(s[i]=='('){
            open.pb(i+1);
        }
        else{
            close.pb(i+1);
        }
      }
      ll i=0;ll j=close.size()-1;
      vector<ll>v;
      if(open.size()>0 && close.size()>0){
      while(open[i]<close[j] && i<open.size() && j>=0){
      v.pb(open[i]);v.pb(close[j]);i++;j--;
      }
      }
      return v;
    }

}solution;
ll dp[105][105];
int main(){
    string s=solution.getstr();
    vector<ll>v=solution.getmin(s);
    if(v.size()>0){
    cout<<"1"<<endl;
    
    cout<<v.size()<<endl;sortall(v);
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
       
        
        

     

   return 0;
}
    


    

    


    

    


    

    


    

    


    

    


    

    


    

    


    