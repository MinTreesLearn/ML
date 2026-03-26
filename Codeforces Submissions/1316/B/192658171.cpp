#include <bits/stdc++.h>
using namespace std;

#ifdef AISH_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define fastIO          {ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define int             long long
#define mod             1000000007
#define PI              3.1415926535897932384626
#define endl            "\n"
#define all(v)          (v).begin(),(v).end()
#define YES             cout << "YES" << "\n"
#define NO              cout << "NO" << "\n"
#define ispowoftwo(n)   (!(n & (n-1)))
#define pb              push_back
#define ppb             pop_back
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef vector<vi> vvi;
vi prime;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

//Function for creating a vector of prime numbers
void primes(int n)
{
    prime.assign(n+1,1);
    for (int p=2;p*p<=n;p++) 
    {
        if(prime[p]) 
        {
            for (int i=p*p;i<=n;i+=p)
            {
                prime[i]=0;
            }
        }
    }
}

//Conditional sorting in vector of pairs
bool sortcon(const pair<int,int>&a,const pair<int,int>&b)
{
    if(a.first==b.first)
    {
        return(a.second>b.second);
    }
    return a.first<b.first;
}

void solve()
{   
    int n;
    string s;
    cin>>n>>s;
    map<string,int>mp;
    int k=0;
    for(int i = 0; i < n; i++)
    {
        string s1=s.substr(0,k);
        string s2=s.substr(k);
        if((n-k)%2!=0)
        {
            reverse(all(s1));
        }
        if(mp[s2+s1]==0)
        {
            mp[s2+s1]=k+1;
        }
        else
        {
            mp[s2+s1]=min(mp[s2+s1],k+1);
        }
        debug(s1, s2);
        k++;
    }
    auto it=mp.begin();
    cout<<it->first<<endl;
    cout<<it->second<<endl;
}


    
//<><><><><><><><><><><><>><><>><><><><><><><>

int32_t main()
{ 
    fastIO;
    auto start = std::chrono::high_resolution_clock::now(); 
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
        solve();        
    } 
    
    return 0;
}