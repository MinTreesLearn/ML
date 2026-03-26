#include<bits/stdc++.h>
typedef long long ll;
const int maxx=10010;
const int inf=0x3f3f3f3f;
using namespace std;
vector<int>a;
int n;
int solve(vector<int>v, int bit)
{
    if(bit<0 || v.size()==0)
        return 0;
    vector<int>z,o;
    for(int i=0; i<v.size(); i++)
    {
        if((v[i]>>bit)&1)
            z.push_back(v[i]);
        else
            o.push_back(v[i]);
    }
    if(o.size()==0)
        return solve(z,bit-1);
    if(z.size()==0)
        return solve(o,bit-1);
    return (min(solve(o,bit-1),solve(z, bit-1))|1<<bit);
}
int main()
{
    cin>>n;
    for(int i=1,x; i++<=n;)
    {
        cin>>x;
        a.push_back(x);
    }
    cout<<solve(a,30)<<endl;
    return 0;
}