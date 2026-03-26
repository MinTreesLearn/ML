// package c1311;

//
// Codeforces Round #624 (Div. 3) 2020-02-24 06:35
// E. Construct the Binary Tree
// https://codeforces.com/contest/1311/problem/E
// time limit per test 2 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// You are given two integers n and d. You need to construct a rooted binary tree consisting of n
// vertices with a root at the vertex 1 and the sum of depths of all vertices equals to d.
//
// A tree is a connected graph without cycles. A rooted tree has a special vertex called the root. A
// parent of a vertex v is the last different from v vertex on the path from the root to the vertex
// v. The depth of the vertex v is the length of the path from the root to the vertex v. Children of
// vertex v are all vertices for which v is the parent. The binary tree is such a tree that no
// vertex has more than 2 children.
//
// You have to answer t independent test cases.
//
// Input
//
// The first line of the input contains one integer t (1 <= t <= 1000) -- the number of test cases.
//
// The only line of each test case contains two integers n and d (2 <= n, d <= 5000) -- the number
// of vertices in the tree and the required sum of depths of all vertices.
//
// It is guaranteed that the sum of n and the sum of d both does not exceed 5000 (\sum n <= 5000,
// \sum d <= 5000).
//
// Output
//
// For each test case, print the answer.
//
// If it is impossible to construct such a tree, print "NO" (without quotes) in the first line.
// Otherwise, print "{YES}" in the first line. Then print n-1 integers p_2, p_3, ..., p_n in the
// second line, where p_i is the parent of the vertex i. Note that the sequence of parents you print
// should describe some binary tree.
//
// Example
/*
input:
3
5 7
10 19
10 18
output:
YES
1 2 1 3
YES
1 2 3 3 9 9 2 1 6
NO
*/
// Note
//
// Pictures corresponding to the first and the second test cases of the example:
//
// https://espresso.codeforces.com/94d2346ee349d5dcb535dcd106cfbaa389c1b21c.png
//
// https://espresso.codeforces.com/c6a4bb4f01e3c79a7c34c54ab163323733690f43.png
//

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Random;
import java.util.StringTokenizer;

public class C1311E {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int[] solve(int n, int d) {
    int[] ans = new int[n-1];
    // compute the minimal possible value
    // 0 1 1 2 2 2 2 3 3 3 3 3 3 3 3 4 4 ...
    int h = 0;
    int min = 0;
    int m = 1;
    while ((1 << (h + 1)) - 1 < n) {
      h++;
      min += (1 << h) * h;
      m += (1 << h);
    }
    min -= (m - n) * h;
    int max = n * (n-1) / 2;

    if (test) System.out.format("n:%d d:%d h:%d m:%d min:%d max:%d\n", n, d, h, m, min, max);
    if (d < min || d > max) {
      return null;
    }

    // Construct toward a perfect binary tree
    Node[] nodes = new Node[n+1];
    Node root = new Node(1);
    Queue<Node> q = new LinkedList<>();
    q.add(root);
    nodes[1] = root;
    int id = 1;
    while (!q.isEmpty()) {
      Node v = q.poll();
      if (id < n) {
        Node x = new Node(++id, v);
        nodes[x.v] = x;
        v.left = x;
        q.add(x);
      }
      if (id < n) {
        Node x = new Node(++id, v);
        nodes[x.v] = x;
        v.right = x;
        q.add(x);
      }
    }
    dfsSubCnt(root);

    List<Node>[] levels = new ArrayList[n];
    for (int i = 0; i < n; i++) {
      levels[i] = new ArrayList<>();
    }
    int maxd = refreshLevels(root, levels);

    // Identify and move subtree down to meet the expected sum of depth
    int ib = 1;
    int sum = sumDepth(root);
    while (sum < d) {
      // System.out.format("  sum:%d ib:%d\n", sum, ib);
      while (levels[ib].size() == 1) {
        ib++;
      }

      // Identify a node x at level ib and another node p at level ie >= ib
      // Check the gain of depth sum if we move x under p and do it if applicable.
      Node x = levels[ib].get(1);

      // look for new parent of x bottom up
      // The catch is such p must NOT be a descendant of x
      Node p = null;
      int gain = -1;
      for (int ie = maxd - 1; ie >= ib; ie--) {
        myAssert(levels[ie].get(0).depth == ie);
        gain = (ie - x.p.depth) * x.subcnt;
        if (sum + gain > d) {
          continue;
        }
        for (Node v : levels[ie]) {
          if (v.v != x.v && (v.left == null || v.right == null)) {
            // v must not be a descendant of x
            boolean ok = true;
            Node y = v;
            while (y != null) {
              if (y.v == x.v) {
                ok = false;
                break;
              }
              y = y.p;
            }
            if (ok) {
              p = v;
              break;
            }
          }
        }
        if (p != null) {
          break;
        }
      }
      if (p == null) {
        ib++;
        continue;
      }
      if (test) System.out.format("  sum:%d ib:%d x:%s p:%s gain:%d\n", sum, ib, x, p, gain);
      // if we move x under p, we gain total depth of:
      myAssert(gain > 0);
      myAssert(sum + gain <= d);
      myAssert(p.depth >= x.depth);

      Node y = x.p;
      while (y != null) {
        y.subcnt -= x.subcnt;
        y = y.p;
      }
      if (x.p.left != null && x.p.left.v == x.v) {
        x.p.left = null;
      } else {
        x.p.right = null;
      }

      x.p = p;
      x.depth = p.depth + 1;
      if (p.left == null) {
        p.left = x;
      } else {
        p.right = x;
      }
      y = p;
      while (y != null) {
        y.subcnt += x.subcnt;
        y = y.p;
      }
      sum += gain;
      maxd = refreshLevels(root, levels);
      dfsSubCnt(root);
    }
    for (int v = 2; v <= n; v++) {
      ans[v-2] = nodes[v].p.v;
    }
    return ans;
  }

  static int refreshLevels(Node root, List<Node>[] levels) {
    Queue<Node> q = new LinkedList<>();
    q.add(root);
    int depth = 0;
    while (!q.isEmpty()) {
      int size = q.size();
      levels[depth].clear();
      for (int i = 0; i < size; i++) {
        Node v = q.poll();
        // correct v's depth
        v.depth = depth;
        levels[v.depth].add(v);
        if (v.left != null) {
          q.add(v.left);
        }
        if (v.right != null) {
          q.add(v.right);
        }
      }
      depth++;
    }
    if (depth < levels.length) {
      levels[depth].clear();
    }
    for (int i = 0; i < depth; i++) {
      if (!levels[i].isEmpty()) {
        if (test) System.out.format("  depth:%d %s\n", i, levels[i].toString());
      }
    }
    return depth;
  }

  static int sumDepth(Node root) {
    Queue<Node> q = new LinkedList<>();
    q.add(root);
    int sum = 0;
    int depth = 0;
    while (!q.isEmpty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        Node v = q.poll();
        myAssert(v.depth == depth);
        sum += depth;
        if (v.left != null) {
          q.add(v.left);
        }
        if (v.right != null) {
          q.add(v.right);
        }
      }
      depth++;
    }
    return sum;
  }

  static void dfsSubCnt(Node root) {
    if (root == null) {
      return;
    }
    dfsSubCnt(root.left);
    dfsSubCnt(root.right);
    root.subcnt = 1 + (root.left == null ? 0 : root.left.subcnt)
        + (root.right == null ? 0 : root.right.subcnt);
  }

  static class Node {
    int v;
    Node p;
    Node left;
    Node right;

    // depth of v in the tree
    int depth;

    // number of node in the subtree rooted at v (inclusive)
    int subcnt;

    public Node(int v) {
      this.v = v;
      this.subcnt = 1;
    }

    public Node(int v, Node p) {
      this.v = v;
      this.p = p;
      this.depth = p.depth + 1;
      this.subcnt = 1;
    }

    @Override
    public
    String toString() {
      return Integer.toString(v);
    }
  }

  static void test(int n, int d) {
    int[] ans = solve(n, d);
    if (ans == null) {
      System.out.format("  %d %d => NO\n", n, d);
    } else {
      StringBuilder sb = new StringBuilder();
      for (int v : ans) {
        sb.append(v);
        sb.append(' ');
      }
      System.out.format("  %d %d => YES %s\n", n, d, sb.toString());
    }
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    test(36, 165);
    for (int t = 0; t < 20000; t++) {
      int n = 2 + RAND.nextInt(50);
      int d = 2 + RAND.nextInt(5000);
      test(n, d);
    }
    test(11, 27);
    test(12, 32);
    test(11, 39);
    test(12, 24);
    test(12, 55);
    test(11, 23);
    test(5, 6);
    test(11, 51);
    test(12, 25);
    test(11, 30);
    test(9, 20);
    test(9, 16);
    test(10, 37);
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      int d = in.nextInt();
      int[] ans = solve(n, d);
      output(ans);
    }
  }

  static void output(int[] a) {
    if (a == null) {
      System.out.println("NO");
      return;
    }
    StringBuilder sb = new StringBuilder();
    sb.append("YES\n");
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
