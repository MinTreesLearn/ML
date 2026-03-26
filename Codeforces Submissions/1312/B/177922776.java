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
            for(int j=0;j<n;j++)
            a[j]=sc.nextInt();
            sort(a);
            for(int j=n-1;j>=0;j--)
            System.out.print(a[j]+" ");
            System.out.println();
        }
    }

    // static int gcd(int a, int b) {
	// 	return b==0?a:gcd(b, a%b);
	// }

    static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

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