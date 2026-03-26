import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class Solution{
	
	

	public static void main(String[] args) {

		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		
		
		int tt = 1;
		while(tt-->0) {
			
			int n = fs.nextInt(), m = fs.nextInt(), p = fs.nextInt();
			
			int p1 = -1;
			int p2 = -1;
			
			for(int i=0;i<n;i++) {
				int c = fs.nextInt();
				if(c%p!=0 && p1==-1) {
					p1 = i;
				}
			}
			
			for(int i=0;i<m;i++) {
				int c = fs.nextInt();
				if(c%p!=0 && p2==-1) {
					p2 = i;
				}
			}
			
			out.println(p1+p2);
			
			
			
			
			
			
		}
		
		out.close();
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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
		
		public char nextChar() {
			return next().toCharArray()[0];
		}
	}
	
}
