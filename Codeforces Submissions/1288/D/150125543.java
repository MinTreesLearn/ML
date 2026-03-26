import java.util.*;

import javax.swing.text.PlainDocument;

import java.io.*;

public class Main {

    static int n, m;
    static int[][] grid;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        grid = new int[n][m];
        int max = 0;
        for (int i = 0; i < n; i++) {
            grid[i] = sc.nextIntArray(m);
        }

        int start = 0;
        int end = (int) 1e9;
        Integer[] result = new Integer[2];

        while (start <= end) {
            int mid = (start + end) / 2;
            HashMap<Integer, Integer> set = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int mask = 0;
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] >= mid)
                        mask = setBit(mask, j);
                }
                if (set.getOrDefault(mask, -1) == -1)
                    set.put(mask, i);
                // pw.println(set.toString());
                if (set.size() == (1 << m))
                    break;

            }
            boolean flag = false;
            for (Integer integer : set.keySet()) {
                for (Integer integer2 : set.keySet()) {
                    if ((integer | integer2) == ((1 << m) - 1)) {
                        result = new Integer[] { set.get(integer) + 1, set.get(integer2) + 1 };
                        flag = true;
                        break;
                    }

                }
                if (flag)
                    break;
            }
            if (flag)
                start = mid + 1;
            else
                end = mid - 1;

        }

        pw.println(toString(result));

        pw.close();
    }

    static long[][] memo;

    public static long dp(int idx1) {
        if (idx1 == n)
            return 0;
        long res = 0;
        for (int i = idx1; i < n; i++) {
            res = Math.max(res, getMin(grid[idx1], grid[i]));
        }
        return res;
    }

    public static int getMin(int[] arr1, int arr2[]) {
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < arr2.length; i++) {
            min = Math.min(min, Math.max(arr2[i], arr1[i]));
        }
        return min;
    }

    public static int setBit(int mask, int ind) {
        return mask | (1 << ind);
    }

    public static boolean checkBit(int mask, int ind) {
        return (mask & (1 << ind)) != 0;
    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
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

        public long[] nextlongArray(int n) throws IOException {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }

        public Long[] nextLongArray(int n) throws IOException {
            Long[] a = new Long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }

        public int[] nextIntArray(int n) throws IOException {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public Integer[] nextIntegerArray(int n) throws IOException {
            Integer[] a = new Integer[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public boolean ready() throws IOException {
            return br.ready();
        }

    }

    static class pair implements Comparable<pair> {
        long x;
        long y;

        public pair(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return x + " " + y;
        }

        public boolean equals(Object o) {
            if (o instanceof pair) {
                pair p = (pair) o;
                return p.x == x && p.y == y;
            }
            return false;
        }

        public int hashCode() {
            return new Long(x).hashCode() * 31 + new Long(y).hashCode();
        }

        public int compareTo(pair other) {
            if (this.x == other.x) {
                return Long.compare(this.y, other.y);
            }
            return Long.compare(this.x, other.x);
        }
    }

    static class tuble implements Comparable<tuble> {
        int x;
        int y;
        int z;

        public tuble(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public String toString() {
            return x + " " + y + " " + z;
        }

        public int compareTo(tuble other) {
            if (this.x == other.x) {
                if (this.y == other.y) {
                    return this.z - other.z;
                }
                return this.y - other.y;
            } else {
                return this.x - other.x;
            }
        }
    }

    public static String toString(int[] arr) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < arr.length; i++) {
            sb.append(arr[i] + " ");
        }
        return sb.toString().trim();
    }

    public static String toString(Integer[] arr) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < arr.length; i++) {
            sb.append(arr[i] + " ");
        }
        return sb.toString().trim();
    }

    static long mod = 1000000007;
    static Random rn = new Random();
    static Scanner sc = new Scanner(System.in);
    static PrintWriter pw = new PrintWriter(System.out);

}
