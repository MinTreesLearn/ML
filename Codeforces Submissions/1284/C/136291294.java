import java.util.Scanner;
 
public class NewYearAndPermutation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long mod = scanner.nextLong();
        long[] fact = new long[n+1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i-1] * i) % mod;
        }
        long res = 0;
        for (int i = n; i > 0; i--) {
            res = (res + ((((i * fact[i]) % mod) * fact[n-i+1]) % mod)) % mod;
        }
        System.out.println(res);
    }
}