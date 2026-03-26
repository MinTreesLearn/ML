import java.util.*;
public class cf17 {
public static void main(String arg[])
{
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	int m=sc.nextInt();
	
	int result = -1;
	if (m % n == 0) {
	    result = 0;
	    int d = m / n;
	    while (d % 2 == 0)
	    	
	    {
	        d /= 2; result++;
	    }
	    while (d % 3 == 0) {
	        d /= 3; result++;
	        }
	    if (d != 1)
	        result = -1;
	}
	System.out.println(result);
}
}
 