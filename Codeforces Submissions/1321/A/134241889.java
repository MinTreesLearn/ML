
import java.util.*;

public class Solution {

    public static void main(String... args) throws Exception {
        Scanner scan = new Scanner(System.in);
        // int t = scan.nextInt();
        int t=1;
        while (t-- > 0) {
            solve(scan);
        }
        scan.close();
    }

    public static void solve(Scanner scan) {
        int n=scan.nextInt();
        int a[]=new int[n];
        int b[]=new int[n];
        for(int i=0;i<n;i++)
            a[i]=scan.nextInt();
        for(int i=0;i<n;i++)
            b[i]=scan.nextInt();
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(a[i]==1 && b[i]==0)
                x++;
            else if(b[i]==1 && a[i]==0)
                y++;
        }
        if(x==0){
            System.out.println("-1");
        }
        else{
            int ans=(y)/x+1;
            System.out.println(ans);
        }


        
    }

}
