import java.util.*;

public class grade {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int s = 0;

            int n = sc.nextInt();
            double m = sc.nextDouble();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                s = s + a[i];
            }
            double avg = s / n;
            if (s > m)
                System.out.println((int) m);
            else
                System.out.println(s);
            t--;
        }
    }

}
