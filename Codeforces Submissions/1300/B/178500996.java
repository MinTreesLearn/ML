import java.util.*;
public class gh{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            int n=sc.nextInt();
            int[] ar=new int[2*n];
            for(int i=0;i<2*n;i++)
            ar[i]=sc.nextInt();
            Arrays.sort(ar);
            int min=Integer.MAX_VALUE;
            for(int i=0;i<n;i++)
            {
                min=Math.min(min,ar[n]-ar[i]);
            }
            for(int i=n;i<2*n;i++)
            {
                min=Math.min(min,ar[i]-ar[n-1]);
            }
            System.out.println(min);
        }
    }
}