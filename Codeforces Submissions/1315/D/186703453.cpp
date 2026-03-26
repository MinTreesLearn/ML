#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
#define pb push_back
#define ff first
#define ss second
const int N=2e3+7;
const int mod=1e9+7;
const double eps=1e-9;
const double pi=    3.14159265358979323846;
using namespace std;  
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    op_set;

int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);

   int n;
   cin >> n;

   int freq[n];
   for(int i=0;i<n;i++)
        cin >> freq[i];
   
   int t[n];
   for(int i=0;i<n;i++)
        cin >> t[i];
   
   map<int,vector<int>> sweepline;
   for(int i=0;i<n;i++)
        sweepline[freq[i]].pb(t[i]);
   
   long long answer=0ll;
   multiset<pair<long long,long long>> curr;

   auto remove=[&](long long at)
   {
        auto it=*curr.begin();
        answer=answer+abs(it.first)*(at-it.second);
        curr.erase(curr.begin());
   };

   for(auto &[currVal,vec] : sweepline)
   {
        for(auto ele : vec)
            curr.insert({-ele,currVal});//will give the highest this way

        remove(currVal);
        for(int j=currVal+1;sweepline.find(j)==sweepline.end() && curr.size()>0;j++)
            remove(j);
   }

   cout << answer << "\n";

}


/*
Teri nazron mein hain tеre sapne
Tere sapno mein hain naraazi
Mujhe lagta hai ke baatein dil ki
Hoti lafzon ki dhokhe-baazi
Tum saath jo na ho, Bedard hai yeh zindagi
*/