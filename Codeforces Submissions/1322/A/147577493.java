
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Map.Entry;

 public class codeforces {
	 

	 
static int mod = 1000000007;
	 
public static void main(String[] args) {
	
	  FastReader sc = new FastReader();
	  try {
          StringBuilder ss = new StringBuilder();
          int n =  sc.nextInt();
          String s = sc.next();
          int cnt = 0 ;
          int ans = 0;
          boolean flag =true;
          for(int i = 0 ; i <s.length(); i++) {
        	  if(s.charAt(i) == ')') {
        		  cnt++;
        	  }
          }
          
        
        	  cnt = 0;
        	  int cnt1 = 0;
        	  for(int i = 0; i < n;i++) {
        		//  System.out.println(cnt +" "+cnt1);
        		  if(s.charAt(i) == '(') {
        			 
        			  cnt++;
        		     int min = Math.min(cnt, cnt1);
        		    	ans += min;
        		    	cnt -= min;
        		    	cnt1 -= min;
        		    
                  }
        		  else {
        			  cnt1++;
        		 	  if(cnt>=cnt1) {
        		 		   int min = Math.min(cnt, cnt1);
        		 		  cnt -= min;
        		 		  cnt1 -= min;
        		 	  }
        		 	  
        		  }
        	  }
        	  //System.out.println(cnt +" "+cnt1);
        	  if(cnt1 != 0 || cnt!= 0) {
        	ss.append(-1);
        	  }
        	  else {
        		  ss.append(2*ans);
        	  }
        	  
          
          
          
        
        
        
        
		  System.out.println(ss);
	      }
	  
	      catch(Exception e) {
		  System.out.println(e.getMessage());
	      }
          }
  
 
 
 
 
 static long pow(long a, long b) {
	 long ans = 1;
	 long temp = a;
	 while(b>0) {
		 if((b&1) == 1) {
			 ans*=temp;
		 }
		 temp = temp*temp;
	  b = b>>1;
	 }
	 return ans;
 }
 
 
 
 static long ncr(int n, int r) { 
	    return fact(n) / (fact(r) *
                fact(n - r));
}
 

static long fact(long n)
{
  long res = 1;
  for (int i = 2; i <= n; i++) {
      res = (res * i);
  }
  return res;
}
 
 static long gcd(long a, long b) {
	 if(b == 0) {
		 return a;
	 } 
	 return gcd(b , a%b);
	 
	 
	 
	 
	 
 }
 
 static ArrayList<Integer> factor(long n) {
	 ArrayList<Integer> al =  new ArrayList<>();
	 
	 for(int i = 1 ; i*i<=n;i++) {
		 if(n%i == 0) {
			 if(n/i == i) {
				 al.add(i);
			 }
			 else {
				 
				 al.add(i);

				 al.add((int) (n/i));
				 }
		 }
	 }
	 
	 return al;
 }
 
 
 
 
 static class Pair implements Comparable<Pair>{
	 long a;
	 int b ;
	
	 Pair(long a, int b){
		 this.a = a;
		 this.b = b;
		
		 
		 
	
	 }
	@Override
	public int compareTo(Pair o) {
		// TODO Auto-generated method stub
	 return (int)(this.a - o.a);
	}
 }
 
 
 
 
 static ArrayList<Integer> sieve(int n) {
	 boolean a[] = new boolean[n+1];
	 Arrays.fill(a, false);
	 
	 for(int i = 2 ; i*i <=n ; i++) {
		 if(!a[i]) {
			 for(int j  = 2*i ;  j<=n ; j+=i) {
				 a[j] = true;
			 }
		 }
	 }
	 
	 ArrayList<Integer> al = new ArrayList<>();
	 for(int i = 2 ; i <=n;i++) {
		 if(!a[i]) {
			 al.add(i);
		 }
	 }
	 return al;
	}
 
 static ArrayList<Long> pf(long n) {
	 ArrayList<Long> al = new ArrayList<>();
	 while(n%2 == 0) {
		 al.add(2l);
		 n = n/2;
	 }
	 
	 for(long i = 3 ; i*i<=n ; i+=2) {
		 while(n%i == 0) {
			 al.add(i);
			 n = n/i;
		 }
	 }
	 
	 if(n>2) {
		 al.add( n);
	 }
	 
	 return al;
 }
 
 
 static class FastReader {
     BufferedReader br;
     StringTokenizer st;

     public FastReader()
     {
         br = new BufferedReader(
             new InputStreamReader(System.in));
     }

     String next()
     {
         while (st == null || !st.hasMoreElements()) {
             try {
                 st = new StringTokenizer(br.readLine());
             }
             catch (IOException e) {
                 e.printStackTrace();
             }
         }
         return st.nextToken();
     }

     int nextInt() { return Integer.parseInt(next()); }

     long nextLong() { return Long.parseLong(next()); }

     double nextDouble()
     {
         return Double.parseDouble(next());
     }

     String nextLine()
     {
         String str = "";
         try {
             str = br.readLine();
         }
         catch (IOException e) {
             e.printStackTrace();
         }
         return str;
     }
 }

 
 } 