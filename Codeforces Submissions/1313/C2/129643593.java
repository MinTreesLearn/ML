import java.io.*;
import java.util.*;

public class CodeForces{
    /*****************************************WRITING CODE STARTS HERE******************************************/
    public static void solve(int tCase)throws IOException {
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++ )arr[i] = sc.nextInt();
        int[] smallerOnLeft = new int[n];
        Deque<Integer> st = new ArrayDeque<>();
        for(int i=0;i<n;i++){
            while (!st.isEmpty() && arr[st.peek()] >= arr[i])st.pop();
            smallerOnLeft[i] = st.isEmpty()?-1:st.peek();
            st.push(i);
        }
        st.clear();
        int[] smallerOnRight = new int[n];
        for(int i=n-1;i>=0;i--){
            while(!st.isEmpty() && arr[st.peek()] >= arr[i])st.pop();
            smallerOnRight[i] = st.isEmpty()?-1:st.peek();
            st.push(i);
        }
        long[] leftDp = new long[n];
        long[] rightDp = new long[n];
        Arrays.fill(leftDp,-1);
        Arrays.fill(rightDp,-1);
        long ans = 0;
        int ind = -1;
        for(int i=0;i<n;i++){
            long curr = leftSum(i,arr,smallerOnLeft,leftDp) + rightSum(i,arr,smallerOnRight,rightDp) - arr[i];
            if(curr>ans){
                ind = i;
                ans =  curr;
            }
//            out.println(curr);
        }
        int[] res = new int[n];
        res[ind] = arr[ind];
        int leftVal = arr[ind];
        for(int i=ind-1;i>=0;i--){
            leftVal = Math.min(leftVal,arr[i]);
            res[i] = leftVal;
        }
        int rightVal = arr[ind];
        for(int i=ind+1;i<n;i++){
            rightVal = Math.min(rightVal,arr[i]);
            res[i] = rightVal;
        }
        for(int ele : res)out.print(ele+" ");

    }
    private static long leftSum(int i,int[] arr,int[] smallerOnLeft,long[] leftDp){
        long ans = 0;
        if(leftDp[i]!=-1)return leftDp[i];
        if(smallerOnLeft[i]==-1)ans =  (long) arr[i] *(i+1);
        else{
            ans = leftSum(smallerOnLeft[i],arr,smallerOnLeft,leftDp) +
                    (long) (i - smallerOnLeft[i]) * arr[i];
        }
        return leftDp[i] = ans;
    }
    private static long rightSum(int i,int[] arr,int[] smallerOnRight,long[] rightDp){
        long ans = 0;
        if(rightDp[i]!=-1)return rightDp[i];
        if(smallerOnRight[i]==-1)ans =  (long) arr[i] *(arr.length-i);
        else{
            ans = rightSum(smallerOnRight[i],arr,smallerOnRight,rightDp) +
                    (long) (smallerOnRight[i] - i) * arr[i];
        }
        return rightDp[i] = ans;
    }



    /*****************************************WRITING CODE ENDS HERE******************************************/
    public static void main(String[] args) throws IOException{
        openIO();
        int testCase = 1;
//        testCase = sc.nextInt();
        for (int i = 1; i <= testCase; i++) solve(i);
        closeIO();
    }
    static FastestReader sc;
    static PrintWriter out;
    private static void openIO() throws IOException{
         sc = new FastestReader();
         out = new PrintWriter(System.out);
    }

    /**************************************HELPER FUNCTION STARTS HERE ************************************/

    public static int mod = (int) 1e9 +7;
    public static  int inf_int = (int) 1e9;
    public static  long inf_long = (long) 1e15;

    public static final String YES = "YES";
    public static final String NO = "NO";

    // euclidean algorithm time O(max (loga ,logb))
    public static long _gcd(long a, long b) {
        long x = Math.min(a, b);
        long y = Math.max(a, b);
        if (y % x == 0) return x;
        return _gcd(y % x, x);
    }

    public static long _lcm(long a, long b) {
        // lcm(a,b) * gcd(a,b) = a * b
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
    //sieve/first divisor time : O(mx * log ( log (mx) ) )
    public static int[]  seive(int mx){
        int[] firstDivisor = new int[mx+1];
        for(int i=0;i<=mx;i++)firstDivisor[i] = i;
        for(int i=2;i*i<=mx;i++)
            if(firstDivisor[i] == i)
                for(int j = i*i;j<=mx;j+=i)
                    firstDivisor[j] = i;
        return firstDivisor;
    }


    /**************************************HELPER FUNCTION ENDS HERE ************************************/

    /*****************************************FAST INPUT STARTS HERE *************************************/

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
    /*****************************************FAST INPUT ENDS HERE *************************************/
}
