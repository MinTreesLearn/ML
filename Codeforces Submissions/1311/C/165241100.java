import java.util.*;
public class PerformtheCombo {
	public static void main(String args[])
	{
		int i,j,k,t,n;
		Scanner sc=new Scanner(System.in);
		t=sc.nextInt();
		while(t-->0)
		{
			n=sc.nextInt();
			k=sc.nextInt();
			int a[]=new int[n];
			
			
			String s=sc.next();
		
			int b[]=new int[k];
			
			
			for(i=0;i<k;i++)
			{
				b[i]=sc.nextInt();
				a[b[i]-1]=a[b[i]-1]+1;
				
			}
			
		
			for(i=n-2;i>=0;i--)
			{
				a[i]=a[i]+a[i+1];		
			}
			
			
			
			
			for(i=0;i<26;i++)
			{
				int ans=0;
				int count=0;
				char ch=(char)('a'+i);
				for(j=0;j<s.length();j++)
				{
					if(s.charAt(j)==ch)
					{
						count++;
						ans=ans+a[j];
					}
				}
				System.out.print((ans+count)+" ");
			}
			System.out.println("");
		}
	}
}
