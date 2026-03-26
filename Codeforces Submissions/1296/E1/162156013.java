// package CP;

import java.util.*;
import java.io.*;
import java.lang.*;

public class contest {
    static long primeMod = 999999999999989L;

    static class pair {
        int x, y, p, q;

        pair(int x, int y, int p, int q) {
            this.x = x;
            this.y = y;
            this.p = p;
            this.q = q;
        }

        pair(int x, int y, int p) {
            this.x = x;
            this.y = y;
            this.p = p;
        }

        pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public boolean equals(Object o) {
            if (o instanceof pair) {
                pair p = (pair) o;
                return x == p.x && y == p.y;
            }
            return false;
        }

        public int hashCode() {
            return (Long.valueOf(x).hashCode()) * 31 + (Long.valueOf(y).hashCode());
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void swap(int arr[], int x, int y) {
        int t = arr[x];
        arr[x] = arr[y];
        arr[y] = t;
    }

    static int LongestIncreasingSubsequenceLength(int A[], int size) {

        int[] tailTable = new int[size];
        int len;

        tailTable[0] = A[0];
        len = 1;
        for (int i = 1; i < size; i++) {
            if (A[i] < tailTable[0])
                tailTable[0] = A[i];

            else if (A[i] > tailTable[len - 1])
                tailTable[len++] = A[i];

            else
                tailTable[CeilIndex(tailTable, -1, len - 1, A[i])] = A[i];
        }

        return len;
    }

    static int CeilIndex(int A[], int l, int r, int key) {
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (A[m] >= key)
                r = m;
            else
                l = m;
        }

        return r;
    }

    public static int gcd(int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    public static long sum(long n) {

        return (n * (n + 1)) / 2;
    }

    static int N = 1000000;
    static boolean primeSeiveDp[] = new boolean[N];

    public static void primeSeive() {
        primeSeiveDp[0] = true;
        primeSeiveDp[1] = true;
        for (int i = 2; i * i < N; i += 2) {
            if (primeSeiveDp[i] == false) {
                for (int j = i * i; j < N; j += i) {
                    primeSeiveDp[j] = true;
                }
            }
        }

    }

    public static ArrayList<Integer> primeLessThan(int m) {
        ArrayList<Integer> primes = new ArrayList<Integer>();
        for (int i = 2; i * i <= m; i++) {
            if (primeSeiveDp[i] == false) {
                primes.add(i);
            }
        }
        return primes;
    }

    public static ArrayList<Integer> primesList(int n, int m) {
        primeSeive();
        ArrayList<Integer> primes = primeLessThan(m);
        boolean primeSeiveRange[] = new boolean[m - n + 1];

        for (int pr : primes) {
            int nextMultiple = (n / pr) * pr;
            if (nextMultiple < n) {
                nextMultiple += pr;
            }
            for (int i = Math.max(nextMultiple, pr * pr); i <= m; i += pr) {
                primeSeiveRange[i - n] = true;
            }
        }
        ArrayList<Integer> primesRange = new ArrayList<Integer>();
        for (int i = n; i <= m; i++) {
            if (primeSeiveRange[i - n] == false && i != 1) {
                primesRange.add(i);
            }
        }
        return primesRange;
    }

    public static HashMap<Integer, ArrayList<Integer>> findDivisors() {
        HashMap<Integer, ArrayList<Integer>> divisors = new HashMap<>();
        for (int i = 2; i < 100000; i++) {
            for (int j = i; j < 100000; j += i) {
                ArrayList<Integer> list = divisors.getOrDefault(j, new ArrayList<Integer>());
                list.add(i);
                divisors.put(j, list);
            }
        }
        return divisors;
    }

    public static int[] findprimeFact() {
        int seivepf[] = new int[10000000];
        for (int i = 0; i < 10000000; i++) {
            seivepf[i] = i;
        }
        for (int i = 2; i * i < 10000000; i++) {
            if (seivepf[i] == i) {
                for (int j = i * i; j < 10000000; j += i) {
                    if (seivepf[j] == j)
                        seivepf[j] = i;
                }
            }
        }
        return seivepf;
    }

    public static ArrayList<Integer> primeFactors(int n) {
        int spf[] = findprimeFact();
        ArrayList<Integer> primeFactors = new ArrayList<Integer>();
        while (n != 1) {
            primeFactors.add(spf[n]);
            n = n / spf[n];
        }
        return primeFactors;
    }

    public static long moduloMulInv(long n, long m) {
        // m is modulo
        // n and must be co-prime
        // n<m
        return binaryExpo(n, m - 2, m);
    }

    public static long binaryExpo(long a, long b, long m) {
        long result = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                // odd
                result = (result * 1L * a) % m;
            }
            // multiply to base
            a = (a * 1L * a) % m;
            b >>= 1;
        }
        return result;
    }

    public static long setBit(long a, long i) {
        // i starts from 0
        return a | (1 << i);
    }

    public static long unSetBit(long a, long i) {
        // i starts from 0
        return a & (~(1 << i));
    }

    public static long toggleBit(long a, long i) {
        // i starts from 0
        return a ^ (1 << i);
    }

    public static long removeRightMostSetBit(long a) {
        // right most set bit = a&(-a)
        return a - (a & (-a));
    }

    public static long addRightMostSetBit(long a) {
        // right most set bit = a&(-a)
        return a + (a & (-a));
    }

    public static int[] buildLPS(String str) {
        int n = str.length();

        int[] lps = new int[n];
        int i = 1;
        int len = 0;
        lps[0] = 0;
        while (i < n) {
            if (str.charAt(i) == str.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else if (len == 0) {
                lps[i] = 0;
                i++;
            } else {
                len = lps[len - 1];
            }
        }
        return lps;
    }

    public static void dfsEdgeCutAlgo(ArrayList<ArrayList<Integer>> adj, int n, HashSet<String> iscut) {
        int timer = 0;
        int dis[] = new int[n];
        int low[] = new int[n];
        Arrays.fill(dis, -1);
        Arrays.fill(low, -1);
        for (int i = 0; i < n; i++) {
            if (dis[i] == -1) {
                dfsEdgeCut(adj, i, -1, dis, low, timer, iscut);
            }
        }
    }

    public static void dfsEdgeCut(ArrayList<ArrayList<Integer>> adj, int i, int parent, int dis[], int low[], int timer,
            HashSet<String> iscut) {
        dis[i] = timer;
        low[i] = timer;

        timer++;
        for (int it : adj.get(i)) {
            if (it == parent)
                continue;
            if (dis[it] == -1) {
                dfsEdgeCut(adj, it, i, dis, low, timer, iscut);
                low[i] = Math.min(low[i], low[it]);
                if (low[it] > dis[i]) {
                    if (!iscut.contains(i + "#" + it) && !iscut.contains(it + "#" + i))
                        iscut.add(it + "#" + i);
                }
            } else {
                low[i] = Math.min(low[i], dis[it]);
            }
        }

    }

    public static void main(String[] args) throws IOException {

        FastReader sc = new FastReader();
        int t = 1;
        // t = sc.nextInt();
        while (t-- != 0) {
            int n = sc.nextInt();
            String str=sc.next();
            char p1='a';
            char p2='a';
            String ans = "";
            for(int i=0;i<n;i++){
                char curr=str.charAt(i);
                if(curr>=p1){
                    ans+='0';
                    p1=curr;
                }else if(curr>=p2){
                    ans+='1';
                    p2=curr;
                }else{
                    System.out.println("NO");
                    return;
                }
            }
            System.out.println("YES");
            System.out.println(ans);

        }
    }

}
