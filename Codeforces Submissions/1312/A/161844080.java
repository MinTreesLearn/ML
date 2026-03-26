
import java.math.BigInteger;
import java.sql.Array;
import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;



public class A {
    static FastScanner scan = new FastScanner();
    static Scanner scanner = new Scanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);
    static long MOD = 998244353;
    static long MOD2 = MOD * MOD;
    static int pInf = Integer.MAX_VALUE;
    static int nInf = Integer.MIN_VALUE;
    static long ded = (long)(1e17)+9;
    public static void main(String[] args) {
       int t = scan.nextInt();

       while(t--!=0){
            solve();
       }
    out.close();
    }

    public static void solve() {
        int n = scan.nextInt();
        int m = scan.nextInt();
        if(n%m==0){
            out.println("YES");
        }
        else{
            out.println("NO");
        }
    }
    static class Pair implements Comparable<Pair> {
        int x;
        int y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
//            this.idx = idx;
        }
        @Override
        public int compareTo(Pair o){
            if(this.y==o.y){
                return this.x-o.x;
            }
            return this.y-o.y;
        }
    }
    public static long mul(long a, long b) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }
    public static long add(long a, long b) {
        return ((a % MOD) + (b % MOD)) % MOD;
    }
    public static long c2(long n) {
        if ((n & 1) == 0) {
            return mul(n / 2, n - 1);
        } else {
            return mul(n, (n - 1) / 2);
        }
    }
    //Shuffle Sort
    static final Random random = new Random();
    static void ruffleSort(int[] a) {
        int n = a.length;//shuffle, then sort
        for (int i = 0; i < n; i++) {
            int oi = random.nextInt(n); int temp= a[oi];
            a[oi] = a[i];
            a[i] = temp;
        }
        Arrays.sort(a);
    }
    //Brian Kernighans Algorithm
    static long countSetBits(long n) {
        if (n == 0) return 0;
        return 1 + countSetBits(n & (n - 1));
    }
    //Euclidean Algorithm
    static long gcd(long A, long B) {
        if (B == 0) return A;
        return gcd(B, A % B);
    }
    //Modular Exponentiation
    static long fastExpo(long x, long n) {
        if (n == 0) return 1;
        if ((n & 1) == 0) return fastExpo((x * x) % MOD, n / 2) % MOD;
        return ((x % MOD) * fastExpo((x * x) % MOD, (n - 1) / 2)) % MOD;
    }
    //AKS Algorithm
    static boolean isPrime(long n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i <= Math.sqrt(n); i += 6)
            if (n % i == 0 || n % (i + 2) == 0) return false;
        return true;
    }
    public static long modinv(long x) {
        return modpow(x, MOD - 2);
    }
    public static long modpow(long a, long b) {
        if (b == 0) {
            return 1;
        }
        long x = modpow(a, b / 2);
        x = (x * x) % MOD;
        if (b % 2 == 1) {
            return (x * a) % MOD;
        }
        return x;
    }


   /* public static void solve(){
       int n = scan.nextInt();
       int q = scan.nextInt();
       int[] arr = new int[n];
       int[] brr = new int[q];
       for (int i =0;i<n;i++)arr[i]= scan.nextInt();
       for (int i =0;i<q;i++)brr[i]= scan.nextInt();
       int J=0;
       while (q-->0){
           int find = arr[J];
           int l =0,r=arr.length;
           while (l<=r){
               int mid = (l + r ) / 2;
               if(arr[mid]==find){
                   out.println(mid+1);
                   break;
               }
               else if(arr[mid]>find){
                   l = mid +1;
               }
               else{
                   r = mid-1;
               }
           }
           J++;
       }
    }*/
    //2 4 8 16 32 64
    // 128 --
    public static boolean isInteger(int n) {
        return Math.sqrt(n) % 1 == 0;
    }
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens()) try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}