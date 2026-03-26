
import java.io.*;
import java.util.*;

public class E {
    private static class Node {
        private long sum;
        private int cnt;

        public Node(final long sum, final int cnt) {
            this.sum = sum;
            this.cnt = cnt;
        }
    }

    public static void main(String[] args) throws IOException {
        final FastReader fastReader = new FastReader();
        final int n = fastReader.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = fastReader.nextInt();
        }
        final Deque<Node> deque = new ArrayDeque<>(n);;
        for (int i = 0; i < n; i++) {
            long sum = a[i];
            int cnt = 1;
            while (!deque.isEmpty()) {
                final Node node = deque.peekLast();
                if (node.sum * cnt >= sum * node.cnt) {
                    deque.pollLast();
                    sum += node.sum;
                    cnt += node.cnt;
                } else {
                    break;
                }
            }
            deque.addLast(new Node(sum, cnt));
        }

        final BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        while (!deque.isEmpty()) {
            final Node node = deque.poll();
            final double avg = (double) node.sum / node.cnt;
            for (int i = 0; i < node.cnt; i++) {
                writer.write(avg + " ");
            }
        }
        writer.close();
    }

    public static class FastReader {
        final BufferedReader bufferedReader;
        StringTokenizer tokenizer;

        public FastReader() {
            bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreElements()) {
                tokenizer = new StringTokenizer(nextLine());
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
            try {
                return bufferedReader.readLine();
            } catch (final IOException e) {
                throw new IllegalStateException(e);
            }
        }
    }
}

