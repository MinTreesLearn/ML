import java.io.*;
import java.util.*;
// #FullSolution
public class new1{
	public static long gcd(long a, long b)
    {
        if (a == 0)
            return b;
         
        return gcd(b%a, a);
    }
	
	//static int max = -1;
	
	public static ArrayList<Integer> dfs(int[] parent, int[] gret, int x){
		//System.out.println(x);
		int n = parent.length - 1;
		ArrayList<Integer> aList = new ArrayList<Integer>();
		for(int i = 1; i <= n; i++) {
			if(parent[i] == x) {
				ArrayList<Integer> a1 = dfs(parent, gret, i);
				if(a1 == null) return null;
				for(int j = 0; j < a1.size(); j++) aList.add(a1.get(j));
			}
		}
		int pos = gret[x];
		if(aList.size() < pos) return null;
		aList.add(pos, x);
		return aList;
	}
	
	
	
	public static void main(String[] args)  throws IOException{

		BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
		FastReader s = new FastReader();
		int t = 1;//s.nextInt();
		for(int z = 0; z < t; z++) {
			int n = s.nextInt();
			int[] parent = new int[n + 1];
			int[] gret = new int[n + 1];
			int root = -1;
			for(int i = 0; i < n; i++) {
				int pa = s.nextInt();
				if(pa == 0) root = i + 1;
				int gr = s.nextInt();
				parent[i + 1] = pa;
				gret[i + 1] = gr;
			}
		//	System.out.println(root);
		//	System.out.println(Arrays.toString(parent));
		//	System.out.println(Arrays.toString(gret));
			ArrayList<Integer> ans = dfs(parent, gret, root);

			if(ans == null) System.out.println("NO");
			else {
				System.out.println("YES");
				int[] ans1 = new int[n + 1];
				for(int i = 1; i <= n; i++) {
					int val = ans.get(i - 1);
					ans1[val] = i;
				}
				
				for(int i = 1; i <= n; i ++) System.out.print(ans1[i] + " ");
			}
			//System.out.println(ans.toString());
			
		}
		
		//output.flush();
			
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