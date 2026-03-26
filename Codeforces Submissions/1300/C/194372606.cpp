using namespace std;
#include <bits/stdc++.h>
#define int long long
#define repp(n) for(int i=0;i<n;i++)
#define mod 1000000007



void solve()
{
    int n;cin>>n;
    int a[n];repp(n)cin>>a[i];

    for(int bit=35;bit>-1;bit--){
        int cnt=0,ind=-1;
        repp(n){
            if((a[i]&(1LL<<bit))>0){
                cnt++;
                ind=i;
            }
        }
        if(cnt==1){
            cout<<a[ind]<<" ";
            repp(n){
                if(i!=ind)cout<<a[i]<<" ";
            }
            cout<<endl;
            return;
        }

    }
    repp(n)cout<<a[i]<<" ";
    cout<<endl;


}



#define int int
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    //int t;cin>>t;while(t--)
    solve();
    return 0;
}
