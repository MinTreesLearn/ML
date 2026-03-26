import java.util.*;
import java.io.*;
import java.math.*;
 
public class Solution {
    public static void main(String[] args) throws IOException {
        //PrintWriter out = new PrintWriter(new File("out.txt"));
        PrintWriter out = new PrintWriter(System.out);
        //Reader in = new Reader(new FileInputStream("in.txt"));
        Reader in = new Reader();
        Solution solver = new Solution();
        solver.solve(out, in);
        out.flush();
        out.close();
 
    }
 
 
    static int maxn = 5*(int)1e5+5;
    static long mod=(int)1e9+7;
    static int n, m, t, k, q;
    
    static int[] rank, clr, arr;
    static Node[] par;
    static ArrayList<Edge> adj[];
    static boolean[] vis;
    
    void solve(PrintWriter out, Reader in) throws IOException{
        n = in.nextInt();
        k = in.nextInt();
        
        String s = in.next();
        arr = new int[n+1];
        for (int i = 0; i < n; i++) {
            arr[i+1] = s.charAt(i)-'0';
        }
        
        adj = new ArrayList[k+1];
        for (int i = 1; i <= k; i++)
            adj[i] = new ArrayList<Edge>();
        
        ArrayList<Integer> pos[] = new ArrayList[n+1];
        for (int i = 1; i <= n; i++)
            pos[i] = new ArrayList<Integer>();
        
        for (int z = 1; z <= k; z++) {
            int c = in.nextInt();
            
            for (int i = 0; i < c; i++) {
                pos[in.nextInt()].add(z);
            }
        }
        
        int u = 0, v = 0;
        for (int i = 1; i <= n; i++) {
            if (pos[i].size() == 2) {
                u = pos[i].get(0);
                v = pos[i].get(1);
                adj[u].add(new Edge(v, i));
                adj[v].add(new Edge(u, i));
            }
        }
        
        clr = new int[k+1];
        vis = new boolean[k+1];
        for (int i = 1; i <= k; i++) {
            if (!vis[i]) {
                clr[i] = 1;
                DFS(i);
            }
        }
        
        int[] ans = new int[n+1];
        rank = new int[k+1];
        par = new Node[k+1];
        for (int i = 1; i <= k; i++) {
            par[i] = new Node(i, clr[i], clr[i]^1);
        }
        for (int i = 1; i <= k; i++) vis[i] = false;
        
        for (int i = 1; i <= n; i++) {
            if (pos[i].size() == 2) {
                u = pos[i].get(0); v = pos[i].get(1);
                u = find(u); v = find(v);
                if (u == v) {
                    vis[u] = true;
                } else {
                    ans[i] -= (vis[u]?getans(u):0) + (vis[v]?getans(v):0);
                    //out.print(u+" "+v+" "+(vis[u]?getans(u):0) +" "+ (vis[v]?getans(v):0)+" ");
                    vis[u] = vis[v] = true;
                    union(u, v);
                    u = find(u);
                    //out.println(u+" "+getans(u)+" "+i);
                    ans[i] += getans(u);
                }
            } else if (pos[i].size() == 1) {
                u = pos[i].get(0);
                v = clr[u]^arr[i];
                u = find(u);
                if (vis[u]) ans[i] -= getans(u);
                //out.print(vis[u]+" "+u+" "+getans(u));
                vis[u] = true;
                if (v == 1) par[u].redf = true;
                else par[u].bluef = true;
                ans[i] += getans(u);
                //out.println(" "+getans(u)+" "+u+" "+i+" "+v);
            }
            ans[i] += ans[i-1];
            out.println(ans[i]);
        }
    }
    
    //<>
    
    static void DFS(int s) {
        vis[s] = true;
        for (Edge e:adj[s]) {
            if (!vis[e.to]) {
                int tmp = clr[s]+arr[e.w];
                clr[e.to] = (tmp%2)^1;
                DFS(e.to);
            }
        }
    }
    
    static int getans(int x) {
        if (par[x].redf) return par[x].red;
        else if (par[x].bluef) return par[x].blue;
        return Math.min(par[x].red, par[x].blue);
    }
    
    static int find(int x) {
        if (x != par[x].rt) par[x].rt = find(par[x].rt);
        return par[x].rt;
    }
    
    static void union(int xroot, int yroot) {
        
        if (rank[xroot] < rank[yroot]) {
            par[xroot].rt = yroot;
        } else if (rank[xroot] > rank[yroot]) {
            par[yroot].rt = xroot;
            int tmp = xroot;
            xroot = yroot;
            yroot = tmp;
        } else {
            par[xroot].rt = yroot;
            rank[yroot]++;
        }
        par[yroot].red += par[xroot].red;
        par[yroot].blue += par[xroot].blue;
        par[yroot].bluef |= par[xroot].bluef;
        par[yroot].redf  |= par[xroot].redf;
    }
    
    static class Node {
        int rt, red, blue;
        boolean bluef, redf;
        
        Node (int rt, int red, int blue) {
            this.rt = rt;
            this.red = red;
            this.blue = blue;
        }
    }
    
    static class Edge {
        int to, w;
        
        Edge(int to, int w) {
            this.to = to;
            this.w  = w;
        }
    }
    
    static class Reader {
 
        private InputStream mIs;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
    
        public Reader() {
            this(System.in);
        }
    
        public Reader(InputStream is) {
            mIs = is;
        }
    
        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
    
        }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = mIs.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }
    
        public String nextLine() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndOfLine(c));
            return res.toString();
        }
    
        public String next() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }
    
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
    
        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
    
        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
    
        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    
        public boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }
 
    }
}
