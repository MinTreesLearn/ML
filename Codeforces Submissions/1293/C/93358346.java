import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C{

	public static void main(String[] args) throws Exception{

		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		
		int tt = 1;
		
		while(tt-->0) {
			
			int n = fs.nextInt(), q = fs.nextInt();
			int[][] arr = new int[3][n+1];
			
			
			int count = 0;
			
			while(q-->0) {
				
				int i = fs.nextInt(), j = fs.nextInt();
				int k = (i==1)?2:1;
				int del = (arr[i][j]==0)?1:-1;
				arr[i][j] = (arr[i][j]==0)?1:0;
				
				if(arr[k][j]==1) count+= del;
				if(j+1<=n && arr[k][j+1]==1) count+= del;
				if(j-1>0 && arr[k][j-1]==1) count+= del;
				
				if(count==0) out.println("YES");
				else out.println("NO");
			
				
				
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

		public int nextInt(){
			return Integer.parseInt(next());
		}

		public int[] readArray(int n){
			int[] a = new int[n];
			for(int i=0;i<n;i++)
				a[i] = nextInt();
			return a;
		}
	}
	
	static int lowerBound(int[] arr, int l, int r, int k) {
		while(r>l) {
			int mid = (l+r)/2;
			if(arr[mid]>=k) {
				r = mid;
			}
			else {
				l = mid+1;
			}
		}
		if(arr[l]<k)
			return -1;
		return l;
	}
	
	
	
	static int upperBound(int[] arr, int l, int r, int k) {
		while(r>l) {
			int mid = (l+r)/2;
			if(arr[mid]>k) {
				r = mid;
			}
			else {
				l = mid+1;
			}
		}
		if(arr[l]<=k)
			return -1;
		return l;
	}

}