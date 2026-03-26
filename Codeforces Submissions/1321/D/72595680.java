import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Collection;
import java.util.Set;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashSet;
import java.util.Queue;
import java.util.LinkedList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Ribhav
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DNavigationSystem solver = new DNavigationSystem();
        solver.solve(1, in, out);
        out.close();
    }

    static class DNavigationSystem {
        public void solve(int testNumber, FastReader s, PrintWriter out) {
            int n = s.nextInt();
            int m = s.nextInt();
            DNavigationSystem.Graph g = new DNavigationSystem.Graph(n, true, false);
            g.takeInput(m, s);
//        out.println(g.neighbours);
            int size = s.nextInt();
            int[] arr = s.nextIntArray(size);
            int src = arr[size - 1];
            int dest = arr[0];
//        g.neighbours.remove(dest);
            HashMap<Integer, HashSet<Integer>> parent = new HashMap<>();
            HashMap<Integer, Integer> distance = new HashMap<>();
            HashSet<Integer> visited = new HashSet<>();
            Queue<Integer> q = new LinkedList<>();
            q.add(src);
            visited.add(src);
            distance.put(src, 0);
            HashMap<Integer, HashMap<Integer, Long>> neighbours = g.neighbours;
            while (!q.isEmpty()) {
                int curr = q.poll();
                HashMap<Integer, Long> neighb = neighbours.getOrDefault(curr, new HashMap<>());
                Iterator<Integer> iter = neighb.keySet().iterator();
                int currD = distance.get(curr);
                while (iter.hasNext()) {
                    int next = iter.next();
                    if (!visited.contains(next)) {
                        distance.put(next, currD + 1);
                        visited.add(next);
                        HashSet<Integer> list = new HashSet<>();
                        list.add(curr);
                        parent.put(next, list);
                        q.add(next);
                    } else {
                        if (distance.get(next) == currD + 1) {
                            HashSet<Integer> list = parent.get(next);
                            list.add(curr);
                            parent.put(next, list);
                        } else if (distance.get(next) > currD + 1) {
                            HashSet<Integer> list = parent.get(next);
                            list.clear();
                            list.add(curr);
                            distance.put(next, currD + 1);
                            parent.put(next, list);
                        }
                    }
                }

            }

//        out.println(parent);

            int worst = 0;
            int best = 0;
            for (int i = 0; i < size - 1; i++) {
                int next = arr[i + 1];
                int curr = arr[i];

                HashSet<Integer> set = parent.get(curr);
                if (set.contains(next)) {
                    if (set.size() != 1) {
                        best++;
                    }
                } else {
                    worst++;
                    best++;
                }
            }
            out.println(worst + " " + best);
        }

        private static class Graph {
            HashMap<Integer, HashMap<Integer, Long>> neighbours;
            int numVertices;
            boolean isDirected;
            boolean isWeighted;

            public Graph(int numVertices, boolean isDirected, boolean isWeighted) {
                neighbours = new HashMap<>();
                this.numVertices = numVertices;
                this.isDirected = isDirected;
                this.isWeighted = isWeighted;
            }

            public void takeInput(int n, FastReader s) {
                for (int i = 0; i < n; i++) {
                    int dest = s.nextInt();
                    int src = s.nextInt();

//                if (dest == )
                    long wt;
                    if (isWeighted) {
                        wt = s.nextLong();
                    } else {
                        wt = 1;
                    }
                    HashMap<Integer, Long> list = neighbours.getOrDefault(src, new HashMap<>());
                    list.put(dest, wt);
                    neighbours.put(src, list);
                    if (!isDirected) {
                        list = neighbours.getOrDefault(dest, new HashMap<>());
                        list.put(src, wt);
                        neighbours.put(dest, list);
                    }
                }
            }

        }

    }

    static class FastReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private FastReader.SpaceCharFilter filter;

        public FastReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}

