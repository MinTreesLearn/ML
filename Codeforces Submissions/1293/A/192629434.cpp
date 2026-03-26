#include<bits/stdc++.h>
#define int long long
#define fa(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define bp pop_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 
void solve(){
    int n,s,k;
    cin >> n >> s >> k;
    int a[k],f=0;
    vector<int> v1,v2;
    for(int i=0;i<k;i++)
    {
        cin >> a[i];
        if(a[i]<s)
            v1.push_back(a[i]);
        else if(a[i]>s)
            v2.push_back(a[i]);
        else{
            f++;
            v1.push_back(a[i]);
        }
    }
    if(f==0)
    {
        cout << "0" << endl;
        return;
    }
    sort(v1.rbegin(),v1.rend());
    sort(v2.begin(),v2.end());
    int cnt1=0,cnt2=0,x=s-1,y=s+1,f1=0,f2=0;
    for(int i=1;i<v1.size();i++)
    {
        if(x!=v1[i])
        {
            f1++;
            cnt1++;
            break;
        }
        cnt1++;
        x--;
    }
    if(!f1 && v1.size()!=s)
        cnt1++;
    for(int i=0;i<v2.size();i++)
    {
        if(y!=v2[i])
        {
            f2++;
            cnt2++;
            break;
        }
        cnt2++;
        y++;
    }
    if(!f2 && v2.size()!=(n-s))
        cnt2++;
    if(v1.size()==s)
    {
        cout << cnt2 << endl;
        return;
    }
    if(v2.size()==(n-s))
    {
        cout << cnt1 << endl;
        return;
    }
    cout << min(cnt1,cnt2) << endl;
    return;
}
signed main()
{
    faster;
    int t=1;
    cin>>t;
    while(t--)
    solve();
}