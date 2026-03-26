// package c1311;

//
// Codeforces Round #624 (Div. 3) 2020-02-24 06:35
// A. Add Odd or Subtract Even
// https://codeforces.com/contest/1311/problem/A
// time limit per test 2 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// You are given two positive integers a and b.
//
// In one move, you can a in the following way:
//  * Choose any positive integer x (x > 0) and replace a with a+x;
//  * choose any positive integer y (y > 0) and replace a with a-y.
//
// You can perform as many such operations as you want. You can choose the same numbers x and y in
// different moves.
//
// Your task is to find the minimum number of moves required to obtain b from a. It is guaranteed
// that you can always obtain b from a.
//
// You have to answer t independent test cases.
//
// Input
//
// The first line of the input contains one integer t (1 <= t <= 10^4) -- the number of test cases.
//
// Then t test cases follow. Each test case is given as two space-separated integers a and b (1 <=
// a, b <= 10^9).
//
// Output
//
// For each test case, print the answer -- the minimum number of moves required to obtain b from a
// if you can perform any number of moves described in the problem statement. It is guaranteed that
// you can always obtain b from a.
//
// Example
/*
input:
5
2 3
10 10
2 4
7 4
9 3
output:
1
0
2
2
1
*/
// Note
//
// In the first test case, you can just add 1.
//
// In the second test case, you don't need to do anything.
//
// In the third test case, you can add 1 two times.
//
// In the fourth test case, you can subtract 4 and add 1.
//
// In the fifth test case, you can just subtract 6.
//

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.Random;
import java.util.StringTokenizer;

public class C1311A {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int solve(int a, int b) {
    if (a == b) {
      return 0;
    } else if (a < b) {
      if (a % 2 == 0 && b % 2 == 0) {
        // 4 -> 10
        return 2;
      } else if (a % 2 == 0 && b % 2 == 1) {
        // 4 -> 5
        return 1;
      } else if (a % 2 == 1 && b % 2 == 0) {
        // 5 -> 6
        return 1;
      } else {
        // 5 -> 7
        return 2;
      }
    } else {
      if (a % 2 == 0 && b % 2 == 0) {
        // 10 -> 4
        return 1;
      } else if (a % 2 == 0 && b % 2 == 1) {
        // 6 -> 5
        return 2;
      } else if (a % 2 == 1 && b % 2 == 0) {
        // 7 -> 6
        return 2;
      } else {
        // 7 -> 5
        return 1;
      }
    }
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
      int ans = solve(a, b);
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
