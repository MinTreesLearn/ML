import java.util.Scanner;

public class Second {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double n = sc.nextInt();
        double ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += (1.0 / i);
        }
        System.out.println(ans);
    }
}
