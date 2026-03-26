import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();

    testLoop:
    for (int test = 0; test < t; ++test) {
      int n = sc.nextInt();
      long[] a = new long[n];
      long[] sums = new long[n];

      for (int i = 0; i < n; ++i) {
        a[i] = sc.nextLong();
        if (i == 0)
          sums[0] = a[i];
        else
          sums[i] = a[i] + sums[i - 1];
      }

      for (int i = 0; i < n - 1; ++i) {
        if (sums[n - 1] - sums[i] >= sums[n - 1]
            || sums[i] >= sums[n - 1]) {
          System.out.println("NO");
          continue testLoop;
        }
      }

      System.out.println("YES");
    }
  }
}