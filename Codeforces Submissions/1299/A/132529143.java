
import java.util.Scanner;
import java.util.Arrays;

public class JavaApplication2 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, AND=0, frq[] = new int[35], t, best=0, mx=0;
        n = in.nextInt();
        int []a=new int [n];
        for (int i = 0; i <= 30; ++i) {
            AND |= (1 << i);
        }
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
            for (int j = 0; j < 30; ++j) {
                if ((a[i]&(1 << j)) != 0) {
                    frq[j]++;
                }
        }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 30; ++j) {
                if ((a[i] & (1 << j)) != 0) {
                    AND &= ~(1 << j);
                } else {
                    AND &= (1 << j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            int tmp_AND = AND;
            for (int j = 0; j <= 30; ++j) {
                if ((a[i]&(1 << j)) != 0 && frq[j] == 1) {
                    tmp_AND |= (1 << j);
                }
            }
            if (mx < (tmp_AND)) {
                mx = (tmp_AND);
                best = i;
            }
        }
        System.out.print(a[best] + " ");
        for (int i = 0; i < n; ++i) {
            if (i == best) {
                continue;
            }
            System.out.print(a[i] + " ");
        }
    }

}
