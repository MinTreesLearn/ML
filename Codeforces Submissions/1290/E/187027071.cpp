// LUOGU_RID: 98169450
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i <= b; i++)
const int N=8e5+10;
#define int long long
int n,a[N],p[N];
struct Seg{
  int c[N],v[N],s[N],tg[N],stg[N],len[N],sln[N];
  long long sum[N];
  void cls(){
      rep(i,0,n<<2)c[i]=v[i]=s[i]=tg[i]=stg[i]=len[i]=sln[i]=sum[i]=0;
  }
  void pushup(int k){
      int L=k<<1,R=k<<1|1;
      c[k]=c[L]+c[R],len[k]=len[L]+len[R],sum[k]=sum[L]+sum[R];
      if(v[L]>v[R]){
         v[k]=v[L],s[k]=max(s[L],v[R]);
         len[k]=len[L],sln[k]=sln[L]+len[R]+sln[R];
      }else if(v[L]<v[R]){
          v[k]=v[R],s[k]=max(v[L],s[R]);
          len[k]=len[R],sln[k]=sln[R]+len[L]+sln[L];
      }else{
          v[k]=v[L],s[k]=max(s[L],s[R]);
          len[k]=len[L]+len[R],sln[k]=sln[L]+sln[R];
      }
  }
  void upd(int k,int t1,int t2){
      v[k]+=t1;tg[k]+=t1;s[k]+=t2;stg[k]+=t2;
      sum[k]+=1ll*t1*len[k]+1ll*t2*sln[k];
  }
  void pushdown(int k){
      int L=k<<1,R=k<<1|1;
      bool tu=v[R]>=v[L];
      if(v[L]>=v[R])upd(L,tg[k],stg[k]);
      else upd(L,stg[k],stg[k]);
      if(tu)upd(R,tg[k],stg[k]);
      else upd(R,stg[k],stg[k]);
      tg[k]=stg[k]=0;
  }
  int adpp(int l,int r,int k,int L,int R){
      if(L>r||R<l)return 0;
      if(L<=l&&r<=R) return upd(k,1,1),c[k];
      int mid=l+r>>1;
      pushdown(k);int sum=0;
      sum+=adpp(l,mid,k<<1,L,R)+adpp(mid+1,r,k<<1|1,L,R);
      pushup(k);return sum;
  }
  void modi(int l,int r,int k,int p,int ti){
      if(l==r)return sum[k]=v[k]=ti,len[k]=c[k]=1,sln[k]=0,void();
      int mid=l+r>>1;
      pushdown(k);
      if(p<=mid)modi(l,mid,k<<1,p,ti);
      else modi(mid+1,r,k<<1|1,p,ti);
      pushup(k);
  }
  void pmin(int l,int r,int k,int L,int R,int ti){
      if(L>r||R<l||ti>=v[k])return;
      if(L<=l&&R>=r&&ti>=s[k]){
          return upd(k,ti-v[k],0),void();
      }int mid=l+r>>1;pushdown(k);
      pmin(l,mid,k<<1,L,R,ti);
      pmin(mid+1,r,k<<1|1,L,R,ti);
      pushup(k);
  }
}seg;
long long res[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    rep(i,1,n){cin>>a[i];p[a[i]]=i;}
    rep(t,1,2){
        seg.cls();
        rep(i,1,n){
            int w=seg.adpp(1,n,1,p[i]+1,n);
            seg.modi(1,n,1,p[i],i+1);
            seg.pmin(1,n,1,1,p[i]-1,i-w);
            res[i]+=seg.sum[1];
        }
        reverse(a+1,a+n+1);
        rep(i,1,n){p[a[i]]=i;}
    }rep(i,1,n)cout<<res[i]-1ll*i*(i+2)<<'\n';
}