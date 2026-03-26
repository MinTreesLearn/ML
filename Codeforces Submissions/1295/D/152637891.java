import java.util.*;

public class Hello {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            long X = sc.nextLong();
            long Y = sc.nextLong();
            long result = Y / getGCD(X, Y);
            long val = result;
            for (long ctr = 2; ctr * ctr <= val; ctr++) {
                if (val % ctr == 0) {
                    result -= result / ctr;
                }
                while (val % ctr == 0) {
                    val /= ctr;
                }
            }
            if (val != 1) {
                result -= result / val;
            }
            System.out.println(result);
        }
    }

    private static long getGCD(long a, long b) {
        return b == 0 ? a : getGCD(b, a % b);
    }
}