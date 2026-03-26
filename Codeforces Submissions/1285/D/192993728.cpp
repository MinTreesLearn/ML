using namespace std;
#include <bits/stdc++.h>
#define int long long
#define repp(n) for(int i=0;i<n;i++)
#define mod 1000000007



void solve()
{
    int n;cin>>n;
    int a[n+1],ans=0;repp(n)cin>>a[i+1];

    vector<int> now(n);repp(n)now[i]=i+1;
    vector<vector<int>> vv,temp1,temp2;
    vv.push_back(now);

    for(int bit=30;bit>-1;bit--){
        //cout<<bit<<endl;
        int f=(1LL<<bit);
        bool flag=false;
        for(vector<int> v:vv){
            vector<int> x,y;
            for(int i:v){
                if(a[i]&f)x.push_back(i);
                else y.push_back(i);
            }
            if(x.size()==0 || y.size()==0){
                flag=true;
                temp1.push_back(v);
            }
            else{
                temp2.push_back(x);
                temp2.push_back(y);
            }

            /*
            cout<<"DEBUG"<<endl;
            //for(vector<int> v:x){
                for(int i:x)cout<<i<<" ";
                //cout<<endl;
            //}
            cout<<endl<<endl;

            cout<<"DEBUG"<<endl;
            //for(vector<int> v:y){
                for(int i:y)cout<<i<<" ";
                //cout<<endl;
            //}
            cout<<endl<<endl;
            */

        }
        if(flag){
            vv=temp1;
        }
        else{
            ans+=f;
            vv=temp2;
        }
        temp1.clear();
        temp2.clear();

        /*
        cout<<"DEBUG"<<endl;
        for(vector<int> v:vv){
            for(int i:v)cout<<i<<" ";
            cout<<endl;
        }
        cout<<endl<<endl;
        */

    }
    cout<<ans<<endl;
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
