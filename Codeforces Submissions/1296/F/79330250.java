import java.io.*;
import java.util.*;

public class Task {

    public static void main(String[] args) throws Exception {

        new Task().go();
    }

    PrintWriter out;
    Reader in;
    BufferedReader br;

    Task() throws IOException {

        try {

            //br = new BufferedReader( new FileReader("input.txt") );
            //in = new Reader("input.txt");
            in = new Reader("input.txt");
            out = new PrintWriter( new BufferedWriter(new FileWriter("output.txt")) );
        }
        catch (Exception e) {

            //br = new BufferedReader( new InputStreamReader( System.in ) );
            in = new Reader();
            out = new PrintWriter( new BufferedWriter(new OutputStreamWriter(System.out)) );
        }
    }

    void go() throws Exception {

        //int t = in.nextInt();
        int t = 1;
        while (t > 0) {
            solve();
            t--;
        }

        out.flush();
        out.close();
    }


    int inf = 2000000000;
    int mod = 1000000007;
    double eps = 0.000000001;

    int n;
    int m;

    ArrayList<Integer>[] g;
    int[][] buity = new int[5000][5000];
    void solve() throws IOException {
        int n = in.nextInt();
        g = new ArrayList[n];
        Pair[] edges = new Pair[n - 1];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            g[x].add(y);
            g[y].add(x);
            buity[x][y] = 1;
            buity[y][x] = 1;
            edges[i] = new Pair(x, y);
        }

        boolean ok = true;
        int m = in.nextInt();
        int[][] paths = new int[m][n + 1];
        int[] gs = new int[m];
        int[] p = new int[n];
        ArrayDeque<Integer> q = new ArrayDeque<>();
        int[] queue = new int[n + 1];
        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            int z = in.nextInt();
            gs[i] = z;
            int h = 0;
            int t = 0;
            queue[h] = a;
            t++;
            Arrays.fill(p, -1);
            p[a] = a;
            while (h < t) {
                int v = queue[h];
                h++;
                for (int u : g[v]) {
                    if (p[u] == -1) {
                        p[u] = v;
                        queue[t] = u;
                        t++;
                    }
                }
            }
            int pos = 1;
            while (b != a) {
                paths[i][pos] = b;
                pos++;
                int prev = b;
                b = p[b];
                if (buity[prev][b] < z) {
                    buity[prev][b] = z;
                    buity[b][prev] = z;
                }
            }
            paths[i][pos] = a;
            pos++;
            paths[i][0] = pos;
        }

        for (int i = 0; i < m; i++) {
            int min = 1000000;
            int len = paths[i][0];
            for (int j = 2; j < len; j++) {
                int x = paths[i][j - 1];
                int y = paths[i][j];
                min = Math.min(min, buity[x][y]);
            }
            ok &= min == gs[i];
        }

        if (ok) {
            for (int i = 0; i < n - 1; i++)
                out.print(buity[edges[i].a][edges[i].b] + " ");
        } else {
            out.println(-1);
        }
    }



    class Pair implements Comparable<Pair> {

        int a;
        int b;

        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }

        public int compareTo(Pair p) {
            if (a != p.a)
                return Integer.compare(a, p.a);
            else
                return Integer.compare(-b, -p.b);
        }
    }

    class Item {

        int a;
        int b;
        int c;

        Item(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

    }


    class Reader {

        BufferedReader  br;
        StringTokenizer tok;

        Reader(String file) throws IOException {
            br = new BufferedReader( new FileReader(file) );
        }

        Reader() throws IOException {
            br = new BufferedReader( new InputStreamReader(System.in) );
        }

        String next() throws IOException {

            while (tok == null || !tok.hasMoreElements())
                tok = new StringTokenizer(br.readLine());
            return tok.nextToken();
        }

        int nextInt() throws NumberFormatException, IOException {
            return Integer.valueOf(next());
        }

        long nextLong() throws NumberFormatException, IOException {
            return Long.valueOf(next());
        }

        double nextDouble() throws NumberFormatException, IOException {
            return Double.valueOf(next());
        }


        String nextLine() throws IOException {
            return br.readLine();
        }

    }

    static class InputReader
    {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public InputReader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public InputReader(String file_name) throws IOException
        {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1)
            {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do
            {
                ret = ret * 10 + c - '0';
            }  while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');

            if (c == '.')
            {
                while ((c = read()) >= '0' && c <= '9')
                {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }

}