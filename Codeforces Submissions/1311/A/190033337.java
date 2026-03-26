import java.util.*;
public class Oddeven {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for(int i=0;i<n;i++)
        {
            int a = in.nextInt();
            int b = in.nextInt();
            if(a==b)
                System.out.println(0);
            else if (a-b>0&&(a-b)%2==0)
                System.out.println(1);
            else if(a-b<0&&(a-b)%2!=0)
                System.out.println(1);
            else
                System.out.println(2);
        }

    }
}
