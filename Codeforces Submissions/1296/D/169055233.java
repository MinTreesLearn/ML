import java.io.*;
import java.util.*;
 
public class ProblemD {
 
	public static void main(String[] args) throws Exception {
		Scanner s= new Scanner();
		int n = s.readInt();
		int a = s.readInt();
		int b = s.readInt();
		int k = s.readInt();
		int arr[] = new int[n];
		int p = a+b,ans = 0;
		for(int i = 0;i<n;i++){
			arr[i] = s.readInt();
			if(arr[i]%p == 0){
				arr[i] = b;
				arr[i]+=a;
			}else arr[i]%=p; 
		}
		
		sort(arr);
		for(int i = 0;i<n;i++){
			if(arr[i]>0){				
				arr[i]-=a;	
			    
				if(arr[i]>0 && k>=(arr[i]+a-1)/a){
					k-=((arr[i]+a-1)/a);
					arr[i] = 0;
				}
				
			}
			if(arr[i]<=0)ans++;			
		}
		System.out.println(ans);
	}
	
	public static void sort(int arr[]){
		ArrayList<Integer>list = new ArrayList<>();
		for(int it:arr)list.add(it);
		Collections.sort(list);
		for(int i = 0;i<arr.length;i++)arr[i] = list.get(i)  ;
	}
	static class Pair{
		int x,y;
		public Pair(int x,int y){
			this.x = x;
			this.y = y;
		}
	}
	
	static class Scanner{
		BufferedReader br;
		StringTokenizer st;
		
		public Scanner(){
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
	    public String read()
	    {
	         while (st == null || !st.hasMoreElements()) {            
	            try {	st = new StringTokenizer(br.readLine()); }
	            catch (Exception e) {	e.printStackTrace(); }
	         }
	         return st.nextToken();
	     }

	     public int  readInt() { return Integer.parseInt(read()); }

	     public long readLong() { return Long.parseLong(read()); }

	     public double readDouble(){return Double.parseDouble(read());}

	     public  String readLine() throws Exception { return br.readLine(); }  
	 
	}

}


