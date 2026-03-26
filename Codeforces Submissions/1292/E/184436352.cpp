// LUOGU_RID: 96893101
/*
 * @Author:             cmk666
 * @Created time:       2022-12-09 15:40:13
 * @Last Modified time: 2022-12-09 16:50:11
 */
#pragma GCC optimize("Ofast", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, j, k) for ( int i = j ; i <= k ; i++ )
#define Fol(i, j, k) for ( int i = j ; i >= k ; i-- )
inline void read(auto &x)
{
	char c = getchar(); for ( ; c < '0' || c > '9' ; c = getchar() );
	for ( x = 0 ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - '0';
}
int n; char s[509]; vector < int > p; bool flag;
inline void ask(const char *s, const auto &f)
{
	printf("? %s\n", s), fflush(stdout);
	int l, x; read(l); if ( !~l ) exit(0);
	For(i, 1, l) read(x), f(x);
}
inline void ans(const char *s)
{
	printf("! %s\n", s), fflush(stdout);
	int r; read(r); if ( !r ) exit(0);
}
inline void work()
{
	read(n), memset(s, 0, sizeof(s)), flag = false;
	if ( n > 4 )
	{
		ask("CC", [](int x) { s[x] = s[x + 1] = 'C'; });
		ask("CH", [](int x) { s[x] = 'C'; });
		ask("CO", [](int x) { s[x] = 'C', s[x + 1] = 'O'; });
		ask("HO", [](int x) { s[x + 1] = 'O'; });
		ask("OO", [](int x) { s[x] = s[x + 1] = 'O'; });
		For(i, 2, n - 1) if ( !s[i] ) s[i] = 'H';
		if ( s[1] && s[n] ) { ans(s + 1); return; }
		if ( s[1] )
		{
			flag = false, s[n] = 'C', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			s[n] = 'H', ans(s + 1); return;
		}
		if ( s[n] )
		{
			flag = false, s[1] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			s[1] = 'H', ans(s + 1); return;
		}
		flag = false, s[1] = 'O', s[n] = 'C', ask(s + 1, [](int x) { flag = true; });
		if ( flag ) { ans(s + 1); return; }
		flag = false, s[1] = 'H', s[n] = 'C', ask(s + 1, [](int x) { flag = true; });
		if ( flag ) { ans(s + 1); return; }
		flag = false, s[1] = 'O', s[n] = 'H', ask(s + 1, [](int x) { flag = true; });
		if ( flag ) { ans(s + 1); return; }
		s[1] = s[n] = 'H', ans(s + 1); return;
	}
	ask("CC", [](int x) { s[x] = s[x + 1] = 'C', flag = true; });
	ask("CO", [](int x) { s[x] = 'C', s[x + 1] = 'O', flag = true; });
	ask("CH", [](int x) { s[x] = 'C', s[x + 1] = 'H', flag = true; });
	ask("HO", [](int x) { s[x] = 'H', s[x + 1] = 'O', flag = true; });
	if ( flag )
	{
		if ( s[1] && s[2] && s[3] && s[4] ) { ans(s + 1); return; }
		if ( s[1] && s[2] && s[3] )
		{
			flag = false, s[4] = 'C', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[4] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			s[4] = 'H', ans(s + 1); return;
		}
		if ( s[1] && s[2] && s[4] )
		{
			flag = false, s[3] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			s[3] = 'H', ans(s + 1); return;
		}
		if ( s[1] && s[3] && s[4] )
		{
			flag = false, s[2] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			s[2] = 'H', ans(s + 1); return;
		}
		if ( s[2] && s[3] && s[4] )
		{
			flag = false, s[1] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			s[1] = 'H', ans(s + 1); return;
		}
		if ( s[1] && s[2] )
		{
			flag = false, s[3] = 'O', s[4] = 'C', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[3] = s[4] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[3] = 'O', s[4] = 'H', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[3] = 'H', s[4] = 'C', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[3] = 'H', s[4] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			s[3] = s[4] = 'H', ans(s + 1); return;
		}
		if ( s[1] && s[3] )
		{
			flag = false, s[2] = 'O', s[4] = 'C', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[2] = s[4] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[2] = 'O', s[4] = 'H', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[2] = 'H', s[4] = 'C', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[2] = 'H', s[4] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			s[2] = s[4] = 'H', ans(s + 1); return;
		}
		if ( s[1] && s[4] )
		{
			flag = false, s[2] = s[3] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[2] = 'O', s[3] = 'H', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[2] = 'H', s[3] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			s[2] = s[3] = 'H', ans(s + 1); return;
		}
		if ( s[2] && s[3] )
		{
			flag = false, s[1] = 'O', s[4] = 'C', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[1] = s[4] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[1] = 'O', s[4] = 'H', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[1] = 'H', s[4] = 'C', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[1] = 'H', s[4] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			s[1] = s[4] = 'H', ans(s + 1); return;
		}
		if ( s[2] && s[4] )
		{
			flag = false, s[1] = s[3] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[1] = 'O', s[3] = 'H', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[1] = 'H', s[3] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			s[1] = s[3] = 'H', ans(s + 1); return;
		}
		if ( s[3] && s[4] )
		{
			flag = false, s[1] = s[2] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[1] = 'O', s[2] = 'H', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			flag = false, s[1] = 'H', s[2] = 'O', ask(s + 1, [](int x) { flag = true; });
			if ( flag ) { ans(s + 1); return; }
			s[1] = s[2] = 'H', ans(s + 1); return;
		}
		assert(false);
	}
	ask("OO", [](int x) { s[x] = s[x + 1] = 'O', flag = true; });
	if ( flag )
	{
		if ( !s[3] ) s[3] = 'H';
		if ( s[4] ) { ans(s + 1); return; }
		flag = false, s[4] = 'C', ask(s + 1, [](int x) { flag = true; });
		if ( flag ) { ans(s + 1); return; }
		s[4] = 'H', ans(s + 1); return;
	}
	s[2] = s[3] = 'H';
	ask("HHH", [](int x) { s[x] = s[x + 1] = s[x + 2] = 'H'; });
	if ( !s[1] ) s[1] = 'O';
	if ( !s[4] ) s[4] = 'C';
	ans(s + 1);
}
int main() { int t; read(t); For(tt, 1, t) work(); return 0; }