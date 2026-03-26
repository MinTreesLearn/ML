// LUOGU_RID: 99461421
#include <stdio.h>
#include <random>
#include <time.h>
#include <set>

#define int long long

std::mt19937 random_pool(time(NULL));
std::set<int> PrimeFactor;

int n, a[200001], m = 1e18;

inline void Decompose(int x)
{
	if(x <= 0)
		return;
		
	for(register int i = 2; i * i <= x; ++ i)
		if(!(x % i))
		{
			PrimeFactor.insert(i);
			while(!(x % i))
				x /= i;
		}

	if(x != 1)
		PrimeFactor.insert(x);
}

signed main()
{
	scanf("%lld", &n);
	
	for(register int i = 1; i <= n; ++ i)
		scanf("%lld", a + i);
		
	for(register int i = 1; i <= 50; ++ i)
	{
		int item = a[random_pool() % n + 1];
		Decompose(item - 1);
		Decompose(item);
		Decompose(item + 1);
	}
	
	for(auto i : PrimeFactor)
	{
		int sum = 0;
		
		for(register int j = 1; j <= n; ++ j)
			sum += a[j] > i ? std::min(a[j] % i, i - a[j] % i) : i - a[j];
			
		m = std::min(m, sum);
	}
	
	printf("%lld", m);
}