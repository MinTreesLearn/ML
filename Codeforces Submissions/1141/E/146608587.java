import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codechef
{
   static void shuffleSort(int[] a) {
        int n=a.length;
        Random r=new Random();
        for (int i=0; i<a.length; i++) {
            int oi=r.nextInt(n), temp=a[i];
            a[i]=a[oi];
            a[oi]=temp;
        }
        Arrays.sort(a);
   }
   
   public static void main (String[] args) throws java.lang.Exception
	{
	  BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	  StringTokenizer st=new StringTokenizer(br.readLine());
	  long H=Long.parseLong(st.nextToken());
	  int n=Integer.parseInt(st.nextToken());
	  int a[]=new int[n];
	  st=new StringTokenizer(br.readLine());
	  long prefix[]=new long[n];
	  long sum=0;
	  long min=Long.MAX_VALUE;
	  for(int i=0;i<n;i++){
	     a[i]=Integer.parseInt(st.nextToken());
	     sum+=a[i];
	     prefix[i]=sum;
	     min=Math.min(min,prefix[i]);
	  }
	  if(prefix[n-1]>=0){
	     if(H+min>0){
	        System.out.print(-1);
	     }
	     else{
	        for(int i=0;i<n;i++){
	           if(prefix[i]+H<=0){
	              System.out.print((i+1));
	              break;
	           }
	        }
	     }
	  }
	  else{
	     if(H+min<=0){
	        for(int i=0;i<n;i++){
	           if(prefix[i]+H<=0){
	              System.out.print((i+1));
	              break;
	           }
	        }
	     }
	     else{
	        long k=(long)Math.ceil((H+min)/(double)Math.abs(prefix[n-1]));
	        H=H+k*prefix[n-1];
	        long time=k*n;
	        for(int i=0;i<n;i++){
	           if(prefix[i]+H<=0){
	              time=time+i+1;
	              break;
	           }
	        }
	        System.out.print(time);
	     }
	  }
	  
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
}
