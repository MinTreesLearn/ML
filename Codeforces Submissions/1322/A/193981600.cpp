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
    string s; cin>>s;

    ll i, c = 0;
    for(i=0; i<n; i++) {
        if(s[i] == '(') ++c;
        else --c;
    }
    if(c != 0) {cout<<-1; return;}

    ll l = 0, ans = 0;
    for(i=0; i<n; i++) {
        if(s[i] == '(') ++c;
        else --c;
        if(c==0 && s[l]!='(' && s[i]!=')') {
            ans += i-l+1;
        }
        if(c==0) l = i+1;
    }

    cout<<ans;

}

int main(){
	solve();
}