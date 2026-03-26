import java.io.*;
import java.util.*;

public class M {
    public static void main(String[] args) {
        FastScanner x = new FastScanner();
        Integer t = x.nextInt();
        while (t-- > 0){
            Long max = (long) Integer.MIN_VALUE;
            Long min = (long)Integer.MAX_VALUE;
            Long res = 0L;
            boolean boo = true;
            int co = 0;
            Integer n = x.nextInt();
            Long[] arr = new Long[n];
            Long sum = 0L;
            for (int i = 0; i < n; i++) {
                arr[i] = x.nextLong();
                sum += arr[i];
                if (sum < 1){
                    boo = false;
                }
            }
            sum = 0L;
            for (int i = n - 1; i >= 0 ; i--) {
                sum += arr[i];
                if (sum < 1){
                    boo = false;
                }
            }


            if (boo){
                System.out.println("YES");
            }else{
                System.out.println("NO");
            }













        }
    }static Long getmax(Long[] arr){
        Long max = (long) Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            max = Math.max(max,arr[i]);
        }return max;

    }
    static String getter(String s, int ind,int len){
        char a1 = s.charAt(ind);
        char a2 = s.charAt(len);
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (i == ind){
                res.append(a2);
            } else if (i == len) {
                res.append(a1);
            }else{
                res.append(s.charAt(i));
            }
        }
        return res.toString();
    }
    static int shift(Integer[] arr,int l,int r,int k){
        Integer[] sarr = new Integer[arr.length];
        for (int i = 0; i < arr.length; i++) {
            sarr[i] = arr[i];
        }
        for (int i = 0; i < k; i++) {
            for (int j = l - 1; j < r - 1; j++) {
                arr[j + 1] = arr[j];
            }
            System.out.println(Arrays.toString(arr));
        }
        return arr[arr.length - 1] - arr[0];
    }

    static int lowerbound(Long[] arr,Long target){
        if(arr == null || arr.length == 0){
            return -1;
        }
        int l = 0;
        int r = arr.length - 1;

        while (l < r){
            int mid = (l + r) / 2;
            if (arr[mid] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        if (arr[l] >= target){
            return l;
        }
        return -1;
    }
    static int upperbound(Long[] arr,Long target){
        if (arr == null || arr.length == 0){
            return -1;
        }
        int l = 0;
        int r = arr.length - 1;
        while (l < r){
            int mid = (l + r) / 2;
            if (arr[mid] <= target){
                l = mid + 1;
            }else {
                r = mid;
            }


        }
        return arr[l] > target ? l : -1;

    }





    public static void rec(int N,String cur) {
        if (cur.length() == N) {
            System.out.println(cur);
            return;
        }
        rec(N, cur + "0");
        rec(N, cur + "1");
    }

    public static int intfromstring(String s){
        String[] nums = {"zero","one","two","three","four","five","six","seven","eight","nine","ten"};
        for (int i = 0; i < nums.length; i++) {
            if (s.equals(nums[i])){
                return i;
            }
        }return -1;
    }


    public static long NOK(long a,long b){
        return lcm(a,b);
    }static long gcd(long a,long b){
        return b == 0 ? a : gcd(b,a % b);
    }static long lcm(long a,long b){
        return a / gcd(a,b) * b;
    }

    public static long sum(long a){
        return a * (a - 1) / 2;
    }
    static boolean odd(int e){
        return e % 2 == 1;
    }static boolean even(int e){
        return e % 2 == 0;
    }


    static boolean isPrime(long n)
    {
        if (n <= 1){
            return false;}
        if (n <= 3){
            return true;}
        if (n % 2 == 0 || n % 3 == 0){
            return false;}
        for (int i = 5; (long) i * i <= n; i = i + 6){
            if (n % i == 0 || n % (i + 2) == 0){
                return false;}}
        return true;
    }static String arrtostring(long res[]){
        return Arrays.toString(res).replace(",","").replace("[","").replace("]","");
    }
    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextLine() {
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
            return Integer.parseInt(nextLine());
        }

        long nextLong() {
            return Long.parseLong(nextLine());
        }

        double nextDouble() {
            return Double.parseDouble(nextLine());
        }
        Integer[] readArray(int n) {
            Integer[] a=new Integer[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }
        Long[] readArrayLong(int n) {
            Long[] a=new Long[n];
            for (int i=0; i<n; i++) a[i]=nextLong();
            return a;
        }


    }

}