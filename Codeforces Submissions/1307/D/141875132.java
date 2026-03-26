import java.io.*;
import java.util.*;

public class CowAndFields {
    static final int INF = 1000000000;
    public static int[] bfs(int N, List<List<Integer>> graph, int src) {
        int[] dist = new int[N];
        Arrays.fill(dist, INF);
        dist[src] = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(src);
        while (!queue.isEmpty()) {
            int cur = queue.remove();
            for (int nxt : graph.get(cur)) {
                if (dist[nxt] > dist[cur] + 1) {
                    dist[nxt] = dist[cur] + 1;
                    queue.add(nxt);
                }
            }
        }
        return dist;
    }
    public static void main(String[] args) {
        InputReader reader = new InputReader(System.in);
        PrintWriter writer = new PrintWriter(System.out, false);
        int N = reader.nextInt();
        int M = reader.nextInt();
        int K = reader.nextInt();
        int[] A = new int[K];
        for (int i = 0; i < K; i++) {
            A[i] = reader.nextInt() - 1;
        }
        List<List<Integer>> graph = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < M; i++) {
            int x = reader.nextInt() - 1;
            int y = reader.nextInt() - 1;
            graph.get(x).add(y);
            graph.get(y).add(x);
        }
        int[][] dist = new int[2][N];
        dist[0] = bfs(N, graph, 0);
        dist[1] = bfs(N, graph, N - 1);
        Arrays.sort(A);
        int[][] data = new int[K][2];
        for (int i = 0; i < K; i++) {
            data[i] = new int[]{dist[0][A[i]] - dist[1][A[i]], A[i]};
        }
        Arrays.sort(data, (a, b) -> a[0] - b[0]);
        int best = 0, max = -INF;
        for (int[] d : data) {
            best = Math.max(best, max + dist[1][d[1]]);
            max = Math.max(max, dist[0][d[1]]);
        }
        writer.println(Math.min(dist[0][N - 1], best + 1));
        writer.close();
        System.exit(0);
    }
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public double nextDouble() {
            return Double.parseDouble(next());
        }
        public String nextLine() {
            String str = "";
            try {
                str = reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}