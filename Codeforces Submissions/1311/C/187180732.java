// package c1311;

//
// Codeforces Round #624 (Div. 3) 2020-02-24 06:35
// C. Perform the Combo
// https://codeforces.com/contest/1311/problem/C
// time limit per test 2 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// You want to perform the combo on your opponent in one popular fighting game. The combo is the
// string s consisting of n lowercase Latin letters. To perform the combo, you have to press all
// buttons in the order they appear in s. I.e. if s="abca" then you have to press 'a', then 'b', 'c'
// and 'a' again.
//
// You know that you will spend m wrong tries to perform the combo and during the i-th try you will
// make a mistake right after p_i-th button (1 <= p_i < n) (i.e. you will press first p_i buttons
// right and start performing the combo from the beginning). It is guaranteed that during the m+1-th
// try you press all buttons right and finally perform the combo.
//
// I.e. if s="abca", m=2 and p = [1, 3] then the sequence of pressed buttons will be 'a' ( you're
// making a mistake and start performing the combo from the beginning), 'a', 'b', 'c', ( you're
// making a mistake and start performing the combo from the beginning), 'a' (), 'b', 'c', 'a'.
//
// Your task is to calculate for each button (letter) the number of times you'll press it.
//
// You have to answer t independent test cases.
//
// Input
//
// The first line of the input contains one integer t (1 <= t <= 10^4) -- the number of test cases.
//
// Then t test cases follow.
//
// The first line of each test case contains two integers n and m (2 <= n <= 2 * 10^5, 1 <= m <= 2 *
// 10^5) -- the length of s and the number of tries correspondingly.
//
// The second line of each test case contains the string s consisting of n lowercase Latin letters.
//
// The third line of each test case contains m integers p_1, p_2, ..., p_m (1 <= p_i < n) -- the
// number of characters pressed right during the i-th try.
//
// It is guaranteed that the sum of n and the sum of m both does not exceed 2 * 10^5 (\sum n <= 2 *
// 10^5, \sum m <= 2 * 10^5).
//
// It is guaranteed that the answer for each letter does not exceed 2 * 10^9.
//
// Output
//
// For each test case, print the answer -- 26 integers: the number of times you press the button
// 'a', the number of times you press the button 'b', ..., the number of times you press the button
// 'z'.
//
// Example
/*
input:
3
4 2
abca
1 3
10 5
codeforces
2 8 3 2 9
26 10
qwertyuioplkjhgfdsazxcvbnm
20 10 1 2 3 5 10 5 9 4
output:
4 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 9 4 5 3 0 0 0 0 0 0 0 0 9 0 0 3 1 0 0 0 0 0 0 0
2 1 1 2 9 2 2 2 5 2 2 2 1 1 5 4 11 8 2 7 5 1 10 1 5 2
*/
// Note
//
// The first test case is described in the problem statement. Wrong tries are "a", "abc" and the
// final try is "abca". The number of times you press 'a' is 4, 'b' is 2 and 'c' is 2.
//
// In the second test case, there are five wrong tries: "co", "codeforc", "cod", "co", "codeforce"
// and the final try is "codeforces". The number of times you press 'c' is 9, 'd' is 4, 'e' is 5,
// 'f' is 3, 'o' is 9, 'r' is 3 and 's' is 1.
//

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.Random;
import java.util.StringTokenizer;

public class C1311C {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int[] solve(String s, int[] p) {
    int n = s.length();
    int m = p.length;
    int[] ans = new int[26];
    int[][] precnt = new int[n + 1][26];
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 26; j++) {
        precnt[i][j] = precnt[i-1][j];
      }
      int id = s.charAt(i-1) - 'a';
      precnt[i][id]++;
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < 26; j++) {
        ans[j] += precnt[p[i]][j];
      }
    }
    for (int j = 0; j < 26; j++) {
      ans[j] += precnt[n][j];
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
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      int m = in.nextInt();
      String s = in.next();
      int[] p = new int[m];
      for (int i = 0; i < m; i++) {
        p[i] = in.nextInt();
      }
      int[] ans = solve(s, p);
      output(ans);
    }
  }

  static void output(int[] a) {
    StringBuilder sb = new StringBuilder();
    for (int v : a) {
      sb.append(v);
      sb.append(' ');
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
