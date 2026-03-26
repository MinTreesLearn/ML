#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
using ull=unsigned long long;
using ll=long long;
const int inf=1e9;
using ld=long double;
const ld eps=1e-12;
int a[N];
void solve()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    vector<pair<ld,int>>vec;
    vec.push_back({a[1],1});
    for(int i=2;i<=n;++i)
    {
        vec.push_back({a[i],1});
        while((int)vec.size()>=2)
        {
            auto [sum,cnt]=vec.back();
            vec.pop_back();
            int fg=1;
            if((vec.back().first+sum)/(vec.back().second+cnt)<
            vec.back().first/vec.back().second-eps)
            {
                fg=0;
                sum+=vec.back().first;cnt+=vec.back().second;
                vec.pop_back();
            }
            vec.push_back({sum,cnt});
            if(fg)break;
        }
    }
    for(auto [t,cnt]:vec)
    {
        ld val=t/cnt;
        while(cnt--)printf("%.10Lf\n",val);
    }
}
int main()
{
    // init();
    int T=1;//scanf("%d",&T);
    while(T--)solve();
}