import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class CODE {
    public static class pair implements Comparable<pair> {
        int x;
        int y;

        public pair(int par1, int par2) {
            x = par1;
            y = par2;
        }

        @Override
        public int compareTo(pair p) {
            return x - p.x;
        }

        @Override
        public String toString() {
            return +x + " " + y;
        }

    }

    static long mod = (long) (1e9 + 7);

    public static long facn(long n, long x) {
        long ans = 1;
        for (int i = 1; i <= x; i++) {
            ans *= n;
            ans %= mod;
            n--;
        }
        long k = 1;
        long t = x;
        for (int i = 1; i <= t; i++) {
            k *= x;
            k %= mod;
            x--;
        }
//      BigInteger b = BigInteger.valueOf((k)).modInverse(BigInteger.valueOf((mod)));
        long b = modPow(k, mod - 2, mod);
        return ((b % mod) * ans) % mod;

    }

    public static long modInverse(long a, long m) {
        a = a % m;
        for (int x = 1; x < m; x++)
            if ((a * x) % m == 1)
                return x;
        return 1;
    }

    static long modPow(long a, long e, long mod) { // O(log e)
        a %= mod;
        long res = 1;
        while (e > 0) {
            if ((e & 1) == 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            e >>= 1;
        }
        return res % mod;
    }

    public static void bb(Serializable s) {
        System.out.println(55);
    }

    public static int dfs(int u) {
        vis[u] = true;
        rank[u] = rnk;
        int ans = 1;
        for (int v : adj[u])
            if (!vis[v])
                ans += dfs(v);

        return ans;
    }

    public static void dfsD(int u) {
        dist[u] = dst;
        for (int v : adj[u])
            if (dist[v] == -1)
                dfsD(v);
    }

    static ArrayList<Integer>[] adj, adj2;
    static int n, m, k, rnk, dst;
    static boolean[] vis;
    static int[] dist, rank;

    public static String rev(String str) {
        StringBuilder sb = new StringBuilder();
        for (int i = str.length() - 1; i >= 0; i--)
            sb.append(str.charAt(i));
        // System.out.println(sb);
        return sb.toString();
    }

    static PriorityQueue<pair> pq;
    static int p;
    static int[][] Matrix;
    static long[][] memo;
    static pair[] Arr;

//  public static long dp(int idx, int mask) {
//      int k=idx-Integer.bitCount(mask);
//      if (k==0&&Integer.bitCount(mask)==p)
//          return 0;
//      long ans = 0;
//      if (memo[mask][idx] != -1)
//          return memo[mask][idx];
//      if (kk > 0)
//          ans = Math.max(ans, Arr[k+p-kk - pp].y + dp(kk - 1, pp, mask));
//      if (pp > 0)
//          for (int i = 0; i < p; i++)
//              if ((mask & (1 << i)) == 0)
//                  ans = Math.max(Matrix[Arr[k+p-kk - pp].x][i] + dp(kk, pp - 1, mask | 1 << i), ans);
//
//      return memo[mask][pp][kk] = ans;
//  }

    public static void main(String[] args) throws IOException {
        try {
            System.setIn(new FileInputStream("input.txt"));
            System.setOut(new PrintStream(new FileOutputStream("output.txt")));
        } catch (Exception e) {
            System.err.println("Error");
        }


        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        int n = sc.nextInt();
        Long[]Arr = new Long[n];
        for (int i = 0; i < n; i++)Arr[i] = sc.nextLong();
        for (int i = 0; i < n; i++)Arr[i] -= sc.nextLong();
        Arrays.sort(Arr);
        long sum = 0;
        for (int i = 0; i < n; i++) {
            int lo = 0;
            int hi = n - 1;
            int mid = n;
            int ans = n;
            while (hi >= lo) {
                mid = (lo + hi) / 2;
                if (Arr[i] + Arr[mid] > 0) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            sum += n - ans;
        }
        for (int i = 0; i < n; i++) {
            if (Arr[i] > 0)sum--;
        }
        pw.println(sum / 2);




        pw.close();
    }
    /*Scanner sc = new Scanner(System.in);
            PrintWriter pw = new PrintWriter(System.out);
            int t=sc.nextInt();
            while(t-->0) {
                int n=sc.nextInt();
                int[]Arr=new int [n];
                for(int i=0;i<n;i++)Arr[i]=sc.nextInt();
                for(int i=0;i<n;i++)Arr[i]-=sc.nextInt();
                Arrays.sort(Arr);
                int sum=0;
                for(int i=0;i<n;i++)
                {
                    int lo=0;
                    int hi=n-1;
                    int mid=n+1;
                    int ans=n+1;
                    while(hi>=lo) {
                        mid=(lo+hi)/2;

                    }
                }

                }



            pw.close();*/
    public static class trie {
        trie[] arr;
        int isLeaf;
        int freq;

        public trie() {
            super();
            this.arr = new trie[26];
            this.isLeaf = 0;
            this.freq = 0;
        }

        public void add(String str) {
            add(str, 0);
        }

        private void add(String str, int idx) {
            if (idx == str.length()) {
                isLeaf++;
                return;
            }
            int x = str.charAt(idx) - 'a';

            if (arr[x] == null)
                arr[x] = new trie();
            arr[x].freq++;
            arr[x].add(str, idx + 1);
        }

        public int numOfPref(String str) {
            return numOfPref(str, 0);
        }

        private int numOfPref(String str, int idx) {
            if (idx == str.length())
                return freq;

            int x = str.charAt(idx) - 'a';

            if (arr[x] == null)
                return 0;
            return arr[x].numOfPref(str, idx + 1);
        }

        public int numofStr(String str) {
            return numOfStr(str, 0);
        }

        private int numOfStr(String str, int idx) {
            if (idx == str.length())
                return isLeaf;

            int x = str.charAt(idx) - 'a';

            if (arr[x] == null)
                return 0;
            return arr[x].numOfStr(str, idx + 1);
        }

        public boolean contains(String str) {
            return numofStr(str) != 0;
        }

        public boolean containsPref(String str) {
            return numOfPref(str) != 0;
        }
    }

    public static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
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

        public boolean ready() throws IOException, IOException {
            return br.ready();
        }

    }
}