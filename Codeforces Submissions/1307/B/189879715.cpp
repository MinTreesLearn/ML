#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vt vector
#define pb push_back
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define f(i, j, k) for (ll i = j; i < k; i++)
#define max_v(x) *max_element(all(x))
#define min_v(x) *min_element(all(x))

void solve()
{
    int n,x; cin>>n>>x;
    vt<int>v(n);
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
    }
    sort(all(v));
    int t=-1;
    for(int i=0 ; i<n ; i++){
        if(x%v[i]==0){
            t=v[i];
        }
    }
    int ans1=0,ans2=0;
    if(t!=-1){
        ans1=x/t;
      //  cout<<ans1<<endl;
    }
    
        reverse(all(v));
        int mx=v[0];
        //cout<<mx<<endl;
        if(2*mx>x){
            
            if(t!=-1) cout<<min(2,ans1)<<endl;
            else cout<<2<<endl;
            
        }
        else{
            if(t!=-1) cout<<min(x/mx+1,ans1)<<endl;
            else cout<<x/mx+1<<endl;
        }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll tt;
    cin >> tt;
    while (tt--)

        solve();
}