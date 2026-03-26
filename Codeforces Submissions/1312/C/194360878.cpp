#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vl vector<ll>
#define pl pair<ll, ll>
#define vi vector<int>
#define pi pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fl(i, a, b) for (ll i = a; i <= b; i++)
#define bfl(i, k, n) for (ll i = k; i > n; i--)
#define prDouble(d) cout << fixed << setprecision(10) << d
#define deb(x) cerr << #x << " = " << x << "   "
#define endl "\n"
#define int long long
#define inf 1e18

const int mod = 1000000007;
double epsilon = 1e-6;
/*-----------------------------------------------------------------------------------------*/
void init_code()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE;
}

int modularExponentiation(int x,int n,int M){
    int result=1;
    while(n>0){
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}
int modInverse(int A,int M){
    return modularExponentiation(A,M-2,M);
}





void solve()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];   

    set<int> st;    
    for(int i=0;i<n;i++){
        if(arr[i]==0) continue;
        
        int val = arr[i];
        int idx = 0;
        while(val>0){
            idx++; val/=k;
        }
        //idx++;
        deb(idx);
        val = arr[i];
        while(val>0){
            int den = pow(k,idx);
            if(den>val){idx--; continue;}

            int quo = val/den;
            //deb(den);
            if(quo==0) {idx--; continue;}
            if(quo>1 or st.find(idx)!=st.end()){cout<<"NO"<<endl; return;}
            st.insert(idx);
            val = val - den;
            idx--;
            //deb(val);
        }
           

        
    }

    cout<<"YES"<<endl;

       

       



    return;


}


signed main()
{

   init_code();
   auto start_time = std::chrono::high_resolution_clock::now();

    int T;
    cin>>T;

    //T = 1;

    while (T--)
    {
        solve();
    }

   auto stop_time = std::chrono::high_resolution_clock::now();
   auto duration = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);

#ifndef ONLINE_JUDGE
   cerr << "Time: " << duration.count() / 1000. << " ms" << endl;
#endif

    return 0;
}
