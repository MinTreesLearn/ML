#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define I_am_speed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define vec vector<ll> 
#define loop(x, start, end) for(int x = start; x < end; ++x) 



 vector<int> primeNumbersTillN(int N) 
{
    bool isprime[N+1] ;
   for(int i =0; i<=N ; i++) {
   isprime[i] = true ;
   }
   for(int i =  2 ; i*i <= N ; i++) {
  if(isprime[i] == true) {
  for(int j = i*i ; j<= N ; j+=i) {
  isprime[j] = false;
  }
  }
   }
   vector<int>  ans ; 
   for(int i =2; i<= N ; i++) {
  if(isprime[i] == true ) {
   ans.push_back(i); 
  }
   }
return ans ;
}
void print(vector<int> & v){ 
   int n = v.size(); 
    for(int i =0; i<v.size()-1; i++){ 
       cout<<v[i]<<" "; 
    }
   cout<<v[n-1]<<endl; 
    return ; 
} 
void print_2d(vector<vector<ll>> &v)
{
   for (int i = 0; i < v.size(); i++)
   {
   for (int j = 0; j < v[i].size(); j++)
   {
   cout << v[i][j] <<" ";
   }
    cout << endl;
   }
   return;
}

void solve() {
    int n ; cin >>n; 
    vector<int> b(n) ;
    unordered_set<int> temp ;

    loop(i,0,n)  cin >>b[i] , temp.insert(b[i]) ;
    set<int> st;
    for(int i = 1;i <= 2*n; i++) {
        if(temp.find(i) == temp.end()){
            st.insert(i) ;
        }
    }
    // for(auto it : st) cout <<it <<" " ;
    // cout <<endl ;
   
    
    vector<int> cp = b;
    sort(cp.begin(), cp.end());
    reverse(cp.begin(), cp.end()) ;
    unordered_map<int ,pair<int ,int>> mp;
    bool flag = false;
    for(int i = 0; i<n; i++) {
        int el = b[i] ;
        if(lower_bound(st.begin() ,st.end() ,el) == st.end()) {
            flag = true;
            break ;
        }
        int se = *lower_bound(st.begin() , st.end(), el) ;
        if(se> el) {
            mp[el] ={el,se} ;
            st.erase(se) ;
        }
        else{
            flag = true;
            break ;
        }
        
    } 

    if(flag) {
        cout <<-1 <<endl ;
        return ;
    }
    vector<int> ans  ;
    for(int i = 0; i<n; i++) {
        ans.push_back(mp[b[i]].first) ;
        ans.push_back(mp[b[i]].second) ;
    }
    print(ans );
    




    


}
int main(){
    I_am_speed();
    int t ; cin>>t;
    while(t--){
      solve();
    }
    return 0;
}