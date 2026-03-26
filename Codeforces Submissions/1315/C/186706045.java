import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String args[]) throws IOException
    {
        // BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		Scanner sc=new Scanner(System.in);
        // String testcases[]=br.readLine().split(" ");
        // int t=Integer.parseInt(testcases[0]);
        PrintWriter pw=new PrintWriter(System.out);
        int t=sc.nextInt();
        for(int i=0;i<t;i++)
        {
            int n=sc.nextInt();
            int a[]=new int[n];
            for(int j=0;j<n;j++)
            a[j]=sc.nextInt();
            int b[]=new int[2*n];
            int taken[]=new int[2*n];
            Arrays.fill(taken,0);
            int f=0;
            inner :
            for(int j=0;j<n;j++)
            {
                if(a[j]>2*n||taken[a[j]-1]==1)
                {
                    f=1;
                    break inner;
                }
                else
                taken[a[j]-1]=1;
            }
            if(f==1)
            {
                pw.write("-1\n");
                continue;
            }
            int index=0;
            outer :
            for(int j=0;j<n;j++)
            {
                b[index++]=a[j];
                int found=0;
                inner :
                for(int k=a[j];k<2*n;k++)
                {
                    if(taken[k]==0)
                    {
                        found=1;
                        taken[k]=1;
                        b[index++]=k+1;
                        break inner;
                    }
                }
                if(found==0)
                {
                    f=1;
                    break outer;
                }
            }
            if(f==1)
            {
                pw.write("-1\n");
                continue;
            }
            for(int j=0;j<2*n;j++)
            pw.write(b[j]+" ");
            pw.write("\n");
        }
        pw.flush();
        pw.close();
    }

    // static int[][] getBitMap(int[] a)
    // {
    //     int n=a.length;
    //     int[][] bit_map=new int[n][32];
    //     for(int j=0;j<n;j++)
    //     Arrays.fill(bit_map[j],0);
    //     for(int j=0;j<n;j++)
    //     {
    //         int counter=0;
    //         while(a[j]!=0)
    //         {
    //             bit_map[j][counter]=a[j]%2;
    //             a[j]/=2;
    //             counter++;
    //         }
    //     }
    //     return bit_map;
    // }

    // static ArrayList<Integer> sieveOfEratosthenes(int n)
    // {
    //     boolean prime[]=new boolean[n+1];
    //     for(int j=0;j<=n;j++)
    //     prime[j]=true;
    //     for(long p=2;p*p<=n;p++)
    //     {
    //         if(prime[(int)p]==true)
    //         {
    //             for(long j=p*p;j<=n;j+=p)
    //             prime[(int)j]=false;
    //         }
    //     }
    //     ArrayList<Integer> al=new ArrayList<>();
    //     for(int j=2;j<=n;j++)
    //     {
    //         if(prime[j]==true)
    //         al.add(j);
    //     }
    //     return al;
    // }

    // static boolean sortedIncreasing(long[] a)
    // {
    //     int f=0;
    //     for(int j=1;j<a.length;j++)
    //     {
    //         if(a[j]<a[j-1])
    //         f=1;
    //     }
    //     return f==0?true:false;
    // }

    // static boolean sortedDecreasing(long[] a)
    // {
    //     int f=0;
    //     for(int j=1;j<a.length;j++)
    //     {
    //         if(a[j]>a[j-1])
    //         f=1;
    //     }
    //     return f==0?true:false;
    // }

    // static ArrayList<Long> getFactors(long n)
    // {
    //     ArrayList<Long> al=new ArrayList<>();
    //     for(long i=1;i<=Math.sqrt(n);i++)
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

    static void sort(long[] a)
    {
		ArrayList<Long> l=new ArrayList<>();
		for (long i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
    }

    // static int gcd(int a, int b)
    // {
	// 	return b==0?a:gcd(b,a%b);
	// }

    // static int lcm(int a, int b)
    // {
    //     return ((a/gcd(a,b))*b);
    // }

    // static boolean checkCoprime(int a, int b)
    // {
    //     if(a==1||b==1)
    //     return true;
    //     if (gcd(a,b)==1)
    //         return true;
    //     else
    //         return false;   
    // }

    // static boolean checkSquare(long n)
    // {
    //     if (Math.ceil((double)Math.sqrt(n)) ==
    //     Math.floor((double)Math.sqrt(n)))
    //     return true;
    //     else
    //     return false;
    // }

    // static long floorSqrt(long x)
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

// class Pair
// {
//     int h=0;
//     int p=0;
//     Pair(int x, int y)
//     {
//         h=x;
//         p=y;
//     }
// }

// class NewComparator implements Comparator<Pair>
// {
//     public int compare(Pair p1, Pair p2)
//     {
//         if (p1.p < p2.p)
//         return 1;
//         else if (p1.p > p2.p)
//         return -1;
//         return 0;
//     }
// }
