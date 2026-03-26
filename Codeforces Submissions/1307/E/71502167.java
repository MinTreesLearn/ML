import java.io.*;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

public class Main {

    static {
        Locale.setDefault(Locale.ENGLISH);
    }

    private static DecimalFormat decimalFormat = new DecimalFormat("#0.00000000");

    private static class Reader implements Closeable {

        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public Reader() {
            reader = new BufferedReader(new InputStreamReader(System.in));
        }

        public Reader(String fileName) {
            try {
                reader = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                throw new IllegalStateException("There is no file with given name");
            }
        }

        public String nextToken() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    String nextLine = reader.readLine();
                    if (nextLine == null) {
                        return null;
                    }
                    tokenizer = new StringTokenizer(nextLine);
                } catch (IOException e) {
                    throw new IllegalStateException("I/O Error");
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }

        @Override
        public void close() throws IOException {
            reader.close();
        }
    }

    private static class Pair implements Comparable<Pair> {

        private int x;
        private int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        @Override
        public int compareTo(Pair o) {
            if (this.x != o.x) return Integer.compare(this.x, o.x);
            return Integer.compare(this.y, o.y);
        }
    }

    private <T> ArrayList<T> createArrayList(int n, T value) {
        ArrayList<T> result = new ArrayList<>();
        IntStream.range(0, n).forEach(i -> result.add(value));
        return result;
    }

    public static void main(String[] args) throws IOException {
        Reader reader = new Reader();
        //Reader reader = new Reader("input.txt");
        PrintWriter writer = new PrintWriter(System.out);
        new Main().solve(reader, writer);
        reader.close();
        writer.close();
    }

    private static class Cow {

        private int l;
        private int r;

        public Cow(int l, int r) {
            this.l = l;
            this.r = r;
        }

        public int getL() {
            return l;
        }

        public int getR() {
            return r;
        }

    }

    private void solve(Reader reader, PrintWriter writer) {
        int n = reader.nextInt();
        int m = reader.nextInt();
        ArrayList<Integer> s = new ArrayList<>();
        boolean[] s1 = new boolean[5001];
        boolean[] s2 = new boolean[5001];
        for (int i = 0; i < n; ++i) {
            s.add(reader.nextInt());
            s1[s.get(s.size() - 1)] = true;
        }

        ArrayList<Cow>[] cowsByF = new ArrayList[5001];
        for (int i = 1; i <= n; ++i) {
            cowsByF[i] = new ArrayList<>();
        }

        boolean[] used = new boolean[5000];

        for (int i = 0; i < m; ++i) {
            int f = reader.nextInt();
            int h = reader.nextInt();
            int l = -1;
            int r = -1;
            s2[f] = true;

            int counter = 0;
            for (int j = 0; j < n; ++j) {
                if (s.get(j) == f) {
                    counter++;
                    if (counter == h) {
                        l = j;
                        break;
                    }
                }
            }

            counter = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (s.get(j) == f) {
                    counter++;
                    if (counter == h) {
                        r = j;
                        break;
                    }
                }
            }

            if (l != -1) {
                used[l] = true;
                cowsByF[f].add(new Cow(l, r));
            }
        }

        int bestResult = 0;
        long bestCount = 0;

        for (int i = -1; i < n; ++i) { //граница разделения
            if (i > -1 && !used[i]) {
                continue;
            }
            int result = 0;
            long count = 1;
            boolean usedProperCow = false;
            for (int j = 1; j <= n; ++j) { //уровень сладости
                if (!s1[j] && !s2[j]) {
                    continue;
                }
                boolean usedProperCowAtJ = false;
                int l = 0;
                int r = 0;
                int mixed = 0;
                for (Cow cow : cowsByF[j]) {
                    if (cow.l == i) {
                        usedProperCow = true;
                        usedProperCowAtJ = true;
                        continue;
                    }
                    if (cow.l <= i && cow.r <= i) {
                        l++;
                    }
                    if (cow.l > i && cow.r > i) {
                        r++;
                    }
                    if (cow.l <= i && cow.r > i) {
                        mixed++;
                    }
                }
                if (usedProperCowAtJ) {
                    if (r + mixed == 0) {
                        result += 1;
                        continue;
                    } else {
                        result += 2;
                        int mult = r + mixed;
                        count *= mult;
                        if (count > 1000000007) {
                            count %= 1000000007;
                        }
                        continue;
                    }
                }
                if (l + r + mixed == 0) {
                    continue;
                }
                if (mixed + (l > 0 ? 1 : 0) + (r > 0 ? 1 : 0) > 1) {
                    result += 2;
                    int mult = l * mixed + r * mixed + mixed * (mixed - 1);
                    count *= mult;
                } else {
                    result += 1;
                    int mult = l + r + mixed * 2;
                    count *= mult;
                }
                if (count > 1000000007) {
                    count %= 1000000007;
                }
            }
            if (result > bestResult) {
                bestResult = result;
                bestCount = count;
            } else if (result == bestResult && (i == -1 || usedProperCow)) {
                bestCount += count;
                bestCount %= 1000000007;
            }
        }
        writer.println(bestResult + " " + bestCount);
    }

}
