import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
	PrintWriter out = new PrintWriter(System.out);
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer tok = new StringTokenizer("");
    String next() throws IOException {
        if (!tok.hasMoreTokens()) { tok = new StringTokenizer(in.readLine()); }
        return tok.nextToken();
    }
    int ni() throws IOException { return Integer.parseInt(next()); }
    long nl() throws IOException { return Long.parseLong(next()); }
    
    long mod=1000000007;
    
    void solve() throws IOException {
        int n=ni(),m=ni();
        int[][]A=new int[n+1][m];
        for (int i=1;i<=n;i++) for (int j=0;j<m;j++) A[i][j]=ni();
        
        int lt=0;
        int rt=1000000001;
        int a1=1;
        int a2=1;
        int tar=(1<<m)-1;
        
        while (lt+1<rt) {
            int av=(lt+rt)/2;
            int[]B=new int[256];
            
            for (int i=1;i<=n;i++) {
                int p=1;
                int h=0;
                for (int j=0;j<m;j++) {
                    if (A[i][j]>=av) h|=p;
                    p<<=1;
                }
                if (B[h]==0) B[h]=i;
            }
            
            boolean f=false;
            outer: for (int x=0;x<256;x++) {
                if (B[x]==0) continue;
                for (int y=x;y<256;y++) {
                    if (B[y]==0) continue;
                    if ((x|y)==tar) { f=true; a1=B[x]; a2=B[y]; break outer; }
                }
            }
            
            if (f) lt=av;
            else rt=av;
        }
        
        out.println(a1+" "+a2);
        out.flush();
    }
    
    int gcd(int a,int b) { return(b==0?a:gcd(b,a%b)); }
    long gcd(long a,long b) { return(b==0?a:gcd(b,a%b)); }
    long mp(long a,long p) { long r=1; while(p>0) { if ((p&1)==1) r=(r*a)%mod; p>>=1; a=(a*a)%mod; } return r; }
    
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}