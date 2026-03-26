// package c1296;

//
// Codeforces Round #617 (Div. 3) 2020-02-04 06:35
// E1. String Coloring (easy version)
// https://codeforces.com/contest/1296/problem/E1
// time limit per test 1 second; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// .
//
// You are given a string s consisting of n lowercase Latin letters.
//
// You have to color its characters (each character to exactly one color, the same letters can be
// colored the same or different colors, i.e. you can choose exactly one color for each index in s).
//
// After coloring, you can swap two neighboring characters of the string that are colored colors.
// You can perform such an operation arbitrary (possibly, zero) number of times.
//
// The goal is to make the string sorted, i.e. all characters should be in alphabetical order.
//
// Your task is to say if it is possible to color the given string so that after coloring it can
// become sorted by sequence of swaps. Note that you have to restore only coloring, not the sequence
// of swaps.
//
// Input
//
// The first line of the input contains one integer n (1 <= n <= 200) -- the length of s.
//
// The second line of the input contains the string s consisting of exactly n lowercase Latin
// letters.
//
// Output
//
// If it is impossible to color the given string so that after coloring it can become sorted by
// sequence of swaps, print "NO" (without quotes) in the first line.
//
// Otherwise, print "YES" in the first line and correct coloring in the second line (the coloring is
// the string consisting of n characters, the i-th character should be '0' if the i-th character is
// colored the first color and '1' otherwise).
//
// Example
/*
input:
9
abacbecfd
output:
YES
001010101

input:
8
aaabbcbb
output:
YES
01011011

input:
7
abcdedc
output:
NO

input:
5
abcde
output:
YES
00000
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

public class C1296E1 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static final int NOCOLOR = 2;

  static String solve(String s) {
    int n = s.length();
    // Array of (src_index, character, color, dst_index)
    List<int[]> arr = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      arr.add(new int[] {i, s.charAt(i) - 'a', NOCOLOR, 0});
    }
    Collections.sort(arr, (x,y)->x[1] != y[1] ? x[1] - y[1] : x[0] - y[0]);
    if (test) System.out.format("  arr:%s %s\n", traceListIntArray(arr), getStr(arr));
    for (int i = 0; i < n; i++) {
      arr.get(i)[3] = i;
    }
    Collections.sort(arr, (x,y) -> x[0] - y[0]);
    if (test) System.out.format("  arr:%s %s\n", traceListIntArray(arr), getStr(arr));

    for (int i = 0; i < n; i++) {
      if (arr.get(i)[3] == i) {
        continue;
      }
      // src: a a b b c e c f d
      // dst: a a b b c c d e f
      //                ^
      //                i
      //
      int j = i + 1;
      for (; j < n; j++) {
        if (arr.get(j)[3] == i) {
          break;
        }
      }
      if (test) System.out.format("  i:%d j:%d\n", i, j);
      myAssert(j > i);
      myAssert(j < n);

      // j should be moved to position i

      // . . . . . . .
      //   ^     ^
      //   i     j
      //   -----
      //   ^   ^
      //   b   e

      if (arr.get(j)[2] != NOCOLOR) {
        // j is already colored
        int color = 1 - arr.get(j)[2];
        for (int h = i; h < j; h++) {
          if (arr.get(h)[2] != NOCOLOR && arr.get(h)[2] != color) {
            return null;
          }
          arr.get(h)[2] = color;
        }
      } else {
        int color = NOCOLOR;
        for (int h = i; h < j; h++) {
          if (arr.get(h)[2] != NOCOLOR) {
            color = arr.get(h)[2];
            break;
          }
        }
        if (color != NOCOLOR) {
          for (int h = i; h < j; h++) {
            if (arr.get(h)[2] != NOCOLOR && arr.get(h)[2] != color) {
              return null;
            }
            arr.get(h)[2] = color;
          }
          arr.get(j)[2] = 1 - color;
        } else {
          for (int h = i; h < j; h++) {
            arr.get(h)[2] = 0;
          }
          arr.get(j)[2] = 1;
        }

        int[] t = arr.get(j);
        arr.remove(j);
        arr.add(i, t);
        if (test) System.out.format("  i:%d j:%d %s %s\n", i, j, traceListIntArray(arr), getStr(arr));
      }
    }
    char[] ans = new char[n];
    for (int[] v : arr) {
      ans[v[0]] = v[2] == NOCOLOR ? '0' : (char) ('0' + v[2]);
    }
    return new String(ans);
  }

  public static String traceListIntArray(List<int[]> points) {
    StringBuilder sb = new StringBuilder();
    sb.append('[');
    boolean first = true;
    for (int[] v : points) {
      if (!first) {
        sb.append(',');
      }
      first = false;
      sb.append('[');
      boolean first2 = true;
      for (int w : v) {
        if (!first2) {
          sb.append(',');
        }
        sb.append(w);
        first2 = false;
      }

      sb.append(']');
    }
    sb.append(']');
    return sb.toString();
  }

  static String getStr(List<int[]> arr) {
    StringBuilder sb = new StringBuilder();
    for (int[] v : arr) {
      sb.append((char)('a' + v[1]));
    }
    return sb.toString();
  }

  static void test(boolean ok, String s) {
    String ans = solve(s);
    if (ans == null) {
      System.out.format("%s => NO\n", s);
    } else {
      System.out.format("%s => YES %s\n", s, ans);
    }
    myAssert((ok && ans != null) || (!ok && ans == null));
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();

    test(true, "abacbecfd");
    test(true, "aaabbcbb");
    test(false, "abcdedc");
    test(true, "abcde");

    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    String s = in.next();
    String ans = solve(s);
    System.out.println(ans == null ? "NO" : "YES\n" + ans);
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
