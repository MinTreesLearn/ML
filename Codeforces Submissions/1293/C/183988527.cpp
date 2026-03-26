#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    IO
    ll n,q,i,cnt=0,col=0;cin>>n>>q;
    ll arr[3][n+1],vis[n+1]={0};
    map<ll,ll> mp;
    for(i=1;i<=n;i++){arr[1][i]=0;arr[2][i]=0;}
    while(q--){
        ll r,c;cin>>r>>c;
        if(arr[r][c]){arr[r][c]=0;mp[c]--;
            if(c>1&&c<n){if(arr[3-r][c+1]){cnt--;}if(arr[3-r][c-1]){cnt--;}}
            else if(c==1&&arr[3-r][c+1]){cnt--;}
            else if(c==n&&arr[3-r][c-1]){cnt--;}
        }
        else{arr[r][c]=1;mp[c]++;
            if(c>1&&c<n){if(arr[3-r][c+1]){cnt++;}if(arr[3-r][c-1]){cnt++;}}
            else if(c==1&&arr[3-r][c+1]){cnt++;}
            else if(c==n&&arr[3-r][c-1]){cnt++;}
        }
        if(mp[c]>1){if(!vis[c]){col++;}vis[c]=1;}
        else{if(vis[c]){col--;}vis[c]=0;}
        if(col){cout<<"No"<<endl;}
        else if(cnt){cout<<"No"<<endl;}
        else{cout<<"Yes"<<endl;}
    }
}