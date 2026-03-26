#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
/*
╭╮╱╱╱╱╱╱╱╱╭━╮
┃┃╱╱╱╱╱╱╱╱┃╭╯
┃╰━┳━━┳━━┳╯╰╮
┃╭╮┃╭╮┃╭╮┣╮╭╯
┃┃┃┃╰╯┃╰╯┃┃┃
╰╯╰┻━╮┣━╮┃╰╯
╱╱╱╭━╯┣━╯┃
╱╱╱╰━━┻━━╯
*/
#include<bits/stdc++.h>
using namespace std;
#define itn int
#define ll long long
#define endl "\n"
#define connect_yesno() string yesno(bool o,string yes="YES",string no="NO"){if(o){return yes;}return no;}
#define connect_math() vector<bool> resheto_eratosfena(int n){vector<bool> prime(n+1,true);prime[0]=prime[1]=false;for(int i=2;i<=n;i++){if(prime[i]){if(prime[i]){if(i*1LL*i<=n){for(int j=i*i;j<=n;j+=i){prime[j]=false;}}}}}return prime;};bool primer(long long k){if(k==0 or k==1 or k<0 or !(k&1)){return false;}for(long long i=3LL;i*i<=k;i++){if(k%i==0){return false;}}return true;}int phunkcia_ailera(int n){int result=n;for(int i=2;i*i<=n;i++){if (n % i == 0) {while (n % i == 0){n /= i;}result -= result / i;}}if (n > 1){result -= result / n;}return result;}long long pow(long long a,long long n){int res = 1;while (n){if (n & 1) {res *= a;--n;}else {a *= a;n >>= 1;}}return res;}long long gcd (long long a, long long b) {	while (b) {		a %= b;swap (a, b);}return a;}long long findD(long long x1,long long y1,long long x2,long long y2){long long a=abs(x1-x2),b=abs(y1-y2);return sqrtl(a*a+b*b);}long long findS(long long a,long long b,long long c){long long p=(a+b+c)/2;return sqrtl(p*(p-a)*(p-b)*(p-c));}
#define connect_inout() long long inll(){long long x;cin>>x;return x;}
#define pb push_back
#define mp make_pair
#define pbmp(a,b) pb(mp(a,b))
#define F first
#define S second
connect_yesno();
connect_inout();
ll d[200][200];
void gogo(){
    int n,mx=-1,t=0;
    cin>>n;
    itn cnt2[n+1];
    fill(cnt2+1,cnt2+n+1,0);
    pair<int,int>q[2*n+1];
    set<int>st;
    st.clear();
    mx=-1;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        cnt++;
        q[cnt]={l,-i};
        cnt++;
        q[cnt]={r,i};
    }
    sort(q+1,q+cnt+1);
    for(int i=1;i<=cnt;i++){
        int j=q[i].second;
        if(j>0){
            if(st.size()==1){
                cnt2[j]--;
            }
            st.erase(j);
        }else{
            if(st.empty()){
                cnt2[-j]--;
            }
            st.insert(-j);
        }
        if(st.size()==1){
           cnt2[*st.begin()]++;
        }else if(st.empty()){
            t++;
        }
    }
    for(int i=1;i<=n;i++){
        mx=max(mx,cnt2[i]);
    }
    cout<<mx+t<<endl;
}
main(){
    
    int t;
    cin>>t;
    while(t--){
        gogo();
    }
}