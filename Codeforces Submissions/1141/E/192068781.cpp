#include<iostream>
#define int long long
using namespace std;
int t[300000];
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int H,n;
    cin>>H>>n;
    int minn=1e9;
    for(int i=1;i<=n;i++)
        cin>>t[i];
    int suma=0;
    int gdzie=0;
    for(int i=1;i<=n;i++)
    {
        suma+=t[i];
        minn=min(minn,suma);
        if(suma+H<=0)
        {
            gdzie=i;
            break;
        }
    }
    if(gdzie!=0)
    {
        cout<<gdzie;
        return 0;
    }
    if(suma>=0)
    {
        cout<<"-1";
        return 0;
    }
    int ile=(H+minn)/abs(suma);
    if((H+minn)%abs(suma)!=0)
        ile++;
    suma=ile*suma;
    gdzie=ile*n;
    for(int i=1;i<=n;i++)
    {
        suma+=t[i];
        if(suma+H<=0)
        {
            cout<<gdzie+i;
            return 0;
        }
    }
    return 0;
}
