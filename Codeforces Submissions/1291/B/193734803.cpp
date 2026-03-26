#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool> primes;

void seive(int n){
    primes.resize(n+1, true);
    primes[0] = false; primes[1] = false;
    for(int i=2; i*i<=n; i++){
        if(primes[i]){
            for(int j=i*i; j<=n; j+=i) primes[j] = false;
        }
    }
}

ll kadane(vector<ll> &vec, ll start, ll end) { //largest sum of contiguous subarray
    ll currSum = 0, maxSum = INT_MIN;
    for(ll i = start; i < end; i++) {
        currSum += vec[i];
        if(currSum < 0) currSum = 0;
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

void solve(){
	ll n; cin>>n;
    ll i = 0;
    vector<ll> a(n);
    while(i < n) cin>>a[i++];

    if(n == 1) {cout<<"Yes\n"; return;}

    ll l = n-1, r = 0;
    for(i=0; i<n; i++) {
        if(a[i] <= i-1) {l = i-1; break;}
    }
    for(i=n-1; i>=0; i--) {
        if(a[i] <= n-i-2) {r = i+1; break;}
    }

    if(l >= r) cout<<"Yes\n";
    else cout<<"No\n";
    
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}