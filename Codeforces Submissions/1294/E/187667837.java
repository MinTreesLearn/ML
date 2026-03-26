// package c1294;

//
// Codeforces Round #615 (Div. 3) 2020-01-22 06:35
// E. Obtain a Permutation
// https://codeforces.com/contest/1294/problem/E
// time limit per test 2 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// You are given a rectangular matrix of size n x m consisting of integers from 1 to 2 * 10^5.
//
// In one move, you can:
//  * choose of the matrix and change its value to integer between 1 and n * m, inclusive;
//  * take and shift it one cell up cyclically (see the example of such cyclic shift below).
//
// A cyclic shift is an operation such that you choose some j (1 <= j <= m) and set a_{1, j} :=
// a_{2, j}, a_{2, j} := a_{3, j}, ..., a_{n, j} := a_{1, j} .
// https://espresso.codeforces.com/874a76a681a525102f53f73c046f306bcc2f1b6d.png Example of cyclic
// shift of the first column
//
// You want to perform the minimum number of moves to make this matrix look like this:
// https://espresso.codeforces.com/886b8c37bc9a14c44d2c736abb7a98b18d00de3d.png
//
// In other words, the goal is to obtain the matrix, where a_{1, 1} = 1, a_{1, 2} = 2, ..., a_{1, m}
// = m, a_{2, 1} = m + 1, a_{2, 2} = m + 2, ..., a_{n, m} = n * m (i.e. a_{i, j} = (i - 1) * m + j)
// with the performed.
//
// Input
//
// The first line of the input contains two integers n and m (1 <= n, m <= 2 * 10^5, n * m <= 2 *
// 10^5) -- the size of the matrix.
//
// The next n lines contain m integers each. The number at the line i and position j is a_{i, j} (1
// <= a_{i, j} <= 2 * 10^5).
//
// Output
//
// Print one integer -- the minimum number of moves required to obtain the matrix, where a_{1, 1} =
// 1, a_{1, 2} = 2, ..., a_{1, m} = m, a_{2, 1} = m + 1, a_{2, 2} = m + 2, ..., a_{n, m} = n * m
// (a_{i, j} = (i - 1)m + j).
//
// Example
/*
input:
3 3
3 2 1
1 2 3
4 5 6
output:
6

input:
4 3
1 2 3
4 5 6
7 8 9
10 11 12
output:
0

input:
3 4
1 6 3 4
5 10 7 8
9 2 11 12
output:
2
*/
// Note
//
// In the first example, you can set a_{1, 1} := 7, a_{1, 2} := 8 and a_{1, 3} := 9 then shift the
// first, the second and the third columns cyclically, so the answer is 6. It can be shown that you
// cannot achieve a better answer.
//
// In the second example, the matrix is already good so the answer is 0.
//
// In the third example, it is enough to shift the second column cyclically twice to obtain a good
// matrix, so the answer is 2.
//

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.StringTokenizer;

public class C1294E {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int solve(int[][] a) {
    int n = a.length;
    int m = a[0].length;
    int ans = 0;
    for (int j = 0; j < m; j++) {
      Map<Integer, List<Integer>> vcm = new HashMap<>();
      int total = 0;
      for (int i = 0; i < n; i++) {
        int v = a[i][j] - 1;
        // target range of the column
        int min = j;
        int max = j + (n-1) * m;
        if (v < min || v > max || v % m != j) {
          // v must be replaced regardless shift amount
          ans++;
          if (test) System.out.format("  j:%d i:%d v:%d replace ans:%d\n", j, i, v + 1, ans);
        } else {
          total++;
          int w = (n + ((j + i * m) - (a[i][j] - 1)) / m) % n;
          vcm.computeIfAbsent(w,  x -> new ArrayList<>()).add(i);
        }
      }
      int cost = total;
      for (Map.Entry<Integer, List<Integer>> e : vcm.entrySet()) {
        int v = e.getKey();
        List<Integer> idxes = e.getValue();
        int k = (n + v) % n;
        // If we shift up by k, this group is happy
        int z = k + (total - idxes.size());
        cost = Math.min(cost, z);
        if (test) System.out.format("  j:%d v:%2d k:%d z:%2d cost:%d idxes:%s\n", j, v, k, z, cost, idxes.toString());
      }
      ans += cost;
    }
    return ans;
  }

  static String trace(int[][] a) {
    return Arrays.deepToString(a).replace(" ", "").replace('[', '{').replace(']', '}');
  }

  static String trace(int[] a) {
    return Arrays.toString(a).replace(" ", "").replace('[', '{').replace(']', '}');
  }

  static int solveNaive(int[][] a) {
    int n = a.length;
    int m = a[0].length;
    int ans = 0;
    for (int j = 0; j < m; j++) {
      int cost = n + 1;
      int minh = -1;
      for (int h = 0; h < n; h++) {
        int cnt = h;
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
          int v = a[(i+h)%n][j];
          nums[i] = v;
          int e = j + i * m + 1;
          if (v != e) {
            cnt++;
          }
        }
        if (cnt < cost) {
          cost = cnt;
          minh = h;
        }
        System.out.format("  j:%d h:%d cnt:%2d %s\n", j, h, cnt, trace(nums));
      }
      ans += cost;
    }
    return ans;
  }

  static void test(int[][] a) {
    int ans = solve(a);
    int exp = solveNaive(a);
    System.out.format("%s => %d %s\n", trace(a), ans, ans == exp ? "":"Expected " + exp);
    myAssert(ans == exp);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    test(new int[][] {{9,7,8,5},{3,8,2,3},{9,2,9,7}});
    for (int t = 0; t < 20; t++) {
      int n = 1 + RAND.nextInt(10);
      int m = 1 + RAND.nextInt(10);
      int[][] a = new int[n][m];
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          a[i][j] = 1 + RAND.nextInt(9);
        }
      }
      test(a);
    }

    test(new int[][] {{3,2,1},{1,2,3},{4,5,6}});
    test(new int[][] {{5},{6},{7},{8},{9},{1},{2},{3},{4}});
    test(new int[][] {{5},{6},{7},{8},{9},{2},{2},{3},{4}});
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int m = in.nextInt();
    int[][] a = new int[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = in.nextInt();
      }
    }
    int ans = solve(a);
    System.out.println(ans);
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
