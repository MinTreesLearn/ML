#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int maxn=2e5+5;
int a[26][maxn];

signed main()
{
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s;
    int n;
    cin>>s>>n;

    for(int i=0;i<(int)s.size();i++)
    {
        for(int j=0;j<26;j++)
        {
            a[j][i+1]=a[j][i];
        }
        a[s[i]-'a'][i+1]++;
    }

    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==y||s[x-1]!=s[y-1])
        {
            cout<<"Yes\n";
            continue;
        }

        int num=0;
        for(int i=0;i<26&&num<3;i++)
        {
            if(a[i][y]>a[i][x-1])
            {
                num++;
            }
        }

        if(num>2)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}


				    	  			  		 			 		 	  		