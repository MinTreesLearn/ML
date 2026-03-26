#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long long
#define X first
#define Y second
typedef pair<double,double>pdd;
pdd operator+(pdd a,pdd b){return {a.X+b.X,a.Y+b.Y }; }
pdd operator-(pdd a,pdd b){return {a.X-b.X,a.Y-b.Y}; }
pdd operator*(pdd a,double b){return {a.X*b,a.Y*b}; }
pdd operator/(pdd a,double b){return {a.X/b,a.Y/b}; }
double cross(pdd a,pdd b){return a.X*b.Y-a.Y*b.X; }
double dot(pdd a,pdd b){return a.X*b.X+a.Y*b.Y;}
bool ptinline(pdd a,pdd b,pdd c){return (cross(b-a,c-a)==0);  }
int sgn(int a){if(a==0){return 0;}if(a<0){return -1;}if(a>0){return 1;}  }

bool cmp(pdd i,pdd j){
int ac=0;int bc=0;
if(i.X>0){ac=1;}
if(i.X==0&&i.Y>0){ac=1;}
if(j.X>0){bc=1;}
if(j.X==0&&j.Y>0){bc=1;}
if(ac&&!bc){return 1;}
if(bc&&!ac){return 0;}
if(cross(i,j)<0){return 1;}
return 0;
}

bool same(pdd a,pdd b){if(sgn(a.X)!=sgn(b.X)){return 0;}if(sgn(a.Y)!=sgn(b.Y)){return 0;}return 1;}
int n;
pdd tar[3000];
vector<pdd>ar;
int ans;
void solve(){
int nn=ar.size();
for(int i=0;i<nn;i++){
    ar.push_back(ar[i]);
}
int rit=0;//cout<<endl;
for(int i=0;i<nn;i++){
    rit=max(rit,i);
    while(cross(ar[i],ar[rit+1])<0){rit++;}
    int vtc=rit-i;
   // cout<<i<<" "<<rit<<endl;
    ans-=(vtc*(vtc-1)*(vtc-2))/6;
}


}


signed main(){

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tar[i].X>>tar[i].Y;
    }
ans=0;
    for(int i=1;i<=n;i++){
            ar.clear();
        for(int j=1;j<=n;j++){
           if(i==j){continue;}
            ar.push_back(tar[i]-tar[j]);
        }
        sort(ar.begin(),ar.end(),cmp);
        solve();
        ans+=((n-1)*(n-2)*(n-3)*(n-4))/24;
    }
    cout<<ans<<endl;


}
