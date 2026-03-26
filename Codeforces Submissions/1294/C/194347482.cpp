#pragma GCC optimize("O3,inline")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) a.begin(), a.end()
#define lpr(i,a,b) for(ll i = a; i >= b; i--)
#define lp(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define pp pop_back
#define endl "\n"
using namespace std;
// const int imax = std::numeric_limits<int>::max();
// using vi = vector<int>;
// 
//ll st,en,n;
 // map<ll,int>ans;
// const int NN=1e6;
// int a[NN];
// vector<vector<int>>adjList(NN);
// set<int>nodes;
// /* printPath - implementation at the end */    
// void printPath(int s, int t, const vi &path);
// 
/*input:
* n is number of the nodes in the Graph
* adjList holds a neighbors vector for each Node
* s is the source node
*/
// 
// void dfs(int n, vector<vi> adjList, int s)
// {
    // //imax declared above as the max value for int (in C++)
    // vector<int> distance(n, imax);
    // vi path;
    // queue<int> q; q.push(s); distance[s] = 0;
// 
    // while (!q.empty()) {
        // auto curr = q.front(); q.pop();
// 
        // for (int i = 0; i < (int)adjList[curr].size(); ++i) {
            // if (distance[i] == imax) {
                // distance[i] = distance[curr] + 1;
                // //save the parent to have the path at the end of the algo.
                // path[i] = curr;
            // }
        // }//for
    // }//while
     // /* t can be anything you want */
    // //int t = 5;
    // printPath(a[st-1], a[en-1], path); cout << endl;
// }
// 
// /* print the shortest path from s to t */ 
// void printPath(int s, int t, const vi &path)
// {
    // if (t == s) {
        // return;
    // }
    // printPath(s, path[t], path);
    // cout << ans[path[t]];
// }
//cout<<setprecision(13)<<n*p;
 // ll gcd(ll x, ll y) {
	  // if (x == 0) return y;
	  // if (y == 0) return x;
	  // return gcd(y, x % y);
	// }
	// bool isprime(ll n) { 
	  // if (n <= 1) return false; 
	  // if (n <= 3) return true; 
// 	  
	  // if (n % 2 == 0 || n % 3 == 0) return false; 
// 	  
	  // for (ll i = 5; i * i <= n; i += 6) 
		// if (n % i == 0 || n % (i+2) == 0) 
		  // return false; 
// 	  
	  // return true; 
	// } 
// 	 
	// bool prime[15000105]; 
	// void sieve(int n) { 
	  // for (ll i = 0; i <= n; i++) prime[i] = 1;
	  // for (ll p = 2; p * p <= n; p++) { 
		// if (prime[p] == true) { 
		  // for (ll i = p * p; i <= n; i += p) 
			// prime[i] = false; 
		// } 
	  // } 
	  // prime[1] = prime[0] = 0;
	// } 
// 	
// ll fast_power(ll b,ll p,ll m)
// {
    // if(p==0) return 1;
    // if(p%2==0)
    // {
        // ll ans=fast_power(b,p/2,m);
        // return(ans*ans)%m;
    // }else{
        // return (b%m*fast_power(b,p-1,m))%m;
        // }

//}
// 
// ll mod=1e9+7;
ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
  
 ll m=1e9+7;
 vector<ll>ans;
void genrate(ll n)
{
	if(n>1e10)return;
	ans.pb(n);
	genrate(n*10);
	genrate(n*10+1);
}
int main()
{
      // ofstream out("number2.out");
         ifstream in("hanya.in");
        
ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        	int t; cin>>t;
        	while(t--)
        	{
        		ll n; cin>>n;
        		map<ll,ll>m;
        		vector<ll>ans;
        	for(int i=2;1LL*i*i<=n;i++)
        	   {
        	   	while(n%i==0)
        	   	{
        	   		ans.pb(i);
        	   		n/=i;
        	   	}
        	   }
        	   if(n>1)ans.pb(n);
        	   sort(all(ans));
        	   set<ll>st;
        	   st.insert(ans[0]);
        	   if(ans[0]==ans[1])
        	   {
        	   	st.insert(ans[1]*ans[2]);
        	   	ll x=1;
        	   	for(int i=3;i<ans.size();i++)
        	   	 x*=ans[i];
        	   	 st.insert(x);
        	   }else{
        	   	st.insert(ans[1]);
        	   	ll x=1;
        	   	for(int i=2;i<ans.size();i++)
        	   	 x*=ans[i];
        	   	 st.insert(x);
        	   }
        	   if(st.size()==3)
        	   {
        	   vector<ll>a;
        	   for(auto it:st)a.pb(it);
        	   if(a[0]>=2 and a[1]>=2 and a[2]>=2)
        	   {
        	   	cout<<"YES\n";
        	   for(auto it:a)cout<<it<<" ";
        	   cout<<"\n";
        	   }else cout<<"NO\n";
        	   }else cout<<"NO\n";
        	}
}

 