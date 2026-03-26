import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.*;


 
 
 
 
public class b {
 

	public static void main(String []args) {
		MyScanner s=new MyScanner();
		
	int n=s.nextInt();
		long a=s.nextLong();
		long b=s.nextLong();
		long k=s.nextLong();
		long []f=new long [n];
		for(int i=0;i<n;i++)
			f[i]=s.nextLong();
		long []t=new long [n];
		for(int i=0;i<n;i++) {
			if(f[i]<=a)
			{
				t[i]=0;
				
			}
			else if(f[i]>a) {
				 long c=f[i]%(a+b);
				 if(c==0) {
					 long e=b/a;
					 if(b%a!=0)
						 e++;
					 t[i]=e;
				 }
				 else {
					 long d=c/a;
					 if(c%a!=0)
						 d++;
					 if(d>1)
					 t[i]=d-1;
					 else t[i]=0; 
				 }
			 }
			
		}
		Arrays.sort(t);
		int res=0;
		for(long x:t) {
			if(k-x>=0) {
				res++;
				k=k-x;
			}
			// System.out.println(x);
		}
			
			 System.out.println(res);
					
	}
			
	
				
				
			
		
			
			
				
			
		
		
				
	
			
	public static  boolean is(String s) {
		int l=0;
		int r=s.length()-1;
		while(l<r) {
			if(s.charAt(l)!=s.charAt(r))
				return false;
			l++;r--;
		}
		return true;
	}
	public static void  shufu(int []f) {
		for(int i=0;i<f.length;i++) {
			int t=(int)Math.random()*f.length;
			int k=f[t];
			f[t]=f[i];
			f[i]=k;
		}
		
	}
			
	
 
	static class MyScanner {
	    BufferedReader br;
	    StringTokenizer st;
	 
	    public MyScanner() {
	      try {
	        final String USERDIR = System.getProperty("user.dir");
	        String cname = MethodHandles.lookup().lookupClass().getCanonicalName().replace(".MyScanner", "");
	        cname = cname.lastIndexOf('.') > 0 ? cname.substring(cname.lastIndexOf('.') + 1) : cname;
	        final File fin = new File(USERDIR + "/io/c" + cname.substring(1,5) + "/" + cname + ".in");
	        br = new BufferedReader(new InputStreamReader(fin.exists()
	            ? new FileInputStream(fin) : System.in));
	      } catch (Exception e) {
	        br = new BufferedReader(new InputStreamReader(System.in));
	      }
	    }
	 
	    public String next() {
	      try {
	        while (st == null || !st.hasMoreElements()) {
	          st = new StringTokenizer(br.readLine());
	        }
	        return st.nextToken();
	      } catch (Exception e) {
	        throw new RuntimeException(e);
	      }
	    }
	 
	    public int nextInt() {
	      return Integer.parseInt(next());
	    }
	 
	    public long nextLong() {
	      return Long.parseLong(next());
	    }
	  }
	
		}