import java.util.*;
public class Main
{
	public static void main(String[] args) {
		//System.out.println("Hello World");
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		
		for(int i=0;i<t;i++)
		{
		    int a=sc.nextInt();
		    int b=sc.nextInt();
		    if(a==b)
		    {
		        System.out.println("0");
		    }
		    else if(a>b)
		    {
		        if((a-b)%2==0)
		        System.out.println("1");
		        else
		        System.out.println("2");
		    }
		    else
		    {
		        if((b-a)%2!=0)
		        System.out.println("1");
		        else
		        System.out.println("2");
		    }
		
		}
	}
}
