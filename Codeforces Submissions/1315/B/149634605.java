 import java.util.*;
import java.io.*;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.math.BigInteger;


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
 
    //Heapify function to maintain heap property.
    public static void swap(int i,int j,int arr[]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    static String endl = "\n" , gap = " ";
    public static int ans;
    public static void main(String[] args)throws IOException {
        int t = ri();
        while(t-->0) {
            solve();
        }
        out.close();
    }
    public static void solve()throws IOException {      
        int a = ri() , b = ri() , p = ri();
        char s[] = rac();
        int n = s.length;
        int prev = s[n-2];
        int sum = 0;
        if(s[n-2] == 'A') {
            if(p < a) {
                System.out.println(n);   
                return;
            }
        }
        if(s[n-2] == 'B') {
            if(p < b) {
              System.out.println(n);
              return;  
            } 
        }
        for(int i =n-3;i>=0;i--) {
            if(prev == s[i]) {
                continue;
            } 
            else {
                sum += (prev == 'A'?a : b);
                // System.out.println("sum iis " + sum);
                prev  = s[i];
                if(prev == 'A') {
                    if(sum + a >p )  {
                        System.out.println(i + 2);
                        return;
                    }
                }
                if(prev == 'B') {
                    if(sum + b > p) {
                        System.out.println(i + 2);
                        return;
                    }
                }
            }
        }
        System.out.println(1);
    }
    public static long get(long a) {
        long ans = 1;
        for(long i = (long)Math.sqrt(a);i>=1;i--) {
            if(i*(i+1l)/2l <= a) return i;
        }
        return ans;
    }
    public static long get2(long a) {
        long ans = 1;
        for(long i = (long)Math.sqrt(a);i>=1;i--) {
            if(i*(i+1)/2 < a ) return ans;
            ans = i;
        }
        return 1l;
    }
    public static long rl() {
        return sc.nextLong();
    }
    public static char[] rac() {
        return sc.next().toCharArray();
    }
    public static String rs() {
        return sc.next();
    }
    public static  int [] rai(int n) {
        int ans[] = new int[n];
        for(int i =0;i<n;i++) {
            ans[i] = sc.nextInt();
        }
        return ans;
    }
    public static  long [] ral(int n) {
        long ans[] = new long[n];
        for(int i =0;i<n;i++) {
            ans[i] = sc.nextLong();
        }
        return ans;
    }
    public static int ri() {
        return sc.nextInt();
    }

    public static int getValue(int num ) {
        int ans = 0;
        while(num > 0) {
            ans++;
            num = num&(num-1);
        }
        return ans;
    }
    public static boolean isValid(int x ,int y , int n,char arr[][],boolean visited[][][][])  {
        return x>=0 && x<n && y>=0 && y <n && !(arr[x][y] == '#');
    }
    // public static Pair join(Pair a , Pair b) {
    //     Pair res = new Pair(Math.min(a.min , b.min) , Math.max(a.max , b.max) , a.count + b.count);
    //     return res;
    // }
    
    // segment tree query over range
    // public static int query(int node,int l , int r,int a,int b ,Pair tree[] ) {
    //     if(tree[node].max < a || tree[node].min > b) return 0;
    //     if(l  > r) return 0;
    //     if(tree[node].min >= a && tree[node].max <= b) {
    //         return tree[node].count;   
    //     }
    //     int mid = l + (r-l)/2;
    //     int ans = query(node*2 ,l , mid ,a , b , tree) + query(node*2 +1,mid + 1, r , a , b, tree);
    //     return ans;
    // }
    // // segment tree update over range
    // public static void update(int node, int i , int j ,int l , int r,long value, long arr[] ) {
    //     if(l >= i && j >= r) {
    //         arr[node]   += value;
    //         return;
    //     }
    //     if(j < l|| r < i) return;
    //     int mid = l + (r-l)/2;
    //     update(node*2 ,i ,j ,l,mid,value, arr);
    //     update(node*2 +1,i ,j ,mid + 1,r, value  , arr);
    // }

    public static long pow(long a , long b  , long mod) {
        if(b == 1) return a;
        if(b == 0) return 1;
        long ans = pow(a , b/2 , mod)%mod;
        if(b%2 == 0) {
            return (ans*ans)%mod;
        }
        else {
            return ((ans*ans)%mod*a)%mod;
        }
    }
    
    
    public static boolean isVowel(char ch) {
        if(ch == 'a' || ch == 'e'||ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
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
            if(num%i==0 || num%(i+2) == 0) return false;
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