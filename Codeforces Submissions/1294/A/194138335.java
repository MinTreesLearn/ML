import java.util.Scanner;

public class zas {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int i = 0; i < t; i++) {
            int a, b, c, n;
            a = input.nextInt();
            b = input.nextInt();
            c = input.nextInt();
            n = input.nextInt();
            if ((a + b + c + n) % 3 == 0 && n >= Math.max(Math.max(a, b), c) * 3 - (a + b + c)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}