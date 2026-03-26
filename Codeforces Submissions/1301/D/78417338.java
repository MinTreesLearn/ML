/**
 * @author derrick20
 */
import java.io.*;
import java.util.*;

public class TimeToRun {
    public static void main(String[] args) throws Exception {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int N = sc.nextInt();
        int M = sc.nextInt();
        int K = sc.nextInt();

        if (K > 4 * M * N - 2 * M - 2 * N) {
            out.println("NO");
        }
        else {
            ArrayList<Integer> f = new ArrayList<>();
            ArrayList<Character> dir = new ArrayList<>();
            for (int i = 0; i < M - 1; i++) {
                if (N > 1) {
                    f.add(N - 1);
                    dir.add('D');
                    f.add(N - 1);
                    dir.add('U');
                }
                f.add(1);
                dir.add('R');
            }
            for (int i = 0; i < N - 1; i++) {
                f.add(1);
                dir.add('D');
                if (M > 1) {
                    f.add(M - 1);
                    dir.add('L');
                    f.add(M - 1);
                    dir.add('R');
                }
            }
            if (N > 1) {
                f.add(N - 1);
                dir.add('U');
            }
            if (M > 1) {
                f.add(M - 1);
                dir.add('L');
            }

            int steps = 0;
            int ptr = 0;
            ArrayList<Integer> ansSteps = new ArrayList<>();
            ArrayList<Character> ansDir = new ArrayList<>();
            while (ptr < f.size() && steps + f.get(ptr) <= K) {
                steps += f.get(ptr);
                ansSteps.add(f.get(ptr));
                ansDir.add(dir.get(ptr));
                ptr++;
            }
            if (steps < K) {
                ansSteps.add(K - steps);
                ansDir.add(dir.get(ptr));
            }
            out.println("YES");
            out.println(ansSteps.size());
            for (int i = 0; i < ansSteps.size(); i++) {
                out.println(ansSteps.get(i) + " " + ansDir.get(i));
            }
        }

        out.close();
    }

    static class FastScanner {
        private int BS = 1<<16;
        private char NC = (char)0;
        private byte[] buf = new byte[BS];
        private int bId = 0, size = 0;
        private char c = NC;
        private double cnt = 1;
        private BufferedInputStream in;

        public FastScanner() {
            in = new BufferedInputStream(System.in, BS);
        }

        public FastScanner(String s) {
            try {
                in = new BufferedInputStream(new FileInputStream(new File(s)), BS);
            }
            catch (Exception e) {
                in = new BufferedInputStream(System.in, BS);
            }
        }

        private char getChar(){
            while(bId==size) {
                try {
                    size = in.read(buf);
                }catch(Exception e) {
                    return NC;
                }
                if(size==-1)return NC;
                bId=0;
            }
            return (char)buf[bId++];
        }

        public int nextInt() {
            return (int)nextLong();
        }

        public int[] nextInts(int N) {
            int[] res = new int[N];
            for (int i = 0; i < N; i++) {
                res[i] = (int) nextLong();
            }
            return res;
        }

        public long[] nextLongs(int N) {
            long[] res = new long[N];
            for (int i = 0; i < N; i++) {
                res[i] = nextLong();
            }
            return res;
        }

        public long nextLong() {
            cnt=1;
            boolean neg = false;
            if(c==NC)c=getChar();
            for(;(c<'0' || c>'9'); c = getChar()) {
                if(c=='-')neg=true;
            }
            long res = 0;
            for(; c>='0' && c <='9'; c=getChar()) {
                res = (res<<3)+(res<<1)+c-'0';
                cnt*=10;
            }
            return neg?-res:res;
        }

        public double nextDouble() {
            double cur = nextLong();
            return c!='.' ? cur:cur+nextLong()/cnt;
        }

        public String next() {
            StringBuilder res = new StringBuilder();
            while(c<=32)c=getChar();
            while(c>32) {
                res.append(c);
                c=getChar();
            }
            return res.toString();
        }

        public String nextLine() {
            StringBuilder res = new StringBuilder();
            while(c<=32)c=getChar();
            while(c!='\n') {
                res.append(c);
                c=getChar();
            }
            return res.toString();
        }

        public boolean hasNext() {
            if(c>32)return true;
            while(true) {
                c=getChar();
                if(c==NC)return false;
                else if(c>32)return true;
            }
        }
    }
}