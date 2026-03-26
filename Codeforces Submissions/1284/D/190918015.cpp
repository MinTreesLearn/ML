#include <bits/stdc++.h>

using namespace std;

#define dg(x) cout<<#x<<"="<<x<<endl

using ll = long long;

const int N = 1e5+5;

int n,sa[N],sb[N],ea[N],eb[N];
pair<pair<int,int>,int> t[N<<1];

bool chk(){
	for (int i=0; i<(n<<1); i+=2){
		t[i]={{sa[i/2],0},i/2};
		t[i+1]={{ea[i/2],1},i/2};
	}
	sort(t,t+(n<<1));
	multiset<int> s,e;
	for (int i=0; i<(n<<1); i++){
		int I=t[i].second;
		if (t[i].first.second==0){ // s
			s.insert(sb[I]),e.insert(eb[I]);
			if ((*s.rbegin())>(*e.begin())){
				return 0;
			}
		}
		else{ // e
			s.erase(s.find(sb[I])),e.erase(e.find(eb[I]));
		}
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for (int i=0; i<n; i++){
		cin>>sa[i]>>ea[i]>>sb[i]>>eb[i];
	}
	if (!chk()){
		cout<<"NO"<<endl;
		return 0;
	}
	swap(sa,sb),swap(ea,eb);
	if (!chk()){
		cout<<"NO"<<endl;
		return 0;
	}
	else{
		cout<<"YES"<<endl;
	}
	return 0;
}
