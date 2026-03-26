import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {

    public static int mod = (int) 1e9 + 7;

    // **** -----> Disjoint Set Union(DSU) Start **********

    public static int findPar(int node, int[] parent) {
        if (parent[node] == node)
            return node;

        return parent[node] = findPar(parent[node], parent);
    }

    public static boolean union(int u, int v, int[] rank, int[] parent) {
        u = findPar(u, parent);
        v = findPar(v, parent);
        if(u == v) return false;
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else {
            parent[u] = v;
            rank[v]++;
        }

        return true;
    }

    // **** DSU Ends ***********

    public static String toBinary(int decimal) {StringBuilder sb = new StringBuilder();while (decimal > 0) {sb.append(decimal % 2);decimal = decimal / 2;}return sb.reverse().toString();}
    public static boolean isPalindrome(String s) {int i = 0, j = s.length() - 1;while (i < j) {if (s.charAt(i) != s.charAt(j))return false;i++;j--;}return true;}
    public static boolean isPalindrome(int[] arr) {int i = 0, j = arr.length - 1;while (i < j) {if (arr[i] != arr[j])return false;}return true;}
    public static int pow(int x, int y) {int res = 1;x = x % mod;if (x == 0)return 0;while (y > 0) {if ((y & 1) != 0)res = (res * x) % mod;y = y >> 1;x = (x * x) % mod;}return res;}
    public static int gcd(int a, int b) {if (b == 0)return a;return gcd(b, a % b);}
    public static long gcd(long a, long b) {if (b == 0)return a;return gcd(b, a % b);}
    public static void sort(long[] a) {Random rnd = new Random();for (int i = 0; i < a.length; i++) {int pos = i + rnd.nextInt(a.length - i);long temp = a[i];a[i] = a[pos];a[pos] = temp;}Arrays.sort(a);}
    public static void reverse(int a[]) {int i, k, t, n = a.length;for (i = 0; i < n / 2; i++) {t = a[i];a[i] = a[n - i - 1];a[n - i - 1] = t;}}
    public static void sort(int[] a) {Random rnd = new Random();for (int i = 0; i < a.length; i++) {int pos = i + rnd.nextInt(a.length - i);int temp = a[i];a[i] = a[pos];a[pos] = temp;}Arrays.sort(a);}
    public static void revSort(int[] a) {Random rnd = new Random();for (int i = 0; i < a.length; i++) {int pos = i + rnd.nextInt(a.length - i);int temp = a[i];a[i] = a[pos];a[pos] = temp;}Arrays.sort(a);reverse(a);}
    public static long LCM(long a, long b) {if (a > b) {long t = a;a = b;b = t;}a /= gcd(a, b);return (a * b);}
    public static int findMax(int[] a, int left, int right) {int res = left;int max = a[left];for (int i = left + 1; i <= right; i++) {if (a[i] > max) {max = a[i];res = i;}}return res;}
    public static long findClosest(long arr[], long target) {int n = arr.length;if (target <= arr[0])return arr[0];if (target >= arr[n - 1])return arr[n - 1];int i = 0, j = n, mid = 0;while (i < j) {mid = (i + j) / 2;if (arr[mid] == target)return arr[mid];if (target < arr[mid]) {if (mid > 0 && target > arr[mid - 1])return getClosest(arr[mid - 1], arr[mid], target);j = mid;} else {if (mid < n - 1 && target < arr[mid + 1])return getClosest(arr[mid], arr[mid + 1], target);i = mid + 1;}}return arr[mid];}
    public static long getClosest(long val1, long val2, long target) {if (target - val1 >= val2 - target)return val2;else return val1;}
    public static int findClosest(int arr[], int target) { int n = arr.length; if (target <= arr[0]) return arr[0]; if (target >= arr[n - 1]) return arr[n - 1]; int i = 0, j = n, mid = 0; while (i < j) { mid = (i + j) / 2; if (arr[mid] == target) return arr[mid];if (target < arr[mid]) {if (mid > 0 && target > arr[mid - 1])return getClosest(arr[mid - 1], arr[mid], target);j = mid;} else {if (mid < n - 1 && target < arr[mid + 1])return getClosest(arr[mid], arr[mid + 1], target);i = mid + 1;}}return arr[mid];}
    public static int getClosest(int val1, int val2, int target) {if (target - val1 >= val2 - target)return val2;else return val1;}
    public static String reverse(String str) {String nstr = "";char ch;for (int i = 0; i < str.length(); i++) {ch = str.charAt(i);nstr = ch + nstr;}return nstr;}
    public static boolean isPrime(int n){if (n <= 1)return false;if (n <= 3)return true;if (n % 2 == 0 || n % 3 == 0)return false;for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false;return true;}
    public static int xorSum(int arr[], int n){int bits = 0;for (int i = 0; i < n; ++i)bits |= arr[i];int ans = bits * (int)Math.pow(2, n-1);return ans;}
    public static ArrayList<Integer> primeFactors(int n) { ArrayList<Integer> res = new ArrayList<>();while (n%2 == 0) { res.add(2); n = n/2; } for (int i = 3; i <= Math.sqrt(n); i = i+2) { while (n%i == 0) { res.add(i); n = n/i; } } if (n > 2) res.add(n);return res;}
    static int lower_bound(int array[], int low, int high, int key){
        int mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (key <= array[mid]) high = mid;
            else low = mid + 1;
        }
        if (low < array.length && array[low] < key) low++;
        return low;
    }
/********************************* Start Here ***********************************/

    public static void main(String[] args) throws java.lang.Exception {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            PrintStream ps = new PrintStream(new File("output.txt"));
            System.setOut(ps);
        }
        FastScanner sc = new FastScanner("input.txt");
        int T = sc.nextInt();
        // int T = 1;
        while (T-- > 0) {
            int n = sc.nextInt();
            String s = sc.next();
            char ch = 'z';
            for(int i = 0; i < n; i++){
                if(s.charAt(i) < ch) ch = s.charAt(i);
            }
            StringBuilder res = new StringBuilder(s);
            // System.out.println(ch);
            int ans = 1;
            for(int i = 0; i < n; i++){
                if(s.charAt(i)==ch){
                    StringBuilder tmp = new StringBuilder(s.substring(i));
                    if((n-i)%2==0){
                        tmp.append(s.substring(0, i));
                    }else {
                        for(int j = i-1; j >= 0; j--){
                            tmp.append(s.charAt(j));
                        }
                    }

                    int num = res.compareTo(tmp);
                    if(num > 0) {
                        res = tmp;
                        ans = i+1;
                    }
                    // System.out.println(res +" " + tmp);
                }
            }
            System.out.println(res);
            System.out.println(ans);
            
        }
        System.out.close();
    }

    // public static long solve(StringBuilder s1, StringBuilder s2, int i, int[] dp){
    //     if(i == s1.length()){
    //         return 0;
    //     }
    //     if(dp[i] != -1) return dp[i];
        
    //     if(s2.charAt(i)=='0'){

    //     }
    //     return res;
    // }

    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                br = new BufferedReader(new InputStreamReader(System.in));
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public String nextLine() {
            if (st == null || !st.hasMoreTokens()) {
                try {
                    return br.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken("\n");
        }

        public String[] readStringArray(int n) {
            String[] a = new String[n];
            for (int i = 0; i < n; i++) {
                a[i] = next();
            }
            return a;
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        String next() {
            return nextToken();
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] readLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }

        int[][] read2dArray(int n, int m) {
            int[][] a = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = nextInt();
                }
            }
            return a;
        }

        long[][] read2dlongArray(int n, int m) {
            long[][] a = new long[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = nextLong();
                }
            }
            return a;
        }
    }
}
