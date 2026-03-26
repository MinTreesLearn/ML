import java.util.*;
import java.lang.*;
import java.io.*;

public class Solution {
    static long[] fac;

    static int m = (int)1e9+7;
    static int c = 1;
    //    static long[] factorial;
    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));


// Do not delete this //
//Uncomment this before using nCrModPFermat
//        fac = new long[200000 + 1];
//        fac[0] = 1;
//
//        for (int i = 1; i <= 200000; i++)
//            fac[i] = (fac[i - 1] * i % 1000000007);


//        long[] fact = factorial((int)1e6);
//        int te = Reader.nextInt();
        int te = 1;

        while(te-->0) {
            String s = Reader.next();
            int n = s.length();

            long ans = 0;

            for(int i = 0;i<26;i++){
                for(int j = 0;j<26;j++){
                    long curr = 0;
                    int jc = 0;

                    for(int k = n-1;k>=0;k--){
                        if(s.charAt(k)-'a'==i){
                            curr += jc;
                        }
                        if(s.charAt(k)-'a'==j){
                            jc++;
                        }
                    }
                    ans = Math.max(ans,curr);
                    ans = Math.max(ans,jc);
                }

            }
            output.write(ans+"\n");
        }



        output.close();
    }

    // Recursive function to return (x ^ n) % m
    static long modexp(long x, long n)
    {
        if (n == 0) {
            return 1;
        }
        else if (n % 2 == 0) {
            return modexp((x * x) % m, n / 2);
        }
        else {
            return (x * modexp((x * x) % m, (n - 1) / 2) % m);
        }
    }

    // Function to return the fraction modulo mod
    static long getFractionModulo(long a, long b)
    {
        long c = gcd(a, b);

        a = a / c;
        b = b / c;

        // (b ^ m-2) % m
        long  d = modexp(b, m - 2);

        // Final answer
        long ans = ((a % m) * (d % m)) % m;

        return ans;
    }
    public static boolean isP(String n){
        StringBuilder s1 = new StringBuilder(n);
        StringBuilder s2 = new StringBuilder(n);
        s2.reverse();

        for(int i = 0;i<s1.length();i++){
            if(s1.charAt(i)!=s2.charAt(i)) return false;
        }
        return true;
    }
    public static long[] factorial(int n){
        long[] factorials = new long[n+1];
        factorials[0] = 1;
        factorials[1] = 1;
        for(int i = 2;i<=n;i++){
            factorials[i] = (factorials[i-1]*i)%1000000007;
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
    public static long power(long x, long y, long p) {

        long res = 1;

        x = x % p;

        while (y > 0) {
            if (y % 2 == 1) res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    // Returns n^(-1) mod p
    public static long modInverse(long n, long p) {
        return power(n, p - 2, p);
    }

    // Returns nCr % p using Fermat's
    // little theorem.
    public static long nCrModPFermat(int n, int r, int p) {

        if (n<r) return 0;
        if (r == 0) return 1;

        // Fill factorial array so that we
        // can find all factorial of r, n
        // and n-r


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

    public static long merge(int[] arr, int[] aux, int low, int mid, int high)
    {
        int k = low, i = low, j = mid + 1;
        long inversionCount = 0;

        // while there are elements in the left and right runs
        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j]) {
                aux[k++] = arr[i++];
            }
            else {
                aux[k++] = arr[j++];
                inversionCount += (mid - i + 1);    // NOTE
            }
        }

        // copy remaining elements
        while (i <= mid) {
            aux[k++] = arr[i++];
        }

        /* no need to copy the second half (since the remaining items
           are already in their correct position in the temporary array) */

        // copy back to the original array to reflect sorted order
        for (i = low; i <= high; i++) {
            arr[i] = aux[i];
        }

        return inversionCount;
    }


    public static long mergesort(int[] arr, int[] aux, int low, int high)
    {

        if (high <= low) {        // if run size <= 1
            return 0;
        }

        int mid = (low + ((high - low) >> 1));
        long inversionCount = 0;

        // recursively split runs into two halves until run size <= 1,
        // then merges them and return up the call chain

        // split/merge left half
        inversionCount += mergesort(arr, aux, low, mid);

        // split/merge right half
        inversionCount += mergesort(arr, aux, mid + 1, high);

        // merge the two half runs
        inversionCount += merge(arr, aux, low, mid, high);

        return inversionCount;
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

class SegTree{
    int n; // array size

    // Max size of tree
    public int[] tree;

    public SegTree(int n){
        this.n = n;
        tree = new int[4*n];
    }
    // function to build the tree
    void update(int pos, int val, int s, int e, int treeIdx){
        if(pos < s || pos > e){
            return;
        }
        if(s == e){
            tree[treeIdx] = val;
            return;
        }
        int mid = s + (e - s) / 2;
        update(pos, val, s, mid, 2 * treeIdx);
        update(pos, val, mid + 1, e, 2 * treeIdx + 1);
        tree[treeIdx] = tree[2 * treeIdx] + tree[2 * treeIdx + 1];
    }

    void update(int pos, int val){
        update(pos, val, 1, n, 1);
    }

    int query(int qs, int qe, int s, int e, int treeIdx){
        if(qs <= s && qe >= e){
            return tree[treeIdx];
        }
        if(qs > e || qe < s){
            return 0;
        }
        int mid = s + (e - s) / 2;
        int subQuery1 = query(qs, qe, s, mid, 2 * treeIdx);
        int subQuery2 = query(qs, qe, mid + 1, e, 2 * treeIdx + 1);
        int res = subQuery1 + subQuery2;
        return res;
    }

    int query(int l, int r){
        return query(l, r, 1, n, 1);
    }
}