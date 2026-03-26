import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class test {
    final static int MOD = 1000000007;
    final static int intMax = 1000000000;
    final static int intMin = -1000000000;
    final static int[] dx = { 0, 0, -1, 1 };
    final static int[] dy = { -1, 1, 0, 0 };

    static int add(int a, int b) {
        return (a + b) % MOD;
    }

    static int sub(int a, int b) {
        return (a - b + MOD) % MOD;
    }

    static int mult(int a, int b) {
        return (int)((((long)(a)) * b) % MOD);
    }

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
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[360]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
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
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
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

    static class Sb_Output implements Closeable, Flushable{
        StringBuilder sb;
        OutputStream os;
        int BUFFER_SIZE;
        public Sb_Output(String s) throws Exception {
            os = new BufferedOutputStream(new FileOutputStream(new File(s)));
            BUFFER_SIZE = 1 << 16;
            sb = new StringBuilder(BUFFER_SIZE);
        }
        public void print(String s) {
            sb.append(s);
            if(sb.length() >= (BUFFER_SIZE>>1)) {
                flush();
            }
        }
        public void println(String s) {
            print(s);
            print("\n");
        }
        public void println(int i) {
            println("" + i);
        }
        public void println(long i) {
            println("" + i);
        }
        public void flush() {
            try {
                os.write(sb.toString().getBytes());
                sb = new StringBuilder(BUFFER_SIZE);
            }catch(IOException e) {
                e.printStackTrace();
            }
        }
        public void close() {
            flush();
            try {
                os.close();
            }catch(IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Reader in = new Reader();
//		Reader in = new Reader("poetry.in");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        BufferedReader br = new BufferedReader(new FileReader("poetry.in"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long x0 = Long.parseLong(st.nextToken());
        long y0 = Long.parseLong(st.nextToken());
        long ax = Long.parseLong(st.nextToken());
        long ay = Long.parseLong(st.nextToken());
        long bx = Long.parseLong(st.nextToken());
        long by = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long xs = Long.parseLong(st.nextToken());
        long ys = Long.parseLong(st.nextToken());
        long t = Long.parseLong(st.nextToken());
        ArrayList<pair> points = new ArrayList<pair>();
        long curx = x0, cury = y0;
        points.add(new pair(curx, cury));
        while(true){
            if(curx > 100000000000000000L / ax || cury > 100000000000000000L / ay) break;
            curx *= ax;
            cury *= ay;
            if(curx > 100000000000000000L - bx || cury > 100000000000000000L - by) break;
            curx += bx;
            cury += by;
            points.add(new pair(curx, cury));
        }/*
        for(pair i : points){
            System.out.println(i.x + " " + i.y);
        }*/
        int sz = points.size();
        int mx = 0;
        for(int i = 0; i < sz; ++i) {
            int cur = 0;
            long curt = t - Math.abs(xs - points.get(i).x) - Math.abs(ys - points.get(i).y);
            if(curt < 0) continue;
            //if(i == 0) System.out.println(curt);
            ++cur;
            curx = points.get(i).x;
            cury = points.get(i).y;
            for(int j = i - 1; j >= 0 && curt > 0; --j) {
                if(curt - Math.abs(curx - points.get(j).x) - Math.abs(cury - points.get(j).y) < 0) break;
                curt -= Math.abs(curx - points.get(j).x) + Math.abs(cury - points.get(j).y);
                curx = points.get(j).x;
                cury = points.get(j).y;
                ++cur;
            }
            for(int j = i + 1; j < sz; ++j){
                if(curt - Math.abs(curx - points.get(j).x) - Math.abs(cury - points.get(j).y) < 0) break;
                curt -= Math.abs(curx - points.get(j).x) + Math.abs(cury - points.get(j).y);
                curx = points.get(j).x;
                cury = points.get(j).y;
                ++cur;
            }
            //System.out.println(cur);
            mx = max(mx, cur);
        }
        System.out.println(mx);
        in.close();
        //out.close();
    }
    static class pair{
        long x, y;
        pair(long a, long b) {
            x = a; y = b;
        }
    }
}