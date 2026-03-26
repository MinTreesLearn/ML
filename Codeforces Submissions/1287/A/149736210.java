import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		
		Scanner s=new Scanner(System.in);
		
		int t=s.nextInt();
		
		while(t-->0) {
			int n=s.nextInt();
			
			String str=s.next();
			
			int count=0;
			
			while(str.contains("AP")) {
				str=str.replaceAll("AP","AA");
				count++;
			}
			System.out.println(count);
		}
	}
 
}
	  			 	  	  	 	  	 			  				 	