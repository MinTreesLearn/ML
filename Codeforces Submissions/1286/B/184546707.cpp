#include <bits/stdc++.h>
using namespace std;
int n,c[2048],father,child[2048],a[2048];
vector<int> v[2048];
void dfs1(int now, int fa, int tmp)
{
    if(now != fa) a[now] += tmp;
    if(a[now] >= c[fa] + 1 && now != fa) a[now] ++;
    for(int i = 0 ; i < v[now].size() ; i ++)
    {
        dfs1(v[now][i],fa,tmp);
        if(now == fa) tmp += child[v[now][i]] + 1;
    }
}

int dfs(int idx)
{
    for(int i = 0 ; i < v[idx].size() ; i ++)
    {
        int tmp = dfs(v[idx][i]);
        child[idx] += tmp;
    }
    dfs1(idx,idx,0);
    a[idx] = c[idx] + 1;
    return child[idx] + 1;
}
int main()
{
    cin >> n;
    for (int i = 1 ; i <= n ; i ++)
    {
        int f;
        cin >> f >> c[i];
        if (f == 0) father = i;
        v[f].push_back(i);
    }
    dfs(father);
    int flag = 0;
    for(int i = 1 ; i <= n ; i ++) if(c[i] > child[i]) flag = 1;
    if(flag == 0)
    {
        cout << "YES" << endl;
        for(int i = 1 ; i <= n ; i ++) cout << a[i] << " ";
    }
    else cout << "NO";
    return 0;
}
	 	 	    	   		    		   		 				