import java.util.Scanner;
public class d
{
	
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		int q = sc.nextInt();
		int x = sc.nextInt();
		int cnt[]=new int[x];
		int mex=0;
		StringBuilder sb=new StringBuilder("");
		while(q-- != 0)
		{
			int val=sc.nextInt();
			cnt[val%x]++;
			while(cnt[mex%x]!=0)
			{
				cnt[mex%x]--;
				mex++;
			}
			sb.append(mex+"\n");
		}
		System.out.println(sb);
	}
}