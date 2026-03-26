	import java.io.*;
	import java.util.*;
	 
	public class ProblemD {
	 
		public static void main(String[] args) throws Exception {
			Scanner in = new Scanner();
			int n = in.readInt();
			int a[] = new int[n];
			for(int i = 0;i<n;i++)a[i] = in.readInt();
			int mx = 0;
			ArrayList<Pair>res = new ArrayList<>();
			for(int i = 0;i<n;i++){
				long sum = 0;
				for(int j = i;j<n;j++){
					sum+=a[j];
					HashMap<Long,Integer>mp = new HashMap<>();
					ArrayList<Pair>l = new ArrayList<>();
					long cur = 0;
					int pos  = 0;
					mp.put(0l, -1);
					for(int z=0;z<n;z++){
						cur+=a[z];
						if(mp.containsKey(cur-sum)){							
							l.add(new Pair(mp.get(cur-sum)+2,z+1));
							mp.clear();
						}
						mp.put(cur, z);
						
						
						
						
					}
					/*if(sum == 2){
						for(Pair it:l)System.out.println(it.x+" "+it.y+" "+sum);
					}*/
					if(l.size()>mx){
						mx = l.size();
						res = new ArrayList<>(l);
					}
				}
			}
			System.out.println(res.size());
			for(Pair it:res)System.out.println(it.x+" "+it.y);
			
				
				
				
				
			

			
		}
		public static long gcd(long a, long b){
			return b ==0 ?a:gcd(b,a%b);
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
		public static ArrayList<Long> factors(long n){
			ArrayList<Long>l = new ArrayList<>();
			for(long i = 1;i*i<=n;i++){
				if(n%i == 0){
					l.add(i);
					if(n/i != i)l.add(n/i);
				}
			}
			Collections.sort(l);
			return l;
		}
		
		public static void swap(int a[],int i, int j){
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		
		public static boolean isSorted(long a[]){
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
	
	
