import java.util.*;
import java.io.*;

public class Div712 {
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////                                                                                                               /////////
////////                                                                                                               /////////
////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMM          MMMM         OOOOOO             SSSSSSS      EEEEEEEEEEEEE  /////////
////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMMMM      MMMMMM      OOO      OOO        SSSS   SSS     EEEEEEEEEEEEE  /////////
////////   HHHH        HHHH  EEEEE           MMMM MMM  MMM MMMM    OOO          OOO    SSSS       SSS   EEEEE          /////////
////////   HHHH        HHHH  EEEEE           MMMM  MMMMMM  MMMM   OOO            OOO   SSSS             EEEEE          /////////
////////   HHHH        HHHH  EEEEE           MMMM          MMMM  OOO              OOO   SSSSSSS         EEEEE          /////////
////////   HHHHHHHHHHHHHHHH  EEEEEEEEEEE     MMMM          MMMM  OOO              OOO      SSSSSS       EEEEEEEEEEE    /////////
////////   HHHHHHHHHHHHHHHH  EEEEEEEEEEE     MMMM          MMMM  OOO              OOO         SSSSSSS   EEEEEEEEEEE    /////////
////////   HHHH        HHHH  EEEEE           MMMM          MMMM   OOO            OOO              SSSS  EEEEE          /////////
////////   HHHH        HHHH  EEEEE           MMMM          MMMM    OOO          OOO     SSS       SSSS  EEEEE          /////////
////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMM          MMMM      OOO      OOO        SSS    SSSS    EEEEEEEEEEEEE  /////////
////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMM          MMMM         OOOOOO             SSSSSSS      EEEEEEEEEEEEE  /////////
////////                                                                                                               /////////
////////                                                                                                               /////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int[] a = sc.nextIntArr(n);
        int[] cost = sc.nextIntArr(n);

        int size = 1;
        while (size < n) size <<= 1;
        SegmentTree tree = new SegmentTree(size);

        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += cost[i];
            tree.update_range(a[i], n, cost[i]);
        }


        long ans = sum;
        long cur = 0;
        for (int i = 0; i < n - 1; i++) {
            cur += cost[i];
            sum -= cost[i];
            ans = Math.min(ans, Math.min(sum, cur));
            tree.update_range(a[i], n, -cost[i]);
            tree.update_range(1, a[i] - 1, cost[i]);
            tree.update_range(a[i], a[i], (long) -2e16);

            ans = Math.min(ans, tree.query(1, n));
        }

        pw.println(ans);

        pw.flush();
    }


    static class SegmentTree {        // 1-based DS, OOP

        int N;            //the number of elements in the array as a power of 2 (i.e. after padding)
        long[] sTree, lazy;

        SegmentTree(int size) {

            N = size;
            sTree = new long[N << 1];        //no. of nodes = 2*N - 1, we add one to cross out index zero
            lazy = new long[N << 1];
            Arrays.fill(sTree, (long) 2e16);
        }


        void update_range(int i, int j, long val)        // O(log n)
        {
            update_range(1, 1, N, i, j, val);
        }

        void update_range(int node, int b, int e, int i, int j, long val) {
            if (i > e || j < b)
                return;
            if (b >= i && e <= j) {
                sTree[node] += val;
                lazy[node] += val;
            } else {
                int mid = b + e >> 1;
                propagate(node, b, mid, e);
                update_range(node << 1, b, mid, i, j, val);
                update_range(node << 1 | 1, mid + 1, e, i, j, val);
                sTree[node] = Math.min(sTree[node << 1], sTree[node << 1 | 1]);
            }

        }

        void propagate(int node, int b, int mid, int e) {
            lazy[node << 1] += lazy[node];
            lazy[node << 1 | 1] += lazy[node];
            sTree[node << 1] += lazy[node];
            sTree[node << 1 | 1] += lazy[node];
            lazy[node] = 0;
        }

        long query(int i, int j) {
            return query(1, 1, N, i, j);
        }

        long query(int node, int b, int e, int i, int j)    // O(log n)
        {
            if (i > e || j < b)
                return (long) 1e18;
            if (b >= i && e <= j)
                return sTree[node];
            int mid = b + e >> 1;
            propagate(node, b, mid, e);
            long q1 = query(node << 1, b, mid, i, j);
            long q2 = query(node << 1 | 1, mid + 1, e, i, j);
            return Math.min(q1, q2);

        }
    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int[] nextIntArr(int n) throws IOException {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            String x = next();
            StringBuilder sb = new StringBuilder("0");
            double res = 0, f = 1;
            boolean dec = false, neg = false;
            int start = 0;
            if (x.charAt(0) == '-') {
                neg = true;
                start++;
            }
            for (int i = start; i < x.length(); i++)
                if (x.charAt(i) == '.') {
                    res = Long.parseLong(sb.toString());
                    sb = new StringBuilder("0");
                    dec = true;
                } else {
                    sb.append(x.charAt(i));
                    if (dec)
                        f *= 10;
                }
            res += Long.parseLong(sb.toString()) / f;
            return res * (neg ? -1 : 1);
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }

}
