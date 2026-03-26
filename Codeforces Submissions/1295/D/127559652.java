import java.util.HashSet;
import java.util.Scanner;

public class E1295D {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int test = scn.nextInt();
        while (test-- > 0) {
            long a = scn.nextLong();
            long b = scn.nextLong();
            long gcd = gcd(a, b);
            b /= gcd;

            HashSet<Long> primeDivs = new HashSet<>();
            long ans = b;
            for (long i = 2; i * i <= b && b > 0; i++) {
                while (b % i == 0) {
                    primeDivs.add(i);
                    b /= i;
                }
            }
            if (b > 1)
                primeDivs.add(b);
            for (long div : primeDivs) {
                ans /= div;
                ans *= div - 1;
            }
            System.out.println(ans);
        }
    }

    static long gcd(long a, long b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
}
