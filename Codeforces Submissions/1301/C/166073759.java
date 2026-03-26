import java.io.*;
import java.util.*;
import java.math.BigInteger;
import static java.lang.Math.min;
import static java.lang.Math.max;
import static java.lang.Math.abs;

public class CodeForces {

	static int mod=1000000000+7;
	static FastScanner in=new FastScanner();
	static PrintWriter out=new PrintWriter(System.out);
	
	public static void main(String[] args) {
		
		int T=in.nextInt();
		//int T=1;
		for (int tt=0; tt<T; tt++) {
		//begin
		
			long n=in.nextLong();long m=in.nextLong();
			
			long tot=(n*(n+1))/2;
			
			long zero_pos=m+1;
			
			long first_freqval=(n-m)/zero_pos;long first_freq=(n-m>=zero_pos)?m+1:n-m;
			
			long second_freqval=((n-m)/zero_pos)+1;long second_freq=(n-m)%zero_pos;
			
			first_freq-=second_freq;
			
			long aa=first_freq*(first_freqval*(first_freqval+1))/2;
			
			long bb=second_freq*(( second_freqval)*(second_freqval+1))/2;
			
			p(tot-aa-bb);
			
		//end
		}
		
		out.close();
	}

	static class Pair implements Comparable<Pair>{
	    	int first;int second;
		        Pair(int first,int second){            
		        	this.first=first;
		        	this.second=second;   	
		        }
		        public int compareTo(Pair o) {
		       return o.second-this.second;
	
		        }
		    }
	
	 static boolean isPrime(long n)
	    {
	        if(n < 2) return false;
	        if(n == 2 || n == 3) return true;
	        if(n%2 == 0 || n%3 == 0) return false;
	        long sqrtN = (long)Math.sqrt(n)+1;
	        for(long i = 6L; i <= sqrtN; i += 6) {
	            if(n%(i-1) == 0 || n%(i+1) == 0) return false;
	        }
	        return true;
	    }
	 
	  static long gcd(long a, long b)
	    {
	        if(a > b)
	            a = (a+b)-(b=a);
	        if(a == 0L)
	            return b;
	        return gcd(b%a, a);
	    }
	 
	 static Pair[] pair(Map<Integer,Integer> map) {
		 Pair pair[]=new Pair[map.size()];int i=0;
		 for(int ele:map.keySet()) {
			 pair[i]=new Pair(ele,map.get(ele));i++;}
		 Arrays.sort(pair);
		 return pair;
	 }
	 
	 static Map map(int[] ar) {
		 Map<Integer,Integer> map=new HashMap<>();
		 for(int i=0;i<ar.length;i++) {
			 if(map.containsKey(ar[i]))
				 map.put(ar[i], map.get(ar[i])+1);
			 else
				 map.put(ar[i], 1); 
		 }
		 return map;
	 }
	 static void p(int arr[]) {
		 for(int i=0;i<arr.length;i++)
			 out.print(arr[i]+" ");
		 out.println();
	 }
	 static<T> void p(T abcd) {
		 out.println(abcd);
	 }
	 
	 static void py() {
		 out.println("YES");
	 }
	 
	 static void pn() {
		 out.println("NO");
	 }
	 
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static void sortd(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l,Comparator.reverseOrder());
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		 String nextLine(){
	            String str = "";
	            try{
	                str = br.readLine();
	            }catch (IOException e){
	                e.printStackTrace();
	            }
	            return str;
	        }
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		double nextDouble(){
            return Double.parseDouble(next());
        }
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		String[] readStringArray(int n) {
			String[] a=new String[n];
			for (int i=0; i<n; i++) a[i]=next();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}