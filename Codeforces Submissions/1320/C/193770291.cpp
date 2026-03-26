#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
#define endl '\n'
#define ilihg ios_base::sync_with_stdio(false);cin.tie(NULL)

int c[1000001];
void build(int i,int l,int r,int a[],vector<ll> &t){
    if(l==r){
        t[i]=a[l];
    }
    else{
        int mid=(l+r)/2;
        build(2*i+1,l,mid,a,t);
        build(2*i+2,mid+1,r,a,t);
        t[i]=max(t[2*i+1],t[2*i+2]);
    }
}
void propagate(int i,int l,int r,vector<ll> &t,vector<ll> &p){
    t[i]+=p[i];
    if(l!=r){
        p[2*i+1]+=p[i];
        p[2*i+2]+=p[i];
    }
    p[i]=0;
}
void update(int i,int tl,int tr,int l,int r,ll val,vector<ll> &t,vector<ll> &p){
    propagate(i,tl,tr,t,p);
    if(tl>=l&&tr<=r){
        p[i]+=val;
    }
    else{
        int mid=(tl+tr)/2;
        if(mid>=l){
            update(2*i+1,tl,mid,l,r,val,t,p);
        }
        if(mid+1<=r){
            update(2*i+2,mid+1,tr,l,r,val,t,p);
        }
        propagate(2*i+1,tl,mid,t,p);
        propagate(2*i+2,mid+1,tr,t,p);
        t[i]=max(t[2*i+1],t[2*i+2]);
    }
}
ll query(int i,int tl,int tr,int l,int r,vector<ll> &t,vector<ll> &p){
    propagate(i,tl,tr,t,p);
    if(tl>=l&&tr<=r){
        return t[i];
    }
    else{
        int mid=(tl+tr)/2;
        ll k=-1e9;
        if(mid>=l){
            k=max(k,query(2*i+1,tl,mid,l,r,t,p));
        }
        if(mid+1<=r){
            k=max(k,query(2*i+2,mid+1,tr,l,r,t,p));
        }
        return k;
    }
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	clock_t time_req=clock();
	ilihg;
	int t=1;
    // cin>>t;
    while(t--){
       	int n,m,q;
       	cin>>n>>m>>q;
       	pair<int,int> a[n],b[m];
       	for(int i=0;i<n;i++){
       		cin>>a[i].first>>a[i].second;
       	}
       	sort(a,a+n);
       	for(int i=0;i<m;i++){
       		cin>>b[i].first>>b[i].second;
       	}
       	sort(b,b+m);
       	int k=-2e9;
       	int j=m-1;
       	for(int i=1000000;i>=0;i--){
       		while(j>=0&&b[j].first>i){
       			k=max(k,-b[j].second);
       			j--;
       		}
       		c[i]=k;
       	}
       	vector<ll> t(4000001),p(4000001);
       	build(0,0,1000000,c,t);
       	vector<pair<pair<int,int>,int>> v(q);
       	for(int i=0;i<q;i++){
       		cin>>v[i].first.first>>v[i].first.second>>v[i].second;
       	}
       	sort(v.begin(),v.end());
       	j=0;
       	ll ans=-2e9;
       	for(int i=0;i<n;i++){
       		while(j<q&&v[j].first.first<a[i].first){
       			update(0,0,1000000,v[j].first.second,1000000000,v[j].second,t,p);
       			j++;
       		}
       		ans=max(ans,query(0,0,1000000,0,1000000,t,p)-a[i].second);
       	}
       	cout<<ans<<endl;
    }
#ifndef ONLINE_JUDGE
    cout<<"Time : "<<fixed<<setprecision(6)<<((double)(clock()-time_req))/CLOCKS_PER_SEC<<endl;
#endif    
}