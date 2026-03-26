import java.io.*;
import java.util.*;

public class Day9 {
    public static ArrayList<Integer>[] g;
    public static int[] c;
    public static boolean[] used;
    public static int[] array;
    public static int[] dep;
    public static int[] p;
    public static class pair implements Comparable<pair>{
        int ind;
        int dep;
        public pair(int i, int d){
            this.ind = i;
            this.dep = d;
        }

        @Override
        public int compareTo(pair o) {
            if(this.dep != o.dep){
                return this.dep - o.dep;
            }
            else{
                return this.ind - o.ind;
            }
        }
    }
    public static void dfs(int node, int d){
        dep[node] = d;
        for(Integer to : g[node]){
            dfs(to, d + 1);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        int n = Integer.parseInt(reader.readLine());
        c = new int[n];
        array = new int[n];
        dep = new int[n];
        g = new ArrayList[n];
        for(int i = 0; i < n; ++i){
            g[i] = new ArrayList<>();
        }
        p = new int[n];
        for(int i = 0; i < n; ++i){
            StringTokenizer st = new StringTokenizer(reader.readLine());
            p[i] = Integer.parseInt(st.nextToken());
            c[i] = Integer.parseInt(st.nextToken());
            if(p[i] != 0) {
                g[p[i] - 1].add(i);
            }
        }
        for(int i = 0; i < n; ++i){
            if(p[i] == 0){
                dfs(i, 0);
                break;
            }
        }
        TreeSet<pair> treeSet = new TreeSet<>();
        for(int i = 0; i < n; ++i){
            if(c[i] == 0){
                treeSet.add(new pair(i, dep[i]));
            }
        }
        int num = 1;
        while(!treeSet.isEmpty()){
            pair par = treeSet.pollFirst();
            array[par.ind] = num;
            ++num;
            int ind = p[par.ind] - 1;
            while(ind != -1){
                c[ind]--;
                if(c[ind] == 0){
                    treeSet.add(new pair(ind, dep[ind]));
                }
                ind = p[ind] - 1;
            }
        }
        if(num != n + 1){
            writer.println("NO");
            writer.close();
            return;
        }
        writer.println("YES");
        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < n; ++i){
            ans.append(array[i]);
            ans.append(" ");
        }
        writer.println(ans);
        writer.close();
    }
}