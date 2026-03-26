import java.util.*;

public class Sol {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a[] = new int[n];
        int b[] = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();
        for (int i = 0; i < n; i++)
            b[i] = in.nextInt();
        int c = 0;
        int z = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i])
                continue;
            if (b[i] == 1)
                z++;
            else if (a[i] == 1)
                c++;
        }
        if (c == 0)
            System.out.println(-1);
        else if (z == 0)
            System.out.println(1);
        else
            System.out.println((z / c) + 1);
        in.close();
    }
}