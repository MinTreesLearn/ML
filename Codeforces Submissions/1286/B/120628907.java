/*
TASK: template
LANG: JAVA
 */
import java.io.*;
import java.lang.*;
import java.util.*;

public class B1286 {
    static HashMap<Integer, ArrayList<Integer>> hash = new HashMap<>();;
    static int[] c;
    static int[] val;
    static int[] parent;
    static boolean broken = false;
    static int[] value;
    public static void main(String[] args) throws IOException {
        StringBuffer ans = new StringBuffer();
        StringTokenizer st;
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        c = new int[n];
        val = new int[n];
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(f.readLine());
            int ft = Integer.parseInt(st.nextToken()) - 1;
            int sc = Integer.parseInt(st.nextToken());
            c[i] = sc;
            if (!hash.containsKey(ft))
                hash.put(ft, new ArrayList<>());
            parent[i] = ft;
            hash.get(ft).add(i);
        }
        ArrayList<Integer> arrl = new ArrayList<>();
        //System.out.println(hash);
        for(int i = 0; i < n; i++){
            if(parent[i] == -1){
                arrl = dfs(i);
            }
        }
        f.close();
        value = new int[n];
        int val = 1;
        for(int i : arrl){
            value[i] = val;
            val++;
        }
        for(int i = 0; i < n; i++){
            //System.out.println(check(i, value[i]) + " " + c[i]);
            if(check(i, value[i]) != c[i])
                broken = true;
        }
        if(broken){
            System.out.println("NO");
            System.exit(0);
        }
        System.out.println("YES");

        for(int i : value)
            ans.append(i).append(" ");
        System.out.println(ans);

    }
    public static ArrayList<Integer> dfs(int node){
        ArrayList<Integer> arrl = new ArrayList<>();
        if(hash.containsKey(node) && hash.get(node).size() != 0){
            for(int i : hash.get(node)){
                arrl.addAll(dfs(i));
            }
        }
        if(c[node] > arrl.size())
            broken = true;
        else
            arrl.add(c[node], node);
        //System.out.println(arrl);
        return arrl;
    }
    public static int check(int node, int val){
        int add = 0;
        if(value[node] < val){
            add++;
        }
        if(hash.containsKey(node))
            for(int i : hash.get(node)){
                add+=check(i, val);
            }
        return add;
    }
    public static class point implements Comparable<point>{
        int x;
        int y;
        public point(int x,int y){
            this.x = x;
            this.y = y;
        }
        public String toString(){
            return(x + " " + y);
        }
        public int compareTo(point other){
            if(this.x > other.x || (this.x == other.x && this.y > other.y)){
                return 1;
            }else if(this.x == other.x && other.y == this.y){
                return 0;
            }
            return -1;
        }
    }

}