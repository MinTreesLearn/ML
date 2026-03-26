// LUOGU_RID: 100833057
#include<bits/stdc++.h>
#define ls 2*p
#define rs 2*p+1
#define INF 2e9
using namespace std;
void read(int &x) {
    x = 0;
    int f = 1;
    char s = getchar();
    while (s > '9' || s < '0') {
        if (s == '-')
            f = -1;
        s = getchar();
    }
    while (s >= '0' && s <= '9') {
        x = (x << 3) + (x << 1) + (s - '0');
        s = getchar();
    }
    x *= f;
}
void write(long long x) {
    if (x < 0) {
        putchar('-');
        x = (~x) + 1;
    }
    if (x > 9) {
        write(x / 10);
    } 
    putchar(x % 10 + '0');
}
const int MAXN=5e5+5;
struct Seg_node{
	int Max_first;
	int Max_second;
	int Add1,Add3;
	long long sumdate;
	int Num_mx;
	int l,r;
	int Num;
}Tree[MAXN*4];
void push_up(int p)
{
	Tree[p].sumdate=Tree[ls].sumdate+Tree[rs].sumdate;
	Tree[p].Num=Tree[ls].Num+Tree[rs].Num;
	if(Tree[ls].Max_first==Tree[rs].Max_first)
	{
		Tree[p].Max_first=Tree[ls].Max_first;
		Tree[p].Num_mx=Tree[ls].Num_mx+Tree[rs].Num_mx;
		Tree[p].Max_second=max(Tree[ls].Max_second,Tree[rs].Max_second);
	}
	else if(Tree[ls].Max_first>Tree[rs].Max_first)
	{
		Tree[p].Max_first=Tree[ls].Max_first;
		Tree[p].Num_mx=Tree[ls].Num_mx;
		Tree[p].Max_second=max(Tree[ls].Max_second,Tree[rs].Max_first);
	}
	else
	{
		Tree[p].Max_first=Tree[rs].Max_first;
		Tree[p].Num_mx=Tree[rs].Num_mx;
		Tree[p].Max_second=max(Tree[rs].Max_second,Tree[ls].Max_first);
	}
	return; 
}
void push_down(int p)
{
	int Mxc=max(Tree[ls].Max_first,Tree[rs].Max_first);
	if(Mxc==Tree[ls].Max_first)
	{
		if(Tree[ls].Num)
		{
			Tree[ls].Max_first+=Tree[p].Add1;
			Tree[ls].Max_second+=Tree[p].Add3;
		}
		
		Tree[ls].sumdate+=((long long)Tree[p].Add1*Tree[ls].Num_mx);
		Tree[ls].sumdate+=((long long)Tree[p].Add3*(Tree[ls].Num-Tree[ls].Num_mx));
		Tree[ls].Add1+=Tree[p].Add1;
		Tree[ls].Add3+=Tree[p].Add3;
	}
	else
	{
		if(Tree[ls].Num)
		{
			Tree[ls].Max_first+=Tree[p].Add3;
			Tree[ls].Max_second+=Tree[p].Add3;
		}
		
		Tree[ls].sumdate+=((long long)Tree[p].Add3*(Tree[ls].Num));
		Tree[ls].Add1+=Tree[p].Add3;
		Tree[ls].Add3+=Tree[p].Add3;
	} 
	
	if(Mxc==Tree[rs].Max_first)
	{
		if(Tree[rs].Num)
		{
			Tree[rs].Max_first+=Tree[p].Add1;
			Tree[rs].Max_second+=Tree[p].Add3;
		}
	
		Tree[rs].sumdate+=((long long)Tree[p].Add1*Tree[rs].Num_mx);
		Tree[rs].sumdate+=((long long)Tree[p].Add3*(Tree[rs].Num-Tree[rs].Num_mx));
		Tree[rs].Add1+=Tree[p].Add1;
		Tree[rs].Add3+=Tree[p].Add3;
	}
	else
	{
		if(Tree[rs].Num)
		{
			Tree[rs].Max_first+=Tree[p].Add3;
			Tree[rs].Max_second+=Tree[p].Add3;
		}
		Tree[rs].sumdate+=((long long)Tree[p].Add3*(Tree[rs].Num));
		Tree[rs].Add1+=Tree[p].Add3;
		Tree[rs].Add3+=Tree[p].Add3;
	} 
	Tree[p].Add1=0;
	Tree[p].Add3=0;
}
void Update_sum(int p,int l,int r,int v)
{
	if(l>r)
	{
		return;
	}
	if(Tree[p].l>=l&&Tree[p].r<=r)
	{
		if(Tree[p].Num)
		{
			Tree[p].Max_first+=v;
			Tree[p].Max_second+=v;
		}
		Tree[p].sumdate+=((long long)(Tree[p].Num)*v);
		Tree[p].Add1+=v;
		Tree[p].Add3+=v;
		return;
	}
	int mid=(Tree[p].l+Tree[p].r)>>1;
	push_down(p);
	if(l<=mid)
	{
		Update_sum(ls,l,r,v);
	}
	if(r>mid)
	{
		Update_sum(rs,l,r,v);
	}
	push_up(p);
}
void update_min(int p,int v)
{
	if(Tree[p].l==Tree[p].r)
	{
		Tree[p].Max_first=min(Tree[p].Max_first,v);
		Tree[p].sumdate=Tree[p].Max_first;
		return;
	}
	
	if(Tree[p].Max_first<v)
	{
		return;
	}
	else if(Tree[p].Max_first>=v&&Tree[p].Max_second<v)
	{
		if(Tree[p].Num)
		{
			int Detl=(Tree[p].Max_first-v);
			Tree[p].sumdate-=((long long)Detl*Tree[p].Num_mx);
			Tree[p].Add1-=Detl;
			Tree[p].Max_first=v;
		}
		
		return;	
	}
	else
	{
		push_down(p);
		update_min(ls,v);
		update_min(rs,v);
		push_up(p);
	}
}
void Update_min(int p,int l,int r,int v)
{
	if(l>r)
	{
		return;
	}
	if(Tree[p].l>=l&&Tree[p].r<=r)
	{
		update_min(p,v);
		return;
	}
	push_down(p);
	int mid=(Tree[p].l+Tree[p].r)>>1;
	if(l<=mid)
	{
		Update_min(ls,l,r,v);
	}
	if(r>mid)
	{
		Update_min(rs,l,r,v);
	}
	
	push_up(p); 
}
void Update(int p,int k)
{
	if(Tree[p].l==Tree[p].r)
	{
		Tree[p].Num++;
		return;
	}
	push_down(p);
	int mid=(Tree[p].l+Tree[p].r)>>1;
	if(k<=mid)
	{
		Update(ls,k);
	}
	else
	{
		Update(rs,k);
	}
	push_up(p);
}
int Query(int p,int l,int r)
{
	if(l>r)
	{
		return 0;
	}
	if(Tree[p].l>=l&&Tree[p].r<=r)
	{
		return Tree[p].Num;
	}
	push_down(p);
	int mid=(Tree[p].l+Tree[p].r)>>1;
	int drs=0;
	if(l<=mid)
	{
		drs+=Query(ls,l,r);
	}
	if(r>mid)
	{
		drs+=Query(rs,l,r);
	}
	return drs;
}
long long Query_sum(int p,int l,int r)
{
	if(l>r)
	{
		return 0;
	}
	if(Tree[p].l>=l&&Tree[p].r<=r)
	{
		return Tree[p].sumdate;
	}
	push_down(p);
	int mid=(Tree[p].l+Tree[p].r)>>1;
	long long Res=0;
	if(l<=mid)
	{
		Res+=Query_sum(ls,l,r);
	}
	if(r>mid)
	{
		Res+=Query_sum(rs,l,r);
	}
	return Res;
}
void print(int p)
{
	if(Tree[p].l==Tree[p].r)
	{
		printf("%d ",Tree[p].Max_first);
		return;
	}
	push_down(p);
	print(ls);
	print(rs);
}
void Build(int p,int l,int r)
{
	Tree[p].l=l;
	Tree[p].r=r;
	Tree[p].Add1=Tree[p].Add3=0;
	if(l==r)
	{
		Tree[p].Max_first=0;
		Tree[p].Max_second=-INF;
		Tree[p].Num_mx=1;
		Tree[p].sumdate=0;
		Tree[p].Num=0;
		return;
	}
	int mid=(l+r)>>1;
	Build(ls,l,mid);
	Build(rs,mid+1,r);
	push_up(p);
}
int n;
int a[MAXN];
int rev[MAXN];
long long Sum[MAXN];
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		rev[a[i]]=i;
	}
	Build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		Update(1,rev[i]);
		
		Update_sum(1,rev[i]+1,n,1);
		Update_sum(1,rev[i],rev[i],i);
		
		int Rx=Query(1,1,rev[i]-1);
		Update_min(1,1,rev[i]-1,Rx);
		Sum[i]+=Query_sum(1,1,n); 
	}
	reverse(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		rev[a[i]]=i;
	}
	Build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		Update(1,rev[i]);
		Update_sum(1,rev[i]+1,n,1);
		int Rg=Query(1,1,n);
		Update_sum(1,rev[i],rev[i],Rg);
		int Rx=Query(1,1,rev[i]-1);
		Update_min(1,1,rev[i]-1,Rx);
		Sum[i]+=Query_sum(1,1,n);
		Sum[i]-=(long long)i*i;
		printf("%lld\n",Sum[i]); 
	}
}
//5
//3 5 1 4 2