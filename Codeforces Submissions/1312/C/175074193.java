//package Educational_Codeforces_Round_83;
import java.util.Scanner;
public class Main//C_Adding_Powers 
{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		int T=input.nextInt();
		for(int t=1;t<=T;t++)
		{
			int n=input.nextInt();
			int k=input.nextInt();
			long[] a=new long[35];
			for(int i=1;i<=n;i++)
				a[i]=input.nextLong();
			long[] pos=new long[105];
			boolean flag=true;
			for(long e:a)
			{
				int cnt=0;
				while(e!=0)
				{
					pos[cnt]+=e%k;
					if(pos[cnt]>1)
					{
						flag=false;
						break;
					}
					e/=k;
					cnt++;
				}
				if(!flag)	break;
			}
			if(flag==true)	System.out.println("YES");
			else			System.out.println("NO");
		}
		
		input.close();
	}
}
