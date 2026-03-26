import java.util.Scanner;

public class Main {
  
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    int test_case = in.nextInt();
    int n,m;

    while(test_case!=0)
    {

       n= in.nextInt();
       m = in.nextInt();

      int[] num = new int[n];
      int sum = 0;

      for (int i = 0; i <n; i++) {
        
        num[i] = in.nextInt();
        sum += num[i];
      }

      if(sum > m){

        System.out.println(m);
      }else{
        System.out.println(sum);
      }
    
      

     
      test_case--;
    }

    in.close();
  }
}

					 	 		 				 		 									 	