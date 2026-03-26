import java.util.Scanner;

public class Main {

	
	static 	 Scanner input = new Scanner(System.in);

	public static void main(String[]args) {
		
		
	
      
      
 
      method( );
	 
	}
	
	
	
	public static void method (  ) {
		

		int group = input.nextInt();
		
		while(group!=0) {
			
		      int num = input.nextInt();
		      StringBuilder str = new StringBuilder(input.next());

				int count =0;


			 int numOuter = num;
		  while(numOuter !=0)  {
			  
          int  round = 0;
		for(int i = 0 ; i < str.length()-1; i++) {
							
				if(str.charAt(i)=='A' && str.charAt(i+1)=='P') {
					round++;
				   str.deleteCharAt(i+1);
				  }
				

			
					}
		
		
		if( round!=0 ) {
			count++;
		   }
		
		
	
		
		numOuter--;

		
		  }
			System.out.println(count);

		
		
			group--;
			
		}

	
	}
	

}

	 		 					      			 	   	 	  	