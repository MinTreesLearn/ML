	import java.io.*;
	import java.util.*;
	 
	public class ProblemB {
		static int ans = Integer.MAX_VALUE;
		static int n,m,x,y,d;
		public static void main(String[] args) throws Exception {
			Scanner in = new Scanner();
			int test = in.readInt();
			StringBuilder sb = new StringBuilder();
			while(test-->0){
				int a = in.readInt();
				int b =in.readInt();
				int c = in.readInt();
				int ans = Integer.MAX_VALUE;
				int res[] = new int[3];
				for(int i =1;i<=2*a;i++){
					for(int j =i;j<=2*b;j+=i){
						int t = (c/j)*j;
						int cur = Math.abs(a-i)+Math.abs(b-j)+Math.abs(c-t);
						if(ans>cur){
							ans  = cur;
							res[0] = i;res[1]=j;res[2]=t;
						}
						t+=j;
						cur = Math.abs(a-i)+Math.abs(b-j)+Math.abs(c-t);
						
						if(ans>cur){
							ans  = cur;
							res[0] = i;res[1]=j;res[2]=t;
							
						}
					}
				}
				
				sb.append(ans+"\n");
				sb.append(res[0]+" "+res[1]+" "+res[2]+"\n");
				
				
			
			}
			System.out.println(sb);
			
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




