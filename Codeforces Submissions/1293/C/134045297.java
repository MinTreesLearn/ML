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
        //for (int tc=ni();tc>0;tc--) {
            int n=ni(),q=ni();
            HashSet<Integer>H=new HashSet();
            int[][]A=new int[3][n+1];
            
            for (int i=0;i<q;i++) {
                int x=ni(),y=ni();
                if (x==1) {
                    if (A[x][y]==1) {
                        A[x][y]=0;
                        for (int j=Math.max(1,y-1);j<=n && j<=y+1;j++) {
                            boolean f=true;
                            for (int k=Math.max(1,j-1);k<=n && k<=j+1;k++)
                                if (A[1][k]==1) f=false;
                                
                            if (f) H.remove(j);
                        }
                    }
                    else {
                        A[x][y]=1;
                        for (int j=Math.max(1,y-1);j<=n && j<=y+1;j++) {
                            if (A[2][j]==0) continue;
                            boolean f=false;
                            for (int k=Math.max(1,j-1);k<=n && k<=j+1;k++)
                                if (A[1][k]==1) f=true;
                                
                            if (f) H.add(j);
                        }
                    }
                }
                else {
                    if (A[x][y]==1) {
                        A[x][y]=0;
                        H.remove(y);
                    }
                    else {
                        A[x][y]=1;
                        boolean f=false;
                        for (int k=Math.max(1,y-1);k<=n && k<=y+1;k++)
                            if (A[1][k]==1) f=true;
                                
                        if (f) H.add(y);
                    }
                }
                
                if (H.size()==0) out.println("Yes");
                else out.println("No");
            }
        //}
        out.flush();
    }
    
    int gcd(int a,int b) { return(b==0?a:gcd(b,a%b)); }
    long gcd(long a,long b) { return(b==0?a:gcd(b,a%b)); }
    long mp(long a,long p) { long r=1; while(p>0) { if ((p&1)==1) r=(r*a)%mod; p>>=1; a=(a*a)%mod; } return r; }
    
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}