import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D{

	public static void main(String[] args) throws Exception{

		FastScanner fs = new FastScanner();
		
		int n = fs.nextInt();
		
		if((n&1)==1) {
			System.out.println("NO");
			return;
		}
		
		int m = n/2;
		
		long[] x1 = new long[m];
		long[] y1 = new long[m];
		long[] x2 = new long[m];
		long[] y2 = new long[m];
		
		for(int i=0;i<m;i++) {
			x1[i] = fs.nextLong();
			y1[i] = fs.nextLong();
		}
		
		for(int i=0;i<m;i++) {
			x2[i] = fs.nextLong();
			y2[i] = fs.nextLong();
		}
		
		long cX = (x1[0] + x2[0]);
		long cY = (y1[0] + y2[0]);
		
		boolean bool = true;
		
		for(int i=0;i<m;i++) {
			if(cX != (x1[i]+x2[i])) {
				bool = false;
				break;
			}
			if(cY != (y1[i] + y2[i])) {
				bool =  false;
				break;
			}
		}
		
		System.out.println(bool?"YES":"NO");
		
		
		
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
		
		public long nextLong() {
			return Long.parseLong(next());
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