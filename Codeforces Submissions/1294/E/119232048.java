import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;

public class E1294 {
    public static void main(String[] args) throws IOException {
        Reader scan = new Reader();
        int n = scan.nextInt();
        int m = scan.nextInt();
        int[][] a = new int[n][m];

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                a[i][j] = scan.nextInt();
            }
        }

        long moves = 0;
        for(int i=0;i<m;i++) {
            moves += solve(a, i, n, m);
        }
        System.out.println(moves);
    }
    static int solve(int[][] a, int i, int n, int m) {
        int count = 0;
        Map<Integer, Integer> posMap = new HashMap<>();
        for(int j=0;j<n;j++) {
            posMap.put((j*m) + i + 1, j);
        }

        int[] shifts = new int[n];

        for(int j=0;j<n;j++) {
            if(posMap.containsKey(a[j][i])) {
                shifts[(j - posMap.get(a[j][i]) + n) % n]++;
            }
        }

        count = n - shifts[0];
        for(int j=1;j<n;j++) {
            count = Math.min(count, n - shifts[j] + j);
        }
        return count;
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

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
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
}
