import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            while (n > 0)
                if (n % 2 == 0) {
                    System.out.print(1);
                    n -= 2;

                } else {
                    System.out.print(7);
                    n -= 3;
                }
            System.out.println();
        }

    }
}