
import java.util.*;
import java.util.Scanner;

public class Main {

    static int mod=1000000007;

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        int n = scn.nextInt();

        for(int i=0;i<n;i++)
        {
            int num=scn.nextInt();

            answer(num);
        }
    }

    public static void answer(int n)
    {
        int a;
        int b;
        int c=0;

        for(a=2;a*a*a<=n;a++)
        {
            if(n%a==0)
            {
                break;
            }
        }

        int rem=n/a;

        for( b=a+1;b*b<=rem;b++)
        {
            if(rem%b==0)
            {
                c=rem/b;
                if(b>=c)
                {
                    c=0;
                }
                break;
            }
        }

        if(a*b*c==n)
        {
            System.out.println("YES");
            System.out.println(a+" "+b+" "+c);
            return;
        }

        System.out.println("NO");





    }


}