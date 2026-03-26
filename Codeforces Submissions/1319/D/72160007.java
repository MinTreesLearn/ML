import java.util.*;
import java.io.*;

public class Main {
    static ArrayList<Integer>[] gr, g;
    static TreeMap<Integer, Integer> way;
    static int[] types, dist;
    static int INF = (int) 1e9;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        gr = new ArrayList[n];
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            gr[i] = new ArrayList<>();
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int from = sc.nextInt() - 1;
            int to = sc.nextInt() - 1;
            gr[from].add(to);
            g[to].add(from);
        }
        int k = sc.nextInt();
        int[] p = new int[k];
        for (int i = 0; i < k; i++)
            p[i] = sc.nextInt() - 1;
        way = new TreeMap<>();
        for (int i = 0; i < k - 1; i++)
            way.put(p[i], p[i + 1]);
        types = new int[n];
        //0 - none
        //1 - +
        //2 - -
        //3 - +-
        dist = new int[n];
        Arrays.fill(dist, INF);
        dist[p[k - 1]] = 0;
        bfs(p[k - 1]);
        int cntMin = 0;
        int cntMax = 0;
        for (int i = 0; i < k - 1; i++) {
            if (types[p[i]] == 2) {
                cntMin++;
                cntMax++;
            }
            if (types[p[i]] == 3)
                cntMax++;
        }
        pw.print(cntMin + " " + cntMax);
        pw.close();
    }

    public static void bfs(int start) {
        ArrayDeque<Pair> bfs = new ArrayDeque<>();
        bfs.add(new Pair(start, -1));
        while(!bfs.isEmpty()){
            int v = bfs.getFirst().v;
            int p = bfs.pollFirst().p;
            for (int to : g[v]) {
                if(dist[to] == INF)
                    bfs.add(new Pair(to, v));
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    if (way.containsKey(to) && way.get(to) == v)
                        types[to] = 1;
                    else
                        types[to] = 2;
                } else if (dist[to] == dist[v] + 1) {
                    if (way.containsKey(to) && way.get(to) == v)
                        types[to]++;
                    else {
                        if (types[to] < 2)
                            types[to] += 2;
                    }
                }
            }
        }
    }


    public static boolean isVowel(char a) {
        return a == 'a' || a == 'e' || a == 'u' || a == 'o' || a == 'y';
    }

    public static long binPow(long a, int n) {
        long p = a;
        long res = 1;
        while (n > 0) {
            if (n % 2 == 1)
                res *= p;
            p *= p;
            n /= 2;
        }
        return res;
    }

    public static int gcd(int a, int b) {
        if (a == 0 || b == 0)
            return a + b;
        return gcd(b % a, a);
    }

    public static long gcd(long a, long b) {
        if (a == 0 || b == 0)
            return a + b;
        return gcd(b % a, a);
    }
}

class Pair{
    int v, p;

    public Pair(int v, int p) {
        this.v = v;
        this.p = p;
    }
}
class FastScanner {
    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public FastScanner(InputStream inputStream) {
        br = new BufferedReader(new InputStreamReader(inputStream));
    }

    public FastScanner(String fileName) throws FileNotFoundException {
        br = new BufferedReader(new FileReader(fileName));
    }

    public boolean hasNext() {
        try {
            while (!st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public String next() {
        hasNext();
        return st.nextToken();
    }
}
