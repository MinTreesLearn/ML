import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int tcs=s.nextInt();
        for(int j=0;j<tcs;j++){
            int a[]=new int[3];
            for(int i=0;i<3;i++) a[i]=s.nextInt();
            int coins=s.nextInt();
            Arrays.sort(a);
            int sum=a[2]-a[1]+a[2]-a[0];
            if(coins<sum) System.out.println("NO");
            else{
                coins=coins-sum;
                if(coins%3==0) System.out.println("YES");
                else System.out.println("NO");
            }
           
        }
    }
}