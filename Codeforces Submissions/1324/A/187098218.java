// package c1324;

//
// Codeforces Round #627 (Div. 3) 2020-03-12 05:05
// A. Yet Another Tetris Problem
// https://codeforces.com/contest/1324/problem/A
// time limit per test 2 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// You are given some Tetris field consisting of n columns. The initial height of the i-th column of
// the field is a_i blocks. On top of these columns you can place figures of size 2 x 1 (i.e. the
// height of this figure is 2 blocks and the width of this figure is 1 block). Note that you rotate
// these figures.
//
// Your task is to say if you can clear the whole field by placing such figures.
//
// More formally, the problem can be described like this:
//
// The following process occurs while :
//  1. You place one figure 2 x 1 (choose some i from 1 to n and replace a_i with a_i + 2);
//  2. then, while all a_i are greater than zero, replace each a_i with a_i - 1.
//
// And your task is to determine if it is possible to clear the whole field (i.e. finish the
// described process), choosing the places for new figures properly.
//
// You have to answer t independent test cases.
//
// Input
//
// The first line of the input contains one integer t (1 <= t <= 100) -- the number of test cases.
//
// The next 2t lines describe test cases. The first line of the test case contains one integer n (1
// <= n <= 100) -- the number of columns in the Tetris field. The second line of the test case
// contains n integers a_1, a_2, ..., a_n (1 <= a_i <= 100), where a_i is the initial height of the
// i-th column of the Tetris field.
//
// Output
//
// For each test case, print the answer -- "YES" (without quotes) if you can clear the whole Tetris
// field and "NO" otherwise.
//
// Example
/*
input:
4
3
1 1 3
4
1 1 2 1
2
11 11
1
100
output:
YES
NO
YES
YES
*/
// Note
//
// The first test case of the example field is shown below:
//
// https://espresso.codeforces.com/c3b3d19786c16dfd52f9729d83217c7154a5852f.png
//
// Gray lines are bounds of the Tetris field. Note that the field has no upper bound.
//
// One of the correct answers is to first place the figure in the first column. Then after the
// second step of the process, the field becomes [2, 0, 2]. Then place the figure in the second
// column and after the second step of the process, the field becomes [0, 0, 0].
//
// And the second test case of the example field is shown below:
//
// https://espresso.codeforces.com/9e670fa3eabfebd5ecdfa6085157f1f4ccfe494e.png
//
// It can be shown that you cannot do anything to end the process.
//
// In the third test case of the example, you first place the figure in the second column after the
// second step of the process, the field becomes [0, 2]. Then place the figure in the first column
// and after the second step of the process, the field becomes [0, 0].
//
// In the fourth test case of the example, place the figure in the first column, then the field
// becomes [102] after the first step of the process, and then the field becomes [0] after the
// second step of the process.
//

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.Random;
import java.util.StringTokenizer;

public class C1324A {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static boolean solve(int[] a) {
    int n = a.length;
    for (int v : a) {
      int w = Math.abs(v - a[0]);
      if (w % 2 != 0) {
        return false;
      }
    }
    return true;
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
      int n = in.nextInt();
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt();
      }
      boolean ans = solve(a);
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
