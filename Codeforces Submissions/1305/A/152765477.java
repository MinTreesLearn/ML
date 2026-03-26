
import java.util.*;

public class cC {

	public static void main(String[] args) {

		
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0) {
			
			int n = sc.nextInt();
			int neck[] = new int[n];
			for(int i=0;i<n;i++) neck[i] = sc.nextInt();
			int brac[] = new int[n];
			for(int i=0;i<n;i++) brac[i] = sc.nextInt();
			
			Arrays.sort(neck);
			Arrays.sort(brac);
			for(int i=0;i<n;i++)System.out.print(neck[i]+" ");
			System.out.println();
			for(int i=0;i<n;i++)System.out.print(brac[i]+" ");
			System.out.println();
	
			
			
		}
				
	
		
	}
	


	

	

	

}
