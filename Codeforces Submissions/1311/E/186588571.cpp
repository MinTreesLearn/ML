#include <bits/stdc++.h>
#include <fstream>
#include <ext/rope> //header with rope

using namespace __gnu_cxx;

#define pb push_back
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
const int N = 200001;
#define endl '\n'
#define int long long
#define ll long long
///int cnt[N+1]={0};
////vector<int>v[N+1];


/*int df(int x)
{
   //// cout<<x<<" "<<dp[x]<<endl;
    if(dp[x]!=-1)
    {
       /// cout<<x<<" "<<dp[x]<<endl;
        return dp[x];
    }
   /// cout<<"ppp"<<endl;
    int f=value[x];
    dp[x]=n-x+df(f);

   /// cout<<f<< " "<<dp[f]<<endl;
    return dp[x];

}
*/
int func( int i, int j, vector<int>a, int k)
{
    // Base condition.
    if(i==0)
    {
        return 0;
    }
    // Initialize 'ans'= '0'.
    int ans = 0;

    // If no operation is applied on the 'i'th index.
    if(j==0)
    {
        // Apply no operation the 'i-1'th index.
        ans = max(ans, abs(a[i] - a[i-1]) + func(i-1, 0, a, k));

        // Apply operation the 'i-1'th index.
        ans = max(ans, abs(a[i] - (a[i-1]^k)) + func(i-1, 1, a, k));
    }

    // If operation is applied on the 'i' the index.
    else
    {
        // Apply no operation the 'i-1'th index.
        ans = max(ans, abs((a[i]^k) - a[i-1]) + func(i-1, 0, a, k));

        // Apply operation the 'i-1'th index.
        ans = max(ans, abs((a[i]^k) - (a[i-1]^k)) + func(i-1, 1, a, k));
    }

    return ans;


}


int xorOrNot(int n, int k, vector<int>a)
{
    // If operation is not applied on the 'n-1'th index.
    int ans1 = func(n-1,0,a,k);

    // If operation is applied on the 'n-1'th index.
    int ans2 =  func(n-1,1,a,k);

    // Return max of the 'ans1' and 'ans2' as the final answer.
    return max(ans1,ans2);

}
class DSU
{
    int* parent;
    int* rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    // Union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2])
            {
                parent[s2] = s1;
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

class Graph
{
    vector<vector<int> > edgelist;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({ w, x, y });
    }

    void kruskals_mst()
    {
        // 1. Sort all edges
        sort(edgelist.begin(), edgelist.end());

        // Initialize the DSU
        DSU s(V);
        int ans = 0;

        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // Take this edge in MST if it does
            // not forms a cycle
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;

            }
        }

        cout <<-ans;
    }
};
int powe(int x, int y, int p)
{
    int res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res%p;
}

void solve()
{
    int n;
    cin>>n;
    // int a[n];
    int m,k;
    cin>>m>>k;
    int ma=0;
    map<int,int>p;
    for( int i=0; i<m; i++)
    {
        int x;
        cin>>x;
        p[x]++;
        ma=max(ma,x);
    }
    int u=(n+k-1)/k;
    int ava=1+(n-1)%k;

    if(ma>u ||( ma==u && p[ma]>ava))
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }

}
long long calculate(long long p,
                    long long q,long long mod)
{
    long long  expo;
    expo = mod - 2;

    // Loop to find the value
    // until the expo is not zero
    while (expo)
    {

        // Multiply p with q
        // if expo is odd
        if (expo & 1)
        {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;

        // Reduce the value of
        // expo by 2
        expo >>= 1;
    }
    return p%mod;
}

int vis[N+1];

// array to store inverse of 1 to N
int  factorialNumInverse[N + 1];

// array to precompute inverse of 1! to N!
int  naturalNumInverse[N + 1];

// array to store factorial of first N numbers
int fact[N + 1];

// Function to precompute inverse of numbers
void InverseofNumber(int p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(int  p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;

    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (calculate(1ll,i,p)* factorialNumInverse[i - 1]) % p;
}

// Function to calculate factorial of 1 to N
void factorial(int p)
{
    fact[0] = 1;

    // precompute factorials
    for (int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

// Function to return nCr % p in O(1) time
int Binomial(int N, int R, int p)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    int ans = ((fact[N] * factorialNumInverse[R])
               % p * factorialNumInverse[N - R])
              % p;
    return ans;
}
int seg[4*N+100],seg1[4*N+100],seg2[4*N+100],seg3[4*N+100];



void build(int node, int st, int en)
{
    if (st == en)
    {
        // left node ,string the single array element
        seg[node] = 1e9;
        return;
    }

    int mid = (st + en) / 2;

    // recursively call for left child
    build(2 * node, st, mid);

    // recursively call for the right child
    build(2 * node + 1, mid + 1, en);

    // Updating the parent with the values of the left and right child.
    seg[node] = min(seg[2 * node],seg[2 * node + 1]);
}

void update(int node, int st, int en, int l, int r, int val)
{

    if ((en < l) || (st > r)) // case 1
    {
        return;
    }
    if (st >= l && en <= r) // case 2
    {
        seg[node] =  val;

        return;
    }

    // case 3
    int mid = (st + en) / 2;

    // recursively call for updating left child
    update(2 * node, st, mid, l, r, val);
    // recursively call for updating right child
    update(2 * node + 1, mid + 1, en, l, r, val);

    // Updating the parent with the values of the left and right child.
    seg[node] =min(seg[2 * node],seg[2 * node + 1]);
}

int query(int node, int st, int en, int l, int r)
{


    // case 1
    if (en < l || st > r)
    {
        return 1e9;
    }

    // case 2
    if ((l <= st) && (en <= r))
    {
        return seg[node];
    }
    int mid = (st + en) / 2;

    //query left child
    ll q1 = query(2 * node, st, mid, l, r);

    // query right child
    ll q2 = query(2 * node + 1, mid + 1, en, l, r);

    return min(q1,q2);
}
void build1(int node, int st, int en)
{
    if (st == en)
    {
        // left node ,string the single array element
        seg1[node] = 1e9;
        return;
    }

    int mid = (st + en) / 2;

    // recursively call for left child
    build1(2 * node, st, mid);

    // recursively call for the right child
    build1(2 * node + 1, mid + 1, en);

    // Updating the parent with the values of the left and right child.
    seg1[node] = min(seg1[2 * node],seg1[2 * node + 1]);
}

void update1(int node, int st, int en, int l, int r, int val)
{

    if ((en < l) || (st > r)) // case 1
    {
        return;
    }
    if (st >= l && en <= r) // case 2
    {
        seg1[node] =  val;

        return;
    }

    // case 3
    int mid = (st + en) / 2;

    // recursively call for updating left child
    update1(2 * node, st, mid, l, r, val);
    // recursively call for updating right child
    update1(2 * node + 1, mid + 1, en, l, r, val);

    // Updating the parent with the values of the left and right child.
    seg1[node] =min(seg1[2 * node],seg1[2 * node + 1]);
}

int query1(int node, int st, int en, int l, int r)
{


    // case 1
    if (en < l || st > r)
    {
        return 1e9;
    }

    // case 2
    if ((l <= st) && (en <= r))
    {
        return seg1[node];
    }
    int mid = (st + en) / 2;

    //query left child
    ll q1 = query1(2 * node, st, mid, l, r);

    // query right child
    ll q2 = query1(2 * node + 1, mid + 1, en, l, r);

    return min(q1,q2);
}
void build2(int node, int st, int en)
{
    if (st == en)
    {
        // left node ,string the single array element
        seg2[node] = 1e9;
        return;
    }

    int mid = (st + en) / 2;

    // recursively call for left child
    build2(2 * node, st, mid);

    // recursively call for the right child
    build2(2 * node + 1, mid + 1, en);

    // Updating the parent with the values of the left and right child.
    seg2[node] = min(seg2[2 * node],seg2[2 * node + 1]);
}

void update2(int node, int st, int en, int l, int r, int val)
{

    if ((en < l) || (st > r)) // case 1
    {
        return;
    }
    if (st >= l && en <= r) // case 2
    {
        seg2[node] =  val;

        return;
    }

    // case 3
    int mid = (st + en) / 2;

    // recursively call for updating left child
    update2(2 * node, st, mid, l, r, val);
    // recursively call for updating right child
    update2(2 * node + 1, mid + 1, en, l, r, val);

    // Updating the parent with the values of the left and right child.
    seg2[node] =min(seg2[2 * node],seg2[2 * node + 1]);
}

int query2(int node, int st, int en, int l, int r)
{


    // case 1
    if (en < l || st > r)
    {
        return 1e9;
    }

    // case 2
    if ((l <= st) && (en <= r))
    {
        return seg2[node];
    }
    int mid = (st + en) / 2;

    //query left child
    ll q1 = query2(2 * node, st, mid, l, r);

    // query right child
    ll q2 = query2(2 * node + 1, mid + 1, en, l, r);

    return min(q1,q2);
}
void build3(int node, int st, int en)
{
    if (st == en)
    {
        // left node ,string the single array element
        seg3[node] = 1e9;
        return;
    }

    int mid = (st + en) / 2;

    // recursively call for left child
    build3(2 * node, st, mid);

    // recursively call for the right child
    build3(2 * node + 1, mid + 1, en);

    // Updating the parent with the values of the left and right child.
    seg3[node] = min(seg3[2 * node],seg3[2 * node + 1]);
}

void update3(int node, int st, int en, int l, int r, int val)
{

    if ((en < l) || (st > r)) // case 1
    {
        return;
    }
    if (st >= l && en <= r) // case 2
    {
        seg3[node] =  val;

        return;
    }

    // case 3
    int mid = (st + en) / 2;

    // recursively call for updating left child
    update3(2 * node, st, mid, l, r, val);
    // recursively call for updating right child
    update3(2 * node + 1, mid + 1, en, l, r, val);

    // Updating the parent with the values of the left and right child.
    seg3[node] =min(seg3[2 * node],seg3[2 * node + 1]);
}

int query3(int node, int st, int en, int l, int r)
{


    // case 1
    if (en < l || st > r)
    {
        return 1e9;
    }

    // case 2
    if ((l <= st) && (en <= r))
    {
        return seg3[node];
    }
    int mid = (st + en) / 2;

    //query left child
    ll q1 = query3(2 * node, st, mid, l, r);

    // query right child
    ll q2 = query3(2 * node + 1, mid + 1, en, l, r);

    return min(q1,q2);
}

int mi[5001],ma[5001];
int parent[6001];

int c1[N],c2[N];
int g=0;
void binarytree(int n,int depth,int pa)
{
    if( n==0)
    {
        return ;
    }
    g++;
    parent[g]=pa;
    int h=depth-(n-1);
    for( int i=0; i<=n-1; i++)
    {
        if( ma[i]+ma[n-1-i]>=h && h>=mi[i]+mi[n-1-i])
        {

        }
    }

}


int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    int nj=5000;
    for( int i=1; i<=nj; i++)
    {
        ma[i]=(i*(i-1))/2;
        int y=i;
        int de=0;
        int u=1;
        while( y>0)
        {
            mi[i]+=min(u,y)*de;
            de++;
            y-=min(u,y);
            u=u*2ll;
        }


    }
    cin >> t;




    for (int tc = 0; tc < t; tc++)
    {

       int n,d;
       cin>>n>>d;
       ///cout<<mi[n]<<endl;
       if( d<mi[n] || d>ma[n] ){
        cout<<"NO"<<endl;
        continue;
       }
       cout<<"YES"<<endl;
       int tot[110]={0};
       int u=1;
       int h=n;
       for( int i=0;i<=109;i++){
        if( h==0)break;
        tot[i]=min(h,u);
        h-=tot[i];
        u*=2;


            }

       for( int i=0;i<d-mi[n];i++){
        for( int i=108;i>=0;i--){
            if( tot[i]>1){
                tot[i]--;
                tot[i+1]++;
                break;
            }
        }
       }
       int g=1;
       int ans[n+100]={0};
       vector<int>v[110];

       for( int i=0;i<=109;i++){

        for( int j=0;j<tot[i];j++){
           v[i].pb(g++);
        }
       }
       for( int i=1;i<=109;i++){
        for( int j=0;j<tot[i];j++){
            ans[v[i][j]]=v[i-1][j/2];
        }
       }
       for( int i=2;i<=n;i++){
        cout<<ans[i]<<" ";
       }

      cout<<endl;



    }


    return 0;
}
