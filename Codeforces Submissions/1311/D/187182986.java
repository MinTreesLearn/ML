// package c1311;

//
// Codeforces Round #624 (Div. 3) 2020-02-24 06:35
// D. Three Integers
// https://codeforces.com/contest/1311/problem/D
// time limit per test 2 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// You are given three integers a <= b <= c.
//
// In one move, you can add +1 or -1 to of these integers (i.e. increase or decrease any number by
// one). You can perform such operation any (possibly, zero) number of times, you can even perform
// this operation several times with one number. .
//
// You have to perform the minimum number of such operations in order to obtain three integers A <=
// B <= C such that B is divisible by A and C is divisible by B.
//
// You have to answer t independent test cases.
//
// Input
//
// The first line of the input contains one integer t (1 <= t <= 100) -- the number of test cases.
//
// The next t lines describe test cases. Each test case is given on a separate line as three
// space-separated integers a, b and c (1 <= a <= b <= c <= 10^4).
//
// Output
//
// For each test case, print the answer. In the first line print res -- the minimum number of
// operations you have to perform to obtain three integers A <= B <= C such that B is divisible by A
// and C is divisible by B. On the second line print suitable triple A, B and C.
//
// Example
/*
input:
8
1 2 3
123 321 456
5 10 15
15 18 21
100 100 101
1 22 29
3 19 38
6 30 46
output:
1
1 1 3
102
114 228 456
4
4 8 16
6
18 18 18
1
100 100 100
7
1 22 22
2
1 19 38
8
6 24 48
*/
//

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.StringTokenizer;

public class C1311D {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static List<Integer>[] DIVS = computeDivisors(20000);

  static int[] solve(int a, int b, int c) {
    int[] ans = new int[4];
    // a,b,c in [1,10000]
    ans[0] = 50000;

    // Evaluate possible values of the middle number
    for (int v = 1; v <= 20000; v++) {
      if (Math.abs(b - v) >= ans[0]) {
        continue;
      }
      int[] curr = new int[] {a, a, v, c};
      for (int x : DIVS[v]) {
        if (Math.abs(a - x) < curr[0]) {
          curr[0] = Math.abs(a - x);
          curr[1] = x;
        }
      }
      curr[0] += Math.abs(b - v);
      int r = c % v;
      if (c < v) {
        curr[0] += v - c;
        curr[3] = v;
      } else if (r != 0) {
        if (r <= v - r) {
          curr[0] += r;
          curr[3] = c - r;
        } else {
          curr[0] += v - r;
          curr[3] = c + (v - r);
        }
      }
      if (curr[0] < ans[0]) {
        ans = curr;
      }
    }
    return ans;
  }

  static List<Integer>[] computeDivisors(int n) {
    List<Integer>[] divs = new ArrayList[n + 1];
    for (int i = 0; i <= n; i++) {
      divs[i] = new ArrayList<>();
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j += i) {
        divs[j].add(i);
      }
    }
    return divs;
  }

  static void test(int[] exp, int a, int b, int c) {
    int[] ans = solve(a, b, c);
    boolean ok = exp[0] == ans[0] && exp[1] == ans[1] && exp[2] == ans[2] && exp[3] == ans[3];
    System.out.format("%d %d %d => %d %d %d %d %s\n",
        a, b, c, ans[0], ans[1], ans[2], ans[3],
        ok ? "":"Expected " + exp[0] + " " + exp[1] + " " + exp[2] + " " + exp[3]);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    test(new int[] {2, 137, 10001, 10001}, 137, 10000, 10000);
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int a = in.nextInt();
      int b = in.nextInt();
      int c = in.nextInt();
      int[] ans = solve(a, b, c);
      System.out.format("%d\n%d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
    }
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
