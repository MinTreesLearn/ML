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

void build(int i,int l,int r,vector<ll> &t){
    if(l==r){
        t[i]=-1;
    }
    else{
        int mid=(l+r)/2;
        build(2*i+1,l,mid,t);
        build(2*i+2,mid+1,r,t);
        t[i]=min(t[2*i+1],t[2*i+2]);
    }
}
void update(int i,int tl,int tr,int l,int r,ll val,vector<ll> &t,vector<ll> &p){
    if(tl>=l&&tr<=r){
        t[i]=max(t[i],val);
    }
    else{
        int mid=(tl+tr)/2;
        if(mid>=l){
            update(2*i+1,tl,mid,l,r,val,t,p);
        }
        if(mid+1<=r){
            update(2*i+2,mid+1,tr,l,r,val,t,p);
        }
        t[i]=min(t[2*i+1],t[2*i+2]);
    }
}
ll query(int i,int tl,int tr,int l,int r,vector<ll> &t,vector<ll> &p){
    if(tl>=l&&tr<=r){
        return t[i];
    }
    else{
        int mid=(tl+tr)/2;
        ll k=27;
        if(mid>=l){
            k=min(k,query(2*i+1,tl,mid,l,r,t,p));
        }
        if(mid+1<=r){
            k=min(k,query(2*i+2,mid+1,tr,l,r,t,p));
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
       	int n;
       	cin>>n;
       	string s;
       	cin>>s;
       	int a[n];
       	int k=0;
       	vector<ll> t(4*n),p(4*n);
       	build(0,0,n-1,t);
       	for(int i=0;i<n;i++){
       		int l=0;
       		int r=n-1;
       		while(l<r){
       			int m=(l+r)/2;
       			if(query(0,0,n-1,m,m,t,p)<=s[i]-97){
       				r=m;
       			}
       			else{
       				l=m+1;
       			}
       		}
       		k=max(k,l+1);
       		a[i]=l+1;
       		update(0,0,n-1,l,l,s[i]-97,t,p);
       	}
       	cout<<k<<endl;
       	for(int i=0;i<n;i++){
       		cout<<a[i]<<" ";
       	}
       	cout<<endl;
    }
#ifndef ONLINE_JUDGE
    cout<<"Time : "<<fixed<<setprecision(6)<<((double)(clock()-time_req))/CLOCKS_PER_SEC<<endl;
#endif    
}