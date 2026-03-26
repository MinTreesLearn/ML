import java.lang.*;
import java.math.*;
import java.io.*;
import java.security.SecureRandom;
import java.util.*;
public class Main{
    public static int mod=(int)(1e9) + 7;

    public static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter ot=new PrintWriter(System.out);

    public static int[] take_arr(int n){
        int a[]=new int[n];
        try {
            String s[]=br.readLine().trim().split(" ");
            for(int i=0;i<n;i++)
            a[i]=Integer.parseInt(s[i]);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return a;
    }
    public static List<Integer> take_list(int n){
        List<Integer> a=new ArrayList<>();
        try {
            String s[]=br.readLine().trim().split(" ");
            for(int i=0;i<n;i++)
            a.add(Integer.parseInt(s[i]));
        } catch (Exception e) {
            e.printStackTrace();
        }
        return a;
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		try{ 
            int t=1;//Integer.parseInt(br.readLine().trim());
         
            int cno=1;
            while(t-->0){
                
                String s[]=br.readLine().trim().split(" ");
                
                int n = Integer.parseInt(s[0]);
                // int m = Integer.parseInt(s[1]);
                // solve(br.readLine());
                // int k = Integer.parseInt(s[2]);
                // char ch[] = br.readLine().trim().toCharArray();
                // int a[] = take_arr(n);
                // int b[] = take_arr(m);
                // long n = Long.parseLong(s[0]);
                // long m = Long.parseLong(s[1]);
                solve(n);
                // solve()
                // solve(n, m);

                // solve(ch);
            }
            ot.close();
            br.close();
        }catch(Exception e){
            e.printStackTrace();
            return;
        }
    }
    static void solve(int n) throws IOException{
        String s[] = br.readLine().trim().split(" ");
        c = new int[n + 1];
        for(int i = 1; i <= n; i++)
            c[i] = Integer.parseInt(s[i - 1]);
        adj = new ArrayList<>();
        for(int i = 0; i <= n; i++)
            adj.add(new ArrayList<>());
        for(int i = 1; i < n; i++){
            s = br.readLine().trim().split(" ");
            int u = Integer.parseInt(s[0]);
            int v = Integer.parseInt(s[1]);
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        dp = new int[n + 1];
        ans = new int[n + 1];
        dfs(1, -1);
        dfs2(1, -1);
        for(int i = 1; i <= n; i++)
            ot.print(ans[i] + " ");
        ot.println();
    }
    static void dfs2(int node, int par){
        ans[node] = dp[node];
        for(int ngr : adj.get(node)){
            if(ngr != par){
                dp[node] -= Math.max(0, dp[ngr]);
                dp[ngr] += Math.max(0, dp[node]);
                dfs2(ngr, node);
                dp[ngr] -= Math.max(0, dp[node]);
                dp[node] += Math.max(0, dp[ngr]);
            }
        }
    }
    static int dfs(int node, int par){
        int ans = (c[node] == 0 ? -1 : 1);
        for(int ngr : adj.get(node)){
            if(ngr != par){
               ans += Math.max(0, dfs(ngr, node));
            }
        }
        return dp[node] = ans;
    }
    static int ans[];
    static int c[];
    static int dp[];
    static List<List<Integer>> adj;
}