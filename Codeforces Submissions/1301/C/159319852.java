import java.util.*;

public class Hello {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            long result = (1L * N * (N + 1)) / 2L;
            int Z = N - M;
            int K = Z / (M + 1);
            result -= (1L * (M + 1) * K * (K + 1)) / 2L;
            result -= (1L * (Z % (M + 1)) * (K + 1));
            System.out.print(result + " ");
        }
    }
}