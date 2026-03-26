import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.List;
import java.util.ArrayList;
public class Solution {
    static Reader input = new Reader();
    static int n;
    static List<Integer>[] adjacents;
    static int[] parent, height, deep;
    static int start = 0, end = 0, v = 0;
    public static void main(String[] args) throws IOException {
        n = input.nextInt();
        adjacents = new List[n];
        for(int i = 0; i < n; ++i) adjacents[i] = new ArrayList<Integer>();
        int u, v;
        for(int i = 1; i < n; ++i) {
            u = input.nextInt()-1;
            v = input.nextInt()-1;
            adjacents[u].add(v);
            adjacents[v].add(u);
        }
        parent = new int[n];
        height = new int[n];
        deep = new int[n];
        dfs(0, -1);
        dfs(0);
        List<Integer> path = new ArrayList<Integer>();
        setPath(start, end, -1, path);
        boolean[] inPath = new boolean[n];
        for(int node : path) inPath[node] = true;
        int[] t = null;
        for(int node : path) {
            int[] temp = test(node, -1, inPath);
            if(temp[0] == start || temp[0] == end) continue;
            if(t == null || temp[1] > t[1]) {
                t = temp;
            }
        }
        StringBuilder output = new StringBuilder();
        int x = t[1] + path.size()-1;
        output.append(x);
        output.append("\n");
        output.append(start+1);
        output.append(" ");
        output.append(end+1);
        output.append(" ");
        output.append(t[0]+1);
        System.out.print(output);
    }
    static int[] test(int node, int p, boolean[] inPath) {
        int[] result = new int[]{node, 0};
        for(int adjacent : adjacents[node]) {
            if(adjacent != p && !inPath[adjacent]) {
                int[] temp = test(adjacent, node, inPath);
                if(temp[1] > result[1]) {
                    result = temp;
                }
            }
        }
        if(p != -1) {
            ++result[1];
        }
        return result;
    }
    static boolean setPath(int node, int dist, int p, List<Integer> path) {
        if(node == dist) {
            path.add(node);
            return true;
        }
        for(int adjacent : adjacents[node]) {
            if(adjacent != p) {
                if(setPath(adjacent, dist, node, path)) {
                    path.add(node);
                    return true;
                }
            }
        }
        return false;
    }
    static void dfs(int node) {
        int max1 = -1, max2 = -1;
        for(int adjacent : adjacents[node]) {
            if(adjacent != parent[node]) {
                if(max1 == -1 || height[adjacent] > height[max1]) {
                    max2 = max1;
                    max1 = adjacent;
                } else if(max2 == -1 || height[adjacent] > height[max2]) {
                    max2 = adjacent;
                }
                dfs(adjacent);
            }
        }
        if(max1 != -1 && max2 != -1) {
            if(height[max1]+height[max2]+1 > v) {
                v = height[max1]+height[max2]+1;
                start = deep[max1];
                end = deep[max2];
            }
        } else if(max1 != -1) {
            if(height[max1]+1 > v) {
                v = height[max1]+1;
                start = deep[max1];
                end = node;
            }
        } else if(max2 != -1) {
            if(height[max2]+1 > v) {
                v = height[max2]+1;
                start = deep[max2]+1;
                end = node;
            }
        }
    }
    static void dfs(int node, int p) {
        parent[node] = p;
        int h = 0;
        int d = node;
        for(int adjacent : adjacents[node]) {
            if(adjacent != p) {
                dfs(adjacent, node);
                if(height[adjacent] > h) {
                    h = height[adjacent];
                    d = deep[adjacent];
                }
            }
        }
        height[node] = h+1;
        deep[node] = d;
    }
    static class Reader {
        BufferedReader bufferedReader;
        StringTokenizer string;
        public Reader() {
            InputStreamReader inr = new InputStreamReader(System.in);
            bufferedReader = new BufferedReader(inr);
        }
        public String next() throws IOException {
            while(string == null || ! string.hasMoreElements()) {
                string = new StringTokenizer(bufferedReader.readLine());
            }
            return string.nextToken();
        }
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
        public String nextLine() throws IOException {
            return bufferedReader.readLine();
        }
    }
}