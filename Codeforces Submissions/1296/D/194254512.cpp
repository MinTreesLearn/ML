#include<iostream>
using namespace std;
#include <iostream>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define sst string
#define pb push_back
#define maxco 100000+5
#define lld long double
#define cha ios_base::sync_with_stdio(false);
#define ffl cout.flush();
#define phi acos(-1)
#define mod 1000000007
ll n,m;
ll dp[5006][3];
ll s[200068];
map<ll,ll> cnt;
vector <ll> vec;
int main(){
    cha
    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    for(ll i=1;i<=n;i++){
        cin>>s[i];
        s[i]%=(a+b);
        if(s[i]==0){
            s[i]=a+b;
        }
    }
    ll ans=0;
    sort(s+1,s+n+1);
    for(ll i=1;i<=n;i++){
        if(s[i]<=a){
            ans++;
        }
        else{
            s[i]-=a;
            ll need=s[i]+a-1;
            need/=a;
            if(need<=k){
                ans++;
                k-=need;
            }
            else{
                break;
            }
        }
    }
    cout<<ans;
}




/*
 3
 
 5 1 7
 4 6 2
 9 3 8
 
 
 1 4 7
 3 6 9
 5 8 2
 
 1 5 9 13
 4 8 12 16
 7 11 15 3
 10 14 2 6
 
 */
