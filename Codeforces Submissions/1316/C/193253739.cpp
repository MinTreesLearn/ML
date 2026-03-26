#include<bits/stdc++.h>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n, m, p;
	cin>>n>>m>>p;
	
	vector<int> A(n);
	vector<int> B(m);
	
	int mina = n;
	int minb = m;
	
	for(int i = 0; i<n; i++){
		cin>>A[i];
	}
	for(int i = 0; i<m; i++){
		cin>>B[i];
	}
	
	for(int i = 0; i<n; i++){
		if(A[i]%p != 0){
			mina = i;
			break;
		}
	}
	
	for(int i = 0; i<m; i++){
		if(B[i]%p != 0){
			minb = i;
			break;
		}
	}
	
	cout<<mina+minb<<"\n";
	
	return 0;
}