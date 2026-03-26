import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        if (m %n != 0) {
            System.out.println("-1");
        } else if (m == n) {
            System.out.println("0");
        } else if (m %n == 0) {
            int x = m / n;
            if (x %2 != 0 && x %3 != 0) {
                System.out.println("-1");
            } else {
                int count2 = 0, count3 = 0;
                while (x %3 == 0 && x > 0) {
                    x /= 3;
                    count3++;
                }
                while (x %2 == 0 && x > 0) {
                    x /= 2;
                    count2++;
                }
                if (x != 1) {
                    System.out.println("-1");
                } else {
                    System.out.println(count2 + count3);
                }
            }
        }
    }
}
