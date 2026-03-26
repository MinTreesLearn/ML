// LUOGU_RID: 102248085
#include <bits/stdc++.h>
using namespace std;
const int N = 600010,MASK = (1<<30)-1;
int n,col[N],necol[N][27],w[N],ne[N];
char str[N];
__int128 ans;
struct map_doge{
	map<int,int> mp;
	map<int,int>::iterator it;
	long long sum;
	void init(){return;}
	void insert(int val){
		it = mp.begin();
		if(it != mp.end() && it->first == -val) ++(it->second);
		else mp.insert(make_pair(-val,1));
		sum -= val;
		return;
	}
	void remove(int val){
		it = mp.find(-val);
		if(it != mp.end()){
			--(it->second);
			if(!(it->second)) mp.erase(it);
			sum += val;
		}
		return;
	}
	void modify(int val){
		int tmpsz = 0;
		it = mp.begin();
		if(it != mp.end() && it->first <= -val)
			while(it != mp.end() && it->first <= -val){
				sum -= (it->first)*1ll*(it->second);
				tmpsz += (it->second);
				mp.erase(it);
				it = mp.begin();
			}
		if(tmpsz) mp.insert(make_pair(-val,tmpsz)),sum -= val*1ll*tmpsz;
		return;
	}
	long long qsum(){return -sum;}
}f;
struct segment_tree{
	#define pushup(u) tr[u].val = min(tr[u<<1].val,tr[u<<1|1].val)
	struct tn{int l,r,val;}tr[N*4];
	void build(int u,int l,int r){
		tr[u] = {l,r,MASK};
		if(l != r){
			int mid = l+r>>1;
			build(u<<1,l,mid);
			build(u<<1|1,mid+1,r);
		}
		return;
	}
	void modify(int u,int pos,int val){
		if(tr[u].l == tr[u].r) tr[u].val = val;
		else{
			int mid = tr[u].l+tr[u].r>>1;
			if(pos <= mid) modify(u<<1,pos,val);
			else modify(u<<1|1,pos,val);
			pushup(u);
		}
		return;
	}
	int query(int u,int l,int r){
		if(tr[u].l >= l && tr[u].r <= r) return tr[u].val;
		else{
			int mid = tr[u].l+tr[u].r>>1,res = MASK;
			if(l <= mid) res = query(u<<1,l,r);
			if(r > mid) res = min(res,query(u<<1|1,l,r));
			return res;
		}
	}
}s;
void del(int x,int c,int I){
	if(x && col[x] != c) f.remove(s.query(1,I-x,I-1));
	x = necol[x][c];
	for(;x;x = necol[x][c]) f.remove(s.query(1,I-x,I-1));
	return;
}
void write(__int128 x){
	static int st[30],tp;
	do st[++tp] = x%10,x /= 10;while(x);
	while(tp) putchar(st[tp--]|'0');
	putchar(10);
	return;
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("out.out","w",stdout);
	scanf("%d",&n);
	s.build(1,1,n);
	f.init();
	scanf("%s%d",str+1,&w[1]);
	s.modify(1,1,w[1]);
	f.insert(w[1]);
	write(ans += f.qsum());
	for(int i = 2;i <= n;i++){
		scanf("%s%d",str+i,&w[i]);
		str[i] = (str[i]-'a'+ans%26)%26+'a',w[i] ^= ans&MASK;
		s.modify(1,i,w[i]);
		col[i-1] = str[i]-'a';
		del(ne[i-1],str[i]-'a',i);
		f.modify(w[i]);
		if(str[i] == str[1]) f.insert(w[i]);
		for(ne[i] = ne[i-1];ne[i] && str[ne[i]+1] != str[i];ne[i] = ne[ne[i]]);
		if(str[ne[i]+1] == str[i]) ++ne[i];
		for(int j = 0;j < 26;j++) necol[i][j] = ne[i];
		necol[i][col[ne[i]]] = necol[ne[i]][col[ne[i]]];
		write(ans += f.qsum());
	}
	return 0;
}