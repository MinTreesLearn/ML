import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static long mod = (long) 1e9 + 7;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // long t=Long.parseLong(br.readLine());
        // while(t-->0){
            // int n=Integer.parseInt(br.readLine());
            String[] in=br.readLine().split(" ");
            String[] in1=br.readLine().split(" ");
            int n=Integer.parseInt(in[0]);
            int m=Integer.parseInt(in[1]);
            // String[] in2=br.readLine().split(" ");
            int[] a=new int[n];
            for(int i=0;i<n;i++){
                a[i]=Integer.parseInt(in1[i]);
            }
            // String[] in1=br.readLine().split(" ");
            // HashMap<String,Integer>m1=new HashMap<>();
            if(n<=m){
                long prod=1;
                for(int i=0;i<n;i++){
                    for(int j=i+1;j<n;j++){
                        prod=prod*Math.abs(a[i]-a[j])%m;
                    }
                }
                System.out.println(prod%m);
            }
            else System.out.println(0);
        // }
    }
    static long n_of_factors(long[][] a) {
        long ans = 1;
        for (int i = 0; i < a.length; i++) {
            ans = ans * (a[i][1] + 1) % mod;
        }
        return ans % mod;
    }

    static long sum_of_factors(long[][] a) {
        long ans = 1;
        for (int i = 0; i < a.length; i++) {
            long res = (((expo(a[i][0], a[i][1] + 1) - 1) % mod) * (modular_inverse(a[i][0] - 1)) % mod) % mod;
            ans = ((res % mod) * (ans % mod)) % mod;
        }
        return (ans % mod);
    }

    static long prod_of_divisors(long[][] a) {
        long ans = 1;
        long d = 1;
        for (int i = 0; i < a.length; i++) {
            long res = expo(a[i][0], (a[i][1] * (a[i][1] + 1) / 2));
            ans = ((expo(ans, a[i][1] + 1) % mod) * (expo(res, d) % mod)) % mod;
            d = (d * (a[i][1] + 1)) % (mod - 1);
        }
        return ans % mod;
    }

    static long expo(long a, long b) {
        long ans = 1;
        a = a % mod;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
            b >>= 1;
        }
        return ans % mod;
    }

    static long modular_inverse(long a) {
        return expo(a, mod - 2) % mod;
    }

    static long phin(long a) {
        if (isPrime(a))
            return a - 1;
        long res = a;
        for (int i = 2; i * i <= (int) a; i++) {
            if (a % i == 0) {
                while (a % i == 0) {
                    a = a / i;
                }
                res -= res / i;
            }
        }
        if (a > 1) {
            res -= res / a;
        }
        return res;
    }

    static boolean isPrime(long a) {
        if (a < 2)
            return false;
        for (int i = 2; i * i <= (int) a; i++) {
            if (a % i == 0)
                return false;
        }
        return true;
    }

    static long catlan(long a) {
        long ans = 1;
        for (int i = 1; i <= a; i++) {
            ans = ans * (4 * i - 2) % mod;
            ans = ((ans % mod) * modular_inverse(i + 1)) % mod;
        }
        return ans % mod;
    }

    static HashMap<Long, Long> primeFactors(long n) {
        HashMap<Long, Long> m1 = new HashMap<>();
        for (int i = 2; (long) i * (long) i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0) {
                    m1.put((long) i, m1.getOrDefault(i, 0l) + 1);
                    n = n / i;
                }
            }
        }
        return m1;
    }
    static long gcd(long a,long b){
        a=Math.abs(a);
        b=Math.abs(b);
        if(b==0) return a;
        return gcd(b,a%b);
    }
    // }
}
class pair{
    long a;
    long b;
    pair(long a,long b){
        this.a=a;
        this.b=b;
    }
}