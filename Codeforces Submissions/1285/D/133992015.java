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
        int n=ni();
        int[]A=new int[n];
        for (int i=0;i<n;i++) A[i]=ni();
        Arrays.sort(A);
        
        ArrayList<Integer>B=new ArrayList();
        B.add(0);
        B.add(n);
        int ans=0;
        int p=1<<29;
        
        while (p>0) {
            ArrayList<Integer>C=new ArrayList();
            ArrayList<Integer>D=new ArrayList();
            
            for (int i=0;i<B.size();i+=2) {
                int lt=B.get(i);
                int rt=B.get(i+1);
                int mid=-1;
                for (int j=lt;j<rt;j++)
                    if ((A[j]&p)>0) { mid=j; break; }
                    
                if (mid==-1 || mid==lt) { D.add(lt); D.add(rt); }
                else { C.add(lt); C.add(mid); C.add(mid); C.add(rt); }
            }
            
            B.clear();
            if (D.size()==0) {
                ans|=p;
                for (int v:C) B.add(v);
            }
            else {
                for (int v:D) B.add(v);
            }
            
            p>>=1;
        }
        
        out.println(ans);
        out.flush();
    }
    
    int gcd(int a,int b) { return(b==0?a:gcd(b,a%b)); }
    long gcd(long a,long b) { return(b==0?a:gcd(b,a%b)); }
    long mp(long a,long p) { long r=1; while(p>0) { if ((p&1)==1) r=(r*a)%mod; p>>=1; a=(a*a)%mod; } return r; }
    
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}