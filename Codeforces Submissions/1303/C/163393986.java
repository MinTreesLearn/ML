import java.lang.*;
import java.util.*;
import java.io.*;

public class practice{

    static int components;

    private static int find(int[] parent, int x){

        if (!(x>=0 && x<parent.length))
            return -1;

        if (parent[x] < 0){
            return x;
        }

        return (parent[x] = find(parent, parent[x]));
    }

    private static void union(int[] parent, int x1, int x2){

        int r1 = find(parent, x1), r2 = find(parent, x2);

        if (r1 == r2)
            return;

        components--;

        if (parent[r1] <= parent[r2]){
            parent[r1] += parent[r2];
            parent[r2] = r1;
        }else{
            parent[r2] += parent[r1];
            parent[r1] = r2;
        }

    }

    private static void union1(int[] parent, int[] cost, int x1, int x2){

        int r1 = find(parent, x1), r2 = find(parent, x2);

        if (r1 == r2)
            return;

        if (cost[r1] >= cost[r2]){
            parent[r1] += parent[r2];
            parent[r2] = r1;
        }else{
            parent[r2] += parent[r1];
            parent[r1] = r2;
        }

    }

    private static boolean check(int[] parent, int x1, int x2){
        int r1 = find(parent, x1), r2 = find(parent, x2);

        if (r1 == r2){
            return false;
        }

        return true;
    }

    private static int dfs(List<List<Integer>> adj, int idx){

        if (adj.get(idx).size() == 0){
            return 1;
        }

        List<Integer> nei = adj.get(idx);

        int count = 0;

        for (int ne : nei){
            count += dfs(adj, ne);
        }

        return count;

    }

    public static class Pair{
        private int idx;
        private int sum;

        Pair(int idx, int sum){
            this.idx = idx;
            this.sum = sum;
        }
    }

    private static int rec(int v, int[] dp){
        if (v == 0){
            return 0;
        }

        if (dp[v] != -1){
            return dp[v];
        }

        return (dp[v]=1+Math.min(rec((v+1)%32768, dp), rec((2*v)%32768, dp)));

    }

    static class Node {
 
        int idx, level;
 
        public Node(int v, int d) {
            this.idx = v;
            this.level = d;
        }
 
    }
    static boolean vis[] = new boolean[100005];

    public static void main(String args[]) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(br.readLine().trim()); 

        while (t-->0){
            String s = br.readLine().trim();

            if (s.length() == 1){
                System.out.println("YES");
                StringBuilder sb = new StringBuilder();

                boolean[] visited = new boolean[26];

                visited[s.charAt(0)-'a'] = true;

                sb.append(s.charAt(0));

                for (int i=0 ; i<26 ; i++){
                    if (!visited[i]){
                        sb.append((char)(i+'a'));
                    }
                }

                System.out.println(sb.toString());

                continue;
            }

            Set<Integer>[] adj = new HashSet[26];

            for (int i=0 ; i<26 ; i++){
                adj[i] = new HashSet<>();
            }

            char[] arr = s.toCharArray();

            boolean check = true;

            for (int i=1 ; i<s.length() ; i++){
                int u = s.charAt(i)-'a';
                int v = s.charAt(i-1)-'a';

                adj[u].add(v);
                adj[v].add(u);

                if (adj[u].size()>=3 || adj[v].size()>=3){
                    check = false;
                }
            }

            if (!check){
                System.out.println("NO");
                continue;
            }

            int start_idx = -1;

            for (int i=0 ; i<26 ; i++){
                if (adj[i].size() == 1){
                    start_idx = i;
                }
            }

            if (start_idx == -1){
                System.out.println("NO");
                continue;
            }

            boolean[] visited = new boolean[26];

            StringBuilder sb = new StringBuilder();

            LinkedList<Integer> q = new LinkedList<>();
            q.offer(start_idx);

            while(!q.isEmpty()){
                int size = q.size();

                while (size-->0){
                    int tmp = q.poll();

                    sb.append((char)(tmp+'a'));

                    visited[tmp] = true;

                    for (int next : adj[tmp]){
                        if (!visited[next]){
                            q.offer(next);
                        }
                    }
                }
            }

            for(int i=0 ; i<26 ; i++){
                if(!visited[i]){
                    sb.append((char)(i+'a'));
                }
            }

            System.out.println("YES");
            System.out.println(sb.toString());
        }
    }

}