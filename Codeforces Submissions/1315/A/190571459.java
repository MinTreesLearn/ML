import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        while (t > 0) {
            int a = input.nextInt();
            int b = input.nextInt();
            int x = input.nextInt();
            int y = input.nextInt();

            int x1 = a * (y);
            int x2 = b * (x);
            int y1 = a * (b - y - 1);
            int y2 = b * (a - x - 1);
            System.out.println(Math.max(x1, Math.max(x2, Math.max(y1, y2))));
            t--;
        }
    }
}