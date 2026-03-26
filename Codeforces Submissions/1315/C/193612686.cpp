#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define mll map<ll,ll>
#define cinv(v) ll x; cin>>x; v.push_back(x);
#define floop(i,b) for(ll i=0;i<b;i++)
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define sortv(v) sort(v.begin(),v.end())

#define ayk ll t; cin>>t; while(t--)


int main(){
    ayk{
        ll n;
        cin>>n;
        vll b;
        mll m;
        ll mx=0;
        floop(i,n){
            cinv(b);
            m[b[i]]=1;
        }
        vll ans;
        floop(i,n){
            ans.push_back(b[i]);
            fr(j,b[i]+1,(2*n) +1){
                if(m[j]==0){
                    ans.push_back(j);
                    m[j]=1;
                    break;
                }
            }
        }

        if(ans.size() != 2*n) cout<<"-1\n";
        else{
            floop(i,ans.size()){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
}