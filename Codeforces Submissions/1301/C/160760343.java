import java.util.*;
public class Ayoub
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        StringBuilder finAns = new StringBuilder();
        while (--T >= 0) {
            long n = sc.nextLong(), m = sc.nextLong();
            long z = n - m;
            long g = m + 1;
            long k = z / g;
            long ans = ((n * (n + 1)) / 2) - (((k * (k + 1)) / 2) * g) - ((k + 1) * (z % g));
            finAns.append(ans + "\n");
        }
        System.out.println(finAns);
        sc.close();
    }
}
