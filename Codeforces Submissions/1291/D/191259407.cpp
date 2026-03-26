#include <bits/stdc++.h>
typedef long long ll;
const int maxx=200010;
const int inf=0x3f3f3f3f;
using namespace std;
int a[26][maxx];
int l,r;
string s;
void solve()
{
    cin>>l>>r;
    l--,r--;
    if(l==r)
    {
        cout<<"Yes"<<endl;
        return ;
    }
    if(s[l]!=s[r])
    {
        cout<<"Yes"<<endl;
        return ;
    }
    int tot=0;
    for(int i=0; i<26; i++)
    {
        int R=a[i][r],L=0;
        if(l>0)
            L=a[i][l-1];
        if(R-L>0)
            tot++;
    }
    if(tot>=3)
    {
        cout<<"Yes"<<endl;
        return ;
    }
    cout<<"No"<<endl;
}
int main()
{
    int t;
    cin>>s;
    cin>>t;
    for(int i=0; i<s.size(); i++)
    {
        a[s[i]-'a'][i]++;
        if(i>0)
        {
            for(int j=0; j<26; j++)
                a[j][i]+=a[j][i-1];
        }
    }
    while(t--)
        solve();
    return 0;
}