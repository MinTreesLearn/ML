import java.io.*;
import java.util.*;

public class new1{
	static FastReader s = new FastReader();
    static int gcd(int a, int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
   
    
    public static int dfs1(ArrayList<ArrayList<Integer>> aList, int u, int p, int[] val, int[] arr1) {
    	
    	int sum = val[u];
    	for(Integer x : aList.get(u)) {
    		if(x != p) {
    			int aa = dfs1(aList, x, u, val, arr1);
    			if(aa >= 0) sum = sum + aa;
    		}
    	}
    	arr1[u] = sum;
    	return sum;
    }
    
    public static void dfs2(ArrayList<ArrayList<Integer>> aList, int u, int p, int[] val, int[] arr1, int[] ans) {
    	
    	if(p == -1) {
    		ans[u] = arr1[u];
    	}
    	else {
    		int ans1 = 0;
        	if(arr1[u] == -1) ans1 = Math.max(-1, ans[p] - 1);
        	else ans1 = Math.max(arr1[u], ans[p]);
        	ans[u] = ans1;
    	}
    	for(Integer x : aList.get(u)) {
    		if(x != p) {
    			dfs2(aList, x, u, val, arr1, ans);
    		}
    	}
    }
    
    
    

	public static void main(String[] args)  throws IOException{

		BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = 1;//s.nextInt();
		for(int z = 0; z < t; z++) {
			int n = s.nextInt();
			int[] val = new int[n + 1];
			for(int i = 1; i <= n; i++) {
				if(s.nextInt() == 0) val[i] = -1;
				else val[i] = 1;
			}
			ArrayList<ArrayList<Integer>> aList = new ArrayList<ArrayList<Integer>>();
			for(int i = 1; i <= n + 1; i++) {
				ArrayList<Integer> list = new ArrayList<Integer>();
				aList.add(list);
			}
			for(int i = 0; i < n - 1; i++) {
				int u = s.nextInt();
				int v = s.nextInt();
				aList.get(u).add(v);
				aList.get(v).add(u);
				
			}
			int[] arr1 = new int[n + 1];
			dfs1(aList, 1, -1, val, arr1);
		//	System.out.println(Arrays.toString(arr1));
			
			int[] ans = new int[n + 1];
			dfs2(aList, 1, -1, val, arr1, ans);
			for(int i = 1; i <= n; i++) {
				output.write(ans[i] + " ");
			}
			output.write("\n");
			//System.out.println(Arrays.toString(ans));
			
			
			
			
			
		}
		
		output.flush();
			
	  }
}


 
class FastReader {
    BufferedReader br;
    StringTokenizer st;
    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
 
    public int nextInt() {
        return Integer.parseInt(next());
    }
 
    long nextLong() {
        return Long.parseLong(next());
    }
 
    double nextDouble() {
        return Double.parseDouble(next());
    }
 
    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
}}