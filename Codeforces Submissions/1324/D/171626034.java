import java.io.*;
import java.util.*;

public class Mainn {

    static StringBuilder sb = new StringBuilder();

    static long M = (long) (1e9 + 7);

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;


        public FastReader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                if (st.hasMoreTokens()) {
                    str = st.nextToken("\n");
                } else {
                    str = br.readLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }


    }

    public static void swap(int[] a, long i, long j) {

        long temp = a[(int) i];
        a[(int) i] = a[(int) j];
        a[(int) j] = (int) temp;
    }

    public static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    public static int lcm(int a, int b) {
        return (int) (a * b / gcd(a, b));
    }

    public static String sortString(String inputString) {
        char[] tempArray = inputString.toCharArray();

        Arrays.sort(tempArray);

        return new String(tempArray);
    }

    static boolean isSquare(int n) {
        int v = (int) Math.sqrt(n);

        return v * v == n;
    }

    static boolean PowerOfTwo(int n) {
        if (n == 0) return false;
        return (int) (Math.ceil((Math.log(n) / Math.log(2)))) ==
                (int) (Math.floor(((Math.log(n) / Math.log(2)))));
    }

    static int power(long a, long b) {
        long res = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                res = (res * a) % M;
            }
            a = ((a * a) % M);
            b = b / 2;
        }
        return (int) res;

    }

    public static boolean isPrime(int n) {
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) {
                return false;
            }

        return true;
    }

    static long computeXOR(long n) {
        if (n % 4 == 0)
            return n;
        if (n % 4 == 1)
            return 1;
        if (n % 4 == 2)
            return n + 1;
        return 0;
    }

    static long binaryToInteger(String binary) {
        char[] numbers = binary.toCharArray();
        long result = 0;
        for (int i = numbers.length - 1; i >= 0; i--)
            if (numbers[i] == '1')
                result += Math.pow(2, (numbers.length - i - 1));
        return result;
    }

    static String reverseString(String str) {
        char ch[] = str.toCharArray();
        String rev = "";
        for (int i = ch.length - 1; i >= 0; i--) {
            rev += ch[i];
        }
        return rev;
    }

    static int countFreq(int[] arr, int n) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int x = 0;
        for (int i = 0; i < n; i++) {
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
        }
        for (int i = 0; i < n; i++) {
            if (map.get(arr[i]) == 1)
                x++;
        }
        return x;
    }

    static void reverse(int[] arr, int l, int r) {
        int d = (r - l + 1) / 2;
        for (int i = 0; i < d; i++) {
            int t = arr[l + i];
            arr[l + i] = arr[r - i];
            arr[r - i] = t;
        }
    }

    static void sort(String[] s, int n) {
        for (int i = 1; i < n; i++) {
            String temp = s[i];

            int j = i - 1;
            while (j >= 0 && temp.length() < s[j].length()) {
                s[j + 1] = s[j];
                j--;
            }
            s[j + 1] = temp;
        }
    }

    static int sqr(int n) {
        double x = Math.sqrt(n);
        if ((int) x == x)
            return (int) x;
        else
            return (int) (x + 1);
    }

    static class Pair implements Comparable<Pair> {
        int start, end;

        public Pair(int x, int y) {
            this.start = x;
            this.end = y;
        }

        @Override
        public int compareTo(Pair p) {
            if (start == p.start) {
                return end - p.end;
            }
            return start - p.start;
        }
    }

    static int set_bits_count(int num) {
        int count = 0;
        while (num > 0) {
            num &= (num - 1);
            count++;
        }
        return count;
    }

    static double factorial(double n)
    {
        double f=1;
        for(int i=1;i<=n;i++)
        {
            f=f*i;
        }
        return f;
    }

    static boolean palindrome(int arr[], int n) {
        boolean flag = true;

        for (int i = 0; i <= n / 2 && n != 0; i++) {
            if (arr[i] != arr[n - i - 1]) {
                flag = false;
                break;
            }
        }
        return flag;
    }

    public static boolean isSorted(int[] a) {
        if (a == null || a.length <= 1) {
            return true;
        }

        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] > a[i + 1]) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        FastReader sc = new FastReader();
        PrintWriter pw = new PrintWriter(System.out);



        int n=sc.nextInt();
        int[] a=new int[n];
        int[] b=new int[n];
        Integer[] c=new Integer[n];
        long ans=0;
        for (int i=0;i<n;++i) {
            a[i]=sc.nextInt();
        }
        for (int i=0;i<n;++i) {
            b[i]=sc.nextInt();
            c[i]=a[i]-b[i];
        }
        Arrays.sort(c);
        int l=0,r=n-1;
        while(l<r){
            if ((c[r]+c[l])>0) {
                ans+=r-l;
                --r;
            }
            else{
                ++l;
            }
        }
        System.out.println(ans);
    }





    static void solve() throws IOException {

    }
}




