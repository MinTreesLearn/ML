import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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

        int temp = a[i];
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


    public static void main(String[] args) throws Exception {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        while (t-- != 0) {


            String ans="";
            int n=sc.nextInt();
            String s=sc.next();
            for(int i=0;i<s.length();i++)
            {
                if((s.charAt(i)-'0')%2!=0)
                {
                    ans=ans+s.charAt(i);
                }
                if(ans.length()==2)
                {
                    break;
                }
            }
            if(ans.length()==2)
            {
                System.out.println(ans);
            }
            else{
                System.out.println("-1");
            }
        }

    }
}
