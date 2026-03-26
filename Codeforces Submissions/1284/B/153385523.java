import com.sun.security.jgss.GSSUtil;

import java.lang.reflect.Array;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Solution {

    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

//        int t = Reader.nextInt();
        int t = 1;
        while(t-->0){
            int n = Reader.nextInt();
            long ans = 0;
            int x = n;
            ArrayList<int[]> arr = new ArrayList<>();
            for(int i = 0;i<n;i++){
                int size = Reader.nextInt();
                int max = Integer.MIN_VALUE;
                int min = Integer.MAX_VALUE;
                int min_so_far = Integer.MAX_VALUE;
                boolean flag = false;
                for(int j = 0;j<size;j++){
                    int num = Reader.nextInt();
                    max = Math.max(max,num);
                    min = Math.min(min,num);
                    if(num<min_so_far){
                        min_so_far = num;
                    }
                    else if(num>min_so_far){
                        flag = true;
                    }
                }
                if(flag){
                    ans += 2L*x-1;
                    x--;
                }
                else{
                    arr.add(new int[]{min,max});
                }
            }

            arr.sort((n1,n2)->n1[1]-n2[1]);
            for(int i = 0;i<arr.size();i++){

                int tar = arr.get(i)[0];

                int l = 0, r = arr.size()-1;
                int curr = arr.size();
                while(l<=r){
                    int mid = l + (r-l)/2;

                    if(arr.get(mid)[1]>tar){
                        curr = mid;
                        r = mid-1;
                    }
                    else{
                        l = mid+1;
                    }
                }

                ans += arr.size()-curr;
            }
            System.out.println(ans);
        }
//        output.close();

    }

    public static long[] factorial(int n){
        long[] factorials = new long[n+1];
        factorials[1] = 1;
        for(int i = 2;i<=n;i++){
            factorials[i] = (factorials[i-1]*i)%998244353;
        }
        return factorials;
    }
    public static long numOfBits(long n){
        long ans = 0;

        while(n>0){
            n = n & (n-1);
            ans++;
        }
        return ans;
    }
    public static long ceilOfFraction(long x, long y){
        // ceil using integer division: ceil(x/y) = (x+y-1)/y
        // using double may go out of range.
        return (x+y-1)/y;
    }
    public static int power(int x, int y, int p) {

        int res = 1;

        x = x % p;

        while (y > 0) {
            if (y % 2 == 1) res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    // Returns n^(-1) mod p
    public static int modInverse(int n, int p) {
        return power(n, p - 2, p);
    }

    // Returns nCr % p using Fermat's
    // little theorem.
    public static int nCrModPFermat(int n, int r, int p) {
        if (n<r) return 0;
        if (r == 0) return 1;

        // Fill factorial array so that we
        // can find all factorial of r, n
        // and n-r
        int[] fac = new int[n + 1];
        fac[0] = 1;

        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % p;

        return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
    }
    public static long ncr(long n, long r) {

        long p = 1, k = 1;

        if (n - r < r) {
            r = n - r;
        }

        if (r != 0) {
            while (r > 0) {
                p *= n;
                k *= r;

                long m = gcd(p, k);

                p /= m;
                k /= m;

                n--;
                r--;
            }

        } else {
            p = 1;
        }
        return p;
    }
    public static boolean isPrime(long n){
        if (n <= 1) return false;
        if (n <= 3) return true;

        if (n % 2 == 0 || n % 3 == 0) return false;

        for (int i = 5; (long) i * i <= n; i = i + 6){
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    public static int powOf2JustSmallerThanN(int n) {
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;

        return n ^ (n >> 1);
    }

    public static int mergeSortAndCount(int[] arr, int l, int r) {
        int count = 0;
        if (l < r) {
            int m = (l + r) / 2;
            count += mergeSortAndCount(arr, l, m);
            count += mergeSortAndCount(arr, m + 1, r);
            count += mergeAndCount(arr, l, m, r);
        }
        return count;
    }

    public static int mergeAndCount(int[] arr, int l, int m, int r) {
        int[] left = Arrays.copyOfRange(arr, l, m + 1);
        int[] right = Arrays.copyOfRange(arr, m + 1, r + 1);

        int i = 0, j = 0, k = l, swaps = 0;

        while (i < left.length && j < right.length) {
            if (left[i] <= right[j])
                arr[k++] = left[i++];
            else {
                arr[k++] = right[j++];
                swaps += (m + 1) - (l + i);
            }
        }
        while (i < left.length)
            arr[k++] = left[i++];
        while (j < right.length)
            arr[k++] = right[j++];
        return swaps;
    }

    public static void reverseArray(int[] arr,int start, int end) {
        int temp;

        while (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    public static long gcd(long a, long b){
        if(a==0){
            return b;
        }

        return gcd(b%a,a);
    }

    public static long lcm(long a, long b){
        if(a>b) return a/gcd(b,a) * b;
        return b/gcd(a,b) * a;
    }

    public static long largeExponentMod(long x,long y,long mod){
        // computing (x^y) % mod
        x%=mod;
        long ans = 1;
        while(y>0){
            if((y&1)==1){
                ans = (ans*x)%mod;
            }
            x = (x*x)%mod;
            y = y >> 1;
        }
        return ans;
    }

    public static boolean[] numOfPrimesInRange(long L, long R){
        boolean[] isPrime = new boolean[(int) (R-L+1)];
        Arrays.fill(isPrime,true);
        long lim = (long) Math.sqrt(R);
        for (long i = 2; i <= lim; i++){
            for (long j = Math.max(i * i, (L + i - 1) / i * i); j <= R; j += i){
                isPrime[(int) (j - L)] = false;
            }
        }
        if (L == 1) isPrime[0] = false;
        return isPrime;
    }

    public static ArrayList<Long> primeFactors(long n){
        ArrayList<Long> factorization = new ArrayList<>();
        if(n%2==0){
            factorization.add(2L);
        }
        while(n%2==0){
            n/=2;
        }
        if(n%3==0){
            factorization.add(3L);
        }
        while(n%3==0){
            n/=3;
        }
        if(n%5==0){
            factorization.add(5L);
        }
        while(n%5==0){
//            factorization.add(5L);
            n/=5;
        }

        int[] increments = {4, 2, 4, 2, 4, 6, 2, 6};
        int i = 0;
        for (long d = 7; d * d <= n; d += increments[i++]) {
            if(n%d==0){
                factorization.add(d);
            }
            while (n % d == 0) {
//                factorization.add(d);
                n /= d;
            }
            if (i == 8)
                i = 0;
        }
        if (n > 1)
            factorization.add(n);
        return factorization;
    }
}

class DSU {
    int[] size, parent;
    int n;

    public DSU(int n){
        this.n = n;
        size = new int[n];
        parent = new int[n];

        for(int i = 0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    public int find(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    public void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u!=v){
            if(size[u]>size[v]){
                parent[v] = u;
                size[u] += size[v];
            }
            else{
                parent[u] = v;
                size[v] += size[u];
            }
        }
    }
}
class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    /** call this method to initialize reader for InputStream */
    static void init(InputStream input) {
        reader = new BufferedReader(
                new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    /** get next word */
    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                    reader.readLine() );
        }
        return tokenizer.nextToken();
    }
    static String nextLine() throws IOException {
        return reader.readLine();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }
    static long nextLong() throws IOException{
        return Long.parseLong(next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }
}