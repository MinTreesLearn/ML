import java.util.*;
import java.lang.Math;

public class Main
{

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0)
        {
            int n = sc.nextInt();
            String str = sc.next();
            int a,count=0, ansp1=0;
            for(int i=0; i<str.length(); i++)
            {
                a = str.charAt(i) - '0';
                if(a%2!=0)
                {
                    ansp1 = 10*ansp1 + a;
                    count++;
                }
                if(count>=2)
                    break;
            }
            if(count<2)
                System.out.println(-1);
            else
                System.out.println(ansp1);
        }
    }




}
