import java.util.Scanner;
 
public class Lesson7ProductOf3Numbers {
	public static  boolean isPrime(int num)
    {
        if(num<=1)
        {
            return false;
        }
       for(int i=2;i<=num/2;i++)
       {
           if((num%i)==0)
               return  false;
       }
       return true;
    }
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int TestCases = sc.nextInt();
		while(TestCases -- > 0) {
			int num =  sc.nextInt();
			int a = 0; 
			int b = 0;
			int c = 0; 
			for(int i = 2; i * i < num; i++) {
				if(num%i == 0) {
					 num /= i;
					 if(a == 0) {
						 a = i;
					 }else {
						 b = i;
						 break;
					 }
				 }else {
					 
				 }
			 }
			 
			 if(a!=0 && b!=0 && num>b) {
				 System.out.println("YES");
				 System.out.println(a+" "+b+" "+num+" ");
			}else{
				System.out.println("NO");
			}
		 }
	}
}