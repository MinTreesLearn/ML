	import java.io.*;
	import java.util.*;
	 
	public class ProblemD {
	 
		public static void main(String[] args) throws Exception {
			Scanner in = new Scanner();
			StringBuilder sb = new StringBuilder();
			int test = in.readInt();
			while(test-->0){
				int n = in.readInt();
				int p  = in.readInt();
				String s = in.readLine();
				int pos[] = new int[p];
				for(int i = 0;i<p;i++)pos[i] = in.readInt()-1;
				int count[][] = new int[n][26];
				for(int i = 0;i<n;i++){
					count[i][s.charAt(i)-'a']++;
					if(i-1>=0){
						for(int j =0;j<26;j++){
							count[i][j]+=count[i-1][j];
						}
					}
				}
				int res[] = new int[26];
				for(int i =0;i<p;i++){
					for(int j = 0;j<26;j++){
						res[j]+=count[pos[i]][j];
					}
				}
				for(int j = 0;j<26;j++){
					res[j]+=count[n-1][j];
				}
				for(int it:res)sb.append(it+" ");
				sb.append("\n");
				
			}
			System.out.println(sb);

			
		}
		public static long nearest(TreeSet<Long> list,long target){
			long nearest = -1,sofar = Integer.MAX_VALUE;
			for(long it:list){
				if(Math.abs(it - target)<sofar){
					sofar = Math.abs(it - target);
					nearest = it;
				}
			}
			return nearest;
		}
		public static TreeSet<Long> factors(long n){
			TreeSet<Long>set = new TreeSet<>();
			for(long i = 1;i*i<=n;i++){
				if(n%i == 0){
					set.add(i);
					if(n/i != i)set.add(n/i);
				}
			}
			return set;
		}
		
		public static void swap(int a[],int i, int j){
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		
		public static boolean sorted(int a[]){
			for(int i =0;i<a.length;i++){
				if(i+1<a.length && a[i]>a[i+1])return false;
			}
			return true;
		}
		
		public static int first(ArrayList<Long>list,long target){
			int index = -1;
			int l = 0,r = list.size()-1;
			while(l<=r){
				int mid = (l+r)/2;
				if(list.get(mid) == target){
					index = mid;
					r = mid-1;
				}else if(list.get(mid)>target){
					r  = mid-1;
				}else l  = mid+1;
			}
			return index;
		}
		
		public static int last(ArrayList<Long>list,long target){
			int index = -1;
			int l = 0,r = list.size()-1;
			while(l<=r){
				int mid = (l+r)/2;
				if(list.get(mid) == target){
					index=  mid;
					l = mid+1;
				}else if(list.get(mid)<target){
					l  = mid+1;
				}else r  = mid-1;
			}
			return index;
		}
		
		
		public static void sort(int arr[]){
			ArrayList<Integer>list = new ArrayList<>();
			for(int it:arr)list.add(it);
			Collections.sort(list);
			for(int i = 0;i<arr.length;i++)arr[i] = list.get(i);
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
	
	
