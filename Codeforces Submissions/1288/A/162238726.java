
import java.util.Scanner;

public class A1288 {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int t = scn.nextInt();
        while (t > 0) {
            int n = scn.nextInt();
            int d = scn.nextInt();
            if (d <= n || binarySearch(n, d)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
            t--;
        }
    }

    public static int func(int x, int d) {
        return x + (int) Math.ceil((double) d / (x + 1));
    }

    public static boolean binarySearch(int n, int days) {
        int left = 0;
        int right = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            int resDays = func(mid, days);
            if (resDays <= n) {
                return true;
            }
            left = mid + 1;
        }
        return false;
    }
}