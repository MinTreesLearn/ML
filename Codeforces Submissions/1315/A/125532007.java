import java.util.*;
 
public class practice {


    public static void main(String[] args) {
 
		Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();

        while (t --> 0) {

            int a = scan.nextInt();
            int b = scan.nextInt();
            int x = scan.nextInt();
            int y = scan.nextInt();
            int max = 0;

            if ((x == 0 && y == 0) || (x == 0 && y == b - 1) || (x == a - 1 && y == 0) || (x == a - 1 && y == b - 1)) {

                max = Math.max(a * (b - 1), (a - 1) * b);
            } else if (x == 0 || x == a - 1) {

                int len = Math.max(y, (b - 1) - y);
                max = Math.max(a * len, (a - 1) * b);
            } else if (y == 0 || y == b - 1) {

                int len = Math.max(x, (a - 1) - x);
                max = Math.max(b * len, a * (b - 1));
            } else {

                int i = x * b;
                int j = a * y;
                int k = ((a - 1) - x) * b;
                int l = a * ((b - 1) - y);
                max = Math.max(i, Math.max(j, Math.max(k, l)));
            }

            System.out.println(max);
        }

        scan.close();
    }
}