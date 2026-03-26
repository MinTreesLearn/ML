import java.util.*;
public class ArrayWithOddSum {
	public static void main(String [] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0)
		{
			int n=sc.nextInt();
			int[] ar=new int[n];
			for(int i=0;i<ar.length;i++)
			{
				ar[i]=sc.nextInt();
			}
			int eve=0;
			int odd=0;
			for(int i=0;i<ar.length;i++)
			{
				if(ar[i]%2==0)
				{
					eve++;
				}
				else
				{
					odd++;
				}
			}
			if(odd%2==1)
			{
				System.out.println("YES");
				continue;
			}
			if(odd==n || odd==0)
			{
				System.out.println("NO");
				continue;
			}
			System.out.println("YES");
			}
		}

}
