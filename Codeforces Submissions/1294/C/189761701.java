import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0)
        {
            long n = sc.nextLong();
            long a=1,b=1,c;
            long rootN = (long)Math.sqrt(n);
            for(long i=2; i<=rootN; i++)
            {
                if(n%i==0)
                {
                    a = i;
                    break;
                }
            }
            if(a==1 || n==1)
            {
                System.out.println("NO");
                continue;
            }
            long temp = n/a;
            rootN = (long)Math.sqrt(temp);
            for(long i=a+1; i<=rootN; i++)
            {
                if(temp%i==0)
                {
                    b = i;
                    break;
                }
            }
            if(b==a || b==1)
            {
                System.out.println("NO");
                continue;
            }
            c = n/(b*a);
            if(c!=1 && c!=a && c!=b)
            {
                System.out.println("YES");
                System.out.println(a + " " + b + " " + c);
            }
            else
                System.out.println("NO");
        }
    }
}

