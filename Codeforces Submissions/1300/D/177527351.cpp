#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
map<pair<int,int>,int> H;
int n;
long long x[maxn],y[maxn];
int main(){
    cin>>n;
    long long midx=0,midy=0;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];x[i]*=n,y[i]*=n;
        midx+=x[i],midy+=y[i];
        H[make_pair(x[i],y[i])]=1;
    }
    midx/=n,midy/=n;
    for(int i=0;i<n;i++){
        if(H[make_pair(2*midx-x[i],2*midy-y[i])]==0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}