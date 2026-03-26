import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long mod= (long) (1e9+7);
        int n=sc.nextInt();
        int m=sc.nextInt();
        long[][] dp=new long[n+1][2*m+1];
        for(int i=1;i<=2*m;i++){
           dp[1][i]=1;
        }
        for(int i=1;i<=n;i++){
            dp[i][1]=i;
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=2*m;j++){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
        System.out.println(dp[n][2*m]);
        // write your code here
    }
}
    	 		  	  		  	 	 		 	  		