import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class test {
    final static int MOD = 1000000007;
    final static int intMax = 1000000000;
    final static int intMin = -1000000000;
    final static int[] dx = { 0, 0, -1, 1 };
    final static int[] dy = { -1, 1, 0, 0 };

    static int add(int a, int b) {
        return (a + b) % MOD;
    }

    static int sub(int a, int b) {
        return (a - b + MOD) % MOD;
    }

    static int mult(int a, int b) {
        return (int)((((long)(a)) * b) % MOD);
    }

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[360]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }

    static class Sb_Output implements Closeable, Flushable{
        StringBuilder sb;
        OutputStream os;
        int BUFFER_SIZE;
        public Sb_Output(String s) throws Exception {
            os = new BufferedOutputStream(new FileOutputStream(new File(s)));
            BUFFER_SIZE = 1 << 16;
            sb = new StringBuilder(BUFFER_SIZE);
        }
        public void print(String s) {
            sb.append(s);
            if(sb.length() >= (BUFFER_SIZE>>1)) {
                flush();
            }
        }
        public void println(String s) {
            print(s);
            print("\n");
        }
        public void println(int i) {
            println("" + i);
        }
        public void println(long i) {
            println("" + i);
        }
        public void flush() {
            try {
                os.write(sb.toString().getBytes());
                sb = new StringBuilder(BUFFER_SIZE);
            }catch(IOException e) {
                e.printStackTrace();
            }
        }
        public void close() {
            flush();
            try {
                os.close();
            }catch(IOException e) {
                e.printStackTrace();
            }
        }
    }

    static ArrayList<Integer>[] adj;
    static long results[][];

    public static void main(String[] args) throws Exception {
        Reader in = new Reader();
//		Reader in = new Reader("poetry.in");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        BufferedReader br = new BufferedReader(new FileReader("poetry.in"));
        int n = Integer.parseInt(br.readLine());
        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i) {
            adj[i] = new ArrayList<Integer>();
        }
        for(int i = 0; i< n - 1; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken()) - 1;
            int v = Integer.parseInt(st.nextToken()) - 1;
            adj[u].add(v);
            adj[v].add(u);
        }
        sz = new int[n];
        cpar = new int[n];
        vis = new boolean[n];
        results = new long[n][n];
        for(int i = 0; i < n; ++i){
            Arrays.fill(results[i], -1);
        }
        long ret = 0;
        for(int cnd = 0; cnd < n; ++cnd){
            long ans = 0;
            dfs(cnd, -1);
            int mx = 0, mxind = 0;
            for(int i : adj[cnd]) {
                if(sz[i] > mx) {
                    mx = sz[i];
                    mxind = i;
                }
            }
            ans += (long) mx * (n - mx);
            //System.out.println(mx);
            long max = 0;
            sz[cnd] = n - mx;
            for(int i : adj[cnd]) {
                if(i == mxind) continue;
                max = max(max, solve(i, cnd, mxind, cnd));
            }
            for(int i : adj[mxind]) {
                if(i == cnd) continue;
                max = max(max, solve(i, mxind, cnd, mxind));
                //System.out.println(solve(i, mxind, cnd, mxind));
            }
            ret = max(ret, max + ans);
        }
        System.out.println(ret);
        in.close();
        //out.close();
    }

    static long solve(int d1, int p1, int d2, int p2) {
        if(results[d1][d2] != -1) {
            return results[d1][d2];
        }
        long mx = 0;
        for(int i : adj[d1]) {
            if(i == p1 || i == d2) continue;
            mx = max(mx, solve(i, d1, d2, p2));
        }
        for(int i : adj[d2]) {
            if(i == p2 || i == d1) continue;
            mx = max(mx, solve(d1, p1, i, d2));
        }
        //if(d1 == 3 && d2 == 4) System.out.println(mx);
        //System.out.println(d1 + " " + p1 + " " + d2 + " " + p2 + " " + mx);
        results[d1][d2] = results[d2][d1] = mx + (long) sz[d1] * sz[d2];
        return mx + (long) sz[d1] * sz[d2];
    }

    static class pair{
        int x, y, same;
        pair(int a, int b) {
            x = a; y = b;
            same = 0;
        }
    }
    static int[] sz, cpar;
    static boolean vis[];
    static int curans;

    static void dfs(int n, int p) {
        sz[n] = 1;
        for (int v : adj[n]) if (v != p && !vis[v]) {
            dfs(v, n);
            sz[n] += sz[v];
        }
    }

    static int centroid(int n) {
        dfs(n, -1);
        int num = sz[n];
        int p = -1;
        do {
            int nxt = -1;
            for (int v : adj[n]) if (v != p && !vis[v]) {
                if (2 * sz[v] > num)
                    nxt = v;
            }
            p = n; n = nxt;
        } while (~n != 0);
        return p;
    }

    static void centroid_decomp(int n, int p) {
        int c = centroid(n);
        vis[c] = true;
        cpar[c] = p;
        for (int v : adj[c]) if (!vis[v]) {
            centroid_decomp(v, c);
        }
    }

}