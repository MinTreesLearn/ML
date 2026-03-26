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
       	int n,m;
       	cin>>n>>m;
       	vector<int> v(n+1);
       	indexed_set s,p;
       	int r[n+1],l[n+1];
       	for(int i=1;i<=m;i++){
       		int k;
       		cin>>k;
       		if(v[k]==0){
       			r[k]=s.size()-s.order_of_key(k)+k;
       			s.insert(k);
       			v[k]=i;
       			p.insert(i);
       		}
       		else{
       			r[k]=max(r[k],(int)p.size()-(int)p.order_of_key(v[k]));
       			p.erase(v[k]);
       			p.insert(i);
       			v[k]=i;
       		}
       	}
       	for(int i=1;i<=n;i++){
       		if(v[i]==0){
       			l[i]=i;
       			r[i]=s.size()-s.order_of_key(i)+i;
       			r[i]=min(r[i],n);
       		}
       		else{
       			l[i]=1;
       			r[i]=max(r[i],(int)p.size()-(int)p.order_of_key(v[i]));
       			r[i]=min(r[i],n);
       		}
       		cout<<l[i]<<" "<<r[i]<<endl;
       	}
    }
#ifndef ONLINE_JUDGE
    cout<<"Time : "<<fixed<<setprecision(6)<<((double)(clock()-time_req))/CLOCKS_PER_SEC<<endl;
#endif    
}