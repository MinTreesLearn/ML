import java.io.*;
import java.util.*;

public class Main {
    private static int n;
    private static ArrayList<ArrayList<Integer>> adjacencyList;
    private static int[] bfs(int u) {
        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(u);
        dist[u] = 0;
        while(!queue.isEmpty()) {
            int cur = queue.poll();
            for(int next: adjacencyList.get(cur)) {
                if(dist[next] == -1) {
                    queue.offer(next);
                    dist[next] = dist[cur]+1;
                }
            }
        }
        return dist;
    }
    public static void main(String[] args) throws IOException {
        //BufferedReader f = new BufferedReader(new FileReader("uva.in"));
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowjump.out")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(f.readLine());
        n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        Integer[] a = new Integer[k];
        for(int i = 0; i < k; i++) {
            a[i] = Integer.parseInt(st.nextToken())-1;
        }
        adjacencyList = new ArrayList<>(n);
        for(int i = 0; i < n; i++) {
            adjacencyList.add(new ArrayList<>());
        }
        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(f.readLine());
            int u = Integer.parseInt(st.nextToken())-1;
            int v = Integer.parseInt(st.nextToken())-1;
            adjacencyList.get(u).add(v);
            adjacencyList.get(v).add(u);
        }
        int[] src = bfs(0);
        int[] dst = bfs(n-1);
        Arrays.sort(a, new Comparator<Integer>() {
            @Override
            public int compare(Integer integer, Integer t1) {
                return (src[t1]-dst[t1])-(src[integer]-dst[integer]);
            }
        });
        int max = 0;
        int d = 0;
        for(int i = 1; i < k; i++) {
            d = Math.max(d, dst[a[i-1]]);
            max = Math.max(max, src[a[i]]+d+1);
        }
        out.println(Math.min(max, src[n-1]));
        f.close();
        out.close();
    }
}
