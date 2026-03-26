// package c1311;

//
// Codeforces Round #624 (Div. 3) 2020-02-24 06:35
// F. Moving Points
// https://codeforces.com/contest/1311/problem/F
// time limit per test 2 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// There are n points on a coordinate axis OX. The i-th point is located at the integer point x_i
// and has a speed v_i. It is guaranteed that no two points occupy the same coordinate. All n points
// move with the constant speed, the coordinate of the i-th point at the moment t (t ) is calculated
// as x_i + t * v_i.
//
// Consider two points i and j. Let d(i, j) be the minimum possible distance between these two
// points over any possible moments of time (even ). It means that if two points i and j coincide at
// some moment, the value d(i, j) will be 0.
//
// Your task is to calculate the value \sum\limits_{1 <= i < j <= n} d(i, j) (the sum of minimum
// distances over all pairs of points).
//
// Input
//
// The first line of the input contains one integer n (2 <= n <= 2 * 10^5) -- the number of points.
//
// The second line of the input contains n integers x_1, x_2, ..., x_n (1 <= x_i <= 10^8), where x_i
// is the initial coordinate of the i-th point. It is guaranteed that all x_i are distinct.
//
// The third line of the input contains n integers v_1, v_2, ..., v_n (-10^8 <= v_i <= 10^8), where
// v_i is the speed of the i-th point.
//
// Output
//
// Print one integer -- the value \sum\limits_{1 <= i < j <= n} d(i, j) (the sum of minimum
// distances over all pairs of points).
//
// Example
/*
input:
3
1 3 2
-100 2 3
output:
3

input:
5
2 1 4 3 5
2 2 2 3 4
output:
19

input:
2
2 1
-3 0
output:
0
*/
//

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.StringTokenizer;

public class C1311F {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static long solve(int[] x, int[] v) {
    int n = x.length;
    long ans = 0;
    List<int[]> points = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      points.add(new int[] {x[i], v[i]});
    }
    Collections.sort(points, (y, z) -> y[1] - z[1]);
    // normalize and compact speed into [1,m)
    int m = 1;
    int b = 0;
    while (b < n) {
      int e = b + 1;
      while (e < n && points.get(e)[1] == points.get(b)[1]) {
        e++;
      }
      for (int i = b; i < e; i++) {
        points.get(i)[1] = m;
      }
      m++;
      b = e;
    }
    // Sort by ascending x
    Collections.sort(points, (y, z) -> y[0] - z[0]);
    // System.out.format("  points:%s\n", Utils.traceListIntArray(points));

    FenwickTree ftCnt = new FenwickTree(m);
    FenwickTree ftX = new FenwickTree(m);

    long sumx = 0;
    for (int i = n-1; i >= 0; i--) {
      int xi = points.get(i)[0];
      int vi = points.get(i)[1];
      //   .  .  .  .  .  .  .
      //      ^        ^
      //      xi       xj

      // how many points with speed >= vi
      long cnt = n-1-i - ftCnt.sum(vi - 1);
      long sum = sumx - ftX.sum(vi - 1);
      ans += sum - xi * cnt;
      sumx += xi;
      ftCnt.add(vi, 1);
      ftX.add(vi, xi);
    }
    return ans;
  }

  static class FenwickTree {
    private long[] arr;
    private final int n;

    public FenwickTree(int n) {
      this.n = n;
      // caller valid index range is [0,n-1]
      // the n + 1 here is for internal convenience
      this.arr = new long[n + 1];
    }

    public FenwickTree(int[] nums) {
      this(nums.length);
      for (int i = 0; i < n; ++i) {
        this.add(i, nums[i]);
      }
    }

    static int next(int idx) {
      // round up the last section of 1s, for example:
      // 10110 -> 10110 + 11...101010 & 10110 = 10110 + 10 = 11000
      return idx + (-idx & idx);
    }

    static int parent(int idx) {
      // Trim the last 1
      return idx - (-idx & idx);
    }

    // Increase value at index by delta
    public void add(int index, int delta) {
      index++;
      while (index <= n) {
        arr[index] += delta;
        index = next(index);
      }
    }

    // get sum of elements arr[0..index], inclusive. index < n (size - 1)
    public long sum(int index) {
      index = Math.min(index + 1, n);
      long ans = 0;
      while (index > 0) {
        ans += arr[index];
        index = parent(index);
      }
      return ans;
    }
  }

  static long solveB(int[] x, int[] v) {
    int n = x.length;
    long ans = 0;
    List<int[]> points = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      points.add(new int[] {x[i], v[i]});
    }
    Collections.sort(points, (y, z)->y[0]-z[0]);
    // System.out.format("  points:%s\n", Utils.traceListIntArray(points));
    for (int i = 0; i < n; i++) {
      int xi = points.get(i)[0];
      int vi = points.get(i)[1];
      for (int j = i + 1; j < n; j++) {
        int xj = points.get(j)[0];
        int vj = points.get(j)[1];
        //   .  .  .  .  .  .  .
        //      ^        ^
        //      xi       xj
        if (vi <= vj) {
          ans += xj - xi;
        }
      }
    }
    return ans;
  }

  static long solveNaive(int[] x, int[] v) {
    int n = x.length;
    long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (x[i] < x[j]) {
          //   .  .  .  .  .  .  .
          //      ^        ^
          //      xi       xj
          if (v[i] <= v[j]) {
            ans += x[j] - x[i];
          }
        } else if (x[i] == x[j]) {
        } else {
          //   .  .  .  .  .  .  .
          //      ^        ^
          //     xj        xi
          if (v[j] <= v[i]) {
            ans += x[i] - x[j];
          }
        }
      }
    }
    return ans;
  }

  static String trace(int[][] a) {
    return Arrays.deepToString(a).replace(" ", "").replace('[', '{').replace(']', '}');
  }

  static String trace(int[] a) {
    return Arrays.toString(a).replace(" ", "").replace('[', '{').replace(']', '}');
  }

  static void test(long exp, int[] x, int[] v) {
    long ans = solve(x, v);
    System.out.format("x:%s v:%s => %d %s\n", trace(x), trace(v), ans, ans == exp ? "":"Expected " + exp);
    myAssert(ans ==exp);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    test(3, new int[] {1,3,2}, new int[] {-100,2,3});
    test(19, new int[] {2,1,4,3,5}, new int[] {2,2,2,3,4});
    test(0, new int[] {2,1}, new int[] {-3,0});
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int[] x = new int[n];
    for (int i = 0; i < n; i++) {
      x[i] = in.nextInt();
    }
    int[] v = new int[n];
    for (int i = 0; i < n; i++) {
      v[i] = in.nextInt();
    }
    long ans = solve(x, v);
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
