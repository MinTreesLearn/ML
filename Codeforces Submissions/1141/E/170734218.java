import java.io.*;
import java.util.*;


 
public class ProblemB {
 
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner();
		StringBuilder sb = new StringBuilder();
		long h = in.readLong();
		int n = in.readInt();
		int a[] = new int[n];
		long sum = 0;
		for(int i = 0;i<n;i++){
			a[i] = in.readInt();
			sum+=a[i];
		}
		long ans = -1;		
		long prefix[] = new long[n];
		long min = Long.MAX_VALUE;
		TreeMap<Long,Integer>mp = new TreeMap<>();
		int ind =0;
		for(int i = 0;i<n;i++){
			prefix[i] = a[i];
			if(i-1>=0)prefix[i]+=prefix[i-1];
			if(prefix[i]+h<=0){
				System.out.println(i+1);
				return;
			}
			if(prefix[i]<0 && !mp.containsKey(-prefix[i]))mp.put(-prefix[i], i);

		}
		if(mp.size()==0 || sum>=0){
			System.out.println(-1);
			return;
		}else{
			long t = mp.lastKey();
			sum = -sum;
			
			long full = (h-t+(sum-1))/sum;
			
			h-=(full*sum);
			ans = full*n;
			for(int i=0;;i=(i+1)%n){
				if(h<=0)break;
				ans++;
				h+=a[i];
			}
			System.out.println(ans);
		}
		
		
		
			
	}
	public static void sort(int a[]){
		ArrayList<Integer>l = new ArrayList<>();
		for(int it:a)l.add(it);
		Collections.sort(l);
		for(int i = 0;i<l.size();i++)a[i] = l.get(i);
	}
	public static int lower(int target,int l,int r,int a[]){
		int index = l;
		while(l<=r){
			int mid = (l+r)/2;
			if(a[mid]<=target){
				index = mid;
				l = mid+1;
			}else r= mid-1;
		}
		return index;
	}
	public static int[] get(long n){
		int count1=0,count2=0;
		while(n%2 == 0){
			n/=2;
			count1++;
		}
		while(n%3 == 0){
			n/=3;
			count2++;
		}
		return new int[]{count1,count2};
	}
	public static boolean isPalindrome(int val){
		String s = String.valueOf(val);
		for(int i = 0;i<s.length()/2;i++){
			if(s.charAt(i) != s.charAt(s.length()-i-1))return false;
		}
		return true;
	}
	public static int sum(int n){
		int sum = 0;
		while(n>0){
			sum+=(n%10);
			n/=10;
		}
		return sum;
	}
	public static void swap(int a[],int i, int j){
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	
	public static boolean subsequence(String cur,String t){
		int pos = 0;
		for(int i = 0;i<cur.length();i++){
			if(pos<t.length() && cur.charAt(i) == t.charAt(pos)){
				pos++;
			}
		}
		return pos == t.length();
	}
	public static long gcd(long a, long b){
		return b ==0 ?a:gcd(b,a%b);
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


