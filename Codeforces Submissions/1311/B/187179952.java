// package c1311;

//
// Codeforces Round #624 (Div. 3) 2020-02-24 06:35
// B. WeirdSort
// https://codeforces.com/contest/1311/problem/B
// time limit per test 2 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// You are given an array a of length n.
//
// You are also given a set of positions p_1, p_2, ..., p_m, where 1 <= p_i < n. The position p_i
// means that you can swap elements a[p_i] and a[p_i + 1]. You can apply this operation any number
// of times for each of the given .
//
// Your task is to determine if it is possible to sort the initial array in non-decreasing order
// (a_1 <= a_2 <= ... <= a_n) using only allowed swaps.
//
// For example, if a = [3, 2, 1] and p = [1, 2], then we can first swap elements a[2] and a[3]
// (because position 2 is contained in the given set p). We get the array a = [3, 1, 2]. Then we
// swap a[1] and a[2] (position 1 is also contained in p). We get the array a = [1, 3, 2]. Finally,
// we swap a[2] and a[3] again and get the array a = [1, 2, 3], sorted in non-decreasing order.
//
// You can see that if a = [4, 1, 2, 3] and p = [3, 2] then you cannot sort the array.
//
// You have to answer t independent test cases.
//
// Input
//
// The first line of the input contains one integer t (1 <= t <= 100) -- the number of test cases.
//
// Then t test cases follow. The first line of each test case contains two integers n and m (1 <= m
// < n <= 100) -- the number of elements in a and the number of elements in p. The second line of
// the test case contains n integers a_1, a_2, ..., a_n (1 <= a_i <= 100). The third line of the
// test case contains m integers p_1, p_2, ..., p_m (1 <= p_i < n, all p_i are distinct) -- the set
// of positions described in the problem statement.
//
// Output
//
// For each test case, print the answer -- "YES" (without quotes) if you can sort the initial array
// in non-decreasing order (a_1 <= a_2 <= ... <= a_n) using only allowed swaps. Otherwise, print
// "NO".
//
// Example
/*
input:
6
3 2
3 2 1
1 2
4 2
4 1 2 3
3 2
5 1
1 2 3 4 5
1
4 2
2 1 4 3
1 3
4 2
4 3 2 1
1 3
5 2
2 1 2 3 3
1 4
output:
YES
NO
YES
YES
NO
YES
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

public class C1311B {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static boolean solve(int[] a, int[] p) {
    int n = a.length;
    boolean[] ok = new boolean[n];
    for (int v : p) {
      ok[v] = true;
    }
    List<Integer> nums = new ArrayList<>();
    List<Integer> curr = new ArrayList<>();

    // .  .  x  x  .  .  x  .  .
    //          ^
    //          e

    for (int i = 0; i < n; i++) {
      curr.add(a[i]);
      if (!ok[i]) {
        Collections.sort(curr);
        nums.addAll(curr);
        curr.clear();
      }
    }
    Collections.sort(curr);
    nums.addAll(curr);
    for (int i = 1; i < n; i++) {
      if (nums.get(i) < nums.get(i-1)) {
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
      int m = in.nextInt();
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt() - 1;
      }
      int[] p = new int[m];
      for (int i = 0; i < m; i++) {
        p[i] = in.nextInt() - 1;
      }
      boolean ans = solve(a, p);
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
