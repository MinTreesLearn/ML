import java.io.*;
import java.util.*;

public class MEX_Maximizing {

    static FastScanner fs;
    static FastWriter fw;
    static boolean checkOnlineJudge = System.getProperty("ONLINE_JUDGE") == null;

    private static final int[][] kdir = new int[][]{{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    private static final int[][] dir = new int[][]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    private static final int iMax = Integer.MAX_VALUE, iMin = Integer.MIN_VALUE;
    private static final long lMax = Long.MAX_VALUE, lMin = Long.MIN_VALUE;
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

        int n = fs.nextInt(), x = fs.nextInt();
        int[] arr = readIntArray(n);
        for (int i = 0; i < n; i++) {
            arr[i] = (arr[i] % x);
        }
        int[] mul = new int[n];
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            long curr = num + ((long) mul[num] * x);
            if (curr >= n) continue;
            arr[i] = (int) curr;
            mul[num]++;
        }

        int[] occ = new int[n + 1];
        int idx = 0;
        for (int i = 0; i < n; i++) {
            occ[arr[i]] = 1;
            while (occ[idx] == 1) idx++;
            fw.out.println(idx);
        }
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

    private static class SCC {
        private final int n;
        private final List<List<Integer>> adjList;

        SCC(int _n, List<List<Integer>> _adjList) {
            n = _n;
            adjList = _adjList;
        }

        private List<List<Integer>> getSCC() {
            List<List<Integer>> ans = new ArrayList<>();

            Stack<Integer> stack = new Stack<>();
            boolean[] vis = new boolean[n];
            for (int i = 0; i < n; i++) {
                if (!vis[i]) dfs(i, adjList, vis, stack);
            }

            vis = new boolean[n];
            List<List<Integer>> rev_adjList = rev_graph(n, adjList);
            while (!stack.isEmpty()) {
                int curr = stack.pop();
                if (!vis[curr]) {
                    List<Integer> scc_list = new ArrayList<>();
                    dfs2(curr, rev_adjList, vis, scc_list);
                    ans.add(scc_list);
                }
            }
            return ans;
        }

        private void dfs(int curr, List<List<Integer>> adjList, boolean[] vis, Stack<Integer> stack) {
            vis[curr] = true;
            for (int x : adjList.get(curr)) {
                if (!vis[x]) dfs(x, adjList, vis, stack);
            }
            stack.add(curr);
        }

        private void dfs2(int curr, List<List<Integer>> adjList, boolean[] vis, List<Integer> scc_list) {
            vis[curr] = true;
            scc_list.add(curr);
            for (int x : adjList.get(curr)) {
                if (!vis[x]) dfs2(x, adjList, vis, scc_list);
            }
        }
    }

    private static List<List<Integer>> rev_graph(int n, List<List<Integer>> adjList) {
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) ans.add(new ArrayList<>());
        for (int i = 0; i < n; i++) {
            for (int x : adjList.get(i)) {
                ans.get(x).add(i);
            }
        }
        return ans;
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

            invfact[n] = pow_with_mod(fact[n], p - 2, p);
            for (int i = n - 1; i >= 0; i--) {
                invfact[i] = (invfact[i + 1] * (i + 1)) % p;
            }
        }

        private long nCr(int n, int r) {
            if (r > n || n < 0 || r < 0) return 0;
            return (((fact[n] * invfact[r]) % p) * invfact[n - r]) % p;
        }
    }

    private static int random_between_two_numbers(int l, int r) {
        Random ran = new Random();
        return ran.nextInt(r - l) + l;
    }

    private static long gcd(long a, long b) {
        return (b == 0 ? a : gcd(b, a % b));
    }

    private static long lcm(long a, long b) {
        return ((a * b) / gcd(a, b));
    }

    private static long pow(long a, long b) {
        long result = 1;
        while (b > 0) {
            if ((b & 1L) == 1) {
                result = (result * a);
            }
            a = (a * a);
            b >>= 1;
        }

        return result;
    }

    private static long pow_with_mod(long a, long b, int mod) {
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

    private static int sumOfDigits(long num) {
        int cnt = 0;
        while (num > 0) {
            cnt += (num % 10);
            num /= 10;
        }
        return cnt;
    }

    private static int noOfDigits(long num) {
        int cnt = 0;
        while (num > 0) {
            cnt++;
            num /= 10;
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
