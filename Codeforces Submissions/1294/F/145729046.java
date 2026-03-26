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

    static class Node {
        int distance;
        int node;
        Node (int distance, int node) {
            this.distance = distance;
            this.node = node;
        }
    }

    static int MAX = 200005;
    static Map<Integer, List<Integer>> graph = new HashMap<>();
    static List<Integer> diameterNodes = new ArrayList<>();
    static int[] parentNode = new int[MAX];
    static int[] distanceFromDiameter = new int[MAX];
    static int n, m;

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
        n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            graph.put(i, new ArrayList<>());
            distanceFromDiameter[i] = -1;
        }

        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        // find diameter endpoints
        int start = dfs(1, -1, 0).node;
        int end = dfs(start, -1, 0).node;

        // find diameter path
        int currNode = end;
        while (currNode != start) {
            diameterNodes.add(currNode);
            currNode = parentNode[currNode];
        }
        diameterNodes.add(start);

        m = diameterNodes.size();
        if (m == n) {
            out.println(m - 1);
            out.println(diameterNodes.get(0) + " " + diameterNodes.get(1) + " " + diameterNodes.get(m - 1));
            return;
        }

        // find the farthest node from this path
        bfs();
    }

    private static void bfs() {
        Queue<Integer> q = new LinkedList<>();
        for (int node : diameterNodes) {
            distanceFromDiameter[node] = 0;
            q.add(node);
        }

        while (!q.isEmpty()) {
            int currNode = q.poll();
            for (int adjacentNode : graph.get(currNode)) {
                if (distanceFromDiameter[adjacentNode] == -1) {
                    distanceFromDiameter[adjacentNode] = distanceFromDiameter[currNode] + 1;
                    q.add(adjacentNode);
                }
            }
        }

        int farthestNode = 1, maxDistance = distanceFromDiameter[1];
        for (int i = 1; i <= n; i++) {
            if (distanceFromDiameter[i] > maxDistance) {
                maxDistance = distanceFromDiameter[i];
                farthestNode = i;
            }
        }

        out.println(m - 1 + maxDistance);
        out.println(diameterNodes.get(0) + " " + farthestNode + " " + diameterNodes.get(m - 1));
    }

    private static Node dfs(int currNode, int parent, int distance) {
        Node node = new Node(distance, currNode);
        parentNode[currNode] = parent;
        for (int adjacentNode : graph.get(currNode)) {
            if (adjacentNode == parent) {
                continue;
            }

            Node next = dfs(adjacentNode, currNode, distance + 1);
            if (next.distance >= node.distance) {
                node = next;
            }
        }
        return node;
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
