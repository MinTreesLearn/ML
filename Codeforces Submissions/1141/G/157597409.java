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

    static class Pair {
        int to;
        int index;

        Pair(int to, int index) {
            this.to = to;
            this.index = index;
        }
    }

    static int MAX = 200005;
    static List<Pair>[] graph = new List[MAX];
    static int[] degree = new int[MAX];
    static int[] colorAssigned = new int[MAX];

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
        int k = sc.nextInt();

        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            graph[u].add(new Pair(v, i));
            graph[v].add(new Pair(u, i));
            degree[u]++;
            degree[v]++;
        }

        TreeMap<Integer, Integer> freqMap = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            freqMap.put(degree[i], freqMap.getOrDefault(degree[i], 0) + 1);
        }

        int minColorsNeeded = 0, remainingNodes = n;
        for (int key : freqMap.keySet()) {
            if (remainingNodes > k) {
                minColorsNeeded = key;
                remainingNodes -= freqMap.get(key);
            }else {
                break;
            }
        }

        dfs(minColorsNeeded, 0, -1, -1);

        out.println(minColorsNeeded);
        for (int i = 0; i < n - 1; i++) {
            out.print((colorAssigned[i] + 1) + " ");
        }
        out.println();
    }

    private static void dfs(int minColorsNeeded, int currNode, int parent, int parentEdgeColor) {
        int color = 0;
        for (Pair adjacentPair : graph[currNode]) {
            if (adjacentPair.to == parent) {
                continue;
            }

            if (color == parentEdgeColor) {
                color = (color + 1) % minColorsNeeded;
                parentEdgeColor = -1;
            }

            colorAssigned[adjacentPair.index] = color;
            dfs(minColorsNeeded, adjacentPair.to, currNode, color);
            color = (color + 1) % minColorsNeeded;
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