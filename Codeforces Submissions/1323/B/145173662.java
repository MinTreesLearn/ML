import java.io.BufferedReader;
import java.io.InputStreamReader;
public class cdf626b
{
	static long check(int arr[],long n)
	{
		long cou1=0,tot1=0;//,tot2=0,cou2=0;
		if(n>arr.length)
			return 0;
		for(int i=0;i<arr.length;i++)
		{
			if(arr[i]!=0)
				cou1++;
			if(cou1==n)
			{
				tot1++;
				cou1--;
			}
			if(arr[i]==0)
				cou1=0;
		}
		return tot1;
	}
	public static void main(String args[])throws Exception
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s=br.readLine();
		String ss[]=s.split(" ");
		int n=Integer.parseInt(ss[0]);
		int m=Integer.parseInt(ss[1]);
		int k=Integer.parseInt(ss[2]);
		s=br.readLine();
		String str[]=s.split(" ");
		int arr[]=new int[n];
		long o1=0,o2=0;
		for(int j=0;j<n;j++)
		{
			arr[j]=Integer.parseInt(str[j]);
			if(arr[j]==1)
				o1++;
		}
		s=br.readLine();
		String ss1[]=s.split(" ");
		int arr1[]=new int[m];
		for(int j=0;j<m;j++)
		{
			arr1[j]=Integer.parseInt(ss1[j]);
			if(arr1[j]==1)
				o2++;
		}
		long copy=k,tempo=1;
		long ans=0;
		if(k==1)
		{
			ans=o1*o2;
			System.out.print(ans);
			return;
		}
		for(int i=1;i<=(int)Math.sqrt(k);i++)
		{
			if(k%i!=0)
			continue;
			if(i*i==k)
			{
				ans=ans+check(arr,i)*check(arr1,k/i);
				break;
			}
			ans=ans+check(arr,i)*check(arr1,k/i)+check(arr,k/i)*check(arr1,i);
		}
		System.out.println(ans);		
	}
}
