import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        long t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int arr[] = new int[n];
            long total = 0;
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
                total += arr[i];
            }
            long sum = 0;
            long maxi = Long.MIN_VALUE;
            ;
            for (int i = 0; i < n - 1; i++) {
                sum += arr[i];
                if (sum > maxi) {
                    maxi = sum;
                }
                if (sum < 0) {
                    sum = 0;
                }
            }

            sum = 0L;
            long maxi2 = Long.MIN_VALUE;
            for (int i = 1; i < n; i++) {
                sum += arr[i];
                if (sum > maxi2) {
                    maxi2 = sum;
                }
                if (sum < 0) {
                    sum = 0;
                }
            }

            if (total > Math.max(maxi, maxi2)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
