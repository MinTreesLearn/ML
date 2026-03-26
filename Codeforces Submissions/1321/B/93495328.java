
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

  public static PrintWriter out = new PrintWriter(System.out);
  public static Scanner in = new Scanner(System.in);

  public static void main(String[] args) {
    solve();
    out.flush();
  }

  private static void solve() {
    int n = ni(), MX = (int) 8e5;
    int[] b = new int[n];
    long[] f = new long[MX];
    for (int i = 0; i < n; i++) {
      b[i] = ni();
      f[b[i] - i + n] += b[i];
    }
    long ans = 0;
    for (int i = 0; i < MX; i++) ans = Math.max(ans, f[i]);
    out.println(ans);
  }

  private static int ni() {
    return in.nextInt();
  }

  private static int[] na(int n) {
    int[] a = new int[n];
    for (int i = 0; i < n; i++) a[i] = ni();
    return a;
  }

  private static long[] nal(int n) {
    long[] a = new long[n];
    for (int i = 0; i < n; i++) a[i] = nl();
    return a;
  }

  private static long nl() {
    return in.nextLong();
  }

  private float nf() {
    return in.nextFloat();
  }

  private static double nd() {
    return in.nextDouble();
  }
}
