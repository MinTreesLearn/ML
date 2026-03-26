 import java.util.*;
import java.io.*;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
public final class Main{
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
            din = new DataInputStream(
                new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                buf[cnt++] = (byte)c;
            }
            return new String(buf, 0, cnt);
        }
 
        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
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
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
 
        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ') c = read();
            boolean neg = (c == '-');
            if (neg) c = read();
 
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }
            if (neg) return -ret;
            return ret;
        }
 
        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0,
                                 BUFFER_SIZE);
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
    static class Kattio extends PrintWriter {
        private BufferedReader r;
        private StringTokenizer st;
    
        // standard input
        public Kattio() { this(System.in, System.out); }
        public Kattio(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }
        // USACO-style file input
        public Kattio(String problemName) throws IOException {
            super(new FileWriter(problemName + ".out"));
            r = new BufferedReader(new FileReader(problemName + ".in"));
        }
    
        // returns null if no more input
        public String next() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(r.readLine());
                return st.nextToken();
            } catch (Exception e) { }
            return null;
        }
    
        public int nextInt() { return Integer.parseInt(next()); }
        public double nextDouble() { return Double.parseDouble(next()); }
        public long nextLong() { return Long.parseLong(next()); }
    }   
    
    static Kattio sc = new Kattio();
    static long  mod  = (long)1e9+7;
    static PrintWriter out =new PrintWriter(System.out);
    public static void buildHeap(int arr[], int n) {
        for(int i = n/2-1;i>=0;i--) {
            heapify(arr,n,i);
        }
        
    }
 
    //Heapify function to maintain heap property.
    public static void heapify(int arr[], int n, int i) {
        int l = i*2 + 1 , r = i*2 + 2;
        int small = l;
        if(r<n&& arr[r]<arr[small]) {
            small = r;
        }
        if(l>=n || arr[i]< arr[small]) return;
        if(small != i)swap(small, i, arr);
        heapify(arr,n,small);
    }
    public static void swap(int i,int j,int arr[]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static void heapSort(int arr[], int n) {
        buildHeap(arr,n);
        System.out.println(Arrays.toString(arr));
        int ans[] = new int[n];
        int l = 0 , r = n-1;
        while(l<=r) {
            swap(l,r,arr);
            r--;
            heapify(arr,r + 1,0);
            
        }       
    }
    public static long getInversion(String a) {
        long zero =0;
        for(char ch : a.toCharArray()) {
            if(ch=='0') zero++;
        }
        long ans = 0;
        for(char ch : a.toCharArray()) {
            if(ch=='1') {
                ans += zero;
            }
            else zero--;
        }
        return  ans;
    }
    public static List<Integer> getAllParent (int node) {
        List<Integer> list = new ArrayList<>();
        while(node >= 1) {
            list.add(node);
            node /= 2;
        }
        return list;
    }
    public static boolean isSubsequence(String small, String big) {
        // System.out.println( small + " " + big);
        int i =0 , j = 0;
        while(i< small.length() && j < big.length()) {
            if(small.charAt(i) == big.charAt(j)) {
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        if(i >= small.length()) return true;
        else return false;
    }
    static long arr[][] = new long[1005][1005];
    public static void main(String[] args)throws IOException {
        int t = sc.nextInt();
        while(t-->0) {
            solve();
        }
        out.close();
    }
    public static void solve() throws IOException {        
        int n = sc.nextInt() , x = sc.nextInt();
        int arr[] = new int[n];
        int sum =0;
        for(int i = 0;i<n;i++) {
            arr[i] = sc.nextInt();
            sum += arr[i];
        }
        System.out.println(Math.min(x , sum));
    


    }
    public static long getx(long num) {
        for(long i =0;i<=64;i++) {
            if((1l<<i) == num) return i;
        }
        return 64;
    }
    public static long pow(long a , long b) {
        long mod = (long)1e9+7;
        if(b == 1) return a;
        if(b == 0) return 1;
        long ans = pow(a , b/2)%mod;
        if(b%2 == 0) {
            return (ans*ans)%mod;
        }
        else {
            return ((ans*ans)%mod*a)%mod;
        }
    }
    public static long getAns(int len) {
        long mod = 998244353l;
        if(len == 1) return 45;
        else {
            long min = pow(10 , len -1);
            long max = pow(10 , len) -1;
            long ans = (max - min + 1)%mod;
            ans = ((ans*(ans + 1))%mod)/2;
            return (ans + getAns(len -1))%mod;
        }
    }
    public static int maxLen(int[] arr, int n) {
        for(int i =0;i<n;i++) {
            if(arr[i] == 0)arr[i] = -1;
        }
        for(int i =1;i<n;i++) {
            arr[i] += arr[i-1];
        }
        System.out.println(Arrays.toString(arr));
        HashMap<Integer , Integer> map = new HashMap<>();
        map.put(0 ,-1);
        int ans = 0;
        for(int  i = 0;i<n;i++) {
            if(map.containsKey(arr[i]*-1)) {
                ans = Math.max(ans ,i -  map.get(arr[i]*-1));
            }
            map.putIfAbsent(arr[i] , i);
        }
        return ans;
    }
    public static int getDifference(char a[] , char b[] , int l1 , int r1,int l2,int r2) {
        int ans = 0;
        while(l1<=r1 && l2 <= r2) {
            if(a[l1] != b[l2]) ans++;
            l1++;
            l2++;
        }
        return ans;
    }

    public static long callfun(int x1 , int y1,int x2,int y2,long arr[][] , long memo[][]) {
        if(x1 == x2 && y1 ==  y2) return arr[x1][y1];
        if(x1 > x2) return Integer.MIN_VALUE;
        if(y1 > y2) return Integer.MIN_VALUE;
        if(memo[x1][y1] != -1) return memo[x1][y1];
        else {
            return memo[x1][y1] = arr[x1][y1] + Math.max(callfun(x1 + 1 ,y1 ,x2,y2,arr , memo ),callfun(x1 ,y1 + 1 ,x2,y2,arr , memo )); 
        }
    }
    public static boolean isVowel(char ch) {
        if(ch == 'a' || ch == 'e'||ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }

    
    
    public static String getAns(int i,int j,String s) {
        if(j>=s.length()) return s.charAt(i) + "";
        while(i>=0 && j<s.length() && s.charAt(i) == s.charAt(j)) {
            i--;
            j++;
        }
        return s.substring(i +1, j);
    }
    
    
    public static int getFactor(int num) {
        if(num==1) return 1;
        int ans = 2;
        int k = num/2;
        for(int i = 2;i<=k;i++) {
            if(num%i==0) ans++;
        }
        return Math.abs(ans);
    }
   


    public static int geti(char ch) {
        if(ch=='R') return 2;
        if(ch=='L') return 3;
        if(ch=='U') return 1;
        else return 0;
    }
    public static int[] readarr()throws IOException {
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i =0;i<n;i++) {
            arr[i] =  sc.nextInt();
        }
        return arr;
    }
 
    public static boolean isPowerOfTwo (long x) {
        return x!=0 && ((x&(x-1)) == 0);
    }
    public static boolean isPrime(long num) {
        if(num==1) return false;
        if(num<=3) return true;
        if(num%2==0||num%3==0) return false;
        for(long i =5;i*i<=num;i+=6) {
            if(num%i==0) return false;
        }
        return true;
    }
    public static boolean isPrime(int num) {
        if(num==1) return false;
        if(num<=3) return true;
        if(num%2==0||num%3==0) return false;
        for(int i =5;i*i<=num;i+=6) {
            if(num%i==0) return false;
        }
        return true;
    }
    public static long gcd(long a , long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public static long get_gcd(long a , long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public static long fac(long num)  {
        long ans = 1;
        int mod = (int)1e9+7;
        for(long i = 2;i<=num;i++) {
            ans  =  (ans*i)%mod;
        }
        return ans;
    }
}