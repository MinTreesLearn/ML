import java.util.*;

public class Sol {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        if (n == m)
            System.out.println(0);
        else if (m % n != 0)
            System.out.println(-1);
        else {
            int ans = 0;
            int x = m / n;
            while (x % 2 == 0) {
                ans++;
                x /= 2;
            }
            while (x % 3 == 0) {
                ans++;
                x /= 3;
            }
            if (x != 1)
                System.out.println(-1);
            else
                System.out.println(ans);
        }
        in.close();
    }
}