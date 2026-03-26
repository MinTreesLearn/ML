import java.util.*;
public class OneRemove {
	public static void main(String [] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0)
		{
			String s=sc.next();
			int one=0;
			int zero=0;
			int tone=0;
			int temp=0;
			for(int i=0;i<s.length();i++)
			{
				if(s.charAt(i)-'0'==1)
				{
					tone++;
				}
			}
			for(int i=0;i<s.length();i++)
			{
				if(s.charAt(i)-'0'==1)
				{
					one++;
					temp++;
				}
				if(temp==tone)
				{
					break;
				}
				if(one>0 && s.charAt(i)-'0'==0)
				{
					zero++;
				}
			}
			System.out.println(zero);
		}
		
	}

}
