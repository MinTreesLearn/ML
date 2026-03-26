import java.util.*;
public class Main
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        double c=0.0000000;
        for(float i=n;i>0;i--)
        {
            c+=(1/i);
        }
        System.out.println(c);
    }
}