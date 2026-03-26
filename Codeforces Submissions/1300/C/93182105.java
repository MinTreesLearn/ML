import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C{

	public static void main(String[] args) throws Exception{

		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		
		int n= fs.nextInt();
		int[] a = fs.readArray(n);
		
		
		int ind = -1;
		boolean bool = false;
		for(int p = (1<<29);p>0;p=p>>1) {
			int count = 0;
			for(int i=0;i<n;i++) {
				if((a[i]&p)!=0) {
					ind = i;
					count++;
				}
			}
			if(count==1) {
				bool = true;
				break;
			}
		}
		
		if(bool) {
			out.print(a[ind]+" ");
			for(int i=0;i<ind;i++) out.print(a[i]+" ");
			for(int i=ind+1;i<n;i++) out.print(a[i]+" ");
			out.println("");
			
		}
		else {
			for(int b: a) out.print(b+" ");
			out.println("");
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