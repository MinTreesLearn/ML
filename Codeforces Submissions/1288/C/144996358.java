
import java.util.Scanner;

public class Main{
    static long mod=(long)(Math.pow(10,9)+7);
    public static void main(String[] args){
        Scanner in= new Scanner(System.in);
        while(in.hasNext()){
            int n=in.nextInt();
            int m=in.nextInt();
            long[][] a=new long[2*m+1][n+1];
            for(int i=1;i<=n;i++) a[1][i] = 1;
            for(int i=2;i<=2*m;i++){
                for(int j=1;j<=n;j++){
                    long s = 0;
                    for(int k=1;k<=j;k++){
                        s=(s+a[i-1][k])%mod;
                    }
                    a[i][j] = s;
                }
            }
            long ans = 0;
            for(int i=1;i<=n;i++){
                ans = (ans+a[2*m][i])%mod;
            }
            System.out.println(ans);
        }
    }
}

  		 	 	 	  	 			 	  		  		 	