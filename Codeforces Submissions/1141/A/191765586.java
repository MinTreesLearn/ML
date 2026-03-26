import java.util.*;


public class JavaApplication14
{

    public static void main(String[] args) 
    {
      
      Scanner in = new Scanner(System.in); 
     long x =in.nextLong(),y=in.nextLong(),count = -1,res=0;
      for (int i = 1 ; i < 2 ; i++)
      {
         if(x == y)
         {
             System.out.println("0");
             break;
         }
         else if (y % x == 0)
         {
             count = 0;
             res = y/x;
             while (res % 2 ==0)
             {
                 res /= 2;
                 count++;
             }
             while (res % 3 == 0)
             {
                 res/= 3;
                 count++;
             }
             if (res != 1)
             {
                 count = -1;
             }
         }
          System.out.println(count);
      }
}
    }
						 	 		  	  	 	 			 	 		