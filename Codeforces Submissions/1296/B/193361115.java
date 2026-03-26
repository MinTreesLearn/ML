import java.util.*;
// 19 --> 21
public class foodbuy{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            long fcount = sc.nextLong();
            long ans= 0;
            while(1>0){
                long x = (fcount/10) * 10;
                ans +=x;
                long y = fcount-x;
                fcount = (fcount/10) + y; 
                if( fcount< 10){
                    ans+=fcount;
                    break;
                }
            }
            System.out.println(ans);
        }

    }
}


