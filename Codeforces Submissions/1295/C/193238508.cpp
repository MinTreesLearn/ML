#include <bits/stdc++.h>

#define itn  long long
#define int  long long
#define double long double
//#define endl '\n'
#define p_b push_back
#define fi first
#define se second
#define pii std::pair<int, int>
#define oo LLONG_MAX
#define big INT_MAX
#define elif else if

using namespace std;

int input()
{
    int x;
    cin>>x;
    return x;
}

void solve()
{

    string s, t;
    cin>>s>>t;
    map<char, bool>mp;
    for(char c:s)mp[c]=true;
    for(char c:t)if(!mp[c])
    {
        cout<<-1;
        return;
    }
    itn n=s.size();
    vector<vector<int>>vc(26, vector<int>(n+1));
    for(int i=0;i<26;i++)
    {
        vc[i][n]=-1;
        for(int j=n-1;j>=0;j--)
        {
            if(s[j]-'a'==i)vc[i][j]=j;
            else
                vc[i][j]=vc[i][j+1];
        }
    }
//    for(int i=0;i<26;i++)
//    {
//        for(int j=0;j<n;j++)
//            cout<<vc[i][j]<<' ';
//        cout<<endl;
//    }
    itn ans=0;
    int cur=0;
    for(int i=0;i<t.size();i++)
    {
        if(cur==0){ans++;}
        if(vc[t[i]-'a'][cur]==-1){
            cur=n;
            i--;
        }
        else
            cur=vc[t[i]-'a'][cur]+1;
        if(cur>=n)
            cur=0;
    }
    cout<<ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

//        freopen("network.in", "r", stdin);
//        freopen("magic.txt", "w", stdout);


    int t=1;
    cin>>t;
    while(t--)
    {
        solve();

        cout<<endl<<endl;
    }


}
