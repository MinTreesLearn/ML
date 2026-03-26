#include<bits/stdc++.h>
using namespace std;
 
 struct hashFunction 
{
  size_t operator()(const vector<string> 
                    &myVector) const 
  {
    std::hash<string> hasher;
    size_t answer = 0;
      
    for (string i : myVector) 
    {
      answer ^= hasher(i) + 0x9e3779b9 + 
                (answer << 6) + (answer >> 2);
    }
    return answer;
  }
};
 
int solve()
{
   int n,k,count=0;
   cin >> n >> k;
   unordered_map<string , int> m;
   unordered_set<vector<string>, 
   hashFunction> s;
   for(int i = 0; i < n; i++){
    string temp1;
    cin >> temp1;
    m[temp1]++;
   }
   
 
   for(auto it = m.begin(); it != m.end(); ++it){
    auto xyz=it;
	for(auto lt = ++xyz;  lt != m.end(); ++lt){
        
        
        
        string s1 = it->first;
        string s2 = lt->first;
        string temp = "";
        
        for(int a = 0; a < k; a++){
           if(s1[a] == s2[a]){
                temp = temp + s1[a];
            }
            else if((s1[a] == 'S' && s2[a] == 'T') || (s1[a] == 'T' && s2[a] == 'S')){
                temp = temp + "E";
            }
            else if((s1[a] == 'S' && s2[a] == 'E') || (s1[a] == 'E' && s2[a] == 'S')){
                temp = temp + "T";
            }
            else if((s1[a] == 'E' && s2[a] == 'T') || (s1[a] == 'T' && s2[a] == 'E')){
                temp = temp + "S";
            }
        }
       
        if(m.find(temp)!=m.end()){
            vector<string> v;
            v.push_back(s1);
            v.push_back(s2);
            v.push_back(temp);
            sort(v.begin(),v.end());
            s.insert(v);
        
        }
    }
   }
   
   cout << s.size() << "\n";
   return 0;
}
int main()
{    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    solve();
    
}