#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define MOD 1e9 + 7;
#define loop_up(a,b) for(ll i=a;i<b;i++)
#define loop_down(a,b) for(ll i=a;i>b;i--)
#define TEST ll t; cin>>t; while(t--)
vector <ll> prime_factors;

//__gcd(a,b) is used to find GCD of 2 numbers.

//bin-pow (binary exponentiation) - (a^b)%m types.
ll pw(ll a, ll b, ll m){
    if(b==0){
        return a%m;
    }
    if(b%2==0){
        ll t=pw(a, b/2, m);
        return(t*t%m);
    }
    else{
        ll t=pw(a,(b-1)/2, m);
        t=(t*t%m);
        return(a*t%m);
    }
}

//multiplicative inverse for division under mod provided that M IS PRIME.
// (a/b)%m = a*(inv b)%m
//invb is multiplicative inverse for division under mod for b - this function returns that
ll modinv(ll x, ll m){
    return(pw(x,m-2,m));
}

//PRIME NUMBER CHECK
bool isPrime(ll p){
    if(p==1)return false;
    if(p==2 | p==3)return true;
    if(p%2==0 | p%3==0)return false;
    for(ll i=5; i*i<p; i+=6)
        if(p%i==0 | p%(i+2)==0)
            return false;
    return true;
}

//SIEVE OF ERATOSTHENES - prime factors
//remove < if(n%i==0) > to return lll prime numbers before some n
void sieve(ll n){
    vector<bool> temp_isPrime(n+1, true);
    prime_factors.clear();
    for(ll i=2; i<=n; i++){
        if(temp_isPrime[i]){
            if(n%i==0)
                prime_factors.push_back(i);
            for(ll j=i*i; j<=n; j+=i){
                temp_isPrime[j]=false;
            }
        }
    }
}

//PALINDROME CHECK
bool isPalindrome(string x){
    ll i=0; ll j=x.length()-1;
    while(i<=j){
        if(x[i]!=x[j])
            return(false);
        i++; j--;
    }
    return(true);
}

//STRING REVERSAL
string reverse(string str){
    ll len = str.length();
    ll n = len;
    string r="";
    while(n--)
        r+=str[n];
    return(r);
}

ll digitsum(ll x){
    ll sum=0;
    while(x>0){
        sum+=(x%10);
        x/=10;
    }
    return(sum);
}
bool mycmp(pair<ll,ll> a, pair<ll,ll> b){
    return(a.first<b.first);
}

int main() {
    string s;
    cin>>s;
    ll n=s.length();
    ll op[n],cl[n];
    ll cnt=0;
    vector<ll> v1,v2;
    loop_up(0,s.length()){
        if(s[i]=='('){
            cnt++;
            v1.push_back(i+1);
        }
        else{
            v2.push_back(i+1);
        }
        op[i]=cnt;
    }
    cnt=0;
    loop_down(s.length()-1,-1) {
        if (s[i] == ')') {
            cnt++;
        }
        cl[i] = cnt;
    }
    ll j=-1,i;
    for(i=0; i<n; i++){
        if(op[i]>cl[i]){
            j=i-1;
            break;
        }
    }
    if(j==-1){
        if((op[n-1]==1) & (cl[n-1]==1)){
            cout<<1<<endl;
            cout<<2<<endl;
            cout<<1<<' '<<n<<endl;
        }
        else
            cout<<0<<endl;
    }
    else if(op[j]==0){
        cout<<0<<endl;
    }
    else{
        cout<<1<<endl;
        cout<<op[j]*2<<endl;
        for(ll i=0; i<op[j]; i++)
            cout<<v1[i]<<' ';
        ll l=v2.size()-1;
        vector<ll> temp;
        while(op[j]--){
            temp.push_back(v2[l]);
            l--;
        }
        for (auto it = temp.end() - 1; it >= temp.begin(); it--)
            cout << *it << " ";
    }
}


