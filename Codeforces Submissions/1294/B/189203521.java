import java.util.*;

public class Solution {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner in = new Scanner(System.in);
        int testcases = in.nextInt();
        while (testcases-- > 0) {
            int n = in.nextInt();
            int a[][] = new int[n][2];
            for (int i = 0; i < n; i++) {
                a[i][0] = in.nextInt();
                a[i][1] = in.nextInt();
            }
            Arrays.sort(a, (x, y) -> x[0] == y[0] ? Integer.compare(x[1], y[1]) : Integer.compare(x[0], y[0]));
            // System.out.println(Arrays.toString(a));
            StringBuilder ans = new StringBuilder();
            int x = 0, y = 0;
            boolean flag = true;
            for (int i = 0; i < n; i++) {
                if (a[i][0] < x) {
                    flag = false;
                    break;
                }
                for (int j = 0; j < a[i][0] - x; j++)
                    ans.append("R");
                x = a[i][0];
                if (a[i][1] < y) {
                    flag = false;
                    break;
                }
                for (int j = 0; j < a[i][1] - y; j++)
                    ans.append("U");
                y = a[i][1];
            }
            if (flag) {
                System.out.println("YES");
                System.out.println(ans);
            } else
                System.out.println("NO");
        }
        in.close();
    }
}