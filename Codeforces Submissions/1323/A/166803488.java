import java.util.*;
public class aa
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        outer : while(t-->0)
        {
            int n = sc.nextInt();
            int a[] = new int[n];
            boolean flag = false;
            for(int i = 0; i<n; i++)
            {
                a[i] = sc.nextInt();

            }
            for(int i = 0; i<n; i++)
            {
                if(a[i]%2==0)
                {
                    System.out.println("1\n" + (i+1));
                    continue outer;
                }
            }
            if(n>1)System.out.println("2\n1 2");
            else System.out.println(-1);
        }
    }
}