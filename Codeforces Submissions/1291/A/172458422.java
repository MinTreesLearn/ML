import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class A {


    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int t = fs.nextInt();
        while (t-- > 0) {
            int n=fs.nextInt();
            char ch[]=fs.next().toCharArray();

            out.println(check(ch));
        }
        out.close();
    }

    public static String check(char ch[]){
        int n=ch.length;
        int ps[]=new int[n];
         ps[0]=ch[0]-'0';


        for(int i=1;i<n;i++){
            ps[i]=(ch[i]-'0')+ps[i-1];
        }

        int i=0;
        for(i=n-1;i>=0;i--){
            if(ps[i]%2==0 && (ch[i]-'0')%2!=0)
                break;
        }

        if(i>=0){
            String res="";
            for(int j=0;j<=i;j++){
                res+=ch[j];
            }
            return res;
        }

        return "-1";
    }

    /* HELPER FUNCTION's */
    static final Random random = new Random();
    static final int mod = 1_000_000_007;

    static void ruffleSort(int[] a) {
        int n = a.length;//shuffle, then sort
        for (int i = 0; i < n; i++) {
            int oi = random.nextInt(n), temp = a[oi];
            a[oi] = a[i];
            a[i] = temp;
        }
        Arrays.sort(a);
    }

    static long add(long a, long b) {
        return (a + b) % mod;
    }

    static long sub(long a, long b) {
        return ((a - b) % mod + mod) % mod;
    }

    static long mul(long a, long b) {
        return (a * b) % mod;
    }

    /* fast exponentiation */
    static long exp(long base, long exp) {
        if (exp == 0) return 1;
        long half = exp(base, exp / 2);
        if (exp % 2 == 0) return mul(half, half);
        return mul(half, mul(half, base));
    }
    /* end of fast exponentiation */

    static long[] factorials = new long[2_000_001];
    static long[] invFactorials = new long[2_000_001];

    static void precompFacts() {
        factorials[0] = invFactorials[0] = 1;
        for (int i = 1; i < factorials.length; i++) factorials[i] = mul(factorials[i - 1], i);
        invFactorials[factorials.length - 1] = exp(factorials[factorials.length - 1], mod - 2);
        for (int i = invFactorials.length - 2; i >= 0; i--)
            invFactorials[i] = mul(invFactorials[i + 1], i + 1);
    }

    static long nCk(int n, int k) {
        return mul(factorials[n], mul(invFactorials[k], invFactorials[n - k]));
    }

    /* sort ascending and descending both */
    static void sort(int[] a,int x) {
        ArrayList<Integer> l = new ArrayList<>();
        for (int i : a) l.add(i);
        if(x==0) {
            Collections.sort(l);
        }
        if(x==1){
            Collections.sort(l,Collections.reverseOrder());
        }
        for (int i = 0; i < a.length; i++) a[i] = l.get(i);
    }

    /* sort String acc. to character */
    static String sortString(String s){
        char ch[]=s.toCharArray();
        Arrays.sort(ch);
        String s1=String.valueOf(ch);
        return s1;
    }


    // lcm(a,b) * gcd(a,b) = a * b
    public static long _lcm(long a, long b) {
        return (a / _gcd(a, b)) * b;
    }

    // euclidean algorithm time O(max (loga ,logb))
    public static long _gcd(long a, long b) {
        while (a > 0) {
            long x = a;
            a = b % a;
            b = x;
        }
        return b;
    }

    /* Pair Class implementation */
    static class Pair<K, V> {
        K ff;
        V ss;

        public Pair(K ff, V ss) {
            this.ff = ff;
            this.ss = ss;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || this.getClass() != o.getClass()) return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return ff.equals(pair.ff) && ss.equals(pair.ss);
        }

        @Override
        public int hashCode() {
            return Objects.hash(ff, ss);
        }

        @Override
        public String toString() {
            return ff.toString() + " " + ss.toString();
        }
    }

    /* pair class ends here */

    /* fast input output class */
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        long[] readArrayL(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = nextLong();
            return a;
        }


        long nextLong() {
            return Long.parseLong(next());
        }
    }

}