import java.io.*;
import java.util.*;
public class Main {
    InputReader in;
    final long mod=1000000007;
    StringBuilder sb;
    public static void main(String[] args) throws java.lang.Exception {
        new Main().run();
    }
    void run() throws Exception {
        in=new InputReader(System.in);
        sb = new  StringBuilder();        
        int t=1;
        for(int i=1;i<=t;i++)
            solve();
        System.out.print(sb);
    }
    ArrayList<Integer> adj[];
    int dis[], p[];
    void dfs(int v, int par) {
        p[v]=par;
        dis[v]=dis[par]+1;
        for(Integer x : adj[v]) {
            if(x!=par)
                dfs(x, v);
        }   
    }
    void solve() {
        int i, j;
        int n=i();
        adj=new ArrayList[n+1];
        dis=new int[n+1];
        p=new int[n+1];
        dis[0]=-1;
        for(i=0;i<=n;i++)
            adj[i]=new ArrayList<>();
        for(i=1;i<n;i++) {
            int x=i(), y=i();
            adj[x].add(y);
            adj[y].add(x);
        }
        dfs(1, 0);
        int max=0, a=0, b=0;
        for(i=2;i<=n;i++) {
            if(dis[i]>max) {
                max=dis[i];
                a=i;
            }
        }
        dfs(a, 0);
        int ans=0;
        for(i=1;i<=n;i++) {
            if(ans<dis[i])  {
                ans=dis[i];
                b=i;
            }
        }
        ArrayList<Integer> diam = new ArrayList<>();
        while(b!=a) {
            diam.add(b);
            b=p[b];
        }
        diam.add(a);
        if(diam.size()==n) {
            sb.append((n-1)+"\n");
            sb.append(diam.get(0)+" "+diam.get(1)+" "+a+"\n");
            return;
        }
        boolean vis[]=new boolean[n+1];
        LinkedList<Integer> queue = new LinkedList<>();
        for(i=0;i<diam.size();i++) {
            queue.add(diam.get(i));
            vis[diam.get(i)]=true;
        }
        dis=new int[n+1];
        while(queue.size()!=0) {
            int v=queue.poll();
            for(Integer u : adj[v]) {
                if(!vis[u]) {
                    queue.add(u);
                    dis[u]=dis[v]+1;
                    vis[u]=true;
                }
            }
        }
        max=0;
        int pos=0;
        for(i=1;i<=n;i++) {
            if(max<dis[i]) {
                max=dis[i];
                pos=i;
            }
        }
        sb.append((diam.size()+max-1)+"\n");
        sb.append(diam.get(0)+" "+pos+" "+a+"\n");
    }
    long mul(long x, long y) {long ans = x*y;return (ans>=mod ? ans%mod : ans);}
    long power(long x, long y, long p) {  
        long res = 1;       
        x = x % p;  
        if (x == 0) return 0;   
        while (y > 0) {
            if((y & 1)==1) 
                res = (res * x) % p;  
            y = y >> 1;  
            x = (x * x) % p;  
        } 
        return res%p; 
    } 
    long gcd(long a, long b) { return (b==0)?a:gcd(b,a%b); }
    int gcd(int a, int b) { return (b==0)?a:gcd(b,a%b); }
    String s() { return in.next(); }
    int i() { return in.nextInt(); }
    long l() {return in.nextLong();}
    class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        public InputReader(InputStream stream) {
            this.stream = stream;
        }
        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }
        public int peek() {
            if (numChars == -1)
                return -1;
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    return -1;
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar];
        }
        public void skip(int x) {
            while (x-->0)
                read();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public String nextString() {
            return next();
        }
        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
 
            return res.toString();
        }
        public String nextLine() {
            StringBuffer buf = new StringBuffer();
            int c = read();
            while (c != '\n' && c != -1) {
                if (c != '\r')
                    buf.appendCodePoint(c);
                c = read();
            }
            return buf.toString();
        }
        public double nextDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, nextInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }
        public boolean hasNext() {
            int value;
            while (isSpaceChar(value = peek()) && value != -1)
                read();
            return value != -1;
        }
        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}