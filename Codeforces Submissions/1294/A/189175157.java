import java.util.*;

public class Solution {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner in = new Scanner(System.in);
        int testcases = in.nextInt();
        while (testcases-- > 0) {
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            int n = in.nextInt();
            int x = Math.max(a, Math.max(b, c));
            x = (x - a) + (x - b) + (x - c);
            if (x > n) {
                System.out.println("NO");
                continue;
            } else {
                n -= x;
                if (n % 3 == 0)
                    System.out.println("YES");
                else
                    System.out.println("NO");
            }
        }
        in.close();
    }
}