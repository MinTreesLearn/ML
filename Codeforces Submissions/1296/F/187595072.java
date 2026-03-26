// package c1296;

//
// Codeforces Round #617 (Div. 3) 2020-02-04 06:35
// F. Berland Beauty
// https://codeforces.com/contest/1296/problem/F
// time limit per test 3 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// There are n railway stations in Berland. They are connected to each other by n-1 railway
// sections. The railway network is connected, i.e. can be represented as an undirected tree.
//
// You have a map of that network, so for each railway section you know which stations it connects.
//
// Each of the n-1 sections has some integer value of the . However, these values are not marked on
// the map and you don't know them. All these values are from 1 to 10^6 inclusive.
//
// You asked m passengers some questions: the j-th one told you three values:
//  * his departure station a_j;
//  * his arrival station b_j;
//  * minimum scenery beauty along the path from a_j to b_j (the train is moving along the shortest
//    path from a_j to b_j).
//
// You are planning to update the map and set some value f_i on each railway section -- the . The
// passengers' answers should be consistent with these values.
//
// Print any valid set of values f_1, f_2, ..., f_{n-1}, which the passengers' answer is consistent
// with or report that it doesn't exist.
//
// Input
//
// The first line contains a single integer n (2 <= n <= 5000) -- the number of railway stations in
// Berland.
//
// The next n-1 lines contain descriptions of the railway sections: the i-th section description is
// two integers x_i and y_i (1 <= x_i, y_i <= n, x_i != y_i), where x_i and y_i are the indices of
// the stations which are connected by the i-th railway section. All the railway sections are
// bidirected. Each station can be reached from any other station by the railway.
//
// The next line contains a single integer m (1 <= m <= 5000) -- the number of passengers which were
// asked questions. Then m lines follow, the j-th line contains three integers a_j, b_j and g_j (1
// <= a_j, b_j <= n; a_j != b_j; 1 <= g_j <= 10^6) -- the departure station, the arrival station and
// the minimum scenery beauty along his path.
//
// Output
//
// If there is no answer then print a single integer -1.
//
// Otherwise, print n-1 integers f_1, f_2, ..., f_{n-1} (1 <= f_i <= 10^6), where f_i is some valid
// scenery beauty along the i-th railway section.
//
// If there are multiple answers, you can print any of them.
//
// Example
/*
input:
4
1 2
3 2
3 4
2
1 2 5
1 3 3
output:
5 3 5

input:
6
1 2
1 6
3 1
1 5
4 1
4
6 1 3
3 4 1
6 5 2
1 2 5
output:
5 3 1 2 1

input:
6
1 2
1 6
3 1
1 5
4 1
4
6 1 1
3 4 3
6 5 3
1 2 4
output:
-1
*/
//

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Random;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class C1296F {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int[] solve(int[][] edges, int[][] paths) {
    int n = edges.length + 1;
    int m = paths.length;

    List<int[]>[] adjs = new ArrayList[n+1];
    for (int i = 0; i < n+1; i++) {
      adjs[i] = new ArrayList<>();
    }
    for (int i = 0; i < n-1; i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      adjs[u].add(new int[] {v, i});
      adjs[v].add(new int[] {u, i});
    }

    int[][] parent = new int[n+1][2];
    int[] depth = new int[n+1];
    int r = 1;

    Queue<Integer> q = new LinkedList<>();
    q.add(r);
    while (!q.isEmpty()) {
      int v = q.poll();
      for (int[] e : adjs[v]) {
        int w = e[0];
        if (w == parent[v][0]) {
          continue;
        }
        parent[w][0] = v;
        parent[w][1] = e[1];
        depth[w] = depth[v] + 1;
        q.add(w);
      }
    }
    if (test) System.out.format("  parent: %s\n", Arrays.deepToString(parent));

    int maxw = 0;
    for (int pid = 0; pid < m; pid++) {
      maxw = Math.max(maxw, paths[pid][2]);
    }

    // Evaluate all paths in descending weight order
    Arrays.sort(paths, (x,y)->y[2]-x[2]);

    int[] ans = new int[n-1];
    for (int pid = 0; pid < m; pid++) {
      int a = paths[pid][0];
      int b = paths[pid][1];
      int w = paths[pid][2];
      List<Integer> eids = getPathEdgesList(a, b, parent, depth);
      if (test) System.out.format("  pid:%d a:%d b:%d w:%d eids:%s\n", pid, a, b, w, eids.toString());
      // All the involved edges has minimal weight w
      boolean ok = false;
      for (int eid : eids) {
        myAssert(ans[eid] == 0 || ans[eid] >= w);
        if (ans[eid] == 0) {
          if (test) System.out.format("  assign %d %d\n", eid, w);
          ans[eid] = w;
          ok = true;
        } else if (ans[eid] == w) {
          ok = true;
        } else {
          // this edge won't satisfy w
        }
      }
      if (!ok) {
        // no edge in the path can support w
        return null;
      }
    }
    for (int i = 0; i < n-1; i++) {
      if (ans[i] == 0) {
        ans[i] = maxw;
      }
    }
    return ans;
  }


  // Time limit exceeded on test 268
  // 5000
  // 1 2
  // 2 3
  // 3 4
  // ...
  // test 264 5000 2261 ms  2262 ms
  // test 266 5000 2713 ms  2355 ms
  static int[] solveA(int[][] edges, int[][] paths) {
    int n = edges.length + 1;
    int m = paths.length;

    List<int[]>[] adjs = new ArrayList[n+1];
    for (int i = 0; i < n+1; i++) {
      adjs[i] = new ArrayList<>();
    }
    for (int i = 0; i < n-1; i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      adjs[u].add(new int[] {v, i});
      adjs[v].add(new int[] {u, i});
    }

    int[][] parent = new int[n+1][2];
    int[] depth = new int[n+1];
    int r = 1;

    Queue<Integer> q = new LinkedList<>();
    q.add(r);
    while (!q.isEmpty()) {
      int v = q.poll();
      for (int[] e : adjs[v]) {
        int w = e[0];
        if (w == parent[v][0]) {
          continue;
        }
        parent[w][0] = v;
        parent[w][1] = e[1];
        depth[w] = depth[v] + 1;
        q.add(w);
      }
    }
    if (test) System.out.format("  parent: %s\n", Arrays.deepToString(parent));

    // pida[eid] is the path ids that contains edge eid
    Set<Integer>[] pida = new HashSet[n-1];
    for (int eid = 0; eid < n-1; eid++) {
      // Sort paths for the edge in ascending order of weight (smallest path first)
      // *** Note that if we sort, ensure the comparison is NOT 0 for different eid regardless ***
      // pida[eid] = new TreeSet<>((x, y)->paths[x][2] - paths[y][2]);
      pida[eid] = new HashSet<>();
    }

    TreeMap<Integer, Set<Integer>> wpids = new TreeMap<>();

    int maxw = 0;
    for (int pid = 0; pid < m; pid++) {
      int a = paths[pid][0];
      int b = paths[pid][1];
      int w = paths[pid][2];
      maxw = Math.max(maxw, w);
      List<Integer> eids = getPathEdgesList(a, b, parent, depth);
      if (test) System.out.format("  pid:%d a:%d b:%d w:%d eids:%s\n", pid, a, b, w, eids.toString());
      for (int eid : eids) {
        pida[eid].add(pid);
      }
      wpids.computeIfAbsent(w, x -> new HashSet<>()).add(pid);
    }

    for (int eid = 0; eid < n-1; eid++) {
      if (!pida[eid].isEmpty()) {
        if (test) {
          List<Integer> pids = new ArrayList<>(pida[eid]);
          System.out.format("  eid:%d pids:%s\n", eid, pids.toString());
        }
      }
    }
    for (Map.Entry<Integer, Set<Integer>> e : wpids.entrySet()) {
      int w = e.getKey();
      Set<Integer> pids = e.getValue();
      if (test) System.out.format("  w:%d pids:%s\n", w, pids.toString());
    }

    boolean[] edone = new boolean[n-1];
    boolean[] pdone = new boolean[m];

    int[] ans = new int[n-1];
    Arrays.fill(ans, maxw);

    Set<Integer> eids = new HashSet<>();
    for (int eid = 0; eid < n-1; eid++) {
      if (edone[eid] || pida[eid].isEmpty()) {
        continue;
      }
      eids.add(eid);
    }

    for (Map.Entry<Integer, Set<Integer>> e : wpids.entrySet()) {
      int w = e.getKey();
      Set<Integer> pids = e.getValue();
      if (test) System.out.format("  w:%d pids:%s\n", w, pids.toString());
      while (!pids.isEmpty()) {
        int eid = -1;
        for (int v : eids) {
          boolean ok = true;
          for (int pid : pida[v]) {
            myAssert(!pdone[pid]);
            if (paths[pid][2] != w) {
              ok = false;
              break;
            }
          }
          if (ok) {
            eid = v;
            break;
          }
        }
        if (eid < 0) {
          if (test) System.out.format("  no edge for %d found\n", w);
          return null;
        }
        if (test) System.out.format("  found edge %d for %d found\n", eid, w);
        Set<Integer> epids = pida[eid];

        if (test) System.out.format("    epids %s\n", epids.toString());

        ans[eid] = w;
        edone[eid] = true;
        // remove eid from all the paths that contain it
        for (int pid : epids) {
          pdone[pid] = true;
        }
        for (int v : eids) {
          if (v != eid) {
            pida[v].removeAll(epids);
            if (test) System.out.format("    v:%d %s\n", v, pida[v].toString());
          }
        }
        eids.remove(eid);
        pids.removeAll(epids);
      }
    }
    return ans;
  }

  static Set<Integer> getPathEdgesSet(int a, int b, int[][] parent, int[] depth) {
    if (depth[a] < depth[b]) {
      return getPathEdgesSet(b, a, parent, depth);
    }
    myAssert(depth[a] >= depth[b]);
    //        root
    //        /
    //       p
    //      / \
    //     *   b
    //    /
    //   a

    Set<Integer> edges = new HashSet<>();
    int x = a;
    for (int i = 0; i < depth[a] - depth[b]; i++) {
      edges.add(parent[x][1]);
      x = parent[x][0];
    }
    int y = b;
    while (x != y) {
      edges.add(parent[x][1]);
      x = parent[x][0];
      edges.add(parent[y][1]);
      y = parent[y][0];
    }
    return edges;
  }

  // Get list of edge ids on the path from a to b.
  // For efficiency, the order is not guarantee.
  static List<Integer> getPathEdgesList(int a, int b, int[][] parent, int[] depth) {
    if (depth[a] < depth[b]) {
      return getPathEdgesList(b, a, parent, depth);
    }
    myAssert(depth[a] >= depth[b]);
    //        root
    //        /
    //       p
    //      / \
    //     *   b
    //    /
    //   a

    List<Integer> edges = new ArrayList<>();
    int x = a;
    for (int i = 0; i < depth[a] - depth[b]; i++) {
      edges.add(parent[x][1]);
      x = parent[x][0];
    }
    int y = b;
    while (x != y) {
      edges.add(parent[x][1]);
      x = parent[x][0];
      edges.add(parent[y][1]);
      y = parent[y][0];
    }
    return edges;
  }

  static String trace(int[][] a) {
    return Arrays.deepToString(a).replace(" ", "").replace('[', '{').replace(']', '}');
  }

  static String trace(int[] a) {
    return Arrays.toString(a).replace(" ", "").replace('[', '{').replace(']', '}');
  }

  static void test(int[] exp, int[][] railways, int[][] paths) {
    System.out.format("edges:%s\n", trace(railways));
    System.out.format("paths:%s\n", trace(paths));
    int[] ans = solve(railways, paths);
    boolean ok = true;
    if (ans == null) {
      ok = exp == null;
      System.out.format("  => %s %s\n", trace(ans), ok ? "":"Expected " + trace(exp));
    } else if (exp == null) {
      System.out.format("  => %s Expected -1\n", trace(ans));
      ok = false;
    } else {
      for (int i = 0; i < ans.length; i++) {
        if (ans[i] != exp[i]) {
          ok = false;
          break;
        }
      }
      System.out.format("  => %s %s\n", trace(ans), ok ? "":"Expected " + trace(exp));
    }
    myAssert(ok);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    test(new int[] {5,3,1,2,5}, new int[][] {{1,2},{1,6},{3,1},{1,5},{4,1}},
        new int[][] {{6,1,3},{3,4,1},{6,5,2},{1,2,5},{1,4,5}});

    test(new int[] {1}, new int[][] {{2,1}}, new int[][] {{1,2,1},{2,1,1}});
    test(null, new int[][] {{1,2},{3,1},{4,2}}, new int[][] {{2,4,1},{4,1,2}});
    test(new int[] {5,3,5}, new int[][] {{1,2},{3,2},{3,4}}, new int[][] {{1,2,5},{1,3,3}});
    test(new int[] {5,3,1,2,1}, new int[][] {{1,2},{1,6},{3,1},{1,5},{4,1}},
        new int[][] {{6,1,3},{3,4,1},{6,5,2},{1,2,5}});
    test(new int[] {3, 3}, new int[][] {{2,1},{3,1}}, new int[][] {{3,2,3}});
    test(new int[] {2, 4}, new int[][] {{1,2},{1,3}}, new int[][] {{3,2,2},{1,3,4}});

    test(null, new int[][] {{1,2},{1,6},{3,1},{1,5},{4,1}},
        new int[][] {{6,1,1},{3,4,3},{6,5,3},{1,2,4}});

    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int[][] railways = new int[n-1][2];
    for (int i = 0; i < n-1; i++) {
      railways[i][0] = in.nextInt();
      railways[i][1] = in.nextInt();
    }
    int m = in.nextInt();
    int[][] questions = new int[m][3];
    for (int i = 0; i < m; i++) {
      questions[i][0] = in.nextInt();
      questions[i][1] = in.nextInt();
      questions[i][2] = in.nextInt();
    }
    int[] ans = solve(railways, questions);
    output(ans);
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
