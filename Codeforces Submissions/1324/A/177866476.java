import java.util.*;
import java.io.*;
public class Main
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out=new PrintWriter(System.out);
		Scanner sc=new Scanner(System.in);
        // String testcases[]=br.readLine().split(" ");
        // int t=Integer.parseInt(testcases[0]);
        int t=sc.nextInt();
        for(int i=0;i<t;i++)
        {
            int n=sc.nextInt();
            int a[]=new int[n];
            int max=0;
            for(int j=0;j<n;j++)
            {
                a[j]=sc.nextInt();
                if(a[j]>=max)
                max=a[j];
            }
            int f=0;
            for(int j=0;j<n;j++)
            {
                if((max-a[j])%2!=0)
                f=1;
            }
            System.out.println(f==0?"YES":"NO");
        }
    }
    // static int __gcd(int a, int b)
    // {
    //     // Everything divides 0
    //     if (a == 0 || b == 0)
    //         return 0;
         
    //     // base case
    //     if (a == b)
    //         return a;
         
    //     // a is greater
    //     if (a > b)
    //         return __gcd(a-b, b);
                 
    //     return __gcd(a, b-a);
    // }

    // static boolean coprime(int a, int b) {
    //     if(a==1||b==1)
    //     return true;
    //     if ( __gcd(a, b) == 1)
    //         return true;
    //     else
    //         return false;   
    // }

    // private static boolean checkSquare(long n)
    // {
    //     if (Math.ceil((double)Math.sqrt(n)) ==
    //     Math.floor((double)Math.sqrt(n)))
    //     return true;
    //     else
    //     return false;
    // }

    // private static long floorSqrt(long x)
    // {
    //     if (x == 0 || x == 1)
    //         return x;
    //     long start = 1, end = x / 2, ans = 0;
    //     while (start <= end) {
    //         long mid = (start + end) / 2;
 
    //         if (mid * mid == x)
    //             return (int)mid;
 
    //         if (mid * mid < x) {
    //             start = mid + 1;
    //             ans = mid;
    //         }
    //         else 
    //             end = mid - 1;
    //     }
    //     return (long)ans;
    // }

}