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

    static int MAX = 100005, DEPTH = 25;

    static int[] tin = new int[MAX];
    static int[] tout = new int[MAX];
    static int time = 1;

    static int[] distance = new int[MAX]; // distance[i] is the distance from root node (1) to node i
    static int[][] ancestor = new int[MAX][DEPTH]; // ancestor[i][j] is the jth ancestor of node i.

    static Map<Integer, List<Integer>> graph = new HashMap<>();

    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();

        int test = 1;
        for (int t = 1; t <= test; t++) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        int n = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            graph.put(i, new ArrayList<>());
        }

        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        dfs(1, 1); // say root is 1, dfs from root

        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {

            // add edge between x and y
            int x = sc.nextInt();
            int y = sc.nextInt();

            // find a path from a to b having exactly k edges
            int a = sc.nextInt();
            int b = sc.nextInt();
            int k = sc.nextInt();

            // if path length between a and b is l, then since a path can contain the same vertices and same edges multiple times,
            // we can also find a path between a and b with length l + 2 * constant
            // we should find a path with length l <= k, which have parity same as parity of k

            List<Integer> possiblePathLengths = new ArrayList<>();

            // case1 : path from a to b without using added edge between x and y
            possiblePathLengths.add(findDistanceBetweenTwoNodes(a, b));

            // case2 : path from a to x, then use added edge from x to y (only once, otherwise it won't affect the parity), and then from y to b
            possiblePathLengths.add(findDistanceBetweenTwoNodes(a, x) + 1 + findDistanceBetweenTwoNodes(b, y));

            // case3 : path from a to y, then use added edge from y to x (only once, otherwise it won't affect the parity), and then from x to b
            possiblePathLengths.add(findDistanceBetweenTwoNodes(a, y) + 1 + findDistanceBetweenTwoNodes(b, x));

            boolean found = false;
            for (int length : possiblePathLengths) {
                if (length <= k && (length % 2 == k % 2)) {
                    found = true;
                    break;
                }
            }

            out.println(found ? "YES" : "NO");
        }
    }

    private static void dfs(int currNode, int parent) {
        tin[currNode] = time++;

        ancestor[currNode][0] = parent;
        for (int j = 1; j < DEPTH; j++) {
            ancestor[currNode][j] = ancestor[ancestor[currNode][j - 1]][j - 1];
        }

        for (int adjacentNode : graph.get(currNode)) {
            if (adjacentNode == parent) {
                continue;
            }
            distance[adjacentNode] = distance[currNode] + 1;
            dfs(adjacentNode, currNode);
        }

        tout[currNode] = time++;
    }

    private static int findDistanceBetweenTwoNodes(int u, int v) {
        int lcaNode = findLCA(u, v);
        return distance[u] + distance[v] - 2 * distance[lcaNode];
    }

    private static int findLCA(int u, int v) {
        if (isAncestor(u, v)) {
            return u;
        }
        if (isAncestor(v, u)) {
            return v;
        }

        for (int j = DEPTH - 1; j >= 0; j--) {
            if (!isAncestor(ancestor[u][j], v)) {
                u = ancestor[u][j];
            }
        }

        return ancestor[u][0];
    }

    private static boolean isAncestor(int u, int v) { // check if u is ancestor of v
        return tin[u] <= tin[v] && tout[u] >= tout[v];
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
