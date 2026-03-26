#include <bits/stdc++.h>
using namespace std;
#define oo 1000000010
#define mod 1000000007
const int N = 510 , LOG = 10;
char grid[N][N];
int val[N][N] , sum[N][N][4];
int st[N][N][LOG][LOG] , lg[N];
int n , q , m , r1 , c1 , r2, c2 , nr , nc;

string S = "RGYB";
int dr[4] = {0 , 0 , 1 , 1};
int dc[4] = {0 , 1 , 0 , 1};

inline bool check(int r1,int c1,int r2,int c2,int k){
    r1++,c1++,r2++,c2++;
    return ((sum[r2][c2][k] - sum[r1 - 1][c2][k] - sum[r2][c1 - 1][k] + sum[r1 - 1][c1 - 1][k]) == (r2 - r1 + 1) * (c2 - c1 + 1));
}   

inline bool can(int r,int c,int s){
    if(r < 0 || c < 0) return false;
    if(r + (s << 1) - 1 >= n || c + (s << 1) - 1 >= m) return false;
    for(int i =0  ;i < 4;i++){
        nr = r + dr[i] * s ;
        nc = c + dc[i] * s;
        if(!check(nr , nc , nr + s - 1 , nc + s - 1 , i))
            return false;
    }
    return true;
}

void build(){
    lg[1] = 0;
    for(int i = 2;i<N;i++){
        lg[i] = lg[i - 1];
        if((1 << (lg[i] + 1)) == i)
            lg[i]++;
    }
    for(int k = 1;k < LOG;k++){
        for(int i=0;i + (1 << k) <= n;i++){
            for(int j=0;j<m;j++){
                st[i][j][k][0] = max(st[i][j][k - 1][0] , st[i + (1 << (k - 1))][j][k - 1][0]);
            }
        }
    }
    for(int l = 1;l < LOG;l++){
        for(int k = 0;k < LOG;k++){
            for(int i=0;i+(1 << k) <= n;i++){
                for(int j = 0;j + (1 << l) <= m;j++){
                    st[i][j][k][l] = max(st[i][j][k][l - 1] , st[i][j + (1 << (l - 1))][k][l-1]);
                }
            }
        }
    }
}

int a , b;

inline int getmax(int r1,int c1,int r2,int c2){
    if(r2 < r1 || c2 < c1 || r1 < 0 || r2 >= n || c1 < 0 || c2 >= m) return -oo;
    a = lg[(r2 - r1) + 1];
    b = lg[(c2 - c1) + 1];
    return max(max(st[r1][c1][a][b] , st[r2 - (1 << a) + 1][c1][a][b]) , max(st[r1][c2 - (1 << b) + 1][a][b] , st[r2 - (1 << a) + 1][c2 - (1 << b) + 1][a][b]));
}


int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++){
        scanf(" %s",grid[i]);
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                sum[i + 1][j + 1][k] = sum[i][j + 1][k] + sum[i + 1][j][k] - sum[i][j][k] + (S[k] == grid[i][j]);
            }
        }
    }
    int low , high , mid , res;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            low = 1 , high = min(min(i + 1,n - i) , min(j + 1,m - j));
            while(high >= low){
                mid = ((low + high) >> 1);
                if(can(i - mid + 1,j - mid + 1,mid))
                    st[i][j][0][0] = mid, low = mid + 1;
                else
                    high = mid - 1;
            }
        }
    }
    build();
    while(q--){
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        r1--,c1--,r2--,c2--;
        low = 1 , high = (n >> 1) , res = 0;
        while(high >= low){
            mid = ((low + high) >> 1);
            if(getmax(r1 + mid - 1,c1 + mid - 1,r2 - mid , c2 - mid) >= mid)
                res = mid, low = mid + 1;
            else
                high = mid - 1;
        }
        printf("%d\n",res * res * 4);
    }
    return 0;
}