import java.util.Scanner;
public class template {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            solve();
        }
    }
    public static void solve() {
        int n = sc.nextInt();
        int[] input = new int[n];
        for (int i = 0; i < n; i++) {
            input[i] = sc.nextInt();
        }
        int even = input[0] % 2;
        for (int i = 0; i < n; i++) {
            if (input[i] % 2 != even) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
        return;
    }
}
