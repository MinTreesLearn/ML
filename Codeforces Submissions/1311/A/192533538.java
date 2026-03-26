import java.util.*;

public class AddOddSubEven {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            if (a == b)
                System.out.println(0);
            else {
                long sub = b - a;
                if (sub > 0) {
                    if (sub % 2 != 0)
                        System.out.println(1);
                    else
                        System.out.println(2);
                } else {
                    if (sub % 2 == 0)
                        System.out.println(1);
                    else
                        System.out.println(2);
                }
            }
        }
    }
}