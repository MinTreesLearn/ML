import java.io.*;
import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.StringTokenizer;

/**
 * * @author zhengnaishan
 * * @date 2023/2/9 9:15
 */
public class CF1141 {

    public static void main(String[] args) {
        //前缀和最后出现的位置
        HashMap<Long, ArrayDeque<int[]>> map = new HashMap<>();
        Kattio io = new Kattio();
        int n = io.nextInt();
        int[] a = new int[n];
        ArrayDeque<int[]> maxQueue = null;
        for (int i = 0; i < n; i++) {
            a[i] = io.nextInt();
            long sum = 0;
            for (int j = i; j >= 0; j--) {
                sum += a[j];
                ArrayDeque<int[]> queue = map.computeIfAbsent(sum, v -> new ArrayDeque<>());
                if (queue.isEmpty() || queue.peek()[1] < j) {
                    queue.push(new int[]{j, i});
                    if (maxQueue == null || queue.size() > maxQueue.size()) {
                        maxQueue = queue;
                    }
                }
            }
        }
        io.println(maxQueue.size());
        for (int[] c : maxQueue) io.println(c[0] + 1 + " " + (c[1] + 1));
        io.flush();
    }


    public static class Kattio extends PrintWriter {
        private BufferedReader r;
        private StringTokenizer st;

        // 标准 IO
        public Kattio() {
            this(System.in, System.out);
        }

        public Kattio(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }

        // 文件 IO
        public Kattio(String intput, String output) throws IOException {
            super(output);
            r = new BufferedReader(new FileReader(intput));
        }

        // 在没有其他输入时返回 null
        public String next() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(r.readLine());
                return st.nextToken();
            } catch (Exception e) {
            }
            return null;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }
}
