import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            int c = 0, l = 0;
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                if (a[i] %2 == 0) {
                    c++;
                } else {
                    l++;
                }
            }
            if (l == 0) {
                System.out.println("NO");
            } else if (c == 0) {
                if (l %2 == 0) {
                    System.out.println("NO");
                } else {
                    System.out.println("YES");
                }
            } else {
                System.out.println("YES");
            }
        }
    }
}
