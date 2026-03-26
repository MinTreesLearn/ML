// package c1294;

//
// Codeforces Round #615 (Div. 3) 2020-01-22 06:35
// F. Three Paths on a Tree
// https://codeforces.com/contest/1294/problem/F
// time limit per test 2 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// You are given an unweighted tree with n vertices. Recall that a tree is a connected undirected
// graph without cycles.
//
// Your task is to choose vertices a, b, c on this tree such that the number of edges which belong
// to one of the simple paths between a and b, b and c, or a and c is the maximum possible. See the
// notes section for a better understanding.
//
// The simple path is the path that visits each vertex at most once.
//
// Input
//
// The first line contains one integer number n (3 <= n <= 2 * 10^5) -- the number of vertices in
// the tree.
//
// Next n - 1 lines describe the edges of the tree in form a_i, b_i (1 <= a_i, b_i <= n, a_i !=
// b_i). It is guaranteed that given graph is a tree.
//
// Output
//
// In the first line print one integer res -- the maximum number of edges which belong to one of the
// simple paths between a and b, b and c, or a and c.
//
// In the second line print three integers a, b, c such that 1 <= a, b, c <= n and a !=, b != c, a
// != c.
//
// If there are several answers, you can print any.
//
// Example
/*
input:
8
1 2
2 3
3 4
4 5
4 6
3 7
3 8
output:
5
1 8 6
*/
// Note
//
// The picture corresponding to the first example (and ):
//
// https://espresso.codeforces.com/a14350f33ff1d0a53f558a037dbaf779e81c1ee9.png
//
// If you choose vertices 1, 5, 6 then the path between 1 and 5 consists of edges (1, 2), (2, 3),
// (3, 4), (4, 5), the path between 1 and 6 consists of edges (1, 2), (2, 3), (3, 4), (4, 6) and the
// path between 5 and 6 consists of edges (4, 5), (4, 6). The union of these paths is (1, 2), (2,
// 3), (3, 4), (4, 5), (4, 6) so the answer is 5. It can be shown that there is no better answer.
//

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Random;
import java.util.StringTokenizer;

public class C1294F {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int[] solve(int[][] edges) {
    int n = edges.length + 1;
    int[] ans = new int[4];

    List<Integer>[] adjs = new ArrayList[n+1];
    for (int i = 0; i < n + 1; i++) {
      adjs[i] = new ArrayList<>();
    }
    for (int[] edge : edges) {
      int u = edge[0];
      int v = edge[1];
      adjs[u].add(v);
      adjs[v].add(u);
    }

    int r = 1;
    List<Integer>[] ca = new ArrayList[n+1];
    for (int i = 0; i < n + 1; i++) {
      ca[i] = new ArrayList<>();
    }

    int[] parent = new int[n+1];
    int[] depth = new int[n+1];
    Queue<Integer> q = new LinkedList<>();
    q.add(r);

    while (!q.isEmpty()) {
      int v = q.poll();
      for (int w : adjs[v]) {
        if (w == parent[v]) {
          continue;
        }
        ca[v].add(w);
        parent[w] = v;
        depth[w] = depth[v] + 1;
        q.add(w);
      }
    }

    if (test) System.out.format("  parent: %s\n", Arrays.toString(parent));
    int[] degs = new int[n+1];
    for (int i = 1; i <= n; i++) {
      degs[i] = ca[i].size();
      if (degs[i] == 0) {
        q.add(i);
      }
      if (test && degs[i] != 0) {
        Collections.sort(ca[i]);
        System.out.format("  %2d: %s\n", i, ca[i].toString());
      }
    }

    // dp[i][0][0]: the node with the maximal depth under the subtree
    // dp[i][1][0]: pivot point depth of pair (x,y)
    // dp[i][1][1]: x
    // dp[i][1][2]: y
    int[][][] dp = new int[n+1][2][3];

    while (!q.isEmpty()) {
      int v = q.poll();
      if (ca[v].isEmpty()) {
        dp[v][0][0] = v;
      } else {
        // sort children by descending depth
        Collections.sort(ca[v], (x,y)->depth[dp[y][0][0]] - depth[dp[x][0][0]]);
        int w0 = ca[v].get(0);
        dp[v][0][0] = dp[w0][0][0];
        if (test) System.out.format("  v:%2d %d %d dp[v][1]: %s ca[v]:%s ans0:%d\n",
            v, w0, dp[w0][0][0], Arrays.toString(dp[v][1]), ca[v].toString(), ans[0]);
        if (ca[v].size() == 1) {
          if (dp[w0][1][0] == 0) {
            // subtree is a stick
            if (ans[0] < depth[dp[v][0][0]] - depth[v] && w0 != dp[v][0][0]) {
              ans[0] = depth[dp[v][0][0]] - depth[v];
              ans[1] = v;
              ans[2] = w0;
              ans[3] = dp[w0][0][0];
            }
          } else {
            int p = dp[w0][1][0];
            int a = dp[w0][1][1];
            int b = dp[w0][1][2];
            int score = depth[a] - depth[p] + depth[b] - depth[p] + depth[p] - depth[v];
            if (test) System.out.format("  v:%2d p:%d a:%d b:%d score:%d\n", v, p, a, b, score);
            dp[v][1][0] = p;
            dp[v][1][1] = a;
            dp[v][1][2] = b;
            if (ans[0] < score) {
              ans[0] = score;
              ans[1] = v;
              ans[2] = a;
              ans[3] = b;
            }
          }
        } else {
          // 2+ children
          //     v
          //    / \
          //  w0   w1
          //  /     \
          // a       b
          int w1 = ca[v].get(1);
          int a = dp[w0][0][0];
          int b = dp[w1][0][0];
          dp[v][1][0] = v;
          dp[v][1][1] = a;
          dp[v][1][2] = b;
          int score = depth[a] + depth[b] - 2 * depth[v];
          if (ans[0] < score) {
            ans[0] = score;
            ans[1] = v;
            ans[2] = a;
            ans[3] = b;
          }

          for (int i = 0; i < ca[v].size(); i++) {
            int w = ca[v].get(i);
            if (dp[w][1][0] > 0) {
              //     v
              //     |
              //     p
              //    / \
              //   a   b
              int p = dp[w][1][0];
              a = dp[w][1][1];
              b = dp[w][1][2];
              int z = depth[a] + depth[b] - depth[p] - depth[v];
              if (z > score) {
                dp[v][1][0] = p;
                dp[v][1][1] = a;
                dp[v][1][2] = b;
                score = z;
                if (ans[0] < score) {
                  ans[0] = score;
                  ans[1] = v;
                  ans[2] = a;
                  ans[3] = b;
                }
              }

              //      v
              //     / \
              //    *   p
              //   /   / \
              //  u   a   b
              int u = i == 0 ? dp[ca[v].get(1)][0][0] : dp[ca[v].get(0)][0][0];
              z = depth[a] - depth[p] + depth[b] - depth[p] + depth[p] - depth[v] + depth[u] - depth[v];
              if (ans[0] < z) {
                ans[0] = z;
                ans[1] = u;
                ans[2] = a;
                ans[3] = b;
              }
            }
          }

          if (ca[v].size() >= 3) {
            //       v
            //     / | \
            //   w0 w1 w2
            //   /   |   \
            //  a    b    c
            int w2 = ca[v].get(2);
            a = dp[w0][0][0];
            b = dp[w1][0][0];
            int c = dp[w2][0][0];
            int x = depth[a] + depth[b] + depth[c] - 3 * depth[v];
            if (ans[0] < x) {
              ans[0] = x;
              ans[1] = a;
              ans[2] = b;
              ans[3] = c;
            }
          }
        }
      }
      if (test) System.out.format("  v:%2d dp[v][0]:%d dp[v][1]:%s\n", v, dp[v][0][0], Arrays.toString(dp[v][1]));

      int p = parent[v];
      if (p != 0) {
        degs[p]--;
        if (degs[p] == 0) {
          q.add(p);
        }
      }
    }
    return ans;
  }

  static void test(int exp, int[][] edges) {
    System.out.format("edges: %s\n", trace(edges));
    int[] ans = solve(edges);
    boolean ok = (exp == ans[0] && ans[1] != 0 && ans[2] != 0 && ans[3] != 0);
    System.out.format(" => %d %d %d %d\n", ans[0], ans[1], ans[2], ans[3], ok ? "":"Expected " + exp);
    myAssert(ok);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();

    test(99, new int[][] {{24,25},{57,58},{83,84},{81,80},{89,88},{34,33},{48,49},{58,59},{95,94},{28,27},
      {98,99},{37,36},{77,76},{11,10},{8,9},{51,52},{49,50},{52,53},{92,91},{20,21},
      {44,45},{65,66},{44,43},{78,79},{14,15},{48,47},{5,6},{28,29},{100,99},{84,85},
      {42,41},{98,97},{40,39},{54,55},{82,83},{75,74},{56,57},{69,68},{11,12},{9,10},
      {46,47},{13,12},{46,45},{93,94},{4,3},{77,78},{1,2},{54,53},{22,21},{87,86},
      {59,60},{37,38},{15,16},{70,69},{29,30},{75,76},{61,62},{33,32},{62,63},{64,65},
      {26,27},{22,23},{73,72},{42,43},{82,81},{66,67},{3,2},{67,68},{93,92},{31,30},
      {71,72},{88,87},{86,85},{56,55},{4,5},{70,71},{40,41},{19,18},{25,26},{97,96},
      {61,60},{90,91},{8,7},{73,74},{38,39},{50,51},{18,17},{35,34},{79,80},{96,95},
      {90,89},{16,17},{20,19},{63,64},{24,23},{7,6},{36,35},{31,32},{14,13}});

    test(20, new int[][] {{29,53},{2,1},{55,73},{89,66},{29,12},{18,1},{53,68},{8,60},{24,34},{10,6},
        {28,44},{58,92},{87,30},{47,95},{11,5},{15,82},{40,91},{2,39},{20,35},{44,65},
        {17,50},{19,33},{45,16},{6,4},{22,76},{26,56},{67,27},{2,9},{4,28},{98,19},
        {27,20},{3,4},{3,88},{31,3},{25,24},{8,4},{44,69},{14,4},{68,80},{73,81},
        {36,25},{30,27},{70,4},{4,5},{50,79},{78,3},{51,5},{3,15},{4,13},{24,6},
        {15,17},{23,62},{1,3},{17,38},{19,54},{19,77},{47,20},{94,97},{34,99},{41,96},
        {4,43},{74,54},{22,12},{100,82},{7,2},{46,71},{72,32},{86,59},{10,21},{35,37},
        {40,19},{75,83},{9,20},{59,42},{16,9},{23,18},{38,41},{6,46},{49,9},{7,12},
        {20,85},{17,90},{58,12},{58,61},{42,17},{19,7},{84,8},{91,93},{63,46},{31,64},
        {32,8},{21,55},{26,21},{24,94},{75,11},{31,48},{26,52},{66,44},{57,10}});


    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int[][] edges = new int[n-1][2];
    for (int i = 0; i < n - 1; i++) {
      edges[i][0] = in.nextInt();
      edges[i][1] = in.nextInt();
    }
    /*
    if (n == 100 && edges[0][0] == 24 && edges[0][1] == 25) {
      int[][] brr = new int[39][2];
      for (int i = 60; i < n - 1; i++) {
        brr[i-60][0] = edges[i][0];
        brr[i-60][1] = edges[i][1];
      }
      throw new RuntimeException(trace(brr));
    }
    */
    int[] ans = solve(edges);
    System.out.format("%d\n%d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
  }

  static String trace(int[][] a) {
    return Arrays.deepToString(a).replace(" ", "").replace('[', '{').replace(']', '}');
  }

  static String trace(int[] a) {
    return Arrays.toString(a).replace(" ", "").replace('[', '{').replace(']', '}');
  }

  static void output(int[] a) {
    if (a == null) {
      System.out.println("-1");
      return;
    }
    StringBuilder sb = new StringBuilder();
    for (int v : a) {
      sb.append(v);
      sb.append(' ');
      if (sb.length() > 4000) {
        System.out.print(sb.toString());
        sb.setLength(0);
      }
    }
    System.out.println(sb.toString());
  }

  static void myAssert(boolean cond) {
    if (!cond) {
      throw new RuntimeException("Unexpected");
    }
  }

  static class MyScanner {
    BufferedReader br;
    StringTokenizer st;

    public MyScanner() {
      try {
        final String USERDIR = System.getProperty("user.dir");
        String cname = MethodHandles.lookup().lookupClass().getCanonicalName().replace(".MyScanner", "");
        cname = cname.lastIndexOf('.') > 0 ? cname.substring(cname.lastIndexOf('.') + 1) : cname;
        final File fin = new File(USERDIR + "/io/c" + cname.substring(1,5) + "/" + cname + ".in");
        br = new BufferedReader(new InputStreamReader(fin.exists()
            ? new FileInputStream(fin) : System.in));
      } catch (Exception e) {
        br = new BufferedReader(new InputStreamReader(System.in));
      }
    }

    public String next() {
      try {
        while (st == null || !st.hasMoreElements()) {
          st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
      } catch (Exception e) {
        throw new RuntimeException(e);
      }
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

    public long nextLong() {
      return Long.parseLong(next());
    }
  }
}
