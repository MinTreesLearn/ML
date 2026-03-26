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
            String[] tmp = br.readLine().trim().split(" ");

            int n = Integer.parseInt(tmp[0]);
            int m = Integer.parseInt(tmp[1]);

            tmp =  br.readLine().trim().split(" ");

            int[] arr = new int[n+1];

            for (int i=0 ; i<n ; i++){
                arr[i] = Integer.parseInt(tmp[i]);
            }

            arr[n] = Integer.MAX_VALUE;

            int[] parents = new int[n];

            Arrays.fill(parents, -1);

            tmp = br.readLine().trim().split(" ");

            int[] markers = new int[m];

            for (int i=0 ; i<m ; i++){
                markers[i] = Integer.parseInt(tmp[i])-1;
            }

            Arrays.sort(markers);

            int[][] minmax = new int[n][2];

            for (int i=0 ; i<n ; i++){
                minmax[i][0] = arr[i];
                minmax[i][1] = arr[i];
            }

            for (int i=0 ; i<m ; i++){
                int u = markers[i];
                int v = (n<=u+1)?-1:u+1;

                if (v == -1)
                    continue;

                minmax[v][0] = Math.min(minmax[v-1][0], Math.min(arr[u], arr[v]));
                minmax[v][1] = Math.max(minmax[v-1][1], Math.max(arr[u], arr[v]));

                union(parents, u, v);

            }

            for (int i=0 ; i<n ; i++){
                find(parents, i);
            }

            /*System.out.println();

            for (int i=0 ; i<n ; i++){
                System.out.print(parents[i]+" ");
            }

            System.out.println();

            for (int i=0 ; i<n ; i++){
                System.out.println(i+" "+minmax[i][0]+" "+minmax[i][1]);
            }*/

            boolean ans = true;

            int i=0;

            while (i<n){
                if (i==0 || parents[i]>=0){
                    i++;
                    continue;
                }

                int parent = find(parents, i-1);

                if (parents[i] < -1){
                    int min = minmax[i-parents[i]-1][0];

                    if (minmax[i-1][1]>min){
                        ans = false;
                        break;
                    }
                    
                    i = i-parents[i];
                }else if (parents[i] == -1){
                    int max = minmax[i-1][1];

                    //System.out.println(max);

                    if (arr[i] < max){
                        ans = false;
                        break;
                    }
                    i++;
                }
            }
            

            if (ans){
                System.out.println("YES");
            }else{
                System.out.println("NO");
            }
        }        

    }

}