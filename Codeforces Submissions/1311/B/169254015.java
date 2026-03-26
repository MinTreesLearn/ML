	import java.io.*;
	import java.util.*;
	 
	public class ProblemD {
	 
		public static void main(String[] args) throws Exception {
			Scanner in = new Scanner();
			StringBuilder sb = new StringBuilder();
			int test = in.readInt();
			while(test-->0){
				int n = in.readInt();
				int k = in.readInt();
				int a[] = new int[n];
				int p[] = new int[n];
				HashSet<Integer>set = new HashSet<>();
				for(int i = 0;i<n;i++)a[i] = in.readInt();
				for(int i = 0;i<k;i++)set.add(in.readInt());
				while(true){
					boolean ok = false;
					for(int i =0;i<n;i++){
						if(i+1<n && a[i]>a[i+1] && set.contains(i+1)){
							swap(a,i,i+1);
							ok = true;
						}
					}
					if(sorted(a) || !ok){
						break;
					}
				}
				if(sorted(a))System.out.println("YES");
				else System.out.println("NO");
				
			}

			
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
	
	
