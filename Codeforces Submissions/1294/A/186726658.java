import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int tcs=s.nextInt();
        while(tcs!=0){
            int a[]=new int[3];
            for(int i=0;i<3;i++) a[i]=s.nextInt();
            int coins=s.nextInt();
            Arrays.sort(a);
            int dif=2*a[2]-a[1]-a[0];
            if(coins<dif) System.out.println("NO");
            else{
                coins=coins-dif;
                if(coins%3==0) System.out.println("YES");
                else System.out.println("NO");
            }
            tcs--;
        }
    }
}