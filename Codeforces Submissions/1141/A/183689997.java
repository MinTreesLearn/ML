import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String args[]) throws IOException
    {
        // BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		// PrintWriter out=new PrintWriter(System.out);
		Scanner sc=new Scanner(System.in);
        // String testcases[]=br.readLine().split(" ");
        // int t=Integer.parseInt(testcases[0]);
        int n=sc.nextInt();
        int m=sc.nextInt();
        if(m%n==0)
        {
            if(m==n)
            System.out.println("0");
            else
            {
                int req=m/n;
                int two=0;
                while(req%2==0)
                {
                    two++;
                    req/=2;
                }
                int three=0;
                while(req%3==0)
                {
                    three++;
                    req/=3;
                }
                if(req!=1)
                System.out.println("-1");
                else
                System.out.println(two+three);
            }
        }
        else
        System.out.println("-1");
    }

    // static ArrayList<Integer> getFactors(int n)
    // {
    //     ArrayList<Integer> al=new ArrayList<>();
    //     for(int i=1;i<=Math.sqrt(n);i++)
    //     {
    //         if(n%i==0)
    //         {
    //             al.add(i);
    //             if(n/i!=i)
    //             al.add(n/i);
    //         }
    //     }
    //     return al;
    // }

    //  static void sort(long[] a) {
	// 	ArrayList<Long> l=new ArrayList<>();
	// 	for (long i:a) l.add(i);
	// 	Collections.sort(l);
	// 	for (int i=0; i<a.length; i++) a[i]=l.get(i);
	// }

    // static int gcd(int a, int b) {
	// 	return b==0?a:gcd(b, a%b);
	// }

    // static int lcm(int a, int b){
    //     return ((a/gcd(a,b))*b);
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

// class Pair{
//     int a=0;
//     int b=0;
//     Pair(int x, int y)
//     {
//         this.a=x;
//         this.b=y;
//     }
// }