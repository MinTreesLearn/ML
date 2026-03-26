// package c1296;

//
// Codeforces Round #617 (Div. 3) 2020-02-04 06:35
// E2. String Coloring (hard version)
// https://codeforces.com/contest/1296/problem/E2
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
// Your task is to find the minimum number of colors which you have to color the given string in so
// that after coloring it can become sorted by sequence of swaps. Note that you have to restore only
// coloring, not the sequence of swaps.
//
// Input
//
// The first line of the input contains one integer n (1 <= n <= 2 * 10^5) -- the length of s.
//
// The second line of the input contains the string s consisting of exactly n lowercase Latin
// letters.
//
// Output
//
// In the first line print one integer res (1 <= res <= n) -- the minimum number of colors in which
// you have to color the given string so that after coloring it can become sorted by sequence of
// swaps.
//
// In the second line print possible coloring that can be used to sort the string using some
// sequence of swaps described in the problem statement. The coloring is the array c of length n,
// where 1 <= c_i <= res and c_i means the color of the i-th character.
//
// Example
/*
input:
9
abacbecfd
output:
2
1 1 2 1 2 1 2 1 2

input:
8
aaabbcbb
output:
2
1 2 1 2 1 2 1 1

input:
7
abcdedc
output:
3
1 1 1 1 1 2 3

input:
5
abcde
output:
1
1 1 1 1 1
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
import java.util.Map;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class C1296E2 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static final int NOCOLOR = 2;

  static int[] solve(String s) {
    int n = s.length();
    // Array of (src_index, character, color, dst_index)
    List<int[]> arr = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      arr.add(new int[] {i, s.charAt(i) - 'a', NOCOLOR, 0});
    }
    Collections.sort(arr, (x,y)->x[1] != y[1] ? x[1] - y[1] : x[0] - y[0]);
    for (int i = 0; i < n; i++) {
      arr.get(i)[3] = i;
    }
    if (test) System.out.format("  arr:%s %s\n", traceListIntArray(arr), getStr(arr));

    // Map from valuie to longest descending sequence in tail
    TreeMap<Integer, Integer> vsm = new TreeMap<>();
    int[] ans = new int[n];
    int[] cnt = new int[n];
    for (int i = n - 1; i >= 0; i--) {
      int v = arr.get(i)[0];
      Map.Entry<Integer, Integer> fe = vsm.floorEntry(v);
      if (fe == null) {
        vsm.put(v, 1);
      } else {
        vsm.put(v, fe.getValue() + 1);
      }
      int value = vsm.get(v);
      int w = v + 1;
      while (true) {
        Map.Entry<Integer, Integer> ce = vsm.ceilingEntry(w);
        if (ce == null || ce.getValue() > value) {
          break;
        } else {
          vsm.remove(ce.getKey());
        }
      }
      cnt[v] = value;
      ans[v] = value;
    }
    return ans;
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

  static void test(int exp, String s) {
    int[] ans = solve(s);
    int maxv = ans[0];
    for (int v : ans) {
      maxv = Math.max(maxv, v);
    }
    System.out.format("%s => %s\n", s, Arrays.toString(ans), maxv == exp ? "":"Expected " + exp);
    myAssert(exp == maxv);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();

    test(2, "abacbecfd");
    test(2, "aaabbcbb");
    test(3, "abcdedc");
    test(1, "abcde");

    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    String s = in.next();
    int[] ans = solve(s);
    output(ans);
  }

  static void output(int[] a) {
    int maxv = a[0];
    for (int v : a) {
      maxv = Math.max(maxv, v);
    }
    StringBuilder sb = new StringBuilder();
    sb.append(maxv);
    sb.append('\n');
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
