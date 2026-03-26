
import java.io.*;
import java.util.*;

public class CodeForces{
    /*-------------------------------------------EDITING CODE STARTS HERE-------------------------------------------*/

    public static void main(String[] args) throws IOException{
        openIO();
        int testCase = 1;
//        testCase = sc.nextInt();
        for (int i = 1; i <= testCase; i++) solve(i);
        closeIO();
    }
    public static void solve(int tCase)throws IOException {
      int n = sc.nextInt();
      int[] arr = new int[n];
      int[] pre = new int[n];
      int[] suff = new int[n+1];
      for(int i=0;i<n;i++)
          arr[i] = sc.nextInt();

      pre[0] = ~arr[0];
      for(int i=1;i<n;i++)pre[i] = (~arr[i]) & pre[i-1];
      suff[n-1] = ~arr[n-1];
      for(int i=n-2;i>=0;i--)suff[i] = (~arr[i]) & suff[i+1];
      int maxVal = -1;
      int maxInd = -1;
      for(int i=0;i<n;i++){
          int curr;
          if(i==0)curr = arr[i] & suff[i+1];
          else if(i==n-1)curr = arr[i] & pre[i-1];
          else curr= arr[i] & pre[i-1] & suff[i+1];
          if(curr > maxVal){
              maxVal = curr;
              maxInd = i;
          }
      }
      out.println(arr[maxInd]);
      for(int i=0;i<n;i++){
          if(i!=maxInd)out.println(arr[i]);
      }

    }
    public static int findComplement(int num) {
        // Duplicate the input for reference
        int originalNum = num;

        // Set a variable for looping on an index
        long i = 1;
        // Loop while `i` is less or equal to `originalNum`
        while(i<=originalNum) {
            // Shift the variables
            num ^= i;
            i <<= 1;
        }
        // Return the resultant `num`
        return num;
    }

   



    /*-------------------------------------------EDITING CODE ENDS HERE-------------------------------------------*/
    static FastestReader sc;
    static PrintWriter out;
    private static void openIO() throws IOException{
        sc = new FastestReader();
        out = new PrintWriter(System.out);
    }

    /*------------------------------------------HELPER FUNCTION STARTS HERE------------------------------------------*/

    public static int mod = (int) 1e9 + 7;
    private static int mod2 =  998244353;
    public static int inf_int = (int) 2e9 + 10;
    public static  long inf_long = (long) 2e15;

    // time : O(1), space : O(1)
    private static int _modIndex(int x, int n){
        // return the valid index  x in an array , like n % n = 0, -1 % b = n-1
        return (x+n) % n;
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

    // time : O(r)
    public static int _ncr(int n,int r){
        if (r > n) return 0;
        long[]  inv = new long[r + 1];
        inv[0] = 1;
        if(r+1>=2)
            inv[1] = 1;

        // Getting the modular inversion
        // for all the numbers
        // from 2 to r with respect to mod
        for (int i = 2; i <= r; i++)
            inv[i] = mod - (mod / i) * inv[(mod % i)] % mod;

        int ans = 1;

        // for 1/(r!) part
        for (int i = 2; i <= r; i++)
            ans = (int) (((ans % mod) * (inv[i] % mod)) % mod);

        // for (n)*(n-1)*(n-2)*...*(n-r+1) part
        for (int i = n; i >= (n - r + 1); i--)
            ans =  (((ans % mod) * (i % mod)) % mod);
        return ans;
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

    public static void _sort(int[] arr,boolean isAscending){
        int n = arr.length;
        List<Integer> list = new ArrayList<>();
        for(int ele : arr)list.add(ele);
        Collections.sort(list);
        if(!isAscending)Collections.reverse(list);
        for(int i=0;i<n;i++)arr[i] = list.get(i);
    }

    public static void _sort(long[] arr,boolean isAscending){
        int n = arr.length;
        List<Long> list = new ArrayList<>();
        for(long ele : arr)list.add(ele);
        Collections.sort(list);
        if(!isAscending)Collections.reverse(list);
        for(int i=0;i<n;i++)arr[i] = list.get(i);
    }
    /*------------------------------------------HELPER FUNCTION ENDS HERE-------------------------------------------*/

    /*-------------------------------------------FAST INPUT STARTS HERE---------------------------------------------*/

    public static void closeIO() throws IOException{
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

        private static boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }

        private int skip() throws IOException {
            int b;
            //noinspection StatementWithEmptyBody
            while ((b = read()) != -1 && isSpaceChar(b)) {}
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
            if (neg) { c = read(); }
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg) { return -ret; }
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ') { c = read(); }
            final boolean neg = c == '-';
            if (neg) { c = read(); }
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg) { return -ret; }
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ') { c = read(); }
            final boolean neg = c == '-';
            if (neg) { c = read(); }

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg) { return -ret; }
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1) { buffer[0] = -1; }
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead) { fillBuffer(); }
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            din.close();
        }
    }
    /*---------------------------------------------FAST INPUT ENDS HERE ---------------------------------------------*/
}