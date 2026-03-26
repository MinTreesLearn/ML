import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Solution{
	
	public static void main(String[] args) throws Exception{

		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		
		int tt = 1;
		while(tt-->0) {
			
			char[] s = fs.next().toCharArray();
			int n = s.length;
			
			int[][] count = new int[n+1][26];
			
			for(int i=1;i<=n;i++) {
				for(int j =0;j<26;j++) {
					count[i][j] = count[i-1][j];
				}
				count[i][s[i-1]-'a']++;
			}
			
			int q = fs.nextInt();
			while(q-->0) {
				
				int l = fs.nextInt();
				int r = fs.nextInt();
				
				int cnt = 0;
				for(int i=0;i<26;i++) {
					cnt += ((count[r][i] - count[l-1][i])>0)?1:0 ;
				}
				
				
				
				if(l==r || cnt>2 ||  s[l-1]!=s[r-1])
					out.println("YES");
				else
					out.println("NO");
				
			}
			
		}
		
		out.close();
	}
	
	
	static class FastScanner{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		public String next(){
			while(!st.hasMoreElements()){
				try{
					st = new StringTokenizer(br.readLine());
				} catch(IOException e){
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		
		public String nextLine() throws IOException {
			return br.readLine();
		}
		
		public int nextInt(){
			return Integer.parseInt(next());
		}

		public int[] readArray(int n){
			int[] a = new int[n];
			for(int i=0;i<n;i++)
				a[i] = nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
	
}
