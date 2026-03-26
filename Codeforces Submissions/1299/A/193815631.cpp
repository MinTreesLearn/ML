#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lb long double
#define pb push_back
#define f first
#define s second

const int mod=1e9+7;
const int mod1=998244353;

void burn ()
{
    int n,p;
    cin >> n;
    while(n--)
    cin>>p;
    return;
}
void reveal ()
{
    int n,p;
    string val;
    cin>>n;
    cout<<n<<endl;
   while(n--)
   { cin>>p;
   cout<<p<<" ";}
   
    cout << '\n';
    return;
}
int fact[200001];
void solve()
{
  ll n,i,j,x,p,y,k,m;
cin>>n;
vector<ll>arr(n);

for(i=0;i<n;i++)
cin>>arr[i];

sort(arr.begin(),arr.end(),greater<int>());
vector<pair<ll,ll>>v;

int pref[n],suff[n];
    pref[0]=suff[n-1]=INT_MAX;
 
    for(i=1;i<n;i++)
        pref[i]=pref[i-1]&(~arr[i-1]);
    for(i=n-2;i>=0;i--)
        suff[i]=suff[i+1]&(~arr[i+1]);
 
    int ans=INT_MIN,pos=-1,tmp;
    for(i=0;i<n;i++){
        tmp=pref[i]&arr[i]&suff[i];
        if(tmp>ans){
            ans=tmp;
            pos=i;
        }
    }
    vector<ll>arr1;
    cout<<arr[pos]<<" ";
    for(i=0;i<n;i++){
        if(i!=pos)
            arr1.push_back(arr[i]);}
    sort(arr1.begin(),arr1.end());
    for(i=0;i<n-1;i++)
    cout<<arr1[i]<<" ";

}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t=1;
	//cin >> t;
  // fact[0]=1;
  //   for(int i=1;i<200001;i++)
  //   {
  //     fact[i]=((fact[i-1]%mod)*((i)%mod))%mod;
  //   }
    // if (t == 10000)
    // {
    //     for (int i = 0; i < 368; i++)
    //         burn ();
    //     reveal ();
    //     return 0;
    // }
    
	while (t--){
     solve();
	}
}