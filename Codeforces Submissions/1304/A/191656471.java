import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            int count = 0;
            int d = y - x;
            if (d % (a + b) == 0) {
                System.out.println(d / (a + b));
            } else {
                System.out.println("-1");
            }
        }
    }
}


