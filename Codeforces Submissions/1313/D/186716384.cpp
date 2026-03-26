// LUOGU_RID: 98031196
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<pair<int,int> >a;
typedef pair<int,int> pii;
int f[1<<8],vis[maxn],n;
signed main()
{
    int tm1,tm2;
    cin>>n>>tm1>>tm2;
    for(int i=1,l,r;i<=n;i++) 
    {
        cin>>l>>r;
        pii s1,s2;
        s1.first=l,  s1.second=i;
        s2.first=r+1,s2.second=-i;
        a.push_back(s1),a.push_back(s2);
    }
    sort(a.begin(),a.end());
    for (int i = 1; i < 256; i++) f[i] = -inf;
    for(int u=0;u<a.size();u++)
    {
        int id=a[u].second,len,k;
        if(u==a.size()-1) len=0;
        else len=a[u+1].first-a[u].first;
        if(id>0)//左端点
        {
            for(int i=0;i<8;i++)
            {
                if(!vis[i]) 
                {
                    k=i,vis[i]=id;
                    break;
                }
            }
            for(int i=255;i>=0;i--)
            {
                if((i>>k)&1) f[i]=f[i^(1<<k)]+len*__builtin_parity(i);
                else f[i]=f[i]+len*__builtin_parity(i);
            }
        }
        else 
        {
            for(int i=0;i<8;i++)
            {
                if(vis[i]==-id)
                {
                    k=i,vis[k]=0;
                    break;
                }
            }
            for(int i=0;i<256;i++)
            {
                if ((i>>k)&1) f[i]=-inf;
                else f[i]=max(f[i],f[i^(1<<k)])+len*__builtin_parity(i);
            }
        }
    }
    cout<<f[0]<<endl;
    return 0;
}