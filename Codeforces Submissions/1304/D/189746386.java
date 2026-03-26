import java.util.*;
import java.io.*;

public class Main {
    static int[] parent, size;

    public static void main(String[] args) throws IOException {
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            char[] temp = sc.next().toCharArray();
            int[] arr = new int[n];
            Arrays.fill(arr, 1);
            if (temp[0] == '<')
                arr[0] = -1;
            if (temp[n - 2] == '>')
                arr[n - 1] = -1;
            for (int i = 1; i < temp.length; i++) {
                if (temp[i - 1] == '>')
                    arr[i] = -1;

            }
            int[] p = new int[n];
            for (int i = 0; i < p.length; i++) {
                p[i] = i + 1;
            }
            int ones = 0;
            for (int i = 0; i < arr.length; i++) {
                if (arr[i] != 1)
                    ones++;
            }
            int[] max = new int[n];
            int l = 0;
            int r = ones;
            for (int i = 0; i < arr.length;) {
                int count = get(arr, i);
                int last = i + count;
                if (arr[i] < 0) {
                    for (int j = last; j >= i; j--) {
                        max[j] = p[l++];
                    }
                } else {
                    for (int j = i; j <= last; j++) {
                        max[j] = p[r++];
                    }
                }
                i += count + 1;
            }
            int[] min = new int[n];
            ones = 0;
            for (int i = 0; i < arr.length; i++) {
                if (arr[i] != -1)
                    ones++;
            }
            l = n - ones - 1;
            r = n - 1;
            for (int i = 0; i < arr.length;) {
                int count = get(arr, i);
                int last = i + count;
                if (arr[i] < 0) {
                    for (int j = i; j <= last; j++) {
                        min[j] = p[l--];
                    }
                } else {
                    for (int j = last; j >= i; j--) {
                        min[j] = p[r--];
                    }
                }
                i += count + 1;
            }
            print(min);
            print(max);

        }
        pw.close();
    }

    static int get(int[] arr, int idx) {
        int res = 0;
        for (int i = idx + 1; i < arr.length; i++) {
            if (arr[i] == arr[i - 1])
                res++;
            else
                break;
        }
        return res;
    }

    static ArrayList<Integer> getDivisors(ArrayList<Pair> list) {
        ArrayList<Integer> res = new ArrayList<>();
        res.add(1);
        for (Pair p : list) {
            int num = (int) p.x;
            int count = (int) p.y;
            int size = res.size();
            int mul = num;
            while (count > 0) {
                for (int i = 0; i < size; i++) {
                    res.add(mul * res.get(i));
                }
                count--;
                mul *= num;
            }
        }
        return res;
    }

    static ArrayList<Pair> getPrimeFactors(int[] arr, int num) {
        ArrayList<Pair> list = new ArrayList<>();
        while (num > 1) {
            if (list.isEmpty() || list.get(list.size() - 1).x != arr[num])
                list.add(new Pair(arr[num], 0));
            list.get(list.size() - 1).y++;
            num /= arr[num];
        }
        return list;
    }

    static void DSU(int n) {
        parent = new int[n + 1];
        size = new int[n + 1];
        for (int i = 1; i < parent.length; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    static int find(int a) {
        if (a == parent[a])
            return a;
        return parent[a] = find(parent[a]);
    }

    static void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        } else {
            parent[b] = a;
            size[a] += size[b];
        }
    }

    static long[] HashStr(char[] arr) {
        long[] hash = new long[arr.length];
        int p = 31;
        int m = 1000000007;
        long hashValue = 0;
        long power = 1;
        for (int i = 0; i < arr.length; i++) {
            hashValue = (hashValue + (arr[i] - 'a' + 1) * power) % m;
            power = (power * p) % m;
            hash[i] = hashValue;
        }
        return hash;
    }

    static long compute_hash(char[] s) {
        long p = 31;
        long m = 1000000007;
        long hash_value = 0;
        long p_pow = 1;
        for (char c : s) {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_value;
    }

    static int toInt(boolean flag) {
        return flag ? 1 : 0;
    }

    static int log2(int n) {
        return (int) (Math.log(n) / Math.log(2));
    }

    static int[] sieve() {
        int n = (int) 2e5 + 55;
        int[] arr = new int[n];
        for (int i = 2; i < arr.length; i++) {
            for (int j = i; j < arr.length; j += i) {
                if (arr[j] == 0)
                    arr[j] = i;
            }
        }
        return arr;
    }

    static void shuffle(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            int r = i + (int) (Math.random() * (n - i));
            int tmp = arr[i];
            arr[i] = arr[r];
            arr[r] = tmp;
        }
    }

    static void sort(int[] arr) {
        shuffle(arr);
        Arrays.sort(arr);
    }

    static long getSum(int[] arr) {
        long sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        return sum;
    }

    static int getMin(int[] arr) {
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length; i++) {
            min = Math.min(min, arr[i]);
        }
        return min;
    }

    static int getMax(int[] arr) {
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            max = Math.max(max, arr[i]);
        }
        return max;
    }

    static boolean isEqual(int[] a, int[] b) {
        if (a.length != b.length)
            return false;
        for (int i = 0; i < b.length; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

    static void reverse(int[] arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    static void swap(char[] arr, int a, int b) {
        char temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    static void swap(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    static boolean isSorted(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    static long gcd(long x, long y) {
        if (x == 0)
            return y;
        return gcd(y % x, x);
    }

    static long lcm(long a, long b) {
        return (1l * a * b) / gcd(a, b);
    }

    static ArrayList<Integer>[] Graph(int n) {
        ArrayList<Integer>[] graph = new ArrayList[n + 1];
        for (int i = 1; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        return graph;
    }

    static HashMap<Integer, Integer> getFrequency(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i : arr) {
            map.put(i, map.getOrDefault(i, 0) + 1);

        }
        return map;
    }

    static HashMap<Character, Integer> Hash(char[] arr) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (char i : arr) {
            map.put(i, map.getOrDefault(i, 0) + 1);

        }
        return map;
    }

    static boolean isPrime(int n) {
        if (n <= 1)
            return false;

        for (int i = 2; i <= Math.sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }

    public static long combination(long n, long r) {
        return factorial(n) / (factorial(n - r) * factorial(r));
    }

    static long factorial(Long n) {
        if (n == 0)
            return 1;
        return (n % mod) * (factorial(n - 1) % mod) % mod;
    }

    static boolean isPalindrome(char[] str, int i, int j) {
        while (i < j) {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    public static int setBit(int mask, int idx) {
        return mask | (1 << idx);
    }

    public static boolean checkBit(int mask, int idx) {
        return (mask & (1 << idx)) != 0;
    }

    public static long setBit(long mask, int idx) {
        return mask | (1l << idx);
    }

    public static boolean checkBit(long mask, int idx) {
        return (mask & (1l << idx)) != 0;
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

        public int[] nextIntCharArray() throws IOException {
            char[] b = sc.next().toCharArray();
            int n = b.length;
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = b[i] - '0';
            return a;
        }

        public int[] NextIntArray(int n) throws IOException {
            int[] arr = new int[n + 1];
            for (int i = 1; i < arr.length; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        public Integer[] nextIntegerArray(int n) throws IOException {
            Integer[] a = new Integer[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public ArrayList<Integer>[] directedGraph(int n, int m) throws IOException {
            ArrayList<Integer>[] graph = new ArrayList[n + 1];
            for (int i = 0; i < graph.length; i++) {
                graph[i] = new ArrayList<>();
            }
            while (m-- > 0) {
                int a = nextInt();
                int b = nextInt();
                graph[a].add(b);
            }
            return graph;
        }

        public ArrayList<Integer>[] undirectedGraph(int n, int m) throws IOException {
            ArrayList<Integer>[] graph = new ArrayList[n + 1];
            for (int i = 0; i < graph.length; i++) {
                graph[i] = new ArrayList<>();
            }
            while (m-- > 0) {
                int a = nextInt();
                int b = nextInt();
                graph[a].add(b);
                graph[b].add(a);
            }
            return graph;
        }

        public boolean ready() throws IOException {
            return br.ready();
        }

    }

    static class Pair implements Comparable<Pair> {
        long x;
        long y;

        public Pair(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return x + " " + y;
        }

        public boolean equals(Object o) {
            if (o instanceof Pair) {
                Pair p = (Pair) o;
                return p.x == x && p.y == y;
            }
            return false;
        }

        public int hashCode() {
            return new Long(x).hashCode() * 31 + new Long(y).hashCode();
        }

        public int compareTo(Pair other) {
            if (this.x == other.x) {
                return Long.compare(this.y, other.y);
            }
            return Long.compare(this.x, other.x);
        }
    }

    public static void print(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            pw.print(arr[i] + " ");
        }
        pw.println();
    }

    public static void print(int[] arr, String separator) {
        for (int i = 0; i < arr.length; i++) {
            pw.print(arr[i] + separator);
        }
        pw.println();

    }

    public static void print(long[] arr) {
        for (int i = 0; i < arr.length; i++) {
            pw.print(arr[i] + " ");
        }
        pw.println();
    }

    public static void print(ArrayList arr) {
        for (int i = 0; i < arr.size(); i++) {
            pw.print(arr.get(i) + " ");
        }
        pw.println();
    }

    public static void print(int[][] arr) {
        for (int[] i : arr) {
            print(i);
        }
    }

    public static void print(boolean[] arr) {
        for (int i = 0; i < arr.length; i++) {
            pw.print(arr[i] + " ");
        }
        pw.println();
    }

    public static void print(char[] arr) {
        for (int i = 0; i < arr.length; i++) {
            pw.print(arr[i] + " ");
        }
        pw.println();
    }

    static int inf = 1000000000;
    static long mod = 1000000007;
    static Random rn = new Random();
    static Scanner sc = new Scanner(System.in);
    static PrintWriter pw = new PrintWriter(System.out);

}