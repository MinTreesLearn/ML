// package c1324;

//
// Codeforces Round #627 (Div. 3) 2020-03-12 05:05
// C. Frog Jumps
// https://codeforces.com/contest/1324/problem/C
// time limit per test 2 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// There is a frog staying to the left of the string s = s_1 s_2 ... s_n consisting of n characters
// (to be more precise, the frog initially stays at the cell 0). Each character of s is either 'L'
// or 'R'. It means that if the frog is staying at the i-th cell and the i-th character is 'L', the
// frog can jump only to the left. If the frog is staying at the i-th cell and the i-th character is
// 'R', the frog can jump only to the right. .
//
// .
//
// The frog wants to reach the n+1-th cell. The frog chooses some value d (and cannot change it
// later) and jumps by no more than d cells at once. I.e. if the i-th character is 'L' then the frog
// can jump to any cell in a range [max(0, i - d); i - 1], and if the i-th character is 'R' then the
// frog can jump to any cell in a range [i + 1; min(n + 1; i + d)].
//
// The frog doesn't want to jump far, so your task is to find the minimum possible value of d such
// that the frog can reach the cell n+1 from the cell 0 if it can jump by no more than d cells at
// once. .
//
// You have to answer t independent test cases.
//
// Input
//
// The first line of the input contains one integer t (1 <= t <= 10^4) -- the number of test cases.
//
// The next t lines describe test cases. The i-th test case is described as a string s consisting of
// at least 1 and at most 2 * 10^5 characters 'L' and 'R'.
//
// It is guaranteed that the sum of lengths of strings over all test cases does not exceed 2 * 10^5
// (\sum |s| <= 2 * 10^5).
//
// Output
//
// For each test case, print the answer -- the minimum possible value of d such that the frog can
// reach the cell n+1 from the cell 0 if it jumps by no more than d at once.
//
// Example
/*
input:
6
LRLRRLL
L
LLR
RRRR
LLLLLL
R
output:
3
2
3
1
7
1
*/
// Note
//
// The picture describing the first test case of the example and one of the possible answers:
//
// https://espresso.codeforces.com/de84e2ea205b39d12a73b422b7f6b0229de451ba.png
//
// In the second test case of the example, the frog can only jump directly from 0 to n+1.
//
// In the third test case of the example, the frog can choose d=3, jump to the cell 3 from the cell
// 0 and then to the cell 4 from the cell 3.
//
// In the fourth test case of the example, the frog can choose d=1 and jump 5 times to the right.
//
// In the fifth test case of the example, the frog can only jump directly from 0 to n+1.
//
// In the sixth test case of the example, the frog can choose d=1 and jump 2 times to the right.
//

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.Random;
import java.util.StringTokenizer;

public class C1324C {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int solve(String s) {
    int n = s.length();
    int ans = 0;
    int maxd = 0;
    int prev = -1;
    for (int i = 0; i < n; i++) {
      if (s.charAt(i) == 'R') {
        maxd = Math.max(maxd, i - prev);
        prev = i;
      }
    }
    maxd = Math.max(maxd, n - prev);
    return maxd;
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
      String s = in.next();
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
