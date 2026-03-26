import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;
import java.security.*;


public class problem {
	
	static FastReader sc=new FastReader();
	static long mod=(long) (1e9+7);
             
	 public static int setbits(int n) {
		 int count=0;
		 while(n!=0) {
			 n=n&(n-1);
			  count++;
		 }
		 return count;
	 }
	 public static int LowerBoundorequaltox(int n,long tar,long[] arr) {
			int l=0,r=n-1,an=0;
			while(l<=r) {
				int mid=(l+r)/2;
				if(arr[mid]<=tar) {
					l=mid+1;
					an=mid;
					
				}
				else {
					r=mid-1;
				}
			}
			return an;
			
		} 
	 
	 
	 
	 public static int mostsetgbit(int n) {
		 int msbcount=0;
		 while(n!=1) {
			 n/=2;
			 msbcount++;
		 }
		 return msbcount;
	 }
	 //Lower Bound
	 static int lower_bound(long array[], int key)
	    {
	 
	        int index = Arrays.binarySearch(array, key);
	 
	        // If key is not present in the array
	        if (index < 0) {
	 
	            // Index specify the position of the key
	            // when inserted in the sorted array
	            // so the element currently present at
	            // this position will be the lower bound
	            return Math.abs(index) - 1;
	        }
	 
	        // If key is present in the array
	        // we move leftwards to find its first occurrence
	        else {
	 
	            // Decrement the index to find the first
	            // occurrence of the key
	 
	            while (index > 0) {
	 
	                // If previous value is same
	                if (array[index - 1] == key)
	                    index--;
	 
	                // Previous value is different which means
	                // current index is the first occurrence of
	                // the key
	                else
	                    return index;
	            }
	 
	            return index;
	        }
	    }	 
	 
	 
	
	    
	       
	       
	    
	

	public static void main(String[] args) {
			int t=sc.nextInt();
			while(t-->0) {
				String s=sc.next();
				ArrayList <Integer> al=new ArrayList<Integer>();
				al.add(-1);
				
				for(int i=0;i<s.length();i++) {
					if(s.charAt(i)=='R')al.add(i);
				}
				al.add(s.length());
				int ans=0;
				for(int i=0;i<al.size()-1;i++) {
					int a=al.get(i+1)-al.get(i);
					ans=Math.max(a, ans);
					
				}
				
				
				System.out.println(ans);
				
				
				
				
				
				
				
				
				}

			
		}
	
	//INTEGER ARRAY INPUT SHORTCUT
	static int[] input(int n) {
		int A[]=new int[n];
		   for(int i=0;i<n;i++) {
			   A[i]=sc.nextInt();
		   }
		   return A;
	   }
	
	//LONG ARRAY INPUT 
	static long[] inputL(int n) {
		long A[]=new long[n];
		   for(int i=0;i<n;i++) {
			   A[i]=sc.nextLong();
		   }
		   return A;
	   }
	
	//STRING ARRAY INPUT
	static String[] inputS(int n) {
		String A[]=new String[n];
		   for(int i=0;i<n;i++) {
			   A[i]=sc.next();
		   }
		   return A;
	   }
	
	//SWAPPING TWO NUMBERS
	 public static void swap(int a ,int b) {
			
		 a=a^b;
		 b=a^b;
		 a=a^b;
		 
		 
	 }
	    
	
	
	//GCD
	public static int gcd(int p,int q) {
		 if(q==0)return 1;
		 else
			 return gcd(q,q%p);
		 
	 }
	
	
	//Custom Input Reader
	static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } }
 
 
 
	}