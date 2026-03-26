#include<bits/stdc++.h>
using namespace std;
#define OM_NAMAH_SHIVAY ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define F first
#define S second
#define int long long
#define pb push_back
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    string temp="";
    string ansst=s;
    int ans=-1;
    for(int k=0;k<s.size();k++){
        temp="";
        for(int j=k;j<s.size();j++){
            temp.pb(s[j]);
        }
        int x= s.size()-k;
        if (x%2==0)
        {
            for (int i = 0; i <k; ++i)
            {
                temp.pb(s[i]);
            }
        }
        else{
        for (int i = k-1; i >=0; --i)
        {
            temp.pb(s[i]);
        }
        }
        if(temp<ansst){
            ansst=temp;
            ans=k+1;
        }
    }
    if (ans==-1)
    {
        cout<<s<<endl;
        cout<<1<<endl;return;
    }
    cout<<ansst<<endl;
    cout<<ans<<endl;return;
}
int32_t main()
{
    OM_NAMAH_SHIVAY;
    int t;
    t=1;
    cin>>t;
    // cout<<"t not found"<<endl;
    
    while(t--){
        solve();
    }
    // #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    // #endif
    return 0;
}