// have faith in yourself!!!!!
/*
    Naive mistakes in java :
    --> Arrays.sort(primitive) is O(n^2)
    --> Never use '=' to compare to Integer data types, instead use 'equals()'
    --> -4 % 3 = -1, actually it should be 2, so add '+n' to modulo result
 */

import java.io.*;
import java.util.*;

public class CodeForces {

    public static void main(String[] args) throws IOException {
        openIO();
        int testCase = 1;
//        testCase = sc. nextInt();
        for (int i = 1; i <= testCase; i++) solve(i);
        closeIO();
    }
    /*-------------------------------------------EDITING CODE STARTS HERE-------------------------------------------*/

    public static void solve(int tCase) throws IOException {
       int n = sc.nextInt();
       mod = sc.nextInt();
       _ncr_precompute(n);
       long ans = 0;
       for(int l = 0;l<n;l++){
           ans += factorial[l+1] * _power(n-l,2)  % mod * factorial[n-l-1]  % mod;
           ans %=mod;
       }
       out.println(ans);

    }




    /*-------------------------------------------EDITING CODE ENDS HERE-------------------------------------------*/

    public static int mod = (int) 1e9 + 7;
    //    public static int mod =  998244353;
    public static int inf_int = (int) 1e9;
    public static long inf_long = (long) 2e18;

    public static void _sort(int[] arr, boolean isAscending) {
        int n = arr.length;
        List<Integer> list = new ArrayList<>();
        for (int ele : arr) list.add(ele);
        Collections.sort(list);
        if (!isAscending) Collections.reverse(list);
        for (int i = 0; i < n; i++) arr[i] = list.get(i);
    }

    public static void _sort(long[] arr, boolean isAscending) {
        int n = arr.length;
        List<Long> list = new ArrayList<>();
        for (long ele : arr) list.add(ele);
        Collections.sort(list);
        if (!isAscending) Collections.reverse(list);
        for (int i = 0; i < n; i++) arr[i] = list.get(i);
    }

    // time : O(1), space : O(1)
    public static int _digitCount(long num,int base){
        // this will give the # of digits needed for a number num in format : base
        return (int)(1 + Math.log(num)/Math.log(base));
    }

    // time : O(n), space: O(n)
    public static long _fact(int n){
        // simple factorial calculator
        long ans = 1;
        for(int i=2;i<=n;i++)
            ans = ans * i % mod;
        return ans;
    }

    // time for pre-computation of factorial and inverse-factorial table : O(nlog(mod))
    public static long[] factorial , inverseFact;
    public static void _ncr_precompute(int n){
        factorial = new long[n+1];
        inverseFact = new long[n+1];
        factorial[0] = inverseFact[0] = 1;
        for (int i = 1; i <=n; i++) {
            factorial[i] = (factorial[i - 1] * i) % mod;
            inverseFact[i] = _power(factorial[i], mod - 2);
        }
    }
    // time of factorial calculation after pre-computation is O(1)
    public static int _ncr(int n,int r){
        if(r > n)return 0;
        return (int)(factorial[n] * inverseFact[r] % mod * inverseFact[n - r] % mod);
    }
    public static int _npr(int n,int r){
        if(r > n)return 0;
        return (int)(factorial[n] * inverseFact[n - r] % mod);
    }


    // euclidean algorithm time O(max (loga ,logb))
    public static long _gcd(long a, long b) {
        if (a == 0)
            return b;
        return _gcd(b % a, a);
    }

    // lcm(a,b) * gcd(a,b) = a * b
    public static long _lcm(long a, long b) {
        return (a / _gcd(a, b)) * b;
    }

    // binary exponentiation time O(logn)
    public static long _power(long x, long n) {
        long ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans *= x;
                ans %= mod;
                n--;
            } else {
                x *= x;
                x %= mod;
                n >>= 1;
            }
        }
        return ans;
    }

    //sieve or first divisor time : O(mx * log ( log (mx) ) )
    public static int[]  _seive(int mx){
        int[] firstDivisor = new int[mx+1];
        for(int i=0;i<=mx;i++)firstDivisor[i] = i;
        for(int i=2;i*i<=mx;i++)
            if(firstDivisor[i] == i)
                for(int j = i*i;j<=mx;j+=i)
                    firstDivisor[j] = i;
        return firstDivisor;
    }

    // check if x is a prime # of not. time : O( n ^ 1/2 )
    private static boolean _isPrime(long x){
        for(long i=2;i*i<=x;i++)
            if(x%i==0)return false;
        return true;
    }

    static class Pair<K, V>{
        K ff;
        V ss;

        public Pair(K ff, V ss) {
            this.ff = ff;
            this.ss = ss;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || this.getClass() != o.getClass()) return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return ff.equals(pair.ff) && ss.equals(pair.ss);
        }

        @Override
        public int hashCode() {
            return Objects.hash(ff, ss);
        }
    }

    static FastestReader sc;
    static PrintWriter out;

    private static void openIO() throws IOException {
        sc = new FastestReader();
        out = new PrintWriter(System.out);
    }
    /*-------------------------------------------FAST INPUT STARTS HERE---------------------------------------------*/

    public static void closeIO() throws IOException {
        out.flush();
        out.close();
        sc.close();
    }

    private static final class FastestReader {
        private static final int BUFFER_SIZE = 1 << 16;
        private final DataInputStream din;
        private final byte[] buffer;
        private int bufferPointer, bytesRead;

        public FastestReader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public FastestReader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        private static boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        private int skip() throws IOException {
            int b;
            //noinspection StatementWithEmptyBody
            while ((b = read()) != -1 && isSpaceChar(b)) {
            }
            return b;
        }

        public String next() throws IOException {
            int b = skip();
            final StringBuilder sb = new StringBuilder();
            while (!isSpaceChar(b)) { // when nextLine, (isSpaceChar(b) && b != ' ')
                sb.appendCodePoint(b);
                b = read();
            }
            return sb.toString();
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            final boolean neg = c == '-';
            if (neg) {
                c = read();
            }
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg) {
                return -ret;
            }
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            final boolean neg = c == '-';
            if (neg) {
                c = read();
            }
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg) {
                return -ret;
            }
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            final boolean neg = c == '-';
            if (neg) {
                c = read();
            }

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg) {
                return -ret;
            }
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1) {
                buffer[0] = -1;
            }
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead) {
                fillBuffer();
            }
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            din.close();
        }
    }
    /*---------------------------------------------FAST INPUT ENDS HERE ---------------------------------------------*/
}