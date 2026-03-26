import java.util.*; 
public class array {
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t-->0)
		{
			int n = in.nextInt();
			Integer[] a = new Integer[n];
			for(int i = 0 ; i< n ; i++) a[i] = in.nextInt();
			Arrays.sort(a, Collections.reverseOrder());
			 
	           for(int i:a)
	           System.out.print(i+" ");
	           
	           System.out.println();
		}
		
		in.close();
		
	}
	
}

			  		 	 		 		  			   	 	 	  	