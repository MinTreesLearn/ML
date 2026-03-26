import java.util.Scanner;

public class _1288A {

    static long f(long x, long d) {
        return x + (long) Math.ceil((double) d / (x + 1));
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int i = 0; i < t; i++) {
            long n = input.nextLong();
            long d = input.nextLong();
            if (d <= n) {
                System.out.println("YES");
            } else {
                long x = n / 2;
                while (x > 0) {
                    if (f(x, d) <= n) {
                        break;
                    }
                    x /= 2;
                }
                if (f(x, d) <= n) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }
    }

}
