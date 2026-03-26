#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = { 0,-1, 1, 0};

int n,m,Q,a[305][305],x[2000005],y[2000005],c[2000005],ans[2000005];
vector <int> vec[305][305];
int pre[2000005];

int fa[4000005];
int getf(int x){
	if(x == fa[x]) return x;
	return fa[x] = getf(fa[x]);
}
void merge(int x,int y,int id){
	x = getf(x); y = getf(y);
	if(x == y) return;
	fa[x] = y; pre[id] --;
}

unordered_map <int,int> mp[1000005];
int get_id(int col,int tx,int ty){
	return mp[col][(tx - 1) * m + ty];
}

int read(){
	int x = 0; char ch; ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

int lc[2000005],lcc = 0;

int main(){
	int tot = 0;
	n = read(); m = read(); Q = read();
	if(n * m == 1){ for(int i = 1;i <= Q;i ++) printf("1\n"); return 0; }
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			mp[0][(i - 1) * m + j] = ++ tot;
		}
	}
	for(int i = 1;i <= Q;i ++){
		x[i] = read(); y[i] = read(); c[i] = read();
		lc[++ lcc] = c[i];
	}
	sort(lc + 1,lc + 1 + lcc);
	lcc = unique(lc + 1,lc + 1 + lcc) - lc - 1;
	for(int i = 1;i <= Q;i ++){
		c[i] = lower_bound(lc + 1,lc + 1 + lcc,c[i]) - lc;
		if(mp[c[i]].find((x[i] - 1) * m + y[i]) == mp[c[i]].end()) mp[c[i]][(x[i] - 1) * m + y[i]] = ++ tot;
	}
	for(int i = 1;i <= tot;i ++) fa[i] = i;
	pre[0] = 1;
	for(int i = 0;i <= n + 1;i ++) a[i][0] = a[i][m + 1] = -1;
	for(int i = 0;i <= m + 1;i ++) a[0][i] = a[n + 1][i] = -1;
	c[0] = c[Q + 1] = -1;
	
	for(int i = 1;i <= Q;i ++){
		pre[i] = pre[i - 1];
		if(c[i] != c[i - 1]) pre[i] = 0;
		vec[x[i]][y[i]].push_back(c[i]);
		if(a[x[i]][y[i]] == c[i]) continue;
		a[x[i]][y[i]] = c[i];
		pre[i] ++;
		for(int d = 0;d < 4;d ++){
			int tx = x[i] + dx[d];
			int ty = y[i] + dy[d];
			if(a[tx][ty] == c[i]) merge(get_id(c[i],tx,ty),get_id(c[i],x[i],y[i]),i);
		}
	}
	for(int i = 1;i <= tot;i ++) fa[i] = i;
	pre[0] = n * m;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			for(int d = 0;d < 4;d ++){
				int tx = i + dx[d];
				int ty = j + dy[d];
				if(a[tx][ty] == a[i][j]) merge(get_id(a[tx][ty],tx,ty),get_id(a[i][j],i,j),0);
			}
		}
	}
	for(int i = Q;i >= 1;i --){
		if(c[i] != c[i + 1]) pre[0] -= pre[i];
		ans[i] = pre[0] + pre[i];
		//cout << i << " : " << pre[0] << ' ' << pre[i] << endl;
		vec[x[i]][y[i]].pop_back();
		int col = vec[x[i]][y[i]].size() ? vec[x[i]][y[i]][vec[x[i]][y[i]].size() - 1] : 0;
		if(a[x[i]][y[i]] == col) continue;
		a[x[i]][y[i]] = col;
		pre[0] ++;
		for(int d = 0;d < 4;d ++){
			int tx = x[i] + dx[d];
			int ty = y[i] + dy[d];
			if(a[tx][ty] == col) merge(get_id(col,tx,ty),get_id(col,x[i],y[i]),0);
		}
	}
	for(int i = 1;i <= Q;i ++) printf("%d\n",ans[i]);
	return 0;
}