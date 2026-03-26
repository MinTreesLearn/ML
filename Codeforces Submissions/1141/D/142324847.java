// have faith in yourself!!!!!

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class CodeForces {
    /*-------------------------------------------EDITING CODE STARTS HERE-------------------------------------------*/
    public static void main(String[] args) throws IOException {
        openIO();
        int testCase = 1;
//        testCase = sc. nextInt();
        for (int i = 1; i <= testCase; i++) solve(i);
        closeIO();
    }

    public static void solve(int tCase) throws IOException {
        Deque<Integer> [] left = new ArrayDeque[27];
        Deque<Integer> [] right = new ArrayDeque[27];
        for(int i=0;i<27;i++){
            left[i] = new ArrayDeque<>();
            right[i] = new ArrayDeque<>();
        }
        int n = sc.nextInt();
        char[] s = sc.next().toCharArray();
        for(int i=0;i<n;i++){
            if(s[i]=='?')left[26].add(i);
            else left[s[i] - 'a'].add(i);
        }
        s = sc.next().toCharArray();
        for(int i=0;i<n;i++){
            if(s[i]=='?')right[26].add(i);
            else right[s[i] - 'a'].add(i);
        }
        List<int[]> ans = new ArrayList<>();
        for(int i=0;i<27;i++){
            Deque<Integer> ll = left[i];
            Deque<Integer> rr = right[i];
            while (!ll.isEmpty() && !rr.isEmpty()){
                ans.add(new int[]{ll.pop(),rr.pop()});
            }
            Deque<Integer> rrr = right[26];
            while (!ll.isEmpty() && !rrr.isEmpty()){
                ans.add(new int[]{ll.pop(),rrr.pop()});
            }
            Deque<Integer> lll = left[26];
            while (!lll.isEmpty() && !rr.isEmpty()){
                ans.add(new int[]{lll.pop(),rr.pop()});
            }
        }
        out.println(ans.size());
        for(int[] x : ans)out.println((x[0]+1)+" "+(x[1]+1));

    }



    public static int mod = (int) 1e9 + 7;
    //    public static int mod =  998244353;
    public static int inf_int = (int) 2e9 ;
    public static  long inf_long = (long) 2e14;

    public static void _sort(int[] arr,boolean isAscending){
        int n = arr.length;
        List<Integer> list = new ArrayList<>();
        for(int ele : arr)list.add(ele);
        Collections.sort(list);
        if(!isAscending)Collections.reverse(list);
        for(int i=0;i<n;i++)arr[i] = list.get(i);
    }

    public static void _sort(long[] arr,boolean isAscending){
        int n = arr.length;
        List<Long> list = new ArrayList<>();
        for(long ele : arr)list.add(ele);
        Collections.sort(list);
        if(!isAscending)Collections.reverse(list);
        for(int i=0;i<n;i++)arr[i] = list.get(i);
    }

    static class Pair<K,V> {
        K f;
        V s;
        public Pair(K f) {
            this.f = f;
        }
        public Pair(K f, V s) {
            this.f = f;
            this.s = s;
        }
    }

    /*-------------------------------------------EDITING CODE ENDS HERE-------------------------------------------*/
    static FastestReader sc;
    static PrintWriter out;
    private static void openIO() throws IOException{
        sc = new FastestReader();
        out = new PrintWriter(System.out);
    }
    /*-------------------------------------------FAST INPUT STARTS HERE---------------------------------------------*/

    public static void closeIO() throws IOException{
        out.flush();
        out.close();
        sc.close();
    }
    private static final class FastestReader {
        private static final int BUFFER_SIZE = 1 << 16;
        private final DataInputStream din;
        private final byte[] buffer;
        private int bufferPointer, bytesRead;

        public FastestReader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public FastestReader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        private static boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }

        private int skip() throws IOException {
            int b;
            //noinspection StatementWithEmptyBody
            while ((b = read()) != -1 && isSpaceChar(b)) {}
            return b;
        }

        public String next() throws IOException {
            int b = skip();
            final StringBuilder sb = new StringBuilder();
            while (!isSpaceChar(b)) { // when nextLine, (isSpaceChar(b) && b != ' ')
                sb.appendCodePoint(b);
                b = read();
            }
            return sb.toString();
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            final boolean neg = c == '-';
            if (neg) { c = read(); }
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg) { return -ret; }
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ') { c = read(); }
            final boolean neg = c == '-';
            if (neg) { c = read(); }
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg) { return -ret; }
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ') { c = read(); }
            final boolean neg = c == '-';
            if (neg) { c = read(); }

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg) { return -ret; }
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1) { buffer[0] = -1; }
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead) { fillBuffer(); }
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            din.close();
        }
    }
    /*---------------------------------------------FAST INPUT ENDS HERE ---------------------------------------------*/
}