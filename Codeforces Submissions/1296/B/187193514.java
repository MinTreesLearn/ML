// package c1296;

//
// Codeforces Round #617 (Div. 3) 2020-02-04 06:35
// B. Food Buying
// https://codeforces.com/contest/1296/problem/B
// time limit per test 1 second; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// Mishka wants to buy some food in the nearby shop. Initially, he has s burles on his card.
//
// Mishka can perform the following operation any number of times (possibly, zero): choose some 1 <=
// x <= s, buy food that costs exactly x burles and obtain \lfloor\frac{x}{10}\rfloor burles as a
// cashback (in other words, Mishka spends x burles and obtains \lfloor\frac{x}{10}\rfloor back).
// The operation \lfloor\frac{a}{b}\rfloor means a divided by b rounded down.
//
// It is guaranteed that you can always buy some food that costs x for any possible value of x.
//
// Your task is to say the maximum number of burles Mishka can spend if he buys food optimally.
//
// For example, if Mishka has s=19 burles then the maximum number of burles he can spend is 21.
// Firstly, he can spend x=10 burles, obtain 1 burle as a cashback. Now he has s=10 burles, so can
// spend x=10 burles, obtain 1 burle as a cashback and spend it too.
//
// You have to answer t independent test cases.
//
// Input
//
// The first line of the input contains one integer t (1 <= t <= 10^4) -- the number of test cases.
//
// The next t lines describe test cases. Each test case is given on a separate line and consists of
// one integer s (1 <= s <= 10^9) -- the number of burles Mishka initially has.
//
// Output
//
// For each test case print the answer on it -- the maximum number of burles Mishka can spend if he
// buys food optimally.
//
// Example
/*
input:
6
1
10
19
9876
12345
1000000000
output:
1
11
21
10973
13716
1111111111
*/
//

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.Random;
import java.util.StringTokenizer;

public class C1296B {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int solve(int s) {
    int ans = 0;
    while (s >= 10) {
      int v = s / 10;
      ans += s - s % 10;
      s -= v * 9;
    }
    ans += s;
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
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int s = in.nextInt();
      int ans = solve(s);
      System.out.println(ans);
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
