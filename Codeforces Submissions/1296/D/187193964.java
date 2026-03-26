// package c1296;

//
// Codeforces Round #617 (Div. 3) 2020-02-04 06:35
// D. Fight with Monsters
// https://codeforces.com/contest/1296/problem/D
// time limit per test 1 second; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// There are n monsters standing in a row numbered from 1 to n. The i-th monster has h_i health
// points (hp). You have your attack power equal to a hp and your opponent has his attack power
// equal to b hp.
//
// You and your opponent are fighting these monsters. Firstly, you and your opponent go to the first
// monster and fight it till his death, then you and your opponent go the second monster and fight
// it till his death, and so on. A monster is considered dead if its hp is less than or equal to 0.
//
// The fight with a monster happens in turns.
//  1. You hit the monster by a hp. If it is dead after your hit, and you both proceed to the next
//     monster.
//  2. Your opponent hits the monster by b hp. If it is dead after his hit, and you both proceed to
//     the next monster.
//
// You have some secret technique to force your opponent to skip his turn. You can use this
// technique at most k times (for example, if there are two monsters and k=4, then you can use the
// technique 2 times on the first monster and 1 time on the second monster, but not 2 times on the
// first monster and 3 times on the second monster).
//
// Your task is to determine the maximum number of points you can gain if you use the secret
// technique optimally.
//
// Input
//
// The first line of the input contains four integers n, a, b and k (1 <= n <= 2 * 10^5, 1 <= a, b,
// k <= 10^9) -- the number of monsters, your attack power, the opponent's attack power and the
// number of times you can use the secret technique.
//
// The second line of the input contains n integers h_1, h_2, ..., h_n (1 <= h_i <= 10^9), where h_i
// is the health points of the i-th monster.
//
// Output
//
// Print one integer -- the maximum number of points you can gain if you use the secret technique
// optimally.
//
// Example
/*
input:
6 2 3 3
7 10 50 12 1 8
output:
5

input:
1 1 100 99
100
output:
1

input:
7 4 2 1
1 3 5 4 2 7 6
output:
6
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
import java.util.Random;
import java.util.StringTokenizer;

public class C1296D {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int solve(int[] h, int a, int b, int k) {
    int n = h.length;
    int ans = 0;
    List<Integer> nums = new ArrayList<>();
    for (int v : h) {
      v %= a + b;
      if (v == 0) {
        v = a + b;
      }
      if (v <= a) {
        ans++;
      } else {
        nums.add(v);
      }
    }
    Collections.sort(nums);
    if (test) System.out.format("  nums:%s\n", nums.toString());
    for (int v : nums) {
      int w = (v + a - 1) / a;
      // need b skip for w - 1 times
      if (k >= w - 1) {
        k -= w - 1;
        ans++;
      } else {
        break;
      }
    }
    return ans;
  }

  static void test(int exp, int[] h, int a, int b, int k) {
    int ans = solve(h, a, b, k);
    System.out.format("%s %d %d %d => %d %s\n", Arrays.toString(h), a, b, k, ans,
        ans == exp ? "":"Expected " + exp);
    myAssert(ans == exp);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    test(5, new int[] {7, 10, 50, 12, 1, 8}, 2, 3, 3);
    test(1, new int[] {100}, 1, 100, 99);
    test(6, new int[] {1,3,5,4,2,7,6}, 4,2,1);
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int a = in.nextInt();
    int b = in.nextInt();
    int k = in.nextInt();
    int[] h = new int[n];
    for (int i = 0; i < n; i++) {
      h[i] = in.nextInt();
    }
    int ans = solve(h, a, b, k);
    System.out.println(ans);
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
