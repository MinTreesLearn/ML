// package c1324;

//
// Codeforces Round #627 (Div. 3) 2020-03-12 05:05
// F. Maximum White Subtree
// https://codeforces.com/contest/1324/problem/F
// time limit per test 2 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// You are given a tree consisting of n vertices. A tree is a connected undirected graph with n-1
// edges. Each vertex v of this tree has a color assigned to it (a_v = 1 if the vertex v is white
// and 0 if the vertex v is black).
//
// You have to solve the following problem for each vertex v: what is the maximum difference between
// the number of white and the number of black vertices you can obtain if you choose some subtree of
// the given tree that the vertex v? The subtree of the tree is the connected subgraph of the given
// tree. More formally, if you choose the subtree that contains cnt_w white vertices and cnt_b black
// vertices, you have to maximize cnt_w - cnt_b.
//
// Input
//
// The first line of the input contains one integer n (2 <= n <= 2 * 10^5) -- the number of vertices
// in the tree.
//
// The second line of the input contains n integers a_1, a_2, ..., a_n (0 <= a_i <= 1), where a_i is
// the color of the i-th vertex.
//
// Each of the next n-1 lines describes an edge of the tree. Edge i is denoted by two integers u_i
// and v_i, the labels of vertices it connects (1 <= u_i, v_i <= n, u_i != v_i).
//
// It is guaranteed that the given edges form a tree.
//
// Output
//
// Print n integers res_1, res_2, ..., res_n, where res_i is the maximum possible difference between
// the number of white and black vertices in some subtree that contains the vertex i.
//
// Example
/*
input:
9
0 1 1 1 0 0 0 0 1
1 2
1 3
3 4
3 5
2 6
4 7
6 8
5 9
output:
2 2 2 2 2 1 1 0 2

input:
4
0 0 1 0
1 2
1 3
1 4
output:
0 -1 1 -1
*/
// Note
//
// The first example is shown below:
//
// https://espresso.codeforces.com/c9bf2c6663342bfd7b533a049ca2ba27b9f4b4df.png
//
// The black vertices have bold borders.
//
// In the second example, the best subtree for vertices 2, 3 and 4 are vertices 2, 3 and 4
// correspondingly. And the best subtree for the vertex 1 is the subtree consisting of vertices 1
// and 3.
//

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Random;
import java.util.StringTokenizer;

public class C1324F {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int[] solve(int[] a, int[][] edges) {
    int n = a.length;

    List<Integer>[] adjs = new ArrayList[n+1];
    for (int i = 0; i < n+1; i++) {
      adjs[i] = new ArrayList<>();
    }
    for (int[] edge : edges) {
      int u = edge[0];
      int v = edge[1];
      adjs[u].add(v);
      adjs[v].add(u);
    }
    int r = 1;
    int[] parent = new int[n+1];
    Queue<Integer> q = new LinkedList<>();
    q.add(r);
    while (!q.isEmpty()) {
      int v = q.poll();
      for (int w : adjs[v]) {
        if (w == parent[v]) {
          continue;
        }
        parent[w] = v;
        q.add(w);
      }
    }

    if (test) System.out.format("  parent: %s\n", Arrays.toString(parent));

    int[] subs = new int[n+1];
    int[] degs = new int[n+1];
    for (int i = 1; i <= n; i++) {
      degs[i] = adjs[i].size() - (i != 1 ? 1 : 0);
      if (degs[i] == 0) {
        q.add(i);
      }
    }
    while (!q.isEmpty()) {
      int v = q.poll();
      // System.out.format("  v:%d\n", v);
      int sum = a[v-1] == 1 ? 1 : -1;
      for (int w : adjs[v]) {
        if (w == parent[v]) {
          continue;
        }
        // System.out.format("    w:%d\n", w);
        if (subs[w] > 0) {
          sum += subs[w];
        }
      }
      subs[v] = sum;
      if (v != 1) {
        int p = parent[v];
        degs[p]--;
        if (degs[p] == 0) {
          q.add(p);
        }
      }
    }
    if (test) System.out.format("    subs: %s\n", Arrays.toString(subs));
    int[] arr = new int[n+1];
    q.add(1);
    arr[1] = subs[1];
    while (!q.isEmpty()) {
      int v = q.poll();
      if (v == 1) {
        arr[1] = subs[1];
      } else {
        int p = parent[v];
        if (test) System.out.format("  v:%d p:%d subv:%2d arrp:%2d\n", v, p, subs[v], arr[p]);
        if (subs[v] >= 1) {
          // arr[p] included subs[v]
          arr[v] = Math.max(subs[v], arr[p]);
        } else {
          // arr[p] does not includedsubs[v]
          arr[v] = Math.max(subs[v], arr[p] + subs[v]);
        }
      }
      for (int w : adjs[v]) {
        if (w == parent[v]) {
          continue;
        }
        q.add(w);
      }
    }

    int[] ans = new int[n];
    for (int i = 1; i <= n; i++) {
      ans[i-1] = arr[i];
    }
    return ans;
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = in.nextInt();
    }
    int[][] edges = new int[n-1][2];
    for (int i = 0; i < n-1; i++) {
      edges[i][0] = in.nextInt();
      edges[i][1] = in.nextInt();
    }
    int[] ans = solve(a, edges);
    output(ans);
  }

  static void output(int[] a) {
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
