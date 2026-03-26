import java.util.*;
public class Solution{
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        int t=in.nextInt();
        for(int c=0;c<t;c++)
        {
            int n=in.nextInt();
            int m=in.nextInt();
            int[] arr = new int[n];
            int sum=0;
            for(int i=0;i<n;i++)
            {
                arr[i]=in.nextInt();
                sum=sum+arr[i];
            }
            if(sum>m)
                System.out.println(m);
            else
                System.out.println(sum);
        }
    }
}