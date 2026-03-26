import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while(t!=0)
        {
            int x=sc.nextInt();
            int a=1;
            int b=x-1;
            int lcm=0;
            int gcd=1;
            int p=0;
            while(true)
            {
                for(int i=1;i<=a&&i<=b;i++)
                {
                    if(a%i==0 && b%i==0)
                    {
                        gcd=i;
                    }
                }
                lcm=(a*b)/gcd;
                if(lcm+gcd==x)
                {
                    //p=1;
                    break;
                }
                a++;
                b--;
            }
                System.out.println(a+" "+b);
            t--;
        }
    }
}