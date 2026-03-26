//package prog_temps;


import java.lang.reflect.Array;
import java.util.*;
import java.io.*;
//166666500+833333500

public class Java_Template {
    static boolean[] primecheck = new boolean[1000002];
    static int M = 1000000007;
    static int mn = Integer.MIN_VALUE;
    static int mx = Integer.MAX_VALUE;
    static int vis[];
    static ArrayList<ArrayList<Integer>> list;

    public static void solve(FastReader sc, PrintWriter w) throws Exception {
        int n  =sc.nI(),k  =sc.nI();
        int count =0;
        String arr[] = new String[n];
        HashMap<String, Integer> map =  new HashMap<>();
        for(int i=0;i<n;i++) {
            arr[i] = sc.nextLine();
            if (map.containsKey(arr[i])) {
                map.put(arr[i], map.get(arr[i]) + 1);
            } else{
                map.put(arr[i], 1);
            }
        }
        String chkr ="";
        for (int i = 0; i < n ; i++) {
            for (int j = i+1; j <n ; j++) {
                // i and j are first 2 sets;
                chkr  ="";
                for (int l = 0; l < k; l++) {
                    if(arr[i].charAt(l)==arr[j].charAt(l)) {
                        chkr += arr[i].charAt(l);
                    }
                    else {
                        chkr += (char) ('S' + 'E' + 'T' - arr[i].charAt(l) - arr[j].charAt(l));
                    }
                }
                if(map.containsKey(chkr)){
                    count +=map.get(chkr);
                }

                if(arr[i].equals(arr[j])){
                    count -=2;
                }
            }
        }


        w.println(count/3);



    }


    public static void main(String[] args) throws Exception {
        FastReader sc = new FastReader();
        PrintWriter w = new PrintWriter(System.out);


        int t = 1;
        //t = sc.nI();
        while (t-- > 0) {
            solve(sc, w);
        }
        w.close();

    }

    //
    public static void matSort(int[][] arr, int l, int r, int row, int index) {
        if (l < r) {
            // Find the middle point
            int m = l + (r - l) / 2;

            // Sort first and second halves
            matSort(arr, l, m, row, index);
            matSort(arr, m + 1, r, row, index);

            // Merge the sorted halves
            matMerge(arr, l, m, r, row, index);
        }
    }

    public static void matMerge(int[][] arr, int l, int m, int r, int row, int index) {
        // Find sizes of two subarrays to be merged
        int n1 = m - l + 1;
        int n2 = r - m;

        /* Create temp arrays */
        int[][] L = new int[2][n1];
        int[][] R = new int[2][n2];

        /*Copy data to temp arrays*/
        for (int i = 0; i < n1; ++i) {
            L[0][i] = arr[row][l + i];
            L[1][i] = arr[index][l + i];
        }
        for (int j = 0; j < n2; ++j) {
            R[0][j] = arr[row][m + 1 + j];
            R[1][j] = arr[index][m + 1 + j];
        }

        /* Merge the temp arrays */

        // Initial indexes of first and second subarrays
        int i = 0, j = 0;

        // Initial index of merged subarry array
        int k = l;
        while (i < n1 && j < n2) {
            if (L[0][i] <= R[0][j]) {
                arr[row][k] = L[0][i];
                arr[index][k] = L[1][i];
                i++;
            } else {
                arr[row][k] = R[0][j];
                arr[index][k] = R[1][j];
                j++;
            }
            k++;
        }

        /* Copy remaining elements of L[] if any */
        while (i < n1) {
            arr[row][k] = L[0][i];
            arr[index][k] = L[1][i];
            i++;
            k++;
        }

        /* Copy remaining elements of R[] if any */
        while (j < n2) {
            arr[row][k] = R[0][j];
            arr[index][k] = R[1][j];
            j++;
            k++;
        }
    }


    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
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

        int nI() {
            return Integer.parseInt(next());
        }

        long nL() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        float nextFloat() {
            return Float.parseFloat(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        void readArr(int[] ar, int n) {
            for (int i = 0; i < n; i++) {
                ar[i] = nI();
            }
        }

    }

    public static boolean perfectSqr(long a) {
        long sqrt = (long) Math.sqrt(a);
        if (sqrt * sqrt == a) {
            return true;

        }
        return false;
    }


    public static void Sieve(int n) {

        Arrays.fill(primecheck, true);
        primecheck[0] = false;
        primecheck[1] = false;

        for (int i = 2; i * i < n + 1; i++) {
            if (primecheck[i]) {
                for (int j = i * 2; j < n + 1; j += i) {
                    primecheck[j] = false;
                }
            }
        }
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static long power(long x, long y) {
        long res = 1;     // Initialize result

        while (y > 0) {

            // If y is odd, multiply x with result
            if ((y & 1) != 0)
                res = res * x;

            // y must be even now
            y = y >> 1; // y = y/2
            x = x * x;  // Change x to x^2
        }
        return res;
    }

    public static void sort(int[] arr, int l, int r) {
        if (l < r) {
            // Find the middle point
            int m = l + (r - l) / 2;

            // Sort first and second halves
            sort(arr, l, m);
            sort(arr, m + 1, r);

            // Merge the sorted halves
            merge(arr, l, m, r);
        }
    }

    public static void merge(int[] arr, int l, int m, int r) {
        // Find sizes of two subarrays to be merged
        int n1 = m - l + 1;
        int n2 = r - m;

        /* Create temp arrays */
        int L[] = new int[n1];
        int R[] = new int[n2];

        /*Copy data to temp arrays*/
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];

        /* Merge the temp arrays */

        // Initial indexes of first and second subarrays
        int i = 0, j = 0;

        // Initial index of merged subarry array
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy remaining elements of L[] if any */
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        /* Copy remaining elements of R[] if any */
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }


}