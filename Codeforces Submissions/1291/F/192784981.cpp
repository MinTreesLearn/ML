#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1024;
bool used[maxn];int a[maxn];
int qu=0;
set<int> o;
void que(int i)
{
    if(used[i]) return;
    cout<<"? "<<i+1<<endl;
    ++qu;
    #ifndef LOCAL
    #else
    if(o.count(a[i])) used[i]=true;
    o.insert(a[i]);
    return;
    #endif
    char ans;cin>>ans;
    if(ans=='Y') {used[i]=true;}
}
void cl()
{
    cout<<'R'<<endl;
    o.clear();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    #ifdef LOCAL
    for(int i=0;i<n;++i) cin>>a[i];
    #endif // LOCAL
    if(k==1) k=2;
    for(int i=0;i<2*n/k;++i)
    {
        for(int l=i*(k/2);l<(i+1)*(k/2);++l)
        {
            que(l);
        }
        cl();
        for(int j=i+1;j<2*n/k;++j)
        {
            for(int l=i*(k/2);l<(i+1)*(k/2);++l)
            {
                que(l);
            }
            for(int l=j*(k/2);l<(j+1)*(k/2);++l)
            {
                que(l);
            }
            cl();
        }
    }
    #ifdef LOCAL
    cout<<qu<<" que "<<endl;
    #endif // LOCAL
    cout<<"! "<<(n-accumulate(used,used+n,0LL))<<endl;
    return 0;
}
