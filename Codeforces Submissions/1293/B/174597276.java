import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
// 		int t=sc.nextInt();
// 		while(t>0){
// 		    t--;
		   int n=sc.nextInt();
		   double sum=0;
		   while(n>0){
		       sum+=(double)(1/(double)n);
		       n--;
		   }
		   System.out.println(sum);
		   
// 		}
   }
}
