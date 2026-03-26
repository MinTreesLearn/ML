	import java.io.*;
	import java.util.*;
	 
	public class ProblemB {
		static HashMap<Long,Integer>mp ;
		static int MOD = (int)1e9+7;
		static int MAX = (int)1e5+1;
		static char c[][];
		public static void main(String[] args) throws Exception {
			Scanner in = new Scanner();
			StringBuilder sb = new StringBuilder();
			int test = in.readInt();

			while(test-->0){
				int n = in.readInt();
				boolean ok = false;
				outer: for(int i = 2;i*i<=n;i++){
					if(n%i == 0){
						int other = n/i;
						for(int j = 2;j*j<=other;j++){
							if(other%j == 0){
								if(other/j != j && j != i && i!= other/j){
									sb.append("YES\n");
									sb.append(i+" "+j+" "+(other/j)+"\n");
									ok = true;
									break outer;
								}
							}
						}
					}
				}
				if(!ok)sb.append("NO\n");
				
			}
			
			
			
			System.out.println(sb);
			
	}
		public static int go(int a[], long h,int b,int g,int ind){
			if(ind>=a.length)return 0;
			if(h>a[ind]) return 1+go(a,h+a[ind]/2,b,g,ind+1);
			return Math.max(g>0?go(a,2*h,b,g-1,ind):0,b>0?go(a,3*h,b-1,g,ind):0);
			
		}
		public static int last(int a[],int t){
			int l = 0,r= a.length-1,ind = -1;
			while(l<=r){
				int mid = (l+r)/2;
				if(a[mid] == t){
					ind = mid;
					l = mid+1;
				}else if(a[mid]<t)l = mid+1;
				else r = mid-1;
			}
			return ind;
		}
		
	public static boolean great(String s){
		if(s.charAt(1)>=s.charAt(0)){
			if(s.charAt(1)>=s.charAt(s.length()-1))return true;
		}
		return false;
	}
		

		public static boolean isSorted(int a[]){
			for(int i = 0;i<a.length;i++){
				if(i+1<a.length && a[i]>a[i+1])return false;
			}
			return true;
		}
		
		public static boolean isPrime(int n){
			for(int i = 2;i*i<=n;i++){
				if(n%i == 0)return false;
			}
			return true;
		}		
		
	 public static int[] fill(String s){
		 int a[] = new int[s.length()];
		 for(int i = 0;i<s.length();i++)a[i] = s.charAt(i)-'0';
		 return a;
	 }
		
		public static long factorial(int n){
			long fac = 1;
			for(int i = 1;i<=n;i++)fac*=i;
			return fac;
		}
		public static ArrayList<Integer> factors(int n){
			ArrayList<Integer>l = new ArrayList<>();
			for(int i = 1;i*i<=n;i++){
				if(n%i == 0){
					l.add(i);
					if(n/i != i)l.add(n/i);
				}
				
			}
			return l;
		}
 
		public static void build(int seg[],int ind,int l,int r,int a[]){
			if(l == r){
				seg[ind] = a[l];
				return;
			}
			int mid = (l+r)/2;
			build(seg,(2*ind)+1,l,mid,a);
			build(seg,(2*ind)+2,mid+1,r,a);
			seg[ind] = Math.min(seg[(2*ind)+1],seg[(2*ind)+2]);
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
		public static void swap(ArrayList<Integer>l,int i, int j){
			int t = l.get(i);l.set(i, l.get(j));l.set(j, t);
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
			int z = 0;
			for(int i = 0;i<arr.length;i++)arr[z++] = list.get(i);
		}
		
		static class Pair{
			int x,z;
			int y;
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


	
