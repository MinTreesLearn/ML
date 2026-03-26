#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef string str;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pair<ll,ll>> vpll;

#define en     "\n"
#define pb     push_back
#define popb   pop_back
#define F      first
#define S      second
#define in     insert
#define mp     make_pair
#define f(i,n) for(ll i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
int gcd(int a, int b)
{
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

bool comp(pair<ll,ll> &a, pair<ll,ll>&b)
{
    if(a.first!=b.first)
    {
        return (a.first>b.first);
    }
    else{
        return(a.second<b.second);
    }
}
int deleteElement(int arr[], int n, int x)
{
 int i;
 for (i=0; i<n; i++)
    if (arr[i] == x)
        break;
 if (i < n)
 {
    n = n - 1;
    for (int j=i; j<n; j++)
        arr[j] = arr[j+1];
 }

 return n;
}

bool isPalindrome(string S)
{
    string P = S;
    reverse(P.begin(), P.end());
    if (S == P)
    {
        return true;
    }

    else
    {
        return false;
    }
}

ll highestPowerof2(ll n)
{
    ll res = 0;
    for (ll i=n; i>=1; i--)
    {
        // If i is a power of 2
        if ((i & (i-1)) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}
// Returns true if s1 is substring of s2
int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for
 pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }

    return -1;
}

/*Returns true if s1 is subsequence of s2*/
bool issubsequence(string& s1, string& s2)
{
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    /*If i reaches end of s1,that mean we found all
    characters of s1 in s2,
    so s1 is subsequence of s2, else not*/
    return i == n;
}
bool isSquare(int x)
{
  int y=sqrt(x);
  return y*y==x;
}

bool isVowel(char c)
{
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}
bool isprime(int n)
{
    if(n==1)
        return false;
    else
    {
        bool f=true;
        for(int i=2;i*i<=n;i++){
            if(n%i==0)
            {
                f=false;
                break;
            }
        }
        return f;
    }
}
vector <ll> prime_factors(ll n)
{
    vector<ll> p;
    for(ll i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            p.pb(i);
            n/=i;
        }
    }
    if(n>1)
        p.pb(n);
    return p;
}
const int M=1e9+7;
int binExpItr(int a,int b) // cal a^b assuming a,b<1e9
{
    int ans=1;
    while(b)
    {
        if(b&1) //checking set bit
        {
            ans=(ans*1LL*a)%M;
        }
        a=(a*1LL*a)%M;
        b>>=1;
    }
    return ans;
}
const int N=200004;
vector<int> isPrime(N+1,1);
const int Mo=1e9+7;
vector <ll> Fact(1000006);

int binExp(int a,ll b,int m)
{
    int ans=1;
    while(b>0)
    {
        if(b&1)
        {
            ans=(ans*1LL*a)%m;
        }
        a=(a*1LL*a)%m;
        b>>=1;
    }
    return ans;
}
bool sortByval(pair<int,int> &a,pair<int,int> &b)
{
    if(a.S!=b.S)
     return(a.S<b.S);
    else
       return(a.F<b.F);
}
vector <int> lc(23,0);
ll func(ll n)
{
    if(n==1) return 1;
    else return n+func(n/2);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


//    int l=1;
//    for(int i=1;i<23;i++)
//    {
//       l=(l*i)/gcd(l,i);
//       lc[i]=l;
//    }
//
//    int f=1;
//    for(ll i=1;i<1000006;i++)
//    {
//       f=(f*1LL*i)%Mo;
//       Fact[i]=f;
//
//    }

    isPrime[0]=isPrime[1]=1;
    for(int i=2;i*i<=N;i++)
    {
        if(isPrime[i]==1)
        {
            for(int j=2*i;j<=N;j+=i)
                isPrime[j]=0;

        }
    }


//int t=1;
   int t;
   cin>>t;
   while(t--)
   {
     ll n;
     cin>>n;
     vector<pair<ll,ll>> v;
     f(i,n)
     {
        ll x,y;
        cin>>x>>y;
        v.pb(mp(y,x));
     }
     sort(all(v));
     bool f=true;
     for(ll i=1;i<n;i++)
     {
        if(v[i].F!=v[i-1].F)
        {
            if(v[i].S<v[i-1].S)
            {
                f=false;
                break;
            }
        }
     }
     if(f)
     {
        cout<<"YES"<<en;
        str ans;
        for(ll i=0;i<(v[0].S);i++)
        {
            ans.pb('R');
        }
        for(ll i=0;i<(v[0].F);i++)
         ans.pb('U');
        for(ll i=1;i<n;i++)
        {
            for(ll j=0;j<(v[i].S-v[i-1].S);j++)
              ans.pb('R');
            for(ll j=0;j<(v[i].F-v[i-1].F);j++)
              ans.pb('U');
        }
        cout<<ans;
     }
     else
      cout<<"NO";
     cout<<en;
   }
  return 0;

}
