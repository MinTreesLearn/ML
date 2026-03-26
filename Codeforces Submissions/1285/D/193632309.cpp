#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
// #define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const double eps=1e-8;
const int INF=0x3f3f3f3f,mod=998244353;

#ifndef ONLINE_JUDGE
#define debug(...)
#include<debug>
#else
#define debug(...)
#endif

const int N=100005;
int n;
int dcq(vector<int> ver,int w)
{
    vector<int> a;
    vector<int> b;
    for(auto x:ver)
    {
        if(x>>w&1) a.push_back(x);
        else b.push_back(x^(1<<w));
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a.empty())
    {
        for(auto &x:b) x^=(1<<w);
        if(w==0) return b.back();
        return dcq(b,w-1);
    }
    else if(b.empty())
    {
        for(auto &x:a) x^=(1<<w);
        if(w==0) return a.back();
        return dcq(a,w-1);
    }
    else
    {
        if(w==0) return min(a.back(),b.back());
        return min(dcq(a,w-1),dcq(b,w-1));
    }

}
int main()
{
    scanf("%d",&n);
    vector<int> ver;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ver.push_back(x);
    }

    int res=dcq(ver,30);
    printf("%d\n",res);
}