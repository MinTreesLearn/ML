/*
        "Everything in the universe is balanced. Every disappointment
                you face in life will be balanced by something good for you!
                        Keep going, never give up."

                        Just have Patience + 1...

*/



import java.util.*;
import java.lang.*;
import java.io.*;


public class Solution {

    static int MAX = 200005, INF = 1000000007;
    static Map<Integer, List<Integer>> graph = new HashMap<>();
    // shortestDistance[0][i] -> shortest distance from node 1 to i.
    // shortestDistance[1][i] -> shortest distance from node n to i.
    static int[][] shortestDistance = new int[2][MAX];

    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();

        int test = 1;
        for (int t = 0; t < test; t++) {
            solve();
        }
        out.close();
    }


    private static void solve() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();

        for (int i = 0; i < 2; i++) {
            Arrays.fill(shortestDistance[i], INF);
        }

        List<Integer> specialNodes = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            int node = sc.nextInt();
            specialNodes.add(node);
        }

        for (int i = 1; i <= n; i++) {
            graph.put(i, new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        bfs(1, 0);
        bfs(n, 1);

        /*
            Select two special nodes (say x and y) to connect such that (the shortest distance from 1 to x) + (the shortest distance from x to n) is maximized.
 
        */

        specialNodes.sort(Comparator.comparingInt(a -> (shortestDistance[0][a] - shortestDistance[1][a])));

        int maxShortestPath = 0, maxSpecialDistanceFromStart = -INF;
        for (int node : specialNodes) {
            maxShortestPath = Math.max(maxShortestPath, maxSpecialDistanceFromStart + shortestDistance[1][node]);
            maxSpecialDistanceFromStart = Math.max(maxSpecialDistanceFromStart, shortestDistance[0][node]);
        }

        maxShortestPath++; // special edge length

        out.println(Math.min(maxShortestPath, shortestDistance[0][n]));
    }

    private static void bfs(int startNode, int index) {
        Queue<Integer> q = new LinkedList<>();
        shortestDistance[index][startNode] = 0;
        q.add(startNode);

        while (!q.isEmpty()) {
            int currNode = q.poll();
            for (int adjacentNode : graph.get(currNode)) {
                if (shortestDistance[index][adjacentNode] > shortestDistance[index][currNode] + 1) {
                    shortestDistance[index][adjacentNode] = shortestDistance[index][currNode] + 1;
                    q.add(adjacentNode);
                }
            }
        }
    }


    public static FastReader sc;
    public static PrintWriter out;
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer str;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (str == null || !str.hasMoreElements())
            {
                try
                {
                    str = new StringTokenizer(br.readLine());
                }
                catch (IOException  lastMonthOfVacation)
                {
                    lastMonthOfVacation.printStackTrace();
                }
            }
            return str.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException lastMonthOfVacation)
            {
                lastMonthOfVacation.printStackTrace();
            }
            return str;
        }
    }
}
