import java.io.*;
import java.util.*;
public class CP {
    static long startTime;
    static long endTime;
    static Boolean [] prime ;
    static int M=(int)1e9+7;
    static int MAX=Integer.MAX_VALUE;
    static int MIN=Integer.MIN_VALUE;
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
    static void printArray(long arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
    static void printArray(Integer arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
    static void printArray(Long arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
    static void yes(){
        System.out.println("YES");
    }
    static void no(){
        System.out.println("NO");
    }
    public static int lowerBound
            (Integer[] array, int length, int value) {
        int l = 0;
        int r = length;
        while (l < r) {
            int mid = (l + r) / 2;
            if (value < array[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    public static long gcd(long a, long b){
        if (b == 0)
            return a;
        else return gcd(b, a % b);
    }
    public  static  long countDivs(long n ){
        int cn=0;
        long sqr = (long)Math.sqrt(n);
        for (long i = 1; i<=sqr ; ++i) {
            if(n%i==0){
                ++cn;
            }
        }
        cn*=2;
        if(sqr*sqr==n) cn--;
        return cn;

    }
    static void prime(int  x) {
        //sieve algorithm. nlog(log(n)).
        prime=new Boolean[ (x+1)];
        Arrays.fill(prime,true);
        prime[0] = prime[1] = false;
        for (int  i = 2; i * i <= x ; i++)
            if (prime[i])
                for (int  j = i * i; j <= x; j += i)
                    prime[j] = false;
    }
    static int[] sum;
    static void cumulitiveSum( int [] arr){
        sum = new int[arr.length];
        sum[0]=arr[0];
        for (int i = 1; i <arr.length; i++) {
            sum[i]=arr[i]+sum[i-1];
        }
    }
    static boolean isEven(long x ){
        return x % 2 == 0;
    }
    static boolean isPrime(long x ){
        boolean flag = true;
        int sqr = (int)Math.sqrt(x);
        if(x<2) return false;
        for (int i = 2; i <=sqr; i++) {
            if(x%i==0){
                flag=false;
                break;
            }
        }
        return flag;
    }
    static long factorial( long x) {
        long total = 1;
        for (int i = 2; i <= x; i++)
            total *= i;
        return total;
    }
    static long power(long x, long n) {
        if (n == 0) {
            return 1;
        }

        long pow = power(x, n / 2L);
        if ((n & 1) == 1) {
            return x * pow * pow;
        }

        return pow * pow;
    }

    public static void main(String [] args) {
        startTime = System.currentTimeMillis();
       // int T = sc.nextInt();while (T--!=0)
        {
            solve();
        }
        endTime = System.currentTimeMillis();
        long duration= endTime-startTime;
        //System.out.println(duration);
    }

    //  static Scanner sc = new Scanner(System.in);
    static FastReader sc = new FastReader();
    public static void solve()  {
//////////////////////////////////////////////////////////////////////
       int n =sc.nextInt();
      String s =sc.next();
      int l=0,r=0;
        for (int i = 0; i < n; i++) {
                if(s.charAt(i)=='(') l++;
                else r++;
        }
        int ans=0;
        if(l!=r) {
            System.out.println(-1);
            return;
        }

        else {
            l=0;r=0;

            for (int i = 0; i < n; i++) {
                    if(s.charAt(i)==')'){
                        if(l>0){
                            l--;
                        }
                      else r++;
                    }
                    else {
                        if(r>0){
                            ans+=2*r;
                            l-=r;
                        }
                        r=0;
                        l++;

                    }
            }
        }
        ans+=2*r;
        System.out.println(ans);
///////////////////////////////////////////////////////////////////////
    }

}
