import java.util.*;
 
public class codeforce {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        for(int i=0;i<t;i++) {
            int n=sc.nextInt();
            int t1=n;
            int sum=0;
            int r=n/10;
            n-=r*10;
            n+=r;
            while(n>=10) {
                int r1=n/10;
                r+=r1;
                n-=r1*10;
                n+=r1;
            }
            System.out.println(t1+r);
        }
    }
}