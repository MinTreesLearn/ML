import java.awt.image.AreaAveragingScaleFilter;
import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

public class Pratice {

    static final long mod = 1000000007;
    static StringBuilder sb = new StringBuilder();
    static int xn = (int) (2e5 + 10);
    static long ans;
    static boolean prime[] = new boolean[1000001];

    // calculate sqrt and cuberoot
//    static Set<Long> set=new TreeSet<>();
//    static
//    {
//        long n=1000000001;
//
//
//        for(int i=1;i*i<=n;i++)
//        {
//            long x=i*i;
//            set.add(x);
//        }

//        for(int i=1;i*i*i<=n;i++)
//        {
//            long x=i*i*i;
//            set.add(x);
//        }

//    }


    static void sieveOfEratosthenes() {


        for (int i = 0; i <= 1000000; i++)
            prime[i] = true;
        prime[0] = false;
        prime[1] = false;

        for (int p = 2; p * p <= 1000000; p++) {

            if (prime[p] == true) {

                for (int i = p * p; i <= 1000000; i += p)
                    prime[i] = false;
            }
        }


    }








    public static void main(String[] args) throws IOException {
        Reader reader = new Reader();
        int t = reader.nextInt();
        while (t-- > 0) {


            int n=reader.nextInt();
            int arr[]=new int[2*n];
            Map<Integer,Integer> map=new HashMap<>();
            Set<Integer> set=new HashSet<>();
            for (int i = 0; i <2* n; i++) {
                arr[i]=reader.nextInt();
            }

            Arrays.sort(arr);


                System.out.println(Math.abs(arr[n-1]-arr[n]));
            









           
















        }
    }























//    }


























































//    static void SieveOfEratosthenes(int n, boolean prime[],
//                                    boolean primesquare[], int a[])
//    {
//        // Create a boolean array "prime[0..n]" and
//        // initialize all entries it as true. A value
//        // in prime[i] will finally be false if i is
//        // Not a prime, else true.
//        for (int i = 2; i <= n; i++)
//            prime[i] = true;
//
//        /* Create a boolean array "primesquare[0..n*n+1]"
//         and initialize all entries it as false.
//         A value in squareprime[i] will finally
//         be true if i is square of prime,
//         else false.*/
//        for (int i = 0; i < ((n * n) + 1); i++)
//            primesquare[i] = false;
//
//        // 1 is not a prime number
//        prime[1] = false;
//
//        for (int p = 2; p * p <= n; p++) {
//            // If prime[p] is not changed,
//            // then it is a prime
//            if (prime[p] == true) {
//                // Update all multiples of p
//                for (int i = p * 2; i <= n; i += p)
//                    prime[i] = false;
//            }
//        }
//
//        int j = 0;
//        for (int p = 2; p <= n; p++) {
//            if (prime[p]) {
//
//                a[j] = p;
//
//
//                primesquare[p * p] = true;
//                j++;
//            }
//        }
//    }
//
//
//    static int countDivisors(int n)
//    {
//
//        if (n == 1)
//            return 1;
//
//        boolean prime[] = new boolean[n + 1];
//        boolean primesquare[] = new boolean[(n * n) + 1];
//
//        int a[] = new int[n];
//
//
//        SieveOfEratosthenes(n, prime, primesquare, a);
//
//
//        int ans = 1;
//
//        // Loop for counting factors of n
//        for (int i = 0;; i++) {
//            // a[i] is not less than cube root n
//            if (a[i] * a[i] * a[i] > n)
//                break;
//
//            int cnt = 1;
//
//            // if a[i] is a factor of n
//            while (n % a[i] == 0) {
//                n = n / a[i];
//
//                // incrementing power
//                cnt = cnt + 1;
//            }
//
//
//            ans = ans * cnt;
//        }
//
//
//        if (prime[n])
//            ans = ans * 2;
//
//            // Second case
//        else if (primesquare[n])
//            ans = ans * 3;
//
//            // Third case
//        else if (n != 1)
//            ans = ans * 4;
//
//        return ans; // Total divisors
//    }








    public static long[] inarr(long n) throws IOException {
        Reader reader = new Reader();
        long arr[]=new long[(int) n];
        for (long i = 0; i < n; i++) {
            arr[(int) i]=reader.nextLong();
        }

        return arr;

    }

    public static boolean checkPerfectSquare(int number)
    {
        int x=number % 10;

        if (x==2 || x==3 || x==7 || x==8)
        {
            return false;
        }
        for (int i=0; i<=number/2 + 1; i++)
        {
            if (i*i==number)
            {
                return true;
            }
        }
        return false;
    }

    // check number is prime or not
    public static boolean isPrime(int n) {
        return BigInteger.valueOf(n).isProbablePrime(1);
    }

    // return the gcd of two numbers
    public static long gcd(long a, long b)
    {
        BigInteger b1 = BigInteger.valueOf(a);
        BigInteger b2 = BigInteger.valueOf(b);
        BigInteger gcd = b1.gcd(b2);
        return gcd.longValue();
    }

    // return lcm of number
    static long lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }



    // number of digits in the given number
    public static long numberOfDigits(long n)
    {
        long ans= (long) (Math.floor((Math.log10(n)))+1);
        return ans;
    }

    // return most significant bit in the number
    public static long mostSignificantNumber(long n)
    {
        double k=Math.log10(n);
        k=k-Math.floor(k);

        int ans=(int)Math.pow(10,k);
        return ans;
    }


    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }
}
