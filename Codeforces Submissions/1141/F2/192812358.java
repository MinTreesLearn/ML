
import java.io.*;
import java.util.*;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        Reader r = new Reader();
//        int t = r.nextInt();
//        while (t-- > 0) {
        solve(r);
//        }
        System.out.println(sb.deleteCharAt(sb.length() - 1));

    }


    private static void solve(Reader sc) {
        int n = sc.nextInt();
        int[] nums = new int[n + 1];
        int[] pre = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            nums[i] = sc.nextInt();
            pre[i] = pre[i - 1] + nums[i];
        }
        HashMap<Integer, ArrayList<int[]>> map = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int key = pre[j] - pre[i - 1];
                ArrayList<int[]> list = map.getOrDefault(key, new ArrayList<>());
                list.add(new int[]{i, j});
                map.put(key, list);
            }
        }
        int ans = 0;
        ArrayList<int[]>  maxQue = new ArrayList<>();
        for (ArrayList<int[]> que : map.values()) {
            ArrayList<int[]> cp = new ArrayList<>();
            que.sort((o1, o2) -> o2[1] == o1[1] ? o2[0] - o1[0] : o1[1] - o2[1]);
            cp.add(que.get(0));
            int c = 1;
            int preRight = que.get(0)[1];
            for (int i = 1; i < que.size(); i++) {
                if (preRight < que.get(i)[0]) {
                    c++;
                    preRight = que.get(i)[1];
                    cp.add(que.get(i));
                }
            }
            if (ans < c) {
                ans = c;
                maxQue = cp;
            }
        }
        println(ans);
        for (int[] item :maxQue) {
            printArr(item);
            println();
        }

    }

    static class BitIndexTree {
        long[] trie;
        int n;

        public BitIndexTree(int n) {
            this.n = n;
            trie = new long[n + 1];
        }

        public static int lowBit(int x) {
            return x & (-x);
        }

        public void add(int index, int v) {
            while (index <= n) {
                trie[index] += v;
                index += lowBit(index);
            }
        }

        public long query(int index) {
            long ans = 0;
            while (index > 0) {
                ans += trie[index];
                index -= lowBit(index);
            }
            return ans;
        }
    }

    private static void swap(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    public static long pow3(long a, long b) {
        long ans = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans *= a;
            }
            a *= a;
            b >>= 1;
        }
        return ans;
    }

    public static long pow4(long a, long b, int p) {
        long ans = 1;
        a %= p;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans = ans * a % p;
            }
            a = a * a % p;
            b >>= 1;
        }
        return ans;
    }

    public static List<Integer> euler(int n) {
        boolean[] check = new boolean[n + 1];
        List<Integer> ans = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (!check[i]) {
                ans.add(i);
            }
            for (Integer item : ans) {
                if (item * i > n) break;
                check[(item * i)] = true;
                if (i % item == 0) break;
            }
        }
        return ans;
    }

    public static void euler_phi(int n) {
        int ans = n;
        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                ans *= (1 - 1.0 / i);
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if (n > 1) ans *= (1 - 1.0 / n);
        System.out.println(ans);
    }

    public static int[] eulers(int n) {
        boolean[] check = new boolean[n + 1];
        int[] phi = new int[n + 1];
        phi[1] = 1;
        ArrayList<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (!check[i]) {
                primes.add(i);
                phi[i] = i - 1;
            }

            for (Integer item : primes) {
                if (item * i > n) break;
                check[item * i] = true;
                if (i % item == 0) {
                    phi[item * i] = item * phi[i];
                    break;
                }
                phi[item * i] = (item - 1) * phi[i];
            }
        }
        return phi;
    }


    static final Random random = new Random();

    static void ruffleSort(int[] a) {
        int n = a.length;//shuffle, then sort
        for (int i = 0; i < n; i++) {
            int oi = random.nextInt(n), temp = a[oi];
            a[oi] = a[i];
            a[i] = temp;
        }
        Arrays.sort(a);
    }

    static class Reader {
        BufferedReader buf;
        StringTokenizer tok;

        Reader() {
            buf = new BufferedReader(new InputStreamReader(System.in));
        }

        boolean hasNext() {
            while (tok == null || !tok.hasMoreElements()) {
                try {
                    tok = new StringTokenizer(buf.readLine());
                } catch (Exception e) {
                    return false;
                }
            }
            return true;
        }

        String nextLine() {
            try {
                return buf.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        String next() {
            if (hasNext()) return tok.nextToken();
            return null;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArrForSizeIndexOfOne(int size) {
            int[] nums = new int[size + 1];
            for (int i = 1; i <= size; i++) {
                nums[i] = nextInt();
            }
            return nums;
        }

        int[] nextIntArrForSizeIndexOfZero(int size) {
            int[] nums = new int[size];
            for (int i = 0; i < size; i++) {
                nums[i] = nextInt();
            }
            return nums;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    private static void printf(Object t) {
        sb.append(t).append(" ");
    }

    private static void println(Object t) {
        sb.append(t).append("\n");
    }

    private static void println() {
        sb.append("\n");
    }

    private static <T> void printArr(long[] arr) {
        for (Object o : arr) {
            sb.append(o).append(" ");
        }
    }

    private static <T> void printArr(int[] arr) {
        for (Object o : arr) {
            sb.append(o).append(" ");
        }
    }

}


