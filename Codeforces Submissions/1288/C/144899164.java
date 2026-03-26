
import java.util.*;
public class Main{
	public static void main(String[]args) {
		final int mx = 1010;
		final int mod = 1000000007;
		long [][] dp = new long [30][mx];
		long sum = 0;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		m*=2;
		for(int i=1;i<=n;i++)//初始化
			dp[1][i]=1;
		for(int i=2;i<=m;i++)//长度 
		{
			for(int j=1;j<=n;j++)//结尾 
			{
				for(int k=1;k<=j;k++)
				dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
			}
		}
		for(int i = 1 ; i<=n ; i++)
			sum = (sum + dp[m][i])%mod;
		System.out.println(sum);
			
	}
	
}

  	 			 					 			 	  	 		  	 	