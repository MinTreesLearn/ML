
import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 *
 * @author eslam
 */
public class Solution {

    // Beginning of the solution
    static Kattio input = new Kattio();
    static BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
    static ArrayList<ArrayList<Integer>> powerSet = new ArrayList<>();
    static ArrayList<LinkedList<Integer>> allprem = new ArrayList<>();
    static ArrayList<LinkedList<String>> allprems = new ArrayList<>();
    static ArrayList<Long> luc = new ArrayList<>();
    static long mod = (long) (1e9 + 7);
    static int grid[][] = {{0, 0, 1, -1, 1, 1, -1, -1}, {1, -1, 0, 0, 1, -1, 1, -1}};
    static long dp[][];
    static double cmp = 1e-7;
    static final double pi = 3.14159265359;
    static int ans[];
    static boolean can;

    public static void main(String[] args) throws IOException {
//        Kattio input = new Kattio("input");
//        BufferedWriter log = new BufferedWriter(new FileWriter(f));
        int test = 1;//input.nextInt();
        loop:
        for (int co = 1; co <= test; co++) {
            int n = input.nextInt();
            char ch[] = input.next().toCharArray();
            pair a[] = new pair[n];
            for (int i = 0; i < n; i++) {
                a[i] = new pair(i, ch[i]);
            }
            ans = new int[n];
            can = true;
            ArrayList<Integer> graph[] = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                graph[i] = new ArrayList<>();
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - 1 - i; j++) {
                    if (a[j].y > a[j + 1].y) {
                        pair c = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = c;
                        graph[a[j].x].add(a[j + 1].x);
                        graph[a[j + 1].x].add(a[j].x);
                    }
                }
            }
            boolean vi[] = new boolean[n];
            for (int i = 0; i < n; i++) {
                if (!vi[i]) {
                    dfs(i, graph, vi, 1);
                }
            }
            if (!can) {
                log.write("NO\n");
            } else {
                log.write("YES\n");
                for (int an : ans) {
                    log.write(an + "");
                }
                log.write("\n");
            }
        }
        log.flush();
    }

    static void dfs(int node, ArrayList<Integer> graph[], boolean vi[], int cur) {
        vi[node] = true;
        ans[node] = cur;
        for (Integer x : graph[node]) {
            if (!vi[x]) {
                dfs(x, graph, vi, 1 - cur);
            } else if (ans[x] != 1 - cur) {
                can = false;
                return;
            }
        }
    }

    static class pair {

        int x;
        int y;

        public pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return x + " " + y;
        }
    }

    static class tri {

        int x, y;
        int z;

        public tri(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        @Override
        public String toString() {
            return x + " " + y + " " + z;
        }
    }

    public static pair[] dijkstra(int node, ArrayList<pair> a[]) {
        PriorityQueue<tri> q = new PriorityQueue<>(new Comparator<tri>() {
            @Override
            public int compare(tri o1, tri o2) {
                if (o1.y > o2.y) {
                    return 1;
                } else if (o1.y < o2.y) {
                    return -1;
                } else {
                    return 0;
                }
            }
        });
        q.add(new tri(node, 0, -1));
        pair distance[] = new pair[a.length];
        while (!q.isEmpty()) {
            tri p = q.poll();
            int cost = p.y;
            if (distance[p.x] != null) {
                continue;
            }
            distance[p.x] = new pair(p.z, cost);
            ArrayList<pair> nodes = a[p.x];
            for (pair node1 : nodes) {
                if (distance[node1.x] == null) {
                    tri pa = new tri(node1.x, cost + node1.y, p.x);
                    q.add(pa);
                }
            }
        }
        return distance;
    }

    public static boolean isSortedInc(int[] a, int l, int r) {
        for (int i = l; i <= r; i++) {
            if (a[i] > a[i + 1]) {
                return false;
            }
        }
        return true;
    }

    public static boolean isSortedDec(int[] a, int l, int r) {
        for (int i = l; i <= r; i++) {
            if (a[i] < a[i + 1]) {
                return false;
            }
        }
        return true;
    }

    static long f(long x) {
        return (long) ((x * (x + 1) / 2) % mod);
    }

    static long Sub(long x, long y) {
        long z = x - y;
        if (z < 0) {
            z += mod;
        }
        return z;
    }

    static long add(long a, long b) {
        a += b;
        if (a >= mod) {
            a -= mod;
        }
        return a;
    }

    static long mul(long a, long b) {
        return (long) ((long) a * b % mod);
    }

    static long powlog(long base, long power) {
        if (power == 0) {
            return 1;
        }
        long x = powlog(base, power / 2);
        x = mul(x, x);
        if ((power & 1) == 1) {
            x = mul(x, base);
        }
        return x;
    }

    static long modinv(long x) {
        return fast_pow(x, mod - 2, mod);
    }

    static long Div(long x, long y) {
        return mul(x, modinv(y));
    }

    static void floodFill(int r, int c, int a[][], boolean vi[][], int w[][], int d) {
        vi[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int nr = grid[0][i] + r;
            int nc = grid[1][i] + c;
            if (isValid(nr, nc, a.length, a[0].length)) {
                if (Math.abs(a[r][c] - a[nr][nc]) <= d && !vi[nr][nc]) {
                    floodFill(nr, nc, a, vi, w, d);
                }
            }
        }
    }

    static boolean isdigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    static boolean lochar(char ch) {
        return ch >= 'a' && ch <= 'z';
    }

    static boolean cachar(char ch) {
        return ch >= 'A' && ch <= 'Z';

    }

    static class Pa {

        long x;
        long y;

        public Pa(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    static long sqrt(long v) {
        long max = (long) 4e9;
        long min = 0;
        long ans = 0;
        while (max >= min) {
            long mid = (max + min) / 2;
            if (mid * mid > v) {
                max = mid - 1;
            } else {
                ans = mid;
                min = mid + 1;
            }
        }
        return ans;
    }

    static long cbrt(long v) {
        long max = (long) 3e6;
        long min = 0;
        long ans = 0;
        while (max >= min) {
            long mid = (max + min) / 2;
            if (mid * mid > v) {
                max = mid - 1;
            } else {
                ans = mid;
                min = mid + 1;
            }
        }
        return ans;
    }

    static void prefixSum2D(long arr[][]) {
        for (int i = 0; i < arr.length; i++) {
            prefixSum(arr[i]);
        }
        for (int i = 0; i < arr[0].length; i++) {
            for (int j = 1; j < arr.length; j++) {
                arr[j][i] += arr[j - 1][i];
            }
        }
    }

    public static long baseToDecimal(String w, long base) {
        long r = 0;
        long l = 0;
        for (int i = w.length() - 1; i > -1; i--) {
            long x = (w.charAt(i) - '0') * (long) Math.pow(base, l);
            r = r + x;
            l++;
        }
        return r;
    }

    static int bs(int v, ArrayList<Integer> a) {
        int max = a.size() - 1;
        int min = 0;
        int ans = 0;
        while (max >= min) {
            int mid = (max + min) / 2;
            if (a.get(mid) >= v) {
                ans = a.size() - mid;
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }
        return ans;
    }

    static Comparator<tri> cmpTri() {
        Comparator<tri> c = new Comparator<tri>() {
            @Override
            public int compare(tri o1, tri o2) {
                if (o1.x > o2.x) {
                    return 1;
                } else if (o1.x < o2.x) {
                    return -1;
                } else {
                    if (o1.y > o2.y) {
                        return 1;
                    } else if (o1.y < o2.y) {
                        return -1;
                    } else {
                        if (o1.z > o2.z) {
                            return 1;
                        } else if (o1.z < o2.z) {
                            return -1;
                        } else {
                            return 0;
                        }
                    }
                }
            }
        };
        return c;
    }

    static Comparator<pair> cmpPair2() {
        Comparator<pair> c = new Comparator<pair>() {
            @Override
            public int compare(pair o1, pair o2) {
                if (o1.y > o2.y) {
                    return 1;
                } else if (o1.y < o2.y) {
                    return -1;
                } else {
                    if (o1.x > o2.x) {
                        return -1;
                    } else if (o1.x < o2.x) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        };
        return c;

    }

    static Comparator<pair> cmpPair() {
        Comparator<pair> c = new Comparator<pair>() {
            @Override
            public int compare(pair o1, pair o2) {
                if (o1.x < o2.x) {
                    return -1;
                } else if (o1.x > o2.x) {
                    return 1;
                } else {
                    if (o1.y > o2.y) {
                        return 1;
                    } else if (o1.y < o2.y) {
                        return -1;
                    } else {
                        return 0;
                    }
                }
            }
        };
        return c;

    }

    static class rec {

        long x1;
        long x2;
        long y1;
        long y2;

        public rec(long x1, long y1, long x2, long y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }

        public long getArea() {
            return (x2 - x1) * (y2 - y1);
        }
    }

    static long sumOfRange(int x1, int y1, int x2, int y2, long a[][]) {
        return (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1]) + a[x1 - 1][y1 - 1];
    }

    public static int[][] bfs(int i, int j, String w[]) {
        Queue<pair> q = new ArrayDeque<>();
        q.add(new pair(i, j));
        int dis[][] = new int[w.length][w[0].length()];
        for (int k = 0; k < w.length; k++) {
            Arrays.fill(dis[k], -1);
        }
        dis[i][j] = 0;
        while (!q.isEmpty()) {
            pair p = q.poll();
            int cost = dis[p.x][p.y];
            for (int k = 0; k < 4; k++) {
                int nx = p.x + grid[0][k];
                int ny = p.y + grid[1][k];
                if (isValid(nx, ny, w.length, w[0].length())) {
                    if (dis[nx][ny] == -1 && w[nx].charAt(ny) == '.') {
                        q.add(new pair(nx, ny));
                        dis[nx][ny] = cost + 1;
                    }
                }
            }
        }
        return dis;
    }

    public static void graphRepresintion(ArrayList<Integer>[] a, int q) throws IOException {
        for (int i = 0; i < a.length; i++) {
            a[i] = new ArrayList<>();
        }
        while (q-- > 0) {
            int x = input.nextInt();
            int y = input.nextInt();
            a[x].add(y);
            a[y].add(x);
        }
    }

    public static boolean isValid(int i, int j, int n, int m) {
        return (i > -1 && i < n) && (j > -1 && j < m);
    }

    // present in the left and right indices
    public static int[] swap(int data[], int left, int right) {

        // Swap the data
        int temp = data[left];
        data[left] = data[right];
        data[right] = temp;

        // Return the updated array
        return data;
    }

    // Function to reverse the sub-array
    // starting from left to the right
    // both inclusive
    public static int[] reverse(int data[], int left, int right) {

        // Reverse the sub-array
        while (left < right) {
            int temp = data[left];
            data[left++] = data[right];
            data[right--] = temp;
        }

        // Return the updated array
        return data;
    }

    // Function to find the next permutation
    // of the given integer array
    public static boolean findNextPermutation(int data[]) {

        // If the given dataset is empty
        // or contains only one element
        // next_permutation is not possible
        if (data.length <= 1) {
            return false;
        }

        int last = data.length - 2;

        // find the longest non-increasing suffix
        // and find the pivot
        while (last >= 0) {
            if (data[last] < data[last + 1]) {
                break;
            }
            last--;
        }

        // If there is no increasing pair
        // there is no higher order permutation
        if (last < 0) {
            return false;
        }

        int nextGreater = data.length - 1;

        // Find the rightmost successor to the pivot
        for (int i = data.length - 1; i > last; i--) {
            if (data[i] > data[last]) {
                nextGreater = i;
                break;
            }
        }

        // Swap the successor and the pivot
        data = swap(data, nextGreater, last);

        // Reverse the suffix
        data = reverse(data, last + 1, data.length - 1);

        // Return true as the next_permutation is done
        return true;
    }

    public static String revs(String w) {
        String ans = "";
        for (int i = w.length() - 1; i > -1; i--) {
            ans += w.charAt(i);
        }
        return ans;
    }

    public static boolean isPalindrome(String w) {
        for (int i = 0; i < w.length() / 2; i++) {
            if (w.charAt(i) != w.charAt(w.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }

    public static void getPowerSet(Queue<Integer> a) {
        int n = a.poll();
        if (!a.isEmpty()) {
            getPowerSet(a);
        }
        int s = powerSet.size();
        for (int i = 0; i < s; i++) {
            ArrayList<Integer> ne = new ArrayList<>();
            ne.add(n);
            for (int j = 0; j < powerSet.get(i).size(); j++) {
                ne.add(powerSet.get(i).get(j));
            }

            powerSet.add(ne);
        }
        ArrayList<Integer> p = new ArrayList<>();
        p.add(n);
        powerSet.add(p);
    }

    public static int getlo(int va) {
        int v = 1;
        while (v <= va) {
            if ((va&v) != 0) {
                return v;
            }
            v <<= 1;
        }
        return 0;
    }

    static long fast_pow(long a, long p, long mod) {
        long res = 1;
        while (p > 0) {
            if (p % 2 == 0) {
                a = (a * a) % mod;
                p /= 2;
            } else {
                res = (res * a) % mod;
                p--;
            }
        }
        return res;
    }

    public static int countPrimeInRange(int n, boolean isPrime[]) {
        int cnt = 0;
        Arrays.fill(isPrime, true);
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * 2; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                cnt++;
            }
        }
        return cnt;
    }

    public static void create(long num) {
        luc.add(num);
        if (num > power(10, 9)) {
            return;
        }
        create(num * 10 + 4);
        create(num * 10 + 7);
    }

    public static long ceil(long a, long b) {
        return (a + b - 1) / b;
    }

    public static long round(long a, long b) {
        if (a < 0) {
            return (a - b / 2) / b;
        }
        return (a + b / 2) / b;
    }

    public static void allPremutationsst(LinkedList<String> l, boolean visited[], ArrayList<String> st) {
        if (l.size() == st.size()) {
            allprems.add(l);
        }
        for (int i = 0; i < st.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                LinkedList<String> nl = new LinkedList<>();
                for (String x : l) {
                    nl.add(x);
                }
                nl.add(st.get(i));
                allPremutationsst(nl, visited, st);
                visited[i] = false;
            }
        }
    }

    public static void allPremutations(LinkedList<Integer> l, boolean visited[], int a[]) {
        if (l.size() == a.length) {
            allprem.add(l);
        }
        for (int i = 0; i < a.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                LinkedList<Integer> nl = new LinkedList<>();
                for (Integer x : l) {
                    nl.add(x);
                }
                nl.add(a[i]);
                allPremutations(nl, visited, a);
                visited[i] = false;
            }
        }
    }

    public static int binarySearch(long[] a, long value) {
        int l = 0;
        int r = a.length - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] == value) {
                return m;
            } else if (a[m] > value) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }

    public static void reverse(int l, int r, char ch[]) {
        for (int i = 0; i < r / 2; i++) {
            char c = ch[i];
            ch[i] = ch[r - i - 1];
            ch[r - i - 1] = c;
        }
    }

    public static long logK(long v, long k) {
        int ans = 0;
        while (v > 1) {
            ans++;
            v /= k;
        }
        return ans;
    }

    public static long power(long a, long p) {
        long res = 1;
        while (p > 0) {
            if (p % 2 == 0) {
                a = (a * a);
                p /= 2;
            } else {
                res = (res * a);
                p--;
            }
        }
        return res;
    }

    public static long get(long max, long x) {
        if (x == 1) {
            return max;
        }
        int cnt = 0;
        while (max > 0) {
            cnt++;
            max /= x;
        }
        return cnt;
    }

    public static int numOF0(long v) {
        long x = 1;
        int cnt = 0;
        while (x <= v) {
            if ((x & v) == 0) {
                cnt++;
            }
            x <<= 1;
        }
        return cnt;
    }

    public static int log2(double n) {
        int cnt = 0;
        while (n > 1) {
            n /= 2;
            cnt++;
        }
        return cnt;
    }

    public static int[] bfs(int node, ArrayList<Integer> a[]) {
        Queue<Integer> q = new LinkedList<>();
        q.add(node);
        int distances[] = new int[a.length];
        Arrays.fill(distances, -1);
        distances[node] = 0;
        while (!q.isEmpty()) {
            int parent = q.poll();
            ArrayList<Integer> nodes = a[parent];
            int cost = distances[parent];
            for (Integer node1 : nodes) {
                if (distances[node1] == -1) {
                    q.add(node1);
                    distances[node1] = cost + 1;
                }
            }
        }
        return distances;
    }

    public static void primeFactors(int n, HashMap<Integer, ArrayList<Integer>> h, int ind) {
        boolean ca = true;
        while (n % 2 == 0) {
            if (ca) {
                if (h.get(2) == null) {
                    h.put(2, new ArrayList<>());
                }
                h.get(2).add(ind);
                ca = false;
            }
            n /= 2;
        }
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            ca = true;
            while (n % i == 0) {
                if (ca) {
                    if (h.get(i) == null) {
                        h.put(i, new ArrayList<>());
                    }
                    h.get(i).add(ind);
                    ca = false;
                }
                n /= i;
            }
            if (n < i) {
                break;
            }
        }
        if (n > 2) {
            if (h.get(n) == null) {
                h.put(n, new ArrayList<>());
            }
            h.get(n).add(ind);

        }

    }

// end of solution
    public static BigInteger ff(long n) {
        if (n <= 1) {
            return BigInteger.ONE;
        }
        long t = n - 1;
        BigInteger b = new BigInteger(t + "");
        BigInteger ans = new BigInteger(n + "");
        while (t > 1) {
            ans = ans.multiply(b);
            b = b.subtract(BigInteger.ONE);
            t--;
        }
        return ans;
    }

    public static long factorial(long n) {
        if (n <= 1) {
            return 1;
        }
        long t = n - 1;
        while (t > 1) {
            n = mod((mod(n, mod) * mod(t, mod)), mod);
            t--;
        }
        return n;
    }

    public static long rev(long n) {
        long t = n;
        long ans = 0;
        while (t > 0) {
            ans = ans * 10 + t % 10;
            t /= 10;
        }
        return ans;
    }

    public static boolean isPalindrome(int n) {
        int t = n;
        int ans = 0;
        while (t > 0) {
            ans = ans * 10 + t % 10;
            t /= 10;
        }
        return ans == n;

    }

    static boolean isPrime(long num) {
        if (num == 1) {
            return false;
        }
        if (num == 2) {
            return true;
        }
        if (num % 2 == 0) {
            return false;
        }
        if (num == 3) {
            return true;
        }
        for (long i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void prefixSum(long[] a) {
        for (int i = 1; i < a.length; i++) {
            a[i] = a[i] + a[i - 1];
        }
    }

    public static void suffixSum(long[] a) {
        for (int i = a.length - 2; i > -1; i--) {
            a[i] = a[i] + a[i + 1];
        }
    }

    static long mod(long a, long b) {
        long r = a % b;
        return r < 0 ? r + b : r;
    }

    public static long binaryToDecimal(String w) {
        long r = 0;
        long l = 0;
        for (int i = w.length() - 1; i > -1; i--) {
            long x = (w.charAt(i) - '0') * (long) Math.pow(2, l);
            r = r + x;
            l++;
        }
        return r;
    }

    public static String decimalAnyBase(long n, long base) {
        String w = "";
        while (n > 0) {
            w = n % base + w;
            n /= base;
        }
        return w;
    }

    public static String decimalToBinary(long n) {
        String w = "";
        while (n > 0) {
            w = n % 2 + w;
            n /= 2;
        }
        return w;
    }

    public static void print(int[] a) throws IOException {
        for (int i = 0; i < a.length; i++) {
            log.write(a[i] + " ");
        }
        log.write("\n");
    }

    public static void read(int[] a) {
        for (int i = 0; i < a.length; i++) {
            a[i] = input.nextInt();

        }
    }

    static class gepair {

        long x;
        long y;

        public gepair(long x, long y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return x + " " + y;
        }
    }

    static class pai {

        long x;
        int y;

        public pai(long x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return x + " " + y;
        }
    }

    public static long LCM(long x, long y) {
        return x / GCD(x, y) * y;
    }

    public static long GCD(long x, long y) {
        if (y == 0) {
            return x;
        }
        return GCD(y, x % y);
    }

    public static void simplifyTheFraction(int a, int b) {
        long GCD = GCD(a, b);
        System.out.println(a / GCD + " " + b / GCD);

    }

    static class Kattio extends PrintWriter {

        private BufferedReader r;
        private StringTokenizer st;
        // standard input

        public Kattio() {
            this(System.in, System.out);
        }

        public Kattio(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }
        // USACO-style file input

        public Kattio(String problemName) throws IOException {
            super(problemName + ".out");
            r = new BufferedReader(new FileReader(problemName));
        }
        // returns null if no more input

        String nextLine() {
            String str = "";
            try {
                str = r.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        public String next() {
            try {
                while (st == null || !st.hasMoreTokens()) {
                    st = new StringTokenizer(r.readLine());
                }
                return st.nextToken();
            } catch (Exception e) {
            }
            return null;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    static class RedBlackNode<T extends Comparable<T>> {

        /**
         * Possible color for this node
         */
        public static final int BLACK = 0;
        /**
         * Possible color for this node
         */
        public static final int RED = 1;
        // the key of each node
        public T key;

        /**
         * Parent of node
         */
        RedBlackNode<T> parent;
        /**
         * Left child
         */
        RedBlackNode<T> left;
        /**
         * Right child
         */
        RedBlackNode<T> right;
        // the number of elements to the left of each node
        public int numLeft = 0;
        // the number of elements to the right of each node
        public int numRight = 0;
        // the color of a node
        public int color;

        RedBlackNode() {
            color = BLACK;
            numLeft = 0;
            numRight = 0;
            parent = null;
            left = null;
            right = null;
        }

        // Constructor which sets key to the argument.
        RedBlackNode(T key) {
            this();
            this.key = key;
        }
    }// end class RedBlackNode

    static class RedBlackTree<T extends Comparable<T>> {

        // Root initialized to nil.
        private RedBlackNode<T> nil = new RedBlackNode<T>();
        private RedBlackNode<T> root = nil;

        public RedBlackTree() {
            root.left = nil;
            root.right = nil;
            root.parent = nil;
        }

        // @param: X, The node which the lefRotate is to be performed on.
        // Performs a leftRotate around X.
        private void leftRotate(RedBlackNode<T> x) {

            // Call leftRotateFixup() which updates the numLeft
            // and numRight values.
            leftRotateFixup(x);

            // Perform the left rotate as described in the algorithm
            // in the course text.
            RedBlackNode<T> y;
            y = x.right;
            x.right = y.left;

            // Check for existence of y.left and make pointer changes
            if (!isNil(y.left)) {
                y.left.parent = x;
            }
            y.parent = x.parent;

            // X's parent is nul
            if (isNil(x.parent)) {
                root = y;
            } // X is the left child of it's parent
            else if (x.parent.left == x) {
                x.parent.left = y;
            } // X is the right child of it's parent.
            else {
                x.parent.right = y;
            }

            // Finish of the leftRotate
            y.left = x;
            x.parent = y;
        }// end leftRotate(RedBlackNode X)

        // @param: X, The node which the leftRotate is to be performed on.
        // Updates the numLeft & numRight values affected by leftRotate.
        private void leftRotateFixup(RedBlackNode x) {

            // Case 1: Only X, X.right and X.right.right always are not nil.
            if (isNil(x.left) && isNil(x.right.left)) {
                x.numLeft = 0;
                x.numRight = 0;
                x.right.numLeft = 1;
            } // Case 2: X.right.left also exists in addition to Case 1
            else if (isNil(x.left) && !isNil(x.right.left)) {
                x.numLeft = 0;
                x.numRight = 1 + x.right.left.numLeft
                        + x.right.left.numRight;
                x.right.numLeft = 2 + x.right.left.numLeft
                        + x.right.left.numRight;
            } // Case 3: X.left also exists in addition to Case 1
            else if (!isNil(x.left) && isNil(x.right.left)) {
                x.numRight = 0;
                x.right.numLeft = 2 + x.left.numLeft + x.left.numRight;

            } // Case 4: X.left and X.right.left both exist in addtion to Case 1
            else {
                x.numRight = 1 + x.right.left.numLeft
                        + x.right.left.numRight;
                x.right.numLeft = 3 + x.left.numLeft + x.left.numRight
                        + x.right.left.numLeft + x.right.left.numRight;
            }

        }// end leftRotateFixup(RedBlackNode X)

        // @param: X, The node which the rightRotate is to be performed on.
        // Updates the numLeft and numRight values affected by the Rotate.
        private void rightRotate(RedBlackNode<T> y) {

            // Call rightRotateFixup to adjust numRight and numLeft values
            rightRotateFixup(y);

            // Perform the rotate as described in the course text.
            RedBlackNode<T> x = y.left;
            y.left = x.right;

            // Check for existence of X.right
            if (!isNil(x.right)) {
                x.right.parent = y;
            }
            x.parent = y.parent;

            // y.parent is nil
            if (isNil(y.parent)) {
                root = x;
            } // y is a right child of it's parent.
            else if (y.parent.right == y) {
                y.parent.right = x;
            } // y is a left child of it's parent.
            else {
                y.parent.left = x;
            }
            x.right = y;

            y.parent = x;

        }// end rightRotate(RedBlackNode y)

        // @param: y, the node around which the righRotate is to be performed.
        // Updates the numLeft and numRight values affected by the rotate
        private void rightRotateFixup(RedBlackNode y) {

            // Case 1: Only y, y.left and y.left.left exists.
            if (isNil(y.right) && isNil(y.left.right)) {
                y.numRight = 0;
                y.numLeft = 0;
                y.left.numRight = 1;
            } // Case 2: y.left.right also exists in addition to Case 1
            else if (isNil(y.right) && !isNil(y.left.right)) {
                y.numRight = 0;
                y.numLeft = 1 + y.left.right.numRight
                        + y.left.right.numLeft;
                y.left.numRight = 2 + y.left.right.numRight
                        + y.left.right.numLeft;
            } // Case 3: y.right also exists in addition to Case 1
            else if (!isNil(y.right) && isNil(y.left.right)) {
                y.numLeft = 0;
                y.left.numRight = 2 + y.right.numRight + y.right.numLeft;

            } // Case 4: y.right & y.left.right exist in addition to Case 1
            else {
                y.numLeft = 1 + y.left.right.numRight
                        + y.left.right.numLeft;
                y.left.numRight = 3 + y.right.numRight
                        + y.right.numLeft
                        + y.left.right.numRight + y.left.right.numLeft;
            }

        }// end rightRotateFixup(RedBlackNode y)

        public void insert(T key) {
            insert(new RedBlackNode<T>(key));
        }

        // @param: z, the node to be inserted into the Tree rooted at root
        // Inserts z into the appropriate position in the RedBlackTree while
        // updating numLeft and numRight values.
        private void insert(RedBlackNode<T> z) {

            // Create a reference to root & initialize a node to nil
            RedBlackNode<T> y = nil;
            RedBlackNode<T> x = root;

            // While we haven't reached a the end of the tree keep
            // tryint to figure out where z should go
            while (!isNil(x)) {
                y = x;

                // if z.key is < than the current key, go left
                if (z.key.compareTo(x.key) < 0) {

                    // Update X.numLeft as z is < than X
                    x.numLeft++;
                    x = x.left;
                } // else z.key >= X.key so go right.
                else {

                    // Update X.numGreater as z is => X
                    x.numRight++;
                    x = x.right;
                }
            }
            // y will hold z's parent
            z.parent = y;

            // Depending on the value of y.key, put z as the left or
            // right child of y
            if (isNil(y)) {
                root = z;
            } else if (z.key.compareTo(y.key) < 0) {
                y.left = z;
            } else {
                y.right = z;
            }

            // Initialize z's children to nil and z's color to red
            z.left = nil;
            z.right = nil;
            z.color = RedBlackNode.RED;

            // Call insertFixup(z)
            insertFixup(z);

        }// end insert(RedBlackNode z)

        // @param: z, the node which was inserted and may have caused a violation
        // of the RedBlackTree properties
        // Fixes up the violation of the RedBlackTree properties that may have
        // been caused during insert(z)
        private void insertFixup(RedBlackNode<T> z) {

            RedBlackNode<T> y = nil;
            // While there is a violation of the RedBlackTree properties..
            while (z.parent.color == RedBlackNode.RED) {

                // If z's parent is the the left child of it's parent.
                if (z.parent == z.parent.parent.left) {

                    // Initialize y to z 's cousin
                    y = z.parent.parent.right;

                    // Case 1: if y is red...recolor
                    if (y.color == RedBlackNode.RED) {
                        z.parent.color = RedBlackNode.BLACK;
                        y.color = RedBlackNode.BLACK;
                        z.parent.parent.color = RedBlackNode.RED;
                        z = z.parent.parent;
                    } // Case 2: if y is black & z is a right child
                    else if (z == z.parent.right) {

                        // leftRotaet around z's parent
                        z = z.parent;
                        leftRotate(z);
                    } // Case 3: else y is black & z is a left child
                    else {
                        // recolor and rotate round z's grandpa
                        z.parent.color = RedBlackNode.BLACK;
                        z.parent.parent.color = RedBlackNode.RED;
                        rightRotate(z.parent.parent);
                    }
                } // If z's parent is the right child of it's parent.
                else {

                    // Initialize y to z's cousin
                    y = z.parent.parent.left;

                    // Case 1: if y is red...recolor
                    if (y.color == RedBlackNode.RED) {
                        z.parent.color = RedBlackNode.BLACK;
                        y.color = RedBlackNode.BLACK;
                        z.parent.parent.color = RedBlackNode.RED;
                        z = z.parent.parent;
                    } // Case 2: if y is black and z is a left child
                    else if (z == z.parent.left) {
                        // rightRotate around z's parent
                        z = z.parent;
                        rightRotate(z);
                    } // Case 3: if y  is black and z is a right child
                    else {
                        // recolor and rotate around z's grandpa
                        z.parent.color = RedBlackNode.BLACK;
                        z.parent.parent.color = RedBlackNode.RED;
                        leftRotate(z.parent.parent);
                    }
                }
            }
            // Color root black at all times
            root.color = RedBlackNode.BLACK;

        }// end insertFixup(RedBlackNode z)

        // @param: node, a RedBlackNode
        // @param: node, the node with the smallest key rooted at node
        public RedBlackNode<T> treeMinimum(RedBlackNode<T> node) {

            // while there is a smaller key, keep going left
            while (!isNil(node.left)) {
                node = node.left;
            }
            return node;
        }// end treeMinimum(RedBlackNode node)

        // @param: X, a RedBlackNode whose successor we must find
        // @return: return's the node the with the next largest key
        // from X.key
        public RedBlackNode<T> treeSuccessor(RedBlackNode<T> x) {

            // if X.left is not nil, call treeMinimum(X.right) and
            // return it's value
            if (!isNil(x.left)) {
                return treeMinimum(x.right);
            }

            RedBlackNode<T> y = x.parent;

            // while X is it's parent's right child...
            while (!isNil(y) && x == y.right) {
                // Keep moving up in the tree
                x = y;
                y = y.parent;
            }
            // Return successor
            return y;
        }// end treeMinimum(RedBlackNode X)

        // @param: z, the RedBlackNode which is to be removed from the the tree
        // Remove's z from the RedBlackTree rooted at root
        public void remove(RedBlackNode<T> v) {

            RedBlackNode<T> z = search(v.key);

            // Declare variables
            RedBlackNode<T> x = nil;
            RedBlackNode<T> y = nil;

            // if either one of z's children is nil, then we must remove z
            if (isNil(z.left) || isNil(z.right)) {
                y = z;
            } // else we must remove the successor of z
            else {
                y = treeSuccessor(z);
            }

            // Let X be the left or right child of y (y can only have one child)
            if (!isNil(y.left)) {
                x = y.left;
            } else {
                x = y.right;
            }

            // link X's parent to y's parent
            x.parent = y.parent;

            // If y's parent is nil, then X is the root
            if (isNil(y.parent)) {
                root = x;
            } // else if y is a left child, set X to be y's left sibling
            else if (!isNil(y.parent.left) && y.parent.left == y) {
                y.parent.left = x;
            } // else if y is a right child, set X to be y's right sibling
            else if (!isNil(y.parent.right) && y.parent.right == y) {
                y.parent.right = x;
            }

            // if y != z, trasfer y's satellite data into z.
            if (y != z) {
                z.key = y.key;
            }

            // Update the numLeft and numRight numbers which might need
            // updating due to the deletion of z.key.
            fixNodeData(x, y);

            // If y's color is black, it is a violation of the
            // RedBlackTree properties so call removeFixup()
            if (y.color == RedBlackNode.BLACK) {
                removeFixup(x);
            }
        }// end remove(RedBlackNode z)

        // @param: y, the RedBlackNode which was actually deleted from the tree
        // @param: key, the value of the key that used to be in y
        private void fixNodeData(RedBlackNode<T> x, RedBlackNode<T> y) {

            // Initialize two variables which will help us traverse the tree
            RedBlackNode<T> current = nil;
            RedBlackNode<T> track = nil;

            // if X is nil, then we will start updating at y.parent
            // Set track to y, y.parent's child
            if (isNil(x)) {
                current = y.parent;
                track = y;
            } // if X is not nil, then we start updating at X.parent
            // Set track to X, X.parent's child
            else {
                current = x.parent;
                track = x;
            }

            // while we haven't reached the root
            while (!isNil(current)) {
                // if the node we deleted has a different key than
                // the current node
                if (y.key != current.key) {

                    // if the node we deleted is greater than
                    // current.key then decrement current.numRight
                    if (y.key.compareTo(current.key) > 0) {
                        current.numRight--;
                    }

                    // if the node we deleted is less than
                    // current.key thendecrement current.numLeft
                    if (y.key.compareTo(current.key) < 0) {
                        current.numLeft--;
                    }
                } // if the node we deleted has the same key as the
                // current node we are checking
                else {
                    // the cases where the current node has any nil
                    // children and update appropriately
                    if (isNil(current.left)) {
                        current.numLeft--;
                    } else if (isNil(current.right)) {
                        current.numRight--;
                    } // the cases where current has two children and
                    // we must determine whether track is it's left
                    // or right child and update appropriately
                    else if (track == current.right) {
                        current.numRight--;
                    } else if (track == current.left) {
                        current.numLeft--;
                    }
                }

                // update track and current
                track = current;
                current = current.parent;

            }

        }//end fixNodeData()

        // @param: X, the child of the deleted node from remove(RedBlackNode v)
        // Restores the Red Black properties that may have been violated during
        // the removal of a node in remove(RedBlackNode v)
        private void removeFixup(RedBlackNode<T> x) {

            RedBlackNode<T> w;

            // While we haven't fixed the tree completely...
            while (x != root && x.color == RedBlackNode.BLACK) {

                // if X is it's parent's left child
                if (x == x.parent.left) {

                    // set w = X's sibling
                    w = x.parent.right;

                    // Case 1, w's color is red.
                    if (w.color == RedBlackNode.RED) {
                        w.color = RedBlackNode.BLACK;
                        x.parent.color = RedBlackNode.RED;
                        leftRotate(x.parent);
                        w = x.parent.right;
                    }

                    // Case 2, both of w's children are black
                    if (w.left.color == RedBlackNode.BLACK
                            && w.right.color == RedBlackNode.BLACK) {
                        w.color = RedBlackNode.RED;
                        x = x.parent;
                    } // Case 3 / Case 4
                    else {
                        // Case 3, w's right child is black
                        if (w.right.color == RedBlackNode.BLACK) {
                            w.left.color = RedBlackNode.BLACK;
                            w.color = RedBlackNode.RED;
                            rightRotate(w);
                            w = x.parent.right;
                        }
                        // Case 4, w = black, w.right = red
                        w.color = x.parent.color;
                        x.parent.color = RedBlackNode.BLACK;
                        w.right.color = RedBlackNode.BLACK;
                        leftRotate(x.parent);
                        x = root;
                    }
                } // if X is it's parent's right child
                else {

                    // set w to X's sibling
                    w = x.parent.left;

                    // Case 1, w's color is red
                    if (w.color == RedBlackNode.RED) {
                        w.color = RedBlackNode.BLACK;
                        x.parent.color = RedBlackNode.RED;
                        rightRotate(x.parent);
                        w = x.parent.left;
                    }

                    // Case 2, both of w's children are black
                    if (w.right.color == RedBlackNode.BLACK
                            && w.left.color == RedBlackNode.BLACK) {
                        w.color = RedBlackNode.RED;
                        x = x.parent;
                    } // Case 3 / Case 4
                    else {
                        // Case 3, w's left child is black
                        if (w.left.color == RedBlackNode.BLACK) {
                            w.right.color = RedBlackNode.BLACK;
                            w.color = RedBlackNode.RED;
                            leftRotate(w);
                            w = x.parent.left;
                        }

                        // Case 4, w = black, and w.left = red
                        w.color = x.parent.color;
                        x.parent.color = RedBlackNode.BLACK;
                        w.left.color = RedBlackNode.BLACK;
                        rightRotate(x.parent);
                        x = root;
                    }
                }
            }// end while

            // set X to black to ensure there is no violation of
            // RedBlack tree Properties
            x.color = RedBlackNode.BLACK;
        }// end removeFixup(RedBlackNode X)

        // @param: key, the key whose node we want to search for
        // @return: returns a node with the key, key, if not found, returns null
        // Searches for a node with key k and returns the first such node, if no
        // such node is found returns null
        public RedBlackNode<T> search(T key) {

            // Initialize a pointer to the root to traverse the tree
            RedBlackNode<T> current = root;

            // While we haven't reached the end of the tree
            while (!isNil(current)) {

                // If we have found a node with a key equal to key
                if (current.key.equals(key)) // return that node and exit search(int)
                {
                    return current;
                } // go left or right based on value of current and key
                else if (current.key.compareTo(key) < 0) {
                    current = current.right;
                } // go left or right based on value of current and key
                else {
                    current = current.left;
                }
            }

            // we have not found a node whose key is "key"
            return null;

        }// end search(int key)

        // @param: key, any Comparable object
        // @return: return's the number of elements greater than key
        public int numGreater(T key) {

            // Call findNumGreater(root, key) which will return the number
            // of nodes whose key is greater than key
            return findNumGreater(root, key);

        }// end numGreater(int key)

        // @param: key, any Comparable object
        // @return: return's teh number of elements smaller than key
        public int numSmaller(T key) {

            // Call findNumSmaller(root,key) which will return
            // the number of nodes whose key is greater than key
            return findNumSmaller(root, key);

        }// end numSmaller(int key)

        // @param: node, the root of the tree, the key who we must
        // compare other node key's to.
        // @return: the number of nodes greater than key.
        public int findNumGreater(RedBlackNode<T> node, T key) {

            // Base Case: if node is nil, return 0
            if (isNil(node)) {
                return 0;
            } // If key is less than node.key, all elements right of node are
            // greater than key, add this to our total and look to the left
            else if (key.compareTo(node.key) < 0) {
                return 1 + node.numRight + findNumGreater(node.left, key);
            } // If key is greater than node.key, then look to the right as
            // all elements to the left of node are smaller than key
            else {
                return findNumGreater(node.right, key);
            }

        }// end findNumGreater(RedBlackNode, int key)

        /**
         * Returns sorted list of keys greater than key. Size of list will not
         * exceed maxReturned
         *
         * @param key Key to search for
         * @param maxReturned Maximum number of results to return
         * @return List of keys greater than key. List may not exceed
         * maxReturned
         */
        public List<T> getGreaterThan(T key, Integer maxReturned) {
            List<T> list = new ArrayList<T>();
            getGreaterThan(root, key, list);
            return list.subList(0, Math.min(maxReturned, list.size()));
        }

        private void getGreaterThan(RedBlackNode<T> node, T key,
                List<T> list) {
            if (isNil(node)) {
                return;
            } else if (node.key.compareTo(key) > 0) {
                getGreaterThan(node.left, key, list);
                list.add(node.key);
                getGreaterThan(node.right, key, list);
            } else {
                getGreaterThan(node.right, key, list);
            }
        }

        // @param: node, the root of the tree, the key who we must compare other
        // node key's to.
        // @return: the number of nodes smaller than key.
        public int findNumSmaller(RedBlackNode<T> node, T key) {

            // Base Case: if node is nil, return 0
            if (isNil(node)) {
                return 0;
            } // If key is less than node.key, look to the left as all
            // elements on the right of node are greater than key
            else if (key.compareTo(node.key) <= 0) {
                return findNumSmaller(node.left, key);
            } // If key is larger than node.key, all elements to the left of
            // node are smaller than key, add this to our total and look
            // to the right.
            else {
                return 1 + node.numLeft + findNumSmaller(node.right, key);
            }

        }// end findNumSmaller(RedBlackNode nod, int key)

        // @param: node, the RedBlackNode we must check to see whether it's nil
        // @return: return's true of node is nil and false otherwise
        private boolean isNil(RedBlackNode node) {

            // return appropriate value
            return node == nil;

        }// end isNil(RedBlackNode node)

        // @return: return's the size of the tree
        // Return's the # of nodes including the root which the RedBlackTree
        // rooted at root has.
        public int size() {
            // Return the number of nodes to the root's left + the number of
            // nodes on the root's right + the root itself.
            return root.numLeft + root.numRight + 1;
        }// end size()

    }// end class RedBlackTree
}
