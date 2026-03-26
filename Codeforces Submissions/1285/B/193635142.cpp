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

ll kadane(vector<ll> &vec, ll start, ll end) {
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

    ll sum = 0;
    for(auto i:a) sum += i;
    ll x = max(kadane(a, 0, n-1), kadane(a, 1, n));
    if(x >= sum) cout<<"NO\n";
    else cout<<"YES\n";
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}