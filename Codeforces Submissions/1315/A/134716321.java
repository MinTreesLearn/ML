import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main{
    public static void solve(BufferedReader sc) throws Exception {
        StringTokenizer tx = new StringTokenizer(sc.readLine());
        int n = Integer.parseInt(tx.nextToken());
        int m = Integer.parseInt(tx.nextToken());
        int x = Integer.parseInt(tx.nextToken());
        int y = Integer.parseInt(tx.nextToken());
        int ans = 0;
        // 
        //     xy
        //
        x++;y++;
        ans = Math.max(ans, (x-1)*m);
       // System.out.println(ans);
        ans = Math.max(ans, (y-1)*n);
       // System.out.println(ans);
        ans = Math.max(ans, (n-x)*m);
       // System.out.println(ans);
        ans = Math.max(ans, (m-y)*n);
        System.out.println(ans);
    }    
    public static void main(String[] args) throws Exception{
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        int tc = 1;
        StringTokenizer tx = new StringTokenizer(sc.readLine()); tc = Integer.parseInt(tx.nextToken());
        for(int i = 0; i < tc; i++){
            solve(sc);
        }
    }
}
		     	  		 	   	 		 	 	 		 	