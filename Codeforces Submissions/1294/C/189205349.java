import java.util.*;

public class Solution {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner in = new Scanner(System.in);
        int testcases = in.nextInt();
        while (testcases-- > 0) {
            int n = in.nextInt();
            int a = 0;
            int b = 0;
            int c = 0;
            a = factors(n, 2);
            b = factors(n / a, a + 1);
            c = n / (a * b);
            if (a >= 2 && b >= 2 && c >= 2 && a != b && b != c && c != a) {
                System.out.println("YES");
                System.out.println(a + " " + b + " " + c);
            } else
                System.out.println("NO");
        }
        in.close();
    }

    static int factors(int N, int k) {
        for (int i = k; i < Math.sqrt(N); i++) {
            if (N % i == 0)
                return i;
        }
        return -1;
    }
}