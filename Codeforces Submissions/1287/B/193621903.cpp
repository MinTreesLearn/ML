using namespace std;
#include <bits/stdc++.h>
#define int long long
#define repp(n) for(int i=0;i<n;i++)
#define mod 1000000007



void solve()
{
    int n,k,ans=0;cin>>n>>k;
    string a[n];
    repp(n)for(int j=0;j<k;j++){
        char c;cin>>c;
        a[i]+=c;
    }

    map<string,int> m;
    repp(n)m[a[i]]++;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string temp;
            for(int f=0;f<k;f++){
                int a1=0,a2=0,a3=0;
                if(a[i][f]=='S')
                    a1++;
                if(a[i][f]=='E')
                    a2++;
                if(a[i][f]=='T')
                    a3++;
                if(a[j][f]=='S')
                    a1++;
                if(a[j][f]=='E')
                    a2++;
                if(a[j][f]=='T')
                    a3++;

                if(a1==2)
                    temp+='S';
                else if(a2==2)
                    temp+='E';
                else if(a3==2)
                    temp+='T';
                else if(a1==0)
                    temp+='S';
                else if(a2==0)
                    temp+='E';
                else if(a3==0)
                    temp+='T';

            }

                //cout<<i+1<<" "<<j+1<<" "<<temp<<endl<<endl;
                if(m.find(temp)!=m.end() && temp!=a[i] && temp!=a[j])
                    ans++;

        }
    }
    cout<<ans/3<<endl;
}



#define int int
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    //int t;cin>>t;while(t--)
    solve();
    return 0;
}
