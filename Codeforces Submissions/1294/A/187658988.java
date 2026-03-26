// package c1294;

//
// Codeforces Round #615 (Div. 3) 2020-01-22 06:35
// A. Collecting Coins
// https://codeforces.com/contest/1294/problem/A
// time limit per test 2 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// Polycarp has three sisters: Alice, Barbara, and Cerene. They're collecting coins. Currently,
// Alice has a coins, Barbara has b coins and Cerene has c coins. Recently Polycarp has returned
// from the trip around the world and brought n coins.
//
// He wants to distribute these n coins between his sisters in such a way that the number of coins
// Alice has is equal to the number of coins Barbara has and is equal to the number of coins Cerene
// has. In other words, if Polycarp gives A coins to Alice, B coins to Barbara and C coins to Cerene
// (A+B+C=n), then a + A = b + B = c + C.
//
// that A, B or C (the number of coins Polycarp gives to Alice, Barbara and Cerene correspondingly)
// can be 0.
//
// Your task is to find out if it is possible to distribute n coins between sisters in a way
// described above.
//
// You have to answer t independent test cases.
//
// Input
//
// The first line of the input contains one integer t (1 <= t <= 10^4) -- the number of test cases.
//
// The next t lines describe test cases. Each test case is given on a new line and consists of four
// space-separated integers a, b, c and n (1 <= a, b, c, n <= 10^8) -- the number of coins Alice
// has, the number of coins Barbara has, the number of coins Cerene has and the number of coins
// Polycarp has.
//
// Output
//
// For each test case, print "YES" if Polycarp can distribute n coins between his sisters and "NO"
// otherwise.
//
// Example
/*
input:
5
5 3 2 8
100 101 102 105
3 2 1 100000000
10 20 15 14
101 101 101 3
output:
YES
YES
NO
NO
YES
*/
//

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.Random;
import java.util.StringTokenizer;

public class C1294A {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static boolean solve(int a, int b, int c, int n) {
    int sum = a + b + c + n;
    if (sum % 3 != 0) {
      return false;
    }
    int m = sum / 3;
    return a <= m && b <= m && c <= m ? true : false;
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
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int a = in.nextInt();
      int b = in.nextInt();
      int c = in.nextInt();
      int n = in.nextInt();
      boolean ans = solve(a, b, c, n);
      System.out.println(ans? "YES" : "NO");
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
