#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

vector<int> findz(string a){
    int n=a.size();
    vector<int> re(n);
    re[0]=n;
    int l=0,r=0;
    vector<int> z;
    int flag=0;
    for(int i=1;i<n;i++){
        if(i+re[i-l]<r){
            re[i]=re[i-l];
        }
        else{
            l=i;
            if(i>r){
                r=i;
            }
            while(r<n && a[r]==a[r-l]){
                r++;
            }
            re[i]=r-l;
        }
        if(flag){
            z.push_back(re[i]);
        }
        if(a[i]=='$'){
            flag=1;
        }
    }
    return z;
}
struct BIT{
    int n;
    vector<int> bt;
    void init(int x){
        n=x;
        bt.resize(n+1);
    }
    void update(int x,int y){
        for(;x>0;x-=x&(-x)){
            bt[x]+=y;
        }
    }
    int query(int x){
        int ans=0;
        for(;x<=n;x+=(x&-x)){
            ans+=bt[x];
        }
        return ans;
    }
};
signed main(){
    AquA;
    int n,m;
    cin >> n >> m;
    string a,b,s;
    cin >> a >> b >> s;
    auto w=s+"$"+a;
    auto z1=findz(w);
    w=b+"$"+s;
    reverse(w.begin(),w.end());
    auto z2=findz(w);
    reverse(z2.begin(),z2.end());
    for(auto &h:z1){
        if(h==m){
            h--;
        }
    }
    for(auto &h:z2){
        if(h==m){
            h--;
        }
    }
    BIT bt,bt2;
    bt.init(m);
    bt2.init(m);
    int ans=0;
    int l=0,r=0;
    auto add=[&](int x,int y){
        bt.update(x,y*x);
        bt2.update(x,y);
    };
    for(int i=0;i<n;i++){
        while(l<i){
            add(z2[l],-1);
            l++;
        }
        while(r<n && r-i<=m-2){
            add(z2[r],1);
            r++;
        }
        if(z1[i]==0){
            continue;
        }
        ans+=bt.query(m-z1[i])+bt2.query(m-z1[i])*(z1[i]-m+1);
    }
    cout << ans << "\n";
    return 0;
}
