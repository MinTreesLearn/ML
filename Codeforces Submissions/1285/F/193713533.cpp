#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define all(v) v.begin(), v.end()
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e5+5;
vector<int>v[N], w[N];
int n, a[N], cnt[N], m[N];

bool cop(const int &j){
    ll res=0;
    for(int i: v[j])
        res+=m[i]*cnt[i];
    return res;
}

ll ans(int i){
    ll res=0, ls=0;
    stack<int>st;
    reverse(all(w[i]));
    int mm=1e5;
    memset(cnt, 0, 4*mm/i+8);
    for(int j: w[i]){
        ls=0;
        while(!st.empty() && cop(j)){
            for(int u:v[st.top()])
                --cnt[u];
            ls=st.top();
            st.pop();
        }
        res=max(res, ls*j);
        for(int u: v[j])
            ++cnt[u];
        st.push(j);
    }
    return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    sort(a, a+n);
    for(int i=1;i<N;++i){
        for(int j=i;j<N;j+=i)
            v[j].push_back(i);
    }
    for(int i=0;i<n;++i){
        for(int j: v[a[i]])
            w[j].push_back(a[i]/j);
    }
    m[1]=1;
    for(int i=2;i<N;++i){
        int x=i/v[i][1];
        if(x%v[i][1])
            m[i]=-m[x];
    }
    ll jav=0;
    for(int i=1;i<N;++i)
        jav=max(jav, ans(i)*i);
    cout<<jav<<'\n';
}
