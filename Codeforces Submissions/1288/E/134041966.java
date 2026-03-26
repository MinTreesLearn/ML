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
        int[]min=new int[n+1];
        for (int i=1;i<=n;i++) min[i]=i;
        int[]max=new int[n+1];
        int[]lastmove=new int[n+1];
        
        st1 pre=new st1(1,n);
        st2 post=new st2(1,m);
        
        for (int i=1;i<=m;i++) {
            int u=ni();
            min[u]=1;
            
            if (lastmove[u]==0) {
                max[u]=u+pre.query(u);
                pre.update(u);
            }
            else {
                max[u]=Math.max(max[u],post.query(lastmove[u]));
            }
            
            post.update(lastmove[u]+1,i);
            lastmove[u]=i;
        }
        
        for (int i=1;i<=n;i++) {
            out.print(min[i]+" ");
            if (lastmove[i]==0) max[i]=i+pre.query(i);
            else {
                max[i]=Math.max(max[i],post.query(lastmove[i]));
            }
            out.println(max[i]);
        }
        out.flush();
    }
    
    class st2 {
        int lt,rt,s;
        st2 lc,rc;
        st2(int p,int q) {
            lt=p; rt=q;
            if (lt==rt) return;
            int mid=(p+q)/2;
            lc=new st2(p,mid);
            rc=new st2(mid+1,q);
        }
        
        void update(int p,int q) {
            if (q<lt || p>rt) return;
            if (p<=lt && q>=rt) { s++; return; }
            distrib();
            lc.update(p,q);
            rc.update(p,q);
        }
        
        int query(int u) {
            if (lt==rt) return s;
            distrib();
            if (u>lc.rt) return rc.query(u);
            else return lc.query(u);
        }
        
        void distrib() {
            if (s>0) {
                lc.s+=s;
                rc.s+=s;
                s=0;
            }
        }
    }
    
    class st1 {
        int mid,s;
        boolean f;
        st1 lc,rc;
        st1(int p,int q) {
            if (p==q) { f=true; return; }
            mid=(p+q)/2;
            lc=new st1(p,mid);
            rc=new st1(mid+1,q);
        }
        
        void update(int u) {
            if (f) { s++; return; }
            distrib();
            if (u<=mid) lc.update(u);
            else { lc.s+=1; rc.update(u); }
        }
        
        int query(int u) {
            if (f) { return s; }
            distrib();
            if (u>mid) return rc.query(u);
            else return lc.query(u);
        }
        
        void distrib() {
            if (s>0) {
                lc.s+=s;
                rc.s+=s;
                s=0;
            }
        }
    }
    
    int gcd(int a,int b) { return(b==0?a:gcd(b,a%b)); }
    long gcd(long a,long b) { return(b==0?a:gcd(b,a%b)); }
    long mp(long a,long p) { long r=1; while(p>0) { if ((p&1)==1) r=(r*a)%mod; p>>=1; a=(a*a)%mod; } return r; }
    
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}