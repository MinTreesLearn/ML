import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

/**
 * * @author zhengnaishan
 * * @date 2023/2/9 9:15
 */
public class CF1141 {

    public static void main(String[] args) {

        HashMap<Long, Integer> cntMap = new HashMap<>();

        //前缀和最后出现的位置
        HashMap<Long, Integer> lastIndex = new HashMap<>();

        Kattio io = new Kattio();
        int n = io.nextInt();
        int[] a = new int[n];
        int maxCnt = 0;
        long maxSum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = io.nextInt();
            long sum = 0;
            for (int j = i; j >= 0; j--) {
                sum += a[j];
                if (lastIndex.getOrDefault(sum, -1) < j) {
                    lastIndex.put(sum, i);
                    int cnt = cntMap.getOrDefault(sum, 0) + 1;
                    cntMap.put(sum, cnt);
                    if (cnt > maxCnt) {
                        maxCnt = cnt;
                        maxSum = sum;
                    }
                }
            }
        }
        io.println(cntMap.get(maxSum));
        long sum = 0;
        HashMap<Long, Integer> sumMap = new HashMap<>();
        sumMap.put(0L, -1);
        for (int i = 0; i < n; i++) {
            sum += a[i];
            Integer v;
            if ((v = sumMap.get(sum - maxSum)) != null) {
                io.println(v + 2 + " " + (i + 1));
                sumMap.clear();
                sumMap.put(0L, i);
                sum = 0;
            } else {
                sumMap.put(sum, i);
            }
        }

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
