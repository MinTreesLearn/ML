import java.io.*;
import java.util.*;

public class E {

    static ArrayList<Integer>[] grf;
    static int[] color;
    static boolean isBipartite = true;

    static void dfs(int ver, boolean[] vis, int c){
        color[ver] = c;
        vis[ver] = true;
        for(int chld: grf[ver]){
            if(color[chld] == -1 || color[chld] == (c^1)){
                if(!vis[chld]) dfs(chld, vis, c^1);
            }
            else{
                isBipartite = false;
                return;
            }
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        //int tst = Integer.parseInt(br.readLine());
        int tst = 1;
        while(tst-->0){
            int n = Integer.parseInt(br.readLine());
            char[] arr = br.readLine().toCharArray();
            grf = new ArrayList[n];
            char[] sorted = new char[n];
            for(int i = 0; i<n; i++){
                sorted[i] = arr[i];
                grf[i] = new ArrayList<>();
            }
            Arrays.sort(sorted);
            color = new int[n];
            //make a grf and check if its bipartite
            boolean[] assigned = new boolean[n];
            int u = -1;
            for(int i = 0; i<n; i++){
                for(int j = i+1; j<n; j++){
                    if(arr[i] > arr[j]){
                        grf[i].add(j);
                        grf[j].add(i);
                    }
                }
            }
            Arrays.fill(color, -1);
            boolean[] vis = new boolean[n];
            for(int i = 0; i<n; i++){
                if(vis[i] == false) dfs(i, vis, 0);
            }
            if(isBipartite){
                sb.append("YES").append('\n');
                for(int c: color) {
                    if(c == -1) sb.append(0);
                    else sb.append(c);
                }
                sb.append('\n');
            }
            else sb.append("NO").append('\n');
        }
        System.out.println(sb);
    }
}
