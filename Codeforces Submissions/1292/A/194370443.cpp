	                        #include <bits/stdc++.h>
	                        using namespace std;
	                        #define        ll                           long long
	                        #define        minheap               priority_queue <ll, vector<ll>, greater<ll> >
	                        #define        maxheap               priority_queue <ll>
	                        #define       forn(i,a,b)              for(int i=a;i<b;i++)
	                        #define          all(v)              v.begin(), v.end() 
	                        #define       forrn(i,n)              for(int i=n-1;i>=0;i--)
	                        #define         rall(v)              v.rbegin(),v.rend()
	                         #define         ub(a,n,x)            upper_bound(a,a+n,x)
	                         #define         lb(a,n,x)            lower_bound(a,a+n,x)
	                        #define            mae(v)                max_element(all(v))
	                        #define            mie(v)               min_element(all(v))
	                        #define            pb                   push_back
	                        #define            pf                push_front
	                        #define            fi                 first
	                        #define            se                 second
	                        #define          sz(a)               (int)a.size()
	                        #define           srt(v)                sort(all(v))
	                        #define           srrt(v)                sort(rall(v))
                            #define           V(v,size)               vector<ll>v(size)
                            #define           G(x)                   ll x; cin >> x;
	                        const int N=2e5+5;
	                        const ll mod=1e9+7;
	                        const ll maxai=1000000000000ll;
	                        const ll modulo=998244353;
	                        bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){ return (a.second < b.second);}
	                        int g_f_b(ll n){return 63-__builtin_clzll(n);}
	                        int g_b_c(ll n){ return __builtin_popcountll(n);}
	                        ll me(ll a,ll b,ll c=mod)
	                        { 
	                          ll ans=1;
	                            while(b>0)
	                            {
	                                if(b&1){
	                                    ans=(1LL*ans*a%c)%c;
	                                }
	                                a=(1LL*a*a)%c;
	                                b=b>>1;
	                            }
	                            return ans;
	                        }
	                        ll lcs( string X, string Y, int m, int n ) 
	{ 
	    if (m == 0 || n == 0) 
	        return 0; 
	    if (X[m-1] == Y[n-1]) 
	        return 1 + lcs(X, Y, m-1, n-1); 
	    else
	        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n)); 
	}
	                        bool subseq(string s1,string s2)//if s1 is subseq of s2
	                        {
	                            if(s1.empty()) return true;
	                            if(s1.size()>sz(s2))return false;
	                            if(s1.back()==s2.back())return(subseq(s1.substr(0,sz(s1)-1),s2.substr(0,sz(s2)-1)));
	                            return subseq(s1,s2.substr(0,s2.size()-1));
	                        }
	                    
	           
	 int nt(ll i, vector<ll>&v,ll n,ll s,ll k)   
	          {
	          	if(i==n)
	          	{
	          		if(s==k)
	          		{
	          		  //for(auto i:ds)cout<<i<<" ";
	          		  //	cout<<endl;
	          		     // cout<<s;
	                      return 1;
	             	}
	          		   // for(auto i:ds)cout<<i<<" ";
	          		    	//cout<<endl;
	                  return 0;
	          		//cout<<endl;
	          		//else return 0;
	          	}
	        //ds.pb(v[i]);
	             s+=v[i];
	     int l=  nt(i+1,v,n,s,k);
	     // ds.pop_back();
	     s-=v[i];
	      int r= nt(i+1,v,n,s,k);
	         return l+r;
	          }  
	        
	          ll mul(ll t,ll a)
	          {
	          	return(t*a)%mod;
	          }
	        void yes()
	        {
	        	cout<<"YES"<<endl;
	        } 
	           
	           void no()
	        {
	        	cout<<"NO"<<endl;
	        }

	/*f1(ll n,vector<ll>&dp)
	{
		if(n<=1)return n;
		if(dp[n]!=-1)return dp[n];
		return dp[n]=f(n-1,dp)+f(n-2,dp);
	}*/
	// ll f(vector<ll>&v,vector<ll>&dp,ll i,ll n,ll s,ll now)
	// {
		

	// }
	    void solve()
	    {
G(n);
G(q);
vector<vector<ll>>v(2,vector<ll>(n));
ll c=0;
forn(i,0,q)
{
	ll a,b;
	cin>>a>>b;
	a--;
	b--;
	v[a][b]^=1;
	if(v[a][b]==1)
	{
           if(v[abs(1-(a))][b]==1)
           	c++;
         if(b-1>=0)
           {
           	if(v[abs(1-(a))][b-1]==1)
           		c++;
           }
             if(b+1<n)
           {
           	if(v[abs(1-(a))][b+1]==1)
           		c++;
           }


	}
	else
	{
           if(v[abs(1-(a))][b]==1)
           	c--;
            if(b-1>=0)
           {
           	if(v[abs(1-(a))][b-1]==1)
           		c--;
           }
           if(b+1<n)
           {
           	if(v[abs(1-(a))][b+1]==1)
           		c--;
           }

	}
/*
for(int j=0;j<2;j++)
	 {
	 	forn(k,0,n)
	 	{
	 		cout<<v[j][k];
	 	}
		cout<<endl;
 }
		cout<<c<<"a";*/
	if(!c)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
		
}

}




  

                   
      int main()
	                        {     
	                            ios_base::sync_with_stdio(false);
	                            cin.tie(NULL);
	                            cout.tie(NULL);
	                            #ifndef ONLINE_JUDGE
	                            freopen("in.txt","r",stdin);
	                            freopen("out.txt","w",stdout);
	                             
	                            #endif 
	      //  int cases;
	           //cin>>cases;
	             // while(cases--)
	                    {
	                    	
	                      solve();            
	                    }                       
	                        return 0;
	                      }
   