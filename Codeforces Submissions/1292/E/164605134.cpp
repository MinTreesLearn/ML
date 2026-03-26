# include <bits/stdc++.h>
using namespace std;
int T;
int n,m,f[60];
inline char get_(int x) { return x==1 ? 'C' : x==2 ? 'H' : 'O';}
int main() {
	scanf("%d",&T);

	while (T--) {
		memset(f,0,sizeof(f));

		scanf("%d",&n);

		printf("? CC\n"), fflush(stdout);
		scanf("%d",&m);
		for (int x,i=1;i<=m;i++) scanf("%d",&x), f[x]=1, f[x+1]=1;
		printf("? CH\n"), fflush(stdout);
		scanf("%d",&m);
		for (int x,i=1;i<=m;i++) scanf("%d",&x), f[x]=1, f[x+1]=2;
		printf("? CO\n"), fflush(stdout);
		scanf("%d",&m);
		for (int x,i=1;i<=m;i++) scanf("%d",&x), f[x]=1, f[x+1]=3;
		printf("? OH\n"), fflush(stdout);
		scanf("%d",&m);
		for (int x,i=1;i<=m;i++) scanf("%d",&x), f[x]=3, f[x+1]=2;

		if (n>4) {
			printf("? HH\n"), fflush(stdout);
			scanf("%d",&m);
			for (int x,i=1;i<=m;i++) scanf("%d",&x), f[x]=2, f[x+1]=2;

			for (int i=2;i<n;i++) if (!f[i]) f[i]=3;

			if (f[1]&&f[n]) {
				printf("! ");
				for (int i=1;i<=n;i++) printf("%c",get_(f[i]));
				printf("\n"), fflush(stdout);
				scanf("%d",&m);
			}
			else if (f[1]) {
				printf("? ");
				for (int i=1;i<n;i++) printf("%c",get_(f[i]));
				printf("C\n"), fflush(stdout);
				scanf("%d",&m);
				for (int x,i=1;i<=m;i++) scanf("%d",&x);
				if (m) {
					printf("! ");
					for (int i=1;i<n;i++) printf("%c",get_(f[i]));
					printf("C\n"), fflush(stdout);
					scanf("%d",&m);
				}
				else {
					printf("! ");
					for (int i=1;i<n;i++) printf("%c",get_(f[i]));
					printf("O\n"), fflush(stdout);
					scanf("%d",&m);
				}
			}
			else if (f[n]) {
				printf("? O");
				for (int i=2;i<=n;i++) printf("%c",get_(f[i]));
				printf("\n"), fflush(stdout);
				scanf("%d",&m);
				for (int x,i=1;i<=m;i++) scanf("%d",&x);
				if (m) {
					printf("! O");
					for (int i=2;i<=n;i++) printf("%c",get_(f[i]));
					printf("\n"), fflush(stdout);
					scanf("%d",&m);
				}
				else {
					printf("! H");
					for (int i=2;i<=n;i++) printf("%c",get_(f[i]));
					printf("\n"), fflush(stdout);
					scanf("%d",&m);
				}
			}
			else {
				printf("? O");
				for (int i=2;i<n;i++) printf("%c",get_(f[i]));
				printf("C\n"), fflush(stdout);
				scanf("%d",&m);
				for (int x,i=1;i<=m;i++) scanf("%d",&x);
				if (m) {
					printf("! O");
					for (int i=2;i<n;i++) printf("%c",get_(f[i]));
					printf("C\n"), fflush(stdout);
					scanf("%d",&m);
					continue;	
				}

				printf("? O");
				for (int i=2;i<n;i++) printf("%c",get_(f[i]));
				printf("O\n"), fflush(stdout);
				scanf("%d",&m);
				for (int x,i=1;i<=m;i++) scanf("%d",&x);
				if (m) {
					printf("! O");
					for (int i=2;i<n;i++) printf("%c",get_(f[i]));
					printf("O\n"), fflush(stdout);
					scanf("%d",&m);
					continue;	
				}

				printf("? H");
				for (int i=2;i<n;i++) printf("%c",get_(f[i]));
				printf("C\n"), fflush(stdout);
				scanf("%d",&m);
				for (int x,i=1;i<=m;i++) scanf("%d",&x);
				if (m) {
					printf("! H");
					for (int i=2;i<n;i++) printf("%c",get_(f[i]));
					printf("C\n"), fflush(stdout);
					scanf("%d",&m);
					continue;	
				}

				printf("! H");
				for (int i=2;i<n;i++) printf("%c",get_(f[i]));
				printf("O\n"), fflush(stdout);
				scanf("%d",&m);
			}
		}
		else {
			if (f[1]||f[n]) {
				printf("? HH\n"), fflush(stdout);
				scanf("%d",&m);
				for (int x,i=1;i<=m;i++) scanf("%d",&x), f[x]=2, f[x+1]=2;
				
				for (int i=2;i<n;i++) if (!f[i]) f[i]=3;
				
				if (f[1]&&f[n]) {
					printf("! ");
					for (int i=1;i<=n;i++) printf("%c",get_(f[i]));
					printf("\n"), fflush(stdout);
					scanf("%d",&m);
				}
				else if (f[1]) {
					printf("? ");
					for (int i=1;i<n;i++) printf("%c",get_(f[i]));
					printf("C\n"), fflush(stdout);
					scanf("%d",&m);
					for (int x,i=1;i<=m;i++) scanf("%d",&x);
					if (m) {
						printf("! ");
						for (int i=1;i<n;i++) printf("%c",get_(f[i]));
						printf("C\n"), fflush(stdout);
						scanf("%d",&m);
					}
					else {
						printf("! ");
						for (int i=1;i<n;i++) printf("%c",get_(f[i]));
						printf("O\n"), fflush(stdout);
						scanf("%d",&m);
					}
				}
				else {
					printf("? O");
					for (int i=2;i<=n;i++) printf("%c",get_(f[i]));
					printf("\n"), fflush(stdout);
					scanf("%d",&m);
					for (int x,i=1;i<=m;i++) scanf("%d",&x);
					if (m) {
						printf("! O");
						for (int i=2;i<=n;i++) printf("%c",get_(f[i]));
						printf("\n"), fflush(stdout);
						scanf("%d",&m);
					}
					else {
						printf("! H");
						for (int i=2;i<=n;i++) printf("%c",get_(f[i]));
						printf("\n"), fflush(stdout);
						scanf("%d",&m);
					}
				}
			}
			else if (f[2]==1&&f[3]==3) {
				printf("? OC\n"), fflush(stdout);
				scanf("%d",&m);
				for (int x,i=1;i<=m;i++) scanf("%d",&x), f[x]=3, f[x+1]=1;
				if (!f[1]) f[1]=2;
				if (!f[4]) f[4]=3;
				printf("! ");
				for (int i=1;i<=n;i++) printf("%c",get_(f[i]));
				printf("\n"), fflush(stdout);
				scanf("%d",&m);
			}
			else if (f[2]==1&&f[3]==2) {
				printf("? HC\n"), fflush(stdout);
				scanf("%d",&m);
				for (int x,i=1;i<=m;i++) scanf("%d",&x), f[x]=2, f[x+1]=1;
				if (!f[1]) f[1]=3;
				if (f[n]) {
					printf("! ");
					for (int i=1;i<=n;i++) printf("%c",get_(f[i]));
					printf("\n"), fflush(stdout);
					scanf("%d",&m);
				}
				else {
					printf("? %cCHO\n",get_(f[1])), fflush(stdout);
					scanf("%d",&m);
					for (int x,i=1;i<=m;i++) scanf("%d",&x);
					if (m) {
						printf("! %cCHO\n",get_(f[1])), fflush(stdout);
						scanf("%d",&m);
					}
					else {
						printf("! %cCHH\n",get_(f[1])), fflush(stdout);
						scanf("%d",&m);
					}
				}
			}
			else if (f[2]==3&&f[3]==2) {
				printf("? HO\n"), fflush(stdout);
				scanf("%d",&m);
				for (int x,i=1;i<=m;i++) scanf("%d",&x), f[x]=2, f[x+1]=3;
				if (!f[1]) f[1]=3;
				if (f[n]) {
					printf("! ");
					for (int i=1;i<=n;i++) printf("%c",get_(f[i]));
					printf("\n"), fflush(stdout);
					scanf("%d",&m);
				}
				else {
					printf("? %cOHC\n",get_(f[1])), fflush(stdout);
					scanf("%d",&m);
					for (int x,i=1;i<=m;i++) scanf("%d",&x);
					if (m) {
						printf("! %cOHC\n",get_(f[1])), fflush(stdout);
						scanf("%d",&m);
					}
					else {
						printf("! %cOHH\n",get_(f[1])), fflush(stdout);
						scanf("%d",&m);
					}
				}
			}
			else {
				printf("? HH\n"), fflush(stdout);
				scanf("%d",&m);
				for (int x,i=1;i<=m;i++) scanf("%d",&x), f[x]=2, f[x+1]=2;

				if (m) {
					if (f[4]) {
						printf("! HHHH\n"), fflush(stdout);
						scanf("%d",&m);
					}
					else {
						if (!f[3]) f[3]=3;
						printf("? ");
						for (int i=1;i<n;i++) printf("%c",get_(f[i]));
						printf("C\n"), fflush(stdout);
						scanf("%d",&m);
						for (int x,i=1;i<=m;i++) scanf("%d",&x);

						if (m) {
							printf("! ");
							for (int i=1;i<n;i++) printf("%c",get_(f[i]));
							printf("C\n"), fflush(stdout);
							scanf("%d",&m);
						}
						else {
							printf("! ");
							for (int i=1;i<n;i++) printf("%c",get_(f[i]));
							printf("O\n"), fflush(stdout);
							scanf("%d",&m);
						}
					}
				}
				else {
					printf("? OOO\n"), fflush(stdout);
					scanf("%d",&m);
					for (int x,i=1;i<=m;i++) scanf("%d",&x), f[x]=3, f[x+1]=3, f[x+2]=3;
					if (!f[1]) f[1]=2;
					if (!f[n]) f[n]=1;
					printf("! ");
					for (int i=1;i<=n;i++) printf("%c",get_(f[i]));
					printf("\n"), fflush(stdout);
					scanf("%d",&m);
				}
			}
		}
	}

	return 0;
}