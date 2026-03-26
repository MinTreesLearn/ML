import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        final Scanner scanner = new Scanner(System.in);
        final int n = scanner.nextInt();
        if (n % 2 == 1) {
            System.out.println("NO");
            return;
        }
        final int[] x = new int[n];
        final int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
            y[i] = scanner.nextInt();
        }
        int half = n / 2;
        for (int i = 0; i < half; i++) {
            int dx = x[i] - x[(half + i + 1) % n];
            int dy = y[i] - y[(half + i + 1) % n];
            if (x[i + 1] != x[half + i] + dx || y[i + 1] != y[half + i] + dy) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
