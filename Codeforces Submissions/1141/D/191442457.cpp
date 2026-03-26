#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb insert
#define mod 998244353
using namespace std;
mt19937 rng(time(0));
int random(int l, int r) { return rng() % (r - l + 1) + l; }
int main()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    map<int,set<int>>m;
    map<int,int>m1;
    set<pair<int,int>>ans;
    for(int i=0;i<n;i++)m[b[i]].pb({i+1});
    set<int>v,vektor,vektor1;
    map<int,int>mapa;
    for(int i=0;i<n;i++){
        if(a[i]=='?'){
            continue;
        }
        if(m[a[i]].size()){
            int r=*m[a[i]].begin();
            m[a[i]].erase(m[a[i]].begin());
            ans.pb({i+1,r});
            mapa[i+1]=1;
            m1[r]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(!m1[i]){
            if(b[i-1]!='?'){
                vektor.pb(i);
            }
        }
    }
    // spajam ? iz string a sa nekim slovom iz stringa b slobodnim
    // m1 je za string b
    for(int i=1;i<=n;i++){
        if(a[i-1]=='?'){
            // spajam sa vektorom
            if(!vektor.size())break;
            int r=*vektor.begin();
            ans.pb({i,r});
            vektor.erase(vektor.begin());
            m1[r]=1;
            mapa[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(!mapa[i]){
            if(a[i-1]!='?'){
                vektor1.pb(i);
            }
        }
    }
    // sad iz stringa B ? spajam sa nekim slovom iz a
    for(int i=1;i<=n;i++){
        if(b[i-1]=='?'){
            // spajam sa vektorom
            if(!vektor1.size())break;
            int r=*vektor1.begin();
            ans.pb({r,i});
            vektor1.erase(vektor1.begin());
            m1[i]=1;
            mapa[r]=1;
        }
    }
    set<int>s;
    for(int i=1;i<=n;i++){
        if(!m1[i]){
            if(b[i-1]=='?')s.pb(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(!mapa[i]){
            if(a[i-1]!='?')continue;
            if(!s.size())break;
            int r=*s.begin();
            ans.pb({i,r});
            s.erase(s.begin());
        }
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
