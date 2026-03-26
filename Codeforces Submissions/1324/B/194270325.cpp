#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define _ ios::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
using namespace std;
int32_t main()
{
    _
    int t = 1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ara[n];
        for(int i = 0;i<n;i++)
            cin >> ara[i];
        int flag = 0,pos = 0;;  
        int rex = 0;
        map<int,int>mp;
        for (int i = 0; i < n; ++i)
        {
            mp[ara[i]]++;
        }
        int f = 0;
        for(auto y : mp)
        {
          if(y.second >= 3){
            f = 1;break;
            // cout << "YES" << endl;
          }
        }

        for(int i = 0;i<n;i++)  
        {
          int a = ara[i];
            for(int j = i+1;j<n;j++)
            {
              if(ara[j] != a) {
                pos = j;
                flag++;
                break;
              }
            }
            for(int k = pos+1;k<n;k++)
              if(ara[k] == a)
              {
                flag++;
                break;
              }

              if(flag ==2 )
                break;
              else flag = 0;

        }     

        if(flag == 2 or f == 1)cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;  
}
