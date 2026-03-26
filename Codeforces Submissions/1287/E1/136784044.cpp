#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define LL long long
#define LD long double
#define pb push_back
#define F first
#define S second
const double PI=3.1415926535897932384626433;
const int KL=1e6;
const LL MOD=1e9+7;
using namespace std;


int q,x,y,z,n,m,a[KL],ans;
string t,s[KL];
map <string,int> mp;

void ask(int l,int r,int sign){
    if(l>r)return ;
    cout<<"? "<<l<<" "<<r<<endl;
    int tot=(r-l+1)*(r-l+2)/2;
    while(tot--){
        cin>>t;
        sort(all(t));
        mp[t]+= sign;
    }
}

map <char,int> fr;
int main()
{
    cin>>n;
    ask(1,n,1);
    ask(2,n,-1);
    int cnt=0;
    vector <pair<int,int>> vec;
    for(auto v:mp){
        if(v.S==0)continue;
        s[cnt]=v.F;
        vec.pb({(v.F).size(),cnt});
        cnt++;
    }
    sort(all(vec));
    string ret;
    ret+=s[vec[0].S];
    fr[s[vec[0].S][0]]++;
    for(int i=1;i<vec.size();i++){
        int idx=vec[i].S;
        for(int j=0;j<s[idx].size();j++){
            fr[s[idx][j]]--;
        }
        for(char c='a';c<='z';c++){
            if(fr[c]==-1){
                ret+=c;
                break;
            }
        }
        fr.clear();
        for(auto v:s[idx])fr[v]++;
    }
    cout<<"! "<<ret<<endl;


    return 0;
}
