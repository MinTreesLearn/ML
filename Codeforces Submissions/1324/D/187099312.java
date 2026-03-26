// package c1324;

//
// Codeforces Round #627 (Div. 3) 2020-03-12 05:05
// D. Pair of Topics
// https://codeforces.com/contest/1324/problem/D
// time limit per test 2 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// The next lecture in a high school requires two topics to be discussed. The i-th topic is
// interesting by a_i units for the teacher and by b_i units for the students.
//
// The pair of topics i and j (i < j) is called if a_i + a_j > b_i + b_j (i.e. it is more
// interesting for the teacher).
//
// Your task is to find the number of pairs of topics.
//
// Input
//
// The first line of the input contains one integer n (2 <= n <= 2 * 10^5) -- the number of topics.
//
// The second line of the input contains n integers a_1, a_2, ..., a_n (1 <= a_i <= 10^9), where a_i
// is the interestingness of the i-th topic for the teacher.
//
// The third line of the input contains n integers b_1, b_2, ..., b_n (1 <= b_i <= 10^9), where b_i
// is the interestingness of the i-th topic for the students.
//
// Output
//
// Print one integer -- the number of pairs of topic.
//
// Example
/*
input:
5
4 8 2 6 2
4 5 4 1 3
output:
7

input:
4
1 3 2 4
1 3 2 4
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
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.StringTokenizer;

public class C1324D {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static long solve(int[] a, int[] b) {
    int n = a.length;
    List<Integer> nums = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      nums.add(a[i]-b[i]);
    }
    Collections.sort(nums);
    // System.out.format("  nums:%s\n", nums.toString());
    long ans = 0;
    int j = n;
    for (int i = 0; i < n; i++) {
      int v = nums.get(i);
      j = Math.max(i+1, j);
      while (j - 1 > i && nums.get(j-1) + v > 0) {
        j--;
      }
      // System.out.format("  i:%d j:%d\n", i, j);
      ans += n - j;
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
    int[] b = new int[n];
    for (int i = 0; i < n; i++) {
      b[i] = in.nextInt();
    }
    long ans = solve(a, b);
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
