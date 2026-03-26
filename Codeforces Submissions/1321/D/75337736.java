// Magic. Do not touch.
import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    static class FastReader
    {
        private InputStream mIs;private byte[] buf = new byte[1024];private int curChar,numChars;public FastReader() { this(System.in); }public FastReader(InputStream is) { mIs = is;}
        public int read() {if (numChars == -1) throw new InputMismatchException();if (curChar >= numChars) {curChar = 0;try { numChars = mIs.read(buf);} catch (IOException e) { throw new InputMismatchException();}if (numChars <= 0) return -1; }return buf[curChar++];}
        public String nextLine(){int c = read();while (isSpaceChar(c)) c = read();StringBuilder res = new StringBuilder();do {res.appendCodePoint(c);c = read();}while (!isEndOfLine(c));return res.toString() ;}
        public String next(){int c = read();while (isSpaceChar(c)) c = read();StringBuilder res = new StringBuilder();do {res.appendCodePoint(c);c = read();}while (!isSpaceChar(c));return res.toString();}
        public long l(){int c = read();while (isSpaceChar(c)) c = read();int sgn = 1;if (c == '-') { sgn = -1 ; c = read() ; }long res = 0; do{ if (c < '0' || c > '9') throw new InputMismatchException();res *= 10 ; res += c - '0' ; c = read();}while(!isSpaceChar(c));return res * sgn;}
        public int i(){int c = read() ;while (isSpaceChar(c)) c = read();int sgn = 1;if (c == '-') { sgn = -1 ; c = read() ; }int res = 0;do{if (c < '0' || c > '9') throw new InputMismatchException();res *= 10 ; res += c - '0' ; c = read() ;}while(!isSpaceChar(c));return res * sgn;}
        public double d() throws IOException {return Double.parseDouble(next()) ;}
        public boolean isSpaceChar(int c) { return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1; }
        public boolean isEndOfLine(int c) { return c == '\n' || c == '\r' || c == -1; }
        public void scanIntArr(int [] arr){ for(int li=0;li<arr.length;++li){ arr[li]=i();}}
        public void scanIntIndexArr(int [] arr){ for(int li=0;li<arr.length;++li){ arr[li]=i()-1;}}
        public void scanLongArr(long [] arr){for (int i=0;i<arr.length;++i){arr[i]=l();}}
        public void shuffle(int [] arr){ for(int i=arr.length;i>0;--i) { int r=(int)(Math.random()*i); int temp=arr[i-1]; arr[i-1]=arr[r]; arr[r]=temp; } }
        public int swapIntegers(int a,int b){return a;} //Call it like this: a=swapIntegers(b,b=a)
    }

    public static int[] minDist;
    public static int[] count;
    public static ArrayList<Integer>[] adjList, adjList2;
    public static boolean[] visited;

    public static void main(String[] args) throws IOException {

        FastReader fr = new FastReader();
        PrintWriter pw = new PrintWriter(System.out);
        /*
inputCopy
6 9
1 5
5 4
1 2
2 3
3 4
4 1
2 6
6 4
4 2
4
1 2 3 4
outputCopy
1 2
inputCopy
7 7
1 2
2 3
3 4
4 5
5 6
6 7
7 1
7
1 2 3 4 5 6 7
outputCopy
0 0
inputCopy
8 13
8 7
8 6
7 5
7 4
6 5
6 4
5 3
5 2
4 3
4 2
3 1
2 1
1 8
5
8 7 5 2 1
outputCopy
0 3
         */

        //Press Ctrl+Win+Alt+L for reformatting indentation
        int t = 1;
        for (int ti = 0; ti < t; ++ti) {
            int n = fr.i();
            int m = fr.i();
            minDist = new int[n];
            count = new int[n];
            Arrays.fill(minDist, Integer.MAX_VALUE);
            adjList = new ArrayList[n];
            adjList2 = new ArrayList[n];
            for (int i = 0; i < n; ++i) {
                adjList[i] = new ArrayList<>();
                adjList2[i] = new ArrayList<>();
            }
            for (int mi = 0; mi < m; ++mi) {
                int u = fr.i() - 1;
                int v = fr.i() - 1;
                adjList[u].add(v);
                adjList2[v].add(u);
            }
            int k = fr.i();
            int[] arr = new int[k];
            fr.scanIntIndexArr(arr);
            int dest = arr[k - 1];
            minDist[dest] = 0;
            BFS(dest);
            visited = new boolean[n];
            DFS(arr[0]);
            count[dest]=0;
            long minRebuild = 0, maxRebuild = 0;
            int expectedDistance = minDist[arr[0]];
            for (int i = 0; i < k; ++i, --expectedDistance) {
                if (minDist[arr[i]] != expectedDistance) {
                    ++minRebuild;
                    expectedDistance = minDist[arr[i]];
                    if(count[arr[i-1]]==1)
                        ++maxRebuild;
                }
                maxRebuild = count[arr[i]] > 1 ? maxRebuild + 1 : maxRebuild;
            }
            pw.println(minRebuild + " " + maxRebuild);
        }
        pw.flush();
        pw.close();
    }

    private static void BFS(int source) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(source);
        while (!queue.isEmpty()) {
            int parent = queue.remove();
            for (int to : adjList2[parent]) {
                if (minDist[to] > minDist[parent] + 1) {
                    minDist[to] = minDist[parent] + 1;
                    queue.add(to);
                }
            }
        }
    }

    private static void DFS(int source) {
        if (visited[source])
            return;
        visited[source] = true;
        int min = Integer.MAX_VALUE;
        int freq = 0;
        for (int dest : adjList[source]) {
            if (min > minDist[dest]) {
                min = minDist[dest];
                freq = 1;
            } else if (min == minDist[dest]) {
                ++freq;
            }
            DFS(dest);
        }
        count[source] = freq;
    }
}
