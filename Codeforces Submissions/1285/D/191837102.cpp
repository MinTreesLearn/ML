// LUOGU_RID: 101363216
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<vector>
typedef long long ll;
const int _=+10;
using namespace std;

void Read(){}template<typename tp,typename... A>
void Read(tp& c,A&... d){
    c=0;char x=getchar();bool op=0;
    while(!isdigit(x)) op|=(x=='-'),x=getchar();
    while(isdigit(x)) c=(c<<1)+(c<<3)+(x^'0'),x=getchar();
    if(op){c=-c;}Read(d...);
}

template<typename tp>void Write(tp c,char x='\n'){
    static char Sta[30];unsigned top=0;
    if(c<0) c=-c,putchar('-');
    do{Sta[top++]=c%10+'0',c/=10;}while(c);
    while(top) putchar(Sta[--top]);
    if(x) putchar(x);
}

int dfs(int x,vector<int>& c){
    if(!~x) return 0;
    vector<int> a,b;
    for(int i=0;i<(int)c.size();i++){
        if(c[i]&(1<<x)) b.push_back(c[i]);
        else a.push_back(c[i]);
    }
    if(a.empty()) return dfs(x-1,b);
    if(b.empty()) return dfs(x-1,a);
    return min(dfs(x-1,a),dfs(x-1,b))|(1<<x);
}

int main(){
    int x;Read(x);
    vector<int> a(x);
    for(int i=0;i<x;i++) Read(a[i]);
    Write(dfs(29,a));
    return 0;
}
