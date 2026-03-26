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
        for (int tc=ni();tc>0;tc--) {
            int n=ni();
            int[][]A=new int[n][3];
            for (int i=0;i<n;i++) { A[i][0]=ni(); A[i][1]=ni(); A[i][2]=i;}
            Arrays.sort(A,(a,b)->Integer.compare(a[0],b[0]));
        
            int[]C=new int[n];
            HashSet<Integer>H=new HashSet();
            PriorityQueue<Pair>Q=new PriorityQueue<Pair>((a,b)->a.v-b.v);
        
            int max=0;
            int seg=-1;
            int ans=1;
            boolean end=false;
            boolean overlap=false;
        
            for (int i=0;i<n;i++) {
                int nextstart=A[i][0];
                while (Q.size()>0 && Q.peek().v<nextstart) {
                    Pair toremove=Q.poll();
                    H.remove(toremove.id);
                    end=true;
                }
                
                if (end && H.size()==1 ) {
                    for (int v:H) {
                        C[v]++;
                        if (C[v]>max) { max=C[v]; seg=v; }
                    }
                }
            
                if (end && H.size()==0) { ans++; end=false; }
                if (H.size()>0) overlap=true;
            
                H.add(A[i][2]);
                Q.add(new Pair(A[i][1],A[i][2]));
            }
            
            if (!overlap) ans--;
            //out.println(ans+" "+max);
            out.println(ans+max);
        }
        out.flush();
    }
    
    class Pair {
        int v,id;
        Pair(int a,int b) { v=a; id=b; }
        int getval() { return v; }
    }
    
    int gcd(int a,int b) { return(b==0?a:gcd(b,a%b)); }
    long gcd(long a,long b) { return(b==0?a:gcd(b,a%b)); }
    long mp(long a,long p) { long r=1; while(p>0) { if ((p&1)==1) r=(r*a)%mod; p>>=1; a=(a*a)%mod; } return r; }
    
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}