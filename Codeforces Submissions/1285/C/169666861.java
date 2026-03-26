// import java.io.BufferedReader;
// import java.io.InputStreamReader;

// public class Main{
//     static int m=(int)1e9+7;
//     public static void main(String[] args) throws Exception{
//         BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//         int t=Integer.parseInt(br.readLine());
//         while(t-->0){
//             String[] in=br.readLine().split(" ");
//             int a=Integer.parseInt(in[0]);
//             int b=Integer.parseInt(in[1]);
//             int c=Integer.parseInt(in[2]);

//             // System.out.println(expo(b,c,m-1));
//             System.out.println(expo(a,expo(b,c,m-1),m));
//         }
//     }
//     static int expo(int a,int b,int c){
//         if(a==0 && b==0) return 1;
//         long res=1;
//         long x=a;
//         while(b>0){
//             if((b&1)==1){
//                 res=(x*res)%c;
//             }
//             x=(x*x)%c;
//             b=b>>1;
//         }
//         return (int)(res%c);
//     }
// }

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static long mod = (long) 1e9 + 7;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long t=Long.parseLong(br.readLine());
        // while(t-->0){
        // }
        long ans=1;
        long n=(long)t;
        long num1=1;
        long num2=n;
        for(long i=1;i*i<=n;i++){
            if(n%i==0){
                if(gcd(i,n/i)==1){
                    num1=i;
                    num2=n/i;
                }
            }
        }
        System.out.print(num1+" "+num2);
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