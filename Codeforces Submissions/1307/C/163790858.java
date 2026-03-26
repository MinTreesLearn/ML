import java.io.*;
import java.util.*;

public class Cow_and_Message {

    static FastScanner fs;
    static FastWriter fw;
    static boolean checkOnlineJudge = System.getProperty("ONLINE_JUDGE") == null;

    private static final int[][] kdir = new int[][]{{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    private static final int[][] dir = new int[][]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    private static final int iMax = (int) (1e9 + 100), iMin = (int) (-1e9 - 100);
    private static final long lMax = (long) (1e18 + 100), lMin = (long) (-1e18 - 100);
    private static final int mod1 = (int) (1e9 + 7);
    private static final int mod2 = 998244353;

    public static void main(String[] args) throws IOException {

        fs = new FastScanner();
        fw = new FastWriter();

        int t = 1;
        //t = fs.nextInt();
        while (t-- > 0) {
            solve();
        }

        fw.out.close();
    }

    private static void solve() {

        String s = fs.nextLine();
        int n = s.length();
        long[][] prefix_sum = new long[n + 1][26];
        for (int i = n - 1; i >= 0; i--) {
            int ascii = s.charAt(i) - 'a';
            prefix_sum[i][ascii] = 1;
            for (int j = 0; j < 26; j++) {
                prefix_sum[i][j] += prefix_sum[i + 1][j];
            }
        }

        List<List<Integer>> indexes = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            indexes.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            int ascii = s.charAt(i) - 'a';
            indexes.get(ascii).add(i);
        }

        long result = 0;
        for (List<Integer> list : indexes) {
            result = Math.max(result, list.size());
            long[] ans = new long[26];
            for (int i : list) {
                for (int j = 0; j < 26; j++) {
                    ans[j] += prefix_sum[i + 1][j];
                }
            }
            for (long x : ans) result = Math.max(result, x);
        }
        fw.out.println(result);
    }

    private static class UnionFind {

        private final int[] parent;
        private final int[] rank;

        UnionFind(int n) {
            parent = new int[n + 5];
            rank = new int[n + 5];
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        private int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }

        private void union(int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) {
                if (rank[a] < rank[b]) {
                    int temp = a;
                    a = b;
                    b = temp;
                }
                parent[b] = a;
                if (rank[a] == rank[b])
                    rank[a]++;
            }
        }
    }

    private static class Calc_nCr {
        private final long[] fact;
        private final long[] invfact;
        private final int p;

        Calc_nCr(int n, int prime) {
            fact = new long[n + 5];
            invfact = new long[n + 5];
            p = prime;

            fact[0] = 1;
            for (int i = 1; i <= n; i++) {
                fact[i] = (i * fact[i - 1]) % p;
            }

            invfact[n] = pow(fact[n], p - 2, p);
            for (int i = n - 1; i >= 0; i--) {
                invfact[i] = (invfact[i + 1] * (i + 1)) % p;
            }
        }

        private long nCr(int n, int r) {
            if (r > n || n < 0 || r < 0) return 0;
            return (((fact[n] * invfact[r]) % p) * invfact[n - r]) % p;
        }
    }

    private static long gcd(long a, long b) {
        return (b == 0 ? a : gcd(b, a % b));
    }

    private static long lcm(long a, long b) {
        return ((a * b) / gcd(a, b));
    }

    private static long pow(long a, long b, int mod) {
        long result = 1;
        while (b > 0) {
            if ((b & 1L) == 1) {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }

        return result;
    }

    private static long ceilDiv(long a, long b) {
        return ((a + b - 1) / b);
    }

    private static long getMin(long... args) {
        long min = lMax;
        for (long arg : args)
            min = Math.min(min, arg);
        return min;
    }

    private static long getMax(long... args) {
        long max = lMin;
        for (long arg : args)
            max = Math.max(max, arg);
        return max;
    }

    private static boolean isPalindrome(String s, int l, int r) {

        int i = l, j = r;
        while (j - i >= 1) {
            if (s.charAt(i) != s.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
    }

    private static List<Integer> primes(int n) {

        boolean[] primeArr = new boolean[n + 5];
        Arrays.fill(primeArr, true);
        for (int i = 2; (i * i) <= n; i++) {
            if (primeArr[i]) {
                for (int j = i * i; j <= n; j += i) {
                    primeArr[j] = false;
                }
            }
        }

        List<Integer> primeList = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (primeArr[i])
                primeList.add(i);
        }

        return primeList;
    }

    private static int noOfSetBits(long x) {
        int cnt = 0;
        while (x != 0) {
            x = x & (x - 1);
            cnt++;
        }
        return cnt;
    }

    private static boolean isPerfectSquare(long num) {
        long sqrt = (long) Math.sqrt(num);
        return ((sqrt * sqrt) == num);
    }

    private static class Pair<U, V> {

        private final U first;
        private final V second;

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return first.equals(pair.first) && second.equals(pair.second);
        }

        @Override
        public int hashCode() {
            return Objects.hash(first, second);
        }

        @Override
        public String toString() {
            return "(" + first + ", " + second + ")";
        }

        private Pair(U ff, V ss) {
            this.first = ff;
            this.second = ss;
        }
    }

    private static void randomizeIntArr(int[] arr, int n) {
        Random r = new Random();
        for (int i = (n - 1); i > 0; i--) {
            int j = r.nextInt(i + 1);
            swapInIntArr(arr, i, j);
        }
    }

    private static void randomizeLongArr(long[] arr, int n) {
        Random r = new Random();
        for (int i = (n - 1); i > 0; i--) {
            int j = r.nextInt(i + 1);
            swapInLongArr(arr, i, j);
        }
    }

    private static void swapInIntArr(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    private static void swapInLongArr(long[] arr, int a, int b) {
        long temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    private static int[] readIntArray(int n) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = fs.nextInt();
        return arr;
    }

    private static long[] readLongArray(int n) {
        long[] arr = new long[n];
        for (int i = 0; i < n; i++)
            arr[i] = fs.nextLong();
        return arr;
    }

    private static List<Integer> readIntList(int n) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(fs.nextInt());
        return list;
    }

    private static List<Long> readLongList(int n) {
        List<Long> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(fs.nextLong());
        return list;
    }

    private static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() throws IOException {
            if (checkOnlineJudge)
                this.br = new BufferedReader(new FileReader("src/input.txt"));
            else
                this.br = new BufferedReader(new InputStreamReader(System.in));

            this.st = new StringTokenizer("");
        }

        public String next() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException err) {
                    err.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public String nextLine() {
            if (st.hasMoreTokens()) {
                return st.nextToken("").trim();
            }
            try {
                return br.readLine().trim();
            } catch (IOException err) {
                err.printStackTrace();
            }
            return "";
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    private static class FastWriter {
        PrintWriter out;

        FastWriter() throws IOException {
            if (checkOnlineJudge)
                out = new PrintWriter(new FileWriter("src/output.txt"));
            else
                out = new PrintWriter(System.out);
        }
    }
}
