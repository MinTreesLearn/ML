// LUOGU_RID: 100584762
#include<bits/stdc++.h>
//#include<type_traits>
//#include<debug/debug.h>
//#include<bits/stl_pair.h>
//#pragma GCC optimize(1)
//#pragma GCC optimize(2)
//#ifndef _STL_ALGOBASE_H
//#if __cplusplus > 201703L
//#define _STL_ALGOBASE_H 1
//#if __cplusplus >= 201103L
//#include<bits/c++config.h>
//#include<ext/type_traits.h>
//#include<bits/functexcept.h>
//#include<bits/stl_iterator.h>
//#include<ext/numeric_traits.h>
//#include<bits/concept_check.h>
//#include<bits/predefined_ops.h>
//#include<bits/cpp_type_traits.h>
//#include<bits/move.h> // For std::swap
//#include<bits/stl_iterator_base_types.h>
//#include<bits/stl_iterator_base_funcs.h>
using namespace std;
//#define int long long
//#define ll long long int
//#define db double
//#define ld long double
#define ull unsigned long long
typedef long long ll;
//#define I using
//#define AK namespac
//#define IOI std
//I AK IOI;


const int N=2e5+5;
int n,k,d[N],ans[N];
vector<int>v[N],p[N];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int fa,int col){
	int now=1;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=fa){
			if(col==now&&now<d[k+1])
				now++;
			ans[p[x][i]]=now;
			dfs(v[x][i],x,now);
			if(now<d[k+1])
				now++;
		}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,x,y;i<n;i++)
		scanf("%d%d",&x,&y),v[x].push_back(y),p[x].push_back(i),v[y].push_back(x),p[y].push_back(i),d[x]++,d[y]++;
	sort(d+1,d+n+1,cmp);
	printf("%d\n",d[k+1]);
	dfs(1,-1,-1);
	for(int i=1;i<n;i++)
		printf("%d ",ans[i]);
	return 0;
}
