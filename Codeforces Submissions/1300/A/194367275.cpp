using namespace std;
#include <bits/stdc++.h>
#define int long long
#define repp(n) for(int i=0;i<n;i++)
#define mod 1000000007



void solve()
{
    int n;cin>>n;
    int a[n];repp(n)cin>>a[i];
    int sum=0,cnt=0;
    repp(n){
        sum+=a[i];
        if(a[i]==0)
            cnt++;
    }

    if(sum+cnt==0){
        cout<<cnt+1<<endl;
    }
    else{
        cout<<cnt<<endl;
    }

}



#define int int
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
    return 0;
}
