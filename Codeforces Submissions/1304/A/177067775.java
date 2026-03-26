import java.util.Scanner;
public class template {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            solve();
        }
    }
    public static void solve() {
        long a = sc.nextLong();
        long b = sc.nextLong();
        long x = sc.nextLong();
        long y = sc.nextLong();
        long c = b-a;
        long d = x+y;
        if (c % d == 0) {
            System.out.println(c/d);
        } else System.out.println(-1);
    }
}
