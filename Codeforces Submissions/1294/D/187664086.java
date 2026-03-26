// package c1294;

//
// Codeforces Round #615 (Div. 3) 2020-01-22 06:35
// D. MEX maximizing
// https://codeforces.com/contest/1294/problem/D
// time limit per test 3 seconds; memory limit per test 256 megabytes
// public class Pseudo for 'Source should satisfy regex [^{}]*public\s+(final)?\s*class\s+(\w+).*'
//
// Recall that of an array is a that does not belong to the array. Examples:
//  * for the array [0, 0, 1, 0, 2] MEX equals to 3 because numbers 0, 1 and 2 are presented in the
//    array and 3 is the minimum non-negative integer not presented in the array;
//  * for the array [1, 2, 3, 4] MEX equals to 0 because 0 is the minimum non-negative integer not
//    presented in the array;
//  * for the array [0, 1, 4, 3] MEX equals to 2 because 2 is the minimum non-negative integer not
//    presented in the array.
//
// You are given an empty array a=[] (in other words, a zero-length array). You are also given a
// positive integer x.
//
// You are also given q queries. The j-th query consists of one integer y_j and means that you have
// to append one element y_j to the array. The array length increases by 1 after a query.
//
// In one move, you can choose any index i and set a_i := a_i + x or a_i := a_i - x (i.e. increase
// or decrease any element of the array by x). The only restriction is that . Since initially the
// array is empty, you can perform moves only after the first query.
//
// You have to maximize the (minimum excluded) of the array if you can perform any number of such
// operations (you can even perform the operation multiple times with one element).
//
// You have to find the answer after each of q queries (i.e. the j-th answer corresponds to the
// array of length j).
//
// Input
//
// The first line of the input contains two integers q, x (1 <= q, x <= 4 * 10^5) -- the number of
// queries and the value of x.
//
// The next q lines describe queries. The j-th query consists of one integer y_j (0 <= y_j <= 10^9)
// and means that you have to append one element y_j to the array.
//
// Output
//
// Print the answer to the initial problem after each query -- for the query j print the maximum
// value of after first j queries. Note that queries are dependent (the array changes after each
// query) but operations are independent between queries.
//
// Example
/*
input:
7 3
0
1
2
2
0
0
10
output:
1
2
3
3
4
4
7

input:
4 3
1
2
1
2
output:
0
0
0
0
*/
// Note
//
// In the first example:
//  * After the first query, the array is a=[0]: you don't need to perform any operations, maximum
//    possible MEX is 1.
//  * After the second query, the array is a=[0, 1]: you don't need to perform any operations,
//    maximum possible MEX is 2.
//  * After the third query, the array is a=[0, 1, 2]: you don't need to perform any operations,
//    maximum possible MEX is 3.
//  * After the fourth query, the array is a=[0, 1, 2, 2]: you don't need to perform any operations,
//    maximum possible MEX is 3 (you can't make it greater with operations).
//  * After the fifth query, the array is a=[0, 1, 2, 2, 0]: you can perform a[4] := a[4] + 3 = 3.
//    The array changes to be a=[0, 1, 2, 2, 3]. Now MEX is maximum possible and equals to 4.
//  * After the sixth query, the array is a=[0, 1, 2, 2, 0, 0]: you can perform a[4] := a[4] + 3 = 0
//    + 3 = 3. The array changes to be a=[0, 1, 2, 2, 3, 0]. Now MEX is maximum possible and equals
//    to 4.
//  * After the seventh query, the array is a=[0, 1, 2, 2, 0, 0, 10]. You can perform the following
//    operations:
//  * a[3] := a[3] + 3 = 2 + 3 = 5,
//  * a[4] := a[4] + 3 = 0 + 3 = 3,
//  * a[5] := a[5] + 3 = 0 + 3 = 3,
//  * a[5] := a[5] + 3 = 3 + 3 = 6,
//  * a[6] := a[6] - 3 = 10 - 3 = 7,
//  * a[6] := a[6] - 3 = 7 - 3 = 4. The resulting array will be a=[0, 1, 2, 5, 3, 6, 4]. Now MEX is
// maximum possible and equals to 7.
//

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class C1294D {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int[] solve(int[] ya, int x) {
    int q = ya.length;
    int[] ans = new int[q];
    int[] min = new int[q+1];
    for (int i = 0; i <= q; i++) {
      min[i] = i;
    }
    boolean[] ok = new boolean[q+1];
    int mex = 0;
    for (int i = 0; i < q; i++) {
      int y = ya[i] % x;
      if (y < q) {
        if (min[y] <= q) {
          ok[min[y]] = true;
          min[y] += x;
        }
      }
      while(ok[mex]) {
        mex++;
      }
      ans[i] = mex;
    }
    return ans;
  }

  // TLE
  static int[] solveA(int[] ya, int x) {
    int q = ya.length;
    int[] ct = new int[q + 1];
    int[] ans = new int[q];
    int mex = 0;
    for (int i = 0; i < q; i++) {
      int y = ya[i];

      // increase y to the minimal value >= mex
      if (y < mex) {
        int k = (mex - y + x - 1) / x;
        y += k * x;
      }
      myAssert(y >= mex);

      // decrease y to the minimal value >= mex
      {
        int k = (y - mex) / x;
        y -= k * x;
      }
      // Increase y if there is already a count
      while (y <= q && ct[y] != 0) {
        y += x;
      }
      if (test) System.out.format("  i:%2d y:%d\n", i, y);
      if (y <= q) {
        ct[y]++;
      }
      while (ct[mex] > 0) {
        mex++;
      }
      ans[i] = mex;
    }
    return ans;
  }

  static String trace(int[][] a) {
    return Arrays.deepToString(a).replace(" ", "").replace('[', '{').replace(']', '}');
  }

  static String trace(int[] a) {
    return Arrays.toString(a).replace(" ", "").replace('[', '{').replace(']', '}');
  }

  static void test(int[] exp, int[] y, int x) {
    System.out.format("%s %d\n", trace(y), x);
    int[] ans = solve(y, x);
    boolean ok = true;
    if (exp != null) {
      for (int i = 0; i < ans.length; i++) {
        if (ans[i] != exp[i]) {
          ok = false;
          break;
        }
      }
    }
    System.out.format(" => %s %s\n", trace(ans), ok ? "":"Expected " + trace(exp));
    myAssert(ok);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    test(new int[] {0,2,3,3,3,5,5,7,9,10,10,10,12,14,14,14,14,16,16,18,18,18,20,20,22,22,22,22,24,26,26,
        28,30,30,30,32,34,36,38,40,41,42,42,44,45,45,45,45,47,49,49},
        new int[] {630874911, 734875554, 732780376, 761466396, 543967336, 727295757, 142396288,
            900137307, 707426025, 179546151, 26986631, 549687, 778668574, 62916138, 98303405,
            884297679, 765856475, 981943572, 659643629, 881357320, 951014691, 422536531, 299232258,
            85228941, 305055348, 88611335, 243438099, 736398145, 741925046, 55318966, 587721649,
            299573818, 10356092, 975743365, 864911753, 206516024, 423602150, 715941614, 393849704,
            889427616, 881407230, 261023741, 768345063, 158178032, 20771974, 922787326}, 2);

    int q = 1 + RAND.nextInt(30);
    int x = 1 + RAND.nextInt(30);
    int[] y = new int[q];
    for (int i = 0; i < q; i++) {
      y[i] = RAND.nextInt(1000);
    }
    test(null, y, x);

    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int q = in.nextInt();
    int x = in.nextInt();
    int[] y = new int[q];
    for (int i = 0; i < q; i++) {
      y[i] = in.nextInt();
    }
    int[] ans = solve(y, x);
    output(ans);
  }

  static void output(int[] a) {
    StringBuilder sb = new StringBuilder();
    for (int v : a) {
      sb.append(v);
      sb.append('\n');
      if (sb.length() > 4000) {
        System.out.print(sb.toString());
        sb.setLength(0);
      }
    }
    System.out.print(sb.toString());
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
