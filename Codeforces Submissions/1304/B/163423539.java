import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;
public class Main {
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

    public static void heapify(int arr[], int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;


        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            heapify(arr, n, largest);
        }
    }


    public static void swap(int[] a, int i, int j) {

        int temp = (int) a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    public static int lcm(int a, int b) {
        return (a * b / gcd(a, b));
    }

    public static String sortString(String inputString) {
        // Converting input string to character array
        char[] tempArray = inputString.toCharArray();

        // Sorting temp array using
        Arrays.sort(tempArray);

        // Returning new sorted string
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
    static  int pown(long n){
        if(n==0)
            return 1;
        if(n==1)
            return 1;
        if((n&(~(n-1)))==n)
            return 0;
        return 1;

    }

    static long computeXOR(long n) {
        // If n is a multiple of 4
        if (n % 4 == 0)
            return n;

        // If n%4 gives remainder 1
        if (n % 4 == 1)
            return 1;

        // If n%4 gives remainder 2
        if (n % 4 == 2)
            return n + 1;

        // If n%4 gives remainder 3
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

   static String reverseString(String str){
        char ch[]=str.toCharArray();
        String rev="";
        for(int i=ch.length-1;i>=0;i--){
            rev+=ch[i];
        }
        return rev;
    }


    public static void main(String[] args) throws Exception {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        int m = sc.nextInt();

        HashSet<String> set = new HashSet<String>();

        String s1="", s2="", pal="";

        for(int i=0; i<n; i++){
            String s = sc.next();
            String rev = reverseString(s);
            if(s.equals(rev))//لو الحروف شبه بعضها
                pal = s;
            else if(set.contains(rev)){
                set.remove(rev);
                s1 += rev;
                s2 = s + s2;
            }else{
                set.add(s);
            }
        }

        String s = s1 + pal + s2;
        System.out.println(s.length() + "\n" + s);

    }

}