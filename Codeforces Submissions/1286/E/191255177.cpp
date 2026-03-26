// S2OJ Submission #67658 @ 1675085389162
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <map>

#define int long long
#define maxn 600005

using namespace std;

inline int read(){
	int x = 0, flag = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') flag = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * flag;
}

inline int readc(){
	char ch = getchar();
	while(ch < 'a' || ch > 'z') ch = getchar();
	return ch - 'a' + 1;
} 

const int MASK = (1 << 30) - 1;
int n, nxt[maxn], lst[maxn][30], s[maxn], w[maxn], SUM;
__int128 lstans;
bool vis[maxn];
map <int, int> mp; 
int q[maxn], top;
vector <int> tmp;

int getlst(int x, int c){
	if(!x) return 0;
	if(!vis[x]) return x;
	return lst[x][c] = getlst(lst[x][c], c);
}

void write(__int128 x){
	if(x / 10) write(x / 10);
	putchar(x % 10 + '0');
	return;
}

signed main(){
	n = read();
	for(int i = 1, j = 0; i <= n; ++i){
		s[i] = readc(), w[i] = read();
		s[i] = ((s[i] + lstans - 1) % 26) + 1;
		w[i] = w[i] ^ (lstans & MASK);
//		cout<<s[i]<<' '<<w[i]<<endl;
		int now = i - 1;
		while(now = getlst(lst[now][s[i]], s[i])){
			vis[now] = 0;
			int mn = w[q[lower_bound(q + 1, q + top + 1, i - now) - q]];
			SUM -= mn;
			--mp[mn];
			if(!mp[mn]) mp.erase(mn);
//			cout<<"del "<<mn<<endl;
		}
		int cnt = 0;
		for(auto id = mp.end(); id != mp.begin(); --id){
			auto x = id; --x;
			if(x -> first > w[i]){
//				cout << "change "<<x.first<<endl;
				cnt += x -> second;
				SUM -= x -> second * x -> first;
				tmp.push_back(x -> first);
			}else break;
		}
		for(auto x : tmp) mp.erase(x);
		tmp.clear();
		mp[w[i]] += cnt;
		SUM += cnt * w[i];
		while(top && w[q[top]] >= w[i]) --top;
		q[++top] = i;
		if(s[i] == s[1]) ++mp[w[i]], SUM += w[i];
		lstans += SUM;
		write(lstans), putchar('\n');
		if(i == 1) continue;
		while(j && s[i] != s[j + 1]) j = nxt[j];
		if(s[i] == s[j + 1]) ++j;
		nxt[i] = j;
		for(int c = 1; c <= 26; ++c){
			if(s[nxt[i] + 1] != c) lst[i][c] = nxt[i];
			else lst[i][c] = lst[nxt[i]][c];
//			cout << "lst "<<i<<' '<<c<<" = "<<lst[i][c]<<endl;
		}
	}
	return 0;
} 