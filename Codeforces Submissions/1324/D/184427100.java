import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class CP {
    static int MAX = Integer.MAX_VALUE,MIN = Integer.MIN_VALUE,MOD = (int)1e9+7;
    static long MAXL = (long)1e18,MINL = -(long)1e18;
    static void solve() {
        int n = fs.nInt();
        int[]ar = new int[n];
        int[]br = new int[n];
        int[]cr = new int[n];
        for(int i=0;i<n;i++)ar[i] = fs.nInt();
        for(int i=0;i<n;i++)br[i] = fs.nInt();

        for(int i=0;i<n;i++){
            cr[i] = ar[i]-br[i];
        }
        sort(cr);
        long ans = 0;
        int l = 0, r = n-1;
        while ( l < r ){
            if( cr[l]+cr[r] > 0 ){
                ans += (r-l);
                r--;
            }else{
                l++;
            }
        }
        out.println(ans);
    }

    static class Triplet<T,U,V>{
        T a;
        U b;
        V c;
        Triplet(T a,U b,V c){
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }
    static class Pair<A, B>{
        A fst;
        B snd;
        Pair(A fst,B snd){
            this.fst = fst;
            this.snd = snd;
        }
    }
    static boolean multipleTestCase = false ;static FastScanner fs;static PrintWriter out;
    static int curTC;
    public static void main(String[] args) {
        try{
            fs = new FastScanner();
            out = new PrintWriter(System.out);
            int tc = (multipleTestCase)?fs.nInt():1;
            curTC = 1;
            while (curTC<=tc){
                solve();
                curTC++;
            }
            out.flush();
            out.close();
        }catch (Exception e){
            e.printStackTrace();
        }

    }
    static class FastScanner extends PrintWriter {
        private InputStream stream;
        private byte[] buf = new byte[1<<16];
        private int curChar, numChars;

        // standard input
        public FastScanner() { this(System.in,System.out); }
        public FastScanner(InputStream i, OutputStream o) {
            super(o);
            stream = i;
        }
        // file input
        public FastScanner(String i, String o) throws IOException {
            super(new FileWriter(o));
            stream = new FileInputStream(i);
        }

        // throws InputMismatchException() if previously detected end of file
        private int nextByte() {
            if (numChars == -1) throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars == -1) return -1; // end of file
            }
            return buf[curChar++];
        }

        // to read in entire lines, replace c <= ' '
        // with a function that checks whether c is a line break
        public String next() {
            int c; do { c = nextByte(); } while (c <= ' ');
            StringBuilder res = new StringBuilder();
            do { res.appendCodePoint(c); c = nextByte(); } while (c > ' ');
            return res.toString();
        }
        public int nInt() { // nextLong() would be implemented similarly
            int c; do { c = nextByte(); } while (c <= ' ');
            int sgn = 1; if (c == '-') { sgn = -1; c = nextByte(); }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res = 10*res+c-'0';
                c = nextByte();
            } while (c > ' ');
            return res * sgn;
        }
        public long nLong(){return Long.parseLong(next());}
        public double nextDouble() { return Double.parseDouble(next()); }
    }
    public static void sort(int[] arr){
        ArrayList<Integer> ls = new ArrayList<Integer>();
        for(int x: arr)
            ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++)
            arr[i] = ls.get(i);
    }
    public static void sort(long[] arr){
        ArrayList<Long> ls = new ArrayList<>();
        for(long x: arr)
            ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++)
            arr[i] = ls.get(i);
    }
    public static void sortR(int[] arr){
        ArrayList<Integer> ls = new ArrayList<>();
        for(int x: arr)
            ls.add(x);
        Collections.sort(ls,Collections.reverseOrder());
        for(int i=0; i < arr.length; i++)
            arr[i] = ls.get(i);
    }
    public static void sortR(long[] arr){
        ArrayList<Long> ls = new ArrayList<>();
        for(long x: arr)
            ls.add(x);
        Collections.sort(ls,Collections.reverseOrder());
        for(int i=0; i < arr.length; i++)
            arr[i] = ls.get(i);
    }

}
