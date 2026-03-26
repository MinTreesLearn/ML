import java.io.*;
import java.util.*;
/*
20 50
20 3
5 16
1 3
10 11
10 15
15 9
20 9
14 6
16 5
13 4
11 5
3 20
13 17
11 8
11 6
12 14
16 18
17 13
18 7
3 1
8 10
17 15
7 2
9 13
5 11
6 1
2 16
8 18
10 8
4 13
9 15
14 12
1 6
9 20
7 18
6 14
7 6
18 16
2 7
3 11
15 17
3 12
14 10
4 14
19 4
11 10
4 19
8 12
17 8
12 8
16
7 2 16 5 11 8 10 15 9 13 4 14 6 1 3 20

5 8
 */
public class CodeForces {

    /*-------------------------------------------EDITING CODE STARTS HERE-------------------------------------------*/
    public static void solve(int tCase) throws IOException {
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList<Integer>[] adj = new ArrayList[n+1];
        for(int i=0;i<=n;i++)adj[i] = new ArrayList<>();
        for(int i=0;i<m;i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            adj[y].add(x);
        }
        int k = sc.nextInt();
        int[] path = new int[k];
        for(int i=0;i<k;i++)path[i] = sc.nextInt();
        int[] distance = new int[n+1];
        Arrays.fill(distance,n+20);
        int[] count = new int[n+1];
        Queue<int[]> q= new ArrayDeque<>();
        boolean[] isVis = new boolean[n+1];
        isVis[path[k-1]] =true;
        q.add(new int[]{path[k-1],0});
        distance[path[k-1]] = 0;
        while(!q.isEmpty()){
            int[] x = q.poll();
            for(int neig : adj[x[0]]){
                if(distance[neig] > x[1] + 1){
                    distance[neig] = x[1] + 1;
                    count[neig] = 0;
                }
                if(distance[neig] == x[1] + 1)count[neig]++;
                if(!isVis[neig]){
                    q.add(new int[]{neig,x[1]+1});
                    isVis[neig] = true;
                }
            }
        }
        int minDist = distance[path[0]];
        int minCount = 0;
        int maxCount = 0;
//        out.println(Arrays.toString(count)+" "+Arrays.toString(distance));
        for(int i=0;i<k-1;i++){
            if(distance[path[i]] == minDist){
                minDist--;
            }
            else {
                minCount++;
                minDist = distance[path[i]]-1;
            }
        }
//        out.println(Arrays.toString(count));
        minDist = distance[path[0]];
        for(int i=0;i<k-1;i++){
//            out.println(distance[path[i+1]]+" "+minDist);
            if(distance[path[i+1]] == minDist-1){
                if(count[path[i]]>1) maxCount++;
                minDist--;
            }else minDist = distance[path[i+1]];
        }
        out.println(minCount+" "+(minCount+maxCount));
    }



    public static void main(String[] args) throws IOException {
        long s = System.currentTimeMillis();
        openIO();
        int testCase = 1;
//        testCase = sc. nextInt();
        for (int i = 1; i <= testCase; i++) solve(i);
//        out.println((System.currentTimeMillis() - s)/1000d);
        closeIO();
    }

    /*-------------------------------------------EDITING CODE ENDS HERE-------------------------------------------*/
    /*--------------------------------------HELPER FUNCTIONS STARTS HERE-----------------------------------------*/

    public static int mod = (int) 1e9 + 7;
    //    public static int mod =  998244353;
    public static int inf_int = (int) 2e9;
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
            inverseFact[i] = _modExpo(factorial[i], mod - 2);
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
        while (a>0){
            long x = a;
            a = b % a;
            b = x;
        }
        return b;
//        if (a == 0)
//            return b;
//        return _gcd(b % a, a);
    }

    // lcm(a,b) * gcd(a,b) = a * b
    public static long _lcm(long a, long b) {
        return (a / _gcd(a, b)) * b;
    }

    // binary exponentiation time O(logn)
    public static long _modExpo(long x, long n) {
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
    // function to find a/b under modulo mod. time : O(logn)
    public static long _modInv(long a,long b){
        return (a * _modExpo(b,mod-2)) % mod;
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
        @Override
        public String toString(){
            return ff.toString()+" "+ss.toString();
        }
    }

    /*--------------------------------------HELPER FUNCTIONS ENDS HERE-----------------------------------------*/
    /*-------------------------------------------FAST INPUT STARTS HERE---------------------------------------------*/
    static FastestReader sc;
    static PrintWriter out;

    private static void openIO() throws IOException {
        sc = new FastestReader();
        out = new PrintWriter(System.out);
    }

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