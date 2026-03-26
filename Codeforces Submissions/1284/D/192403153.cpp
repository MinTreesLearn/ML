#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <chrono>
#include <random>

#define ld long double
#define ll long long
using namespace std;

struct event{
    int t, type, id;
    event(int t, int type, int id) : t(t), type(type), id(id) {}
};

bool operator<(event a, event b){
    if(a.t==b.t){
        if(a.type==b.type){
            return a.id < b.id;
        }
        return a.type>b.type;
    }
    return a.t<b.t;
}

void solve(){
    int n;
    cin>>n;
    mt19937_64 gen(time(NULL));
    uniform_int_distribution<ll> distribution(1,1e9);
    vector<ll> hash(n);
    for(int i=0;i<n;i++){
        hash[i] = distribution(gen);
    }
    vector<event> a,b;
    for(int i=0;i<n;i++){
        int l1,r1, l2, r2;
        cin>>l1>>r1>>l2>>r2;
        a.emplace_back(l1,1,i);
        a.emplace_back(r1+1,2,i);
        b.emplace_back(l2,1,i);
        b.emplace_back(r2+1,2,i);
    }
    set<ll> founda,foundb;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll curr = 0;
    for(int i=0;i<a.size();i++){
        auto e = a[i];
        if(e.type==1){
            curr += hash[e.id];
        }
        else{
            curr -= hash[e.id];
            continue;
        }
        if(i!=a.size()-1 and a[i+1].type == 2){
            founda.insert(curr);
        }
    }
    // set<int> in;
    for(int i=0;i<b.size();i++){
        auto e = b[i];
        if(e.type==1){
            curr += hash[e.id];
        }
        else{
            curr -= hash[e.id];
            continue;
        }
        if(i!=b.size()-1 and b[i+1].type == 2){
            foundb.insert(curr);
        }
    }
    for(auto vala:founda){
        if(!foundb.count(vala)){
            cout<<"NO\n";
            return;
        }
    }
    for(auto valb:foundb){
        if(!founda.count(valb)){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    // cin >> t;
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve();
    }
}