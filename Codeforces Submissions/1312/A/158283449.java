import java.util.Scanner;
public class Main 
{
    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        int j=s.nextInt();
        for(int k=0;k<j;k++)
        {
        int[] a=new int[2];
        for(int i=0;i<a.length;i++)
        {
            a[i]=s.nextInt();
        }
        if((a[0]%a[1])==0)
        {
            System.out.println("YES");
        }
        else
        {
            System.out.println("NO");
        }
    }
    }
}