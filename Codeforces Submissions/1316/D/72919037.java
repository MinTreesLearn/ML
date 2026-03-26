import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Main implements Runnable
{
    boolean multiple = false;
    long MOD = 998244353;

    @SuppressWarnings("Duplicates")
    void solve() throws Exception
    {
        int n = sc.nextInt();
        int[][] x = new int[n][n];
        int[][] y = new int[n][n];
        int[][] ans = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                x[i][j] = max(-1, sc.nextInt() - 1);
                y[i][j] = max(-1, sc.nextInt() - 1);
            }
        boolean gay = true;

        boolean[][] visited = new boolean[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j]) continue;
                if (x[i][j] == -1)
                {
                    if (i > 0 && x[i - 1][j] == -1) ans[i][j] = 1;
                    else if (i < n - 1 && x[i + 1][j] == -1) ans[i][j] = 2;
                    else if (j > 0 && x[i][j - 1] == -1) ans[i][j] = 3;
                    else if (j < n - 1 && x[i][j + 1] == -1) ans[i][j] = 4;
                    else
                    {
                        gay = false;
                        break;
                    }
                }
                else
                {
                    int start = p(x[i][j], y[i][j]);
//                    System.out.println(i + " " + j);
                    ans[x[i][j]][y[i][j]] = 5;

                    HashSet<Integer> fringe = new HashSet<>();
                    fringe.add(start);
                    visited[f(start)][s(start)] = true;
                    int tx = f(start), ty = s(start);

                    if (x[x[i][j]][y[i][j]] != x[i][j] || y[x[i][j]][y[i][j]] != y[i][j])
                    {
                        gay = false;
                        break;
                    }

                    while (!fringe.isEmpty())
                    {
                        HashSet<Integer> next = new HashSet<>();
//                System.out.println("fringe:" + fringe);
                        for (Integer u : fringe)
                        {
//                    System.out.println(u);
//                    System.out.println(next);
                            int ux = f(u), uy = s(u);
                            int qx = ux - 1, qy = uy;
                            if (qx >= 0 && qx < n && qy >= 0 && qy < n
                                    && !visited[qx][qy] && x[qx][qy] == tx && y[qx][qy] == ty)
                            {
//                        System.out.println("1");
                                visited[qx][qy] = true;
                                ans[qx][qy] = 2;
                                next.add(p(qx, qy));
                            }
                            qx = ux + 1;
                            if (qx >= 0 && qx < n && qy >= 0 && qy < n
                                    && !visited[qx][qy] && x[qx][qy] == tx && y[qx][qy] == ty)
                            {
//                        System.out.println(2);
                                visited[qx][qy] = true;
                                ans[qx][qy] = 1;
                                next.add(p(qx, qy));
                            }
                            qx = ux;
                            qy = uy - 1;
                            if (qx >= 0 && qx < n && qy >= 0 && qy < n
                                    && !visited[qx][qy] && x[qx][qy] == tx && y[qx][qy] == ty)
                            {
//                        System.out.println(3);
                                visited[qx][qy] = true;
                                ans[qx][qy] = 4;
                                next.add(p(qx, qy));
                            }
                            qy = uy + 1;
                            if (qx >= 0 && qx < n && qy >= 0 && qy < n
                                    && !visited[qx][qy] && x[qx][qy] == tx && y[qx][qy] == ty)
                            {
//                        System.out.println(4);
                                visited[qx][qy] = true;
                                ans[qx][qy] = 3;
                                next.add(p(qx, qy));
                            }
//                    System.out.println(next);
//                    System.out.println();
                        }
                        fringe = next;
                    }
                }
                visited[i][j] = true;
            }

            if (!gay) break;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (ans[i][j] == 0) gay = false;

        if (!gay) System.out.println("INVALID");
        else
        {
            System.out.println("VALID");
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (ans[i][j] == 1) sb.append('U');
                    if (ans[i][j] == 2) sb.append('D');
                    if (ans[i][j] == 3) sb.append('L');
                    if (ans[i][j] == 4) sb.append('R');
                    if (ans[i][j] == 5) sb.append('X');
                }
                sb.append('\n');
            }
            System.out.print(sb);
        }
    }

    int p(int i, int j)
    {
        return (i * 1000) + j;
    }

    int f(int key)
    {
        return key / 1000;
    }

    int s(int key)
    {
        return key % 1000;
    }

    class Node implements Comparable<Node>
    {
        int idx, val;
        Node(int I, int V)
        {
            idx = I;
            val = V;
        }

        @Override
        public int compareTo(Node o)
        {
            if (val != o.val) return Integer.compare(val, o.val);
            return Integer.compare(o.idx, idx);
        }
    }

    long inv(long a, long b) { return 1 < a ? b - inv(b % a, a) * b / a : 1; }
    long gcd(long a, long b) { return a == 0 ? b : gcd(b % a, a); }
    long powmod(long x, long pow) { if (pow == 0) return 1L;long temp = powmod(x,pow / 2);if (pow % 2 == 0) return (temp * temp) % MOD;return (((x * temp) % MOD) * temp) % MOD; }
    long lcm(long a, long b) { return (a * b) / gcd(a , b); }
    void printarr(int[] arr) { for (int t : arr) System.out.print(t + " ");System.out.println(); }
    TreeMap<Integer, TreeSet<Integer>> buildGraph(int n, int m) throws Exception{TreeMap<Integer, TreeSet<Integer>> graph = new TreeMap<>();for (int i = 1; i <= n; i++) graph.put(i, new TreeSet<>());for (int i = 0; i < m; i++) { int u = sc.nextInt();int v = sc.nextInt();graph.get(u).add(v);graph.get(v).add(u); }return graph; }
    TreeMap<Integer, TreeSet<Integer>> buildDirGraph(int n, int m) throws Exception { TreeMap<Integer, TreeSet<Integer>> graph = new TreeMap<>();for (int i = 1; i <= n; i++) graph.put(i, new TreeSet<>());for (int i = 0; i < m; i++) graph.get(sc.nextInt()).add(sc.nextInt());return graph; }
    TreeMap<Integer, TreeSet<Integer>> revGraph(TreeMap<Integer, TreeSet<Integer>> graph) { TreeMap<Integer, TreeSet<Integer>> rev = new TreeMap<>();for (Integer u : graph.keySet()) rev.put(u, new TreeSet<>());for (Integer u : graph.keySet()) for (Integer v : graph.get(u)) rev.get(v).add(u);return rev; }
    int[] iarr(int n) throws Exception { int[] a = new int[n];for (int i = 0; i < n; i++) a[i] = sc.nextInt();return a; }
    Integer[] Iarr(int n) throws Exception { Integer[] a = new Integer[n];for (int i = 0; i < n; i++) a[i] = sc.nextInt();return a; }
    long[] larr(int n) throws Exception { long[] a = new long[n];for (int i = 0; i < n; i++) a[i] = sc.nextLong();return a; }
    TreeMap<Long, Integer> counts(long[] arr) { TreeMap<Long, Integer> counts = new TreeMap<>(); for (long a : arr) { if (!counts.containsKey(a)) counts.put(a, 0); counts.put(a, counts.get(a) + 1);} return counts; }
    String reverse(String s, int i, int j) /*[i, j] closed*/ { return (i > j) ? reverse(s, j, i) : s.substring(0, i) + (new StringBuilder(s.substring(i, j + 1))).reverse() + ((j + 1 <= s.length() - 1) ? s.substring(j + 1) : "");}
    @Override public void run() { try { in = new BufferedReader(new InputStreamReader(System.in));out = new PrintWriter(System.out);sc = new FastScanner(in);if (multiple) { int q = sc.nextInt();for (int i = 0; i < q; i++) solve(); } else solve(); } catch (Throwable uncaught) { Main.uncaught = uncaught; } finally { out.close(); }} public static void main(String[] args) throws Throwable{ Thread thread = new Thread(null, new Main(), "", (1 << 26));thread.start();thread.join();if (Main.uncaught != null) {throw Main.uncaught;} } static Throwable uncaught; BufferedReader in; FastScanner sc; PrintWriter out; } class FastScanner { BufferedReader in; StringTokenizer st; public FastScanner(BufferedReader in) {this.in = in;}public String nextToken() throws Exception { while (st == null || !st.hasMoreTokens()) { st = new StringTokenizer(in.readLine()); }return st.nextToken(); }public int nextInt() throws Exception { return Integer.parseInt(nextToken()); }public long nextLong() throws Exception { return Long.parseLong(nextToken()); }public double nextDouble() throws Exception { return Double.parseDouble(nextToken()); }
}