import java.util.*;
import java.io.*;

public class A {









    static boolean tests = false;
    static class Graph{
        ArrayList<Integer>[] graph;
        int[] dist;
        int destination, highestNode;
        Graph(int highestNode){
            this.highestNode = highestNode;
            this.graph = new ArrayList[highestNode+5];
            this.dist = new int[highestNode+5];
            Arrays.fill(dist, int_max);
        }
        void addEdge(int u, int v){
            if (graph[v] == null) graph[v] = new ArrayList<>();
            graph[v].add(u);
        }
        void clear(){
            for (int i = 0; i <= highestNode; ++i){
                if (graph[i] == null) continue;
                graph[i].clear();
            }
        }
        void calcDistFrom(int destination){
             this.destination = destination;
             ArrayDeque<Node> pq = new ArrayDeque<>();
             pq.add(new Node(destination, 0));
             dist[destination] = 0;
             while (!pq.isEmpty()){
                 Node node = pq.poll();
                 for (int u : graph[node.v]){
                     if (dist[u] > node.d+1){
                         dist[u] = node.d+1;
                         pq.addLast(new Node(u, node.d+1));
                     }
                 }
             }
        }
        int nodeDist(int v){
            return dist[v];
        }
        ArrayList<Integer> adj(int v){
            return graph[v];
        }
        class Node{
            int v, d;
            public Node(int v, int d){
                this.v = v;
                this.d = d;
            }
        }
    }
    static void printPath(int v, Graph g, int av, int bv){
        int node = v;
        while (node != g.destination){
            System.out.println(node);
            for (int u : g.adj(node)){
                if (g.nodeDist(node) == g.nodeDist(u)+1 && u != av && u != bv){
                    node = u;
                    break;
                }
            }
        }
        System.out.println(node);
    }
    static void solve(){
        int n = fs.nextInt();
        int m = fs.nextInt();
        Graph graph = new Graph(n);
        int[][] edges = new int[m][2];
        for (int i = 0; i < m; ++i){
            edges[i][0] = fs.nextInt();
            edges[i][1] = fs.nextInt();
            graph.addEdge(edges[i][0], edges[i][1]);
        }
        int k = fs.nextInt();
        int[] path = fs.readIntArray(k);
        graph.calcDistFrom(path[k-1]);
        graph.clear();
        for (int[] edge : edges){
            graph.addEdge(edge[1], edge[0]);
        }
        int min = 0, max = 0;
        for (int i = 0; i < k-1; ++i){
            int dist = graph.nodeDist(path[i]);
            int nextDist = graph.nodeDist(path[i+1]);
            if (dist != nextDist+1){
                ++min;
            }
            for (int v : graph.adj(path[i])){
                if (v == path[i+1]){
                    continue;
                }
                if (graph.nodeDist(v)+1 == dist){
                    ++max;
                    break;
                }
            }
        }
        System.out.println(min+" "+max);
    }
























    static FastScanner fs = new FastScanner();
    static int int_max = (int)1e9+5;
    public static void main(String[] args) {
        int t = 1;
        if (tests) t = fs.nextInt();
        while (t-- > 0) solve();
    }
    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        int[] readIntArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }
        long[] readLongArray(int n){
            long a[] = new long[n];
            for (int i = 0; i < n; ++i){
                a[i] = nextLong();
            }
            return a;
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
    }
}