import java.util.*;
import java.lang.*;
import java.io.*;
public class Main
{
    static final PrintWriter out =new PrintWriter(System.out);
    static final FastReader sc = new FastReader();
    /*
                       _oo0oo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      0\  =  /0
                    ___/`---'\___
                  .' \\|     |// '.
                 / \\|||  :  |||// \
                / _||||| -:- |||||- \
               |   | \\\  -  /// |   |
               | \_|  ''\---/''  |_/ |
               \  .-\__  '-'  ___/-. /
             ___'. .'  /--.--\  `. .'___
          ."" '<  `.___\_<|>_/___.' >' "".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `_.   \_ __\ /__ _/   .-` /  /
     =====`-.____`.___ \_____/___.-`___.-'=====
                       `=---='
 
    */
     static class Pair{
          int f,l;
          public Pair(int first,int last)
          {
                this.f=first;
                this.l=last;
          }
    }
    public static boolean sorted(int a[])
    {
        int n=a.length,i;
        int b[]=new int[n];
        for(i=0;i<n;i++)
        b[i]=a[i];
        Arrays.sort(b);
        for(i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            return false;
        }
        return true;
    }
	public static void main (String[] args) throws java.lang.Exception
	{
	      int tes=1;
	    while(tes-->0)
	    {
	         int n=sc.nextInt();
	         int a[]=new int[n];
HashMap<Integer,Long> map=new HashMap<>();
	         int i,j; long ans=0;
	         for(i=0;i<n;i++)
	         a[i]=sc.nextInt();
	         for(i=0;i<n;i++)
	               map.put(a[i]-i,map.getOrDefault(a[i]-i,0L)+(long)a[i]);
	         for(Integer it:map.keySet())
	         ans=Math.max(map.get(it),ans);
	         System.out.println(ans);
	    }
	}
	public static int first(ArrayList<Integer> arr, int low, int high, int x, int n)
    {
        if (high >= low) {
            int mid = low + (high - low) / 2;
            if ((mid == 0 || x > arr.get(mid-1)) && arr.get(mid) == x)
                return mid;
            else if (x > arr.get(mid))
                return first(arr, (mid + 1), high, x, n);
            else
                return first(arr, low, (mid - 1), x, n);
        }
        return -1;
    }
	public static int last(ArrayList<Integer> arr, int low, int high, int x, int n)
    {
        if (high >= low) {
            int mid = low + (high - low) / 2;
            if ((mid == n - 1 || x < arr.get(mid+1)) && arr.get(mid) == x)
                return mid;
            else if (x < arr.get(mid))
                return last(arr, low, (mid - 1), x, n);
            else
                return last(arr, (mid + 1), high, x, n);
        }
        return -1;
    }
	public static int lis(int[] arr) {
	int n = arr.length;
	ArrayList<Integer> al = new ArrayList<Integer>();
	al.add(arr[0]);
	for(int i = 1 ; i<n;i++) {
		int x = al.get(al.size()-1);
		if(arr[i]>=x) {
			al.add(arr[i]);
		}else {
			int v = upper_bound(al, 0, al.size(), arr[i]);
			al.set(v, arr[i]);
		}
	}
	return al.size();
}
 
	public static int lower_bound(ArrayList<Long> ar,int lo , int hi , long k)
{
    Collections.sort(ar);
    int s=lo;
    int e=hi;
    while (s !=e)
    {
        int mid = s+e>>1;
        if (ar.get((int)mid) <k)
        {
            s=mid+1;
        }
        else
        {
            e=mid;
        }
    }
    if(s==ar.size())
    {
        return -1;
    }
    return s;
}	
	
public static int upper_bound(ArrayList<Integer> ar,int lo , int hi, int k)
{
    Collections.sort(ar);
    int s=lo;
    int e=hi;
    while (s !=e)
    {
        int mid = s+e>>1;
        if (ar.get(mid) <=k)
        {
            s=mid+1;
        }
        else
        {
            e=mid;
        }
    }
    if(s==ar.size())
    {
        return -1;
    }
    return s;
}
static boolean isPrime(long N)
    {
        if (N<=1)  return false; 
        if (N<=3)  return true; 
        if (N%2 == 0 || N%3 == 0) return false; 
        for (int i=5; i*i<=N; i=i+6) 
            if (N%i == 0 || N%(i+2) == 0) 
                return false; 
        return true; 
    }
    static int countBits(long a)
    {
        return (int)(Math.log(a)/Math.log(2)+1);
    }
 
    static long fact(long N)
    { 
        long mod=1000000007;
        long n=2; 
        if(N<=1)return 1;
        else
        {
            for(int i=3; i<=N; i++)n=(n*i)%mod;
        }
        return n;
    }
    private static boolean isInteger(String s) {
        try {
            Integer.parseInt(s);
        } catch (NumberFormatException e) {
            return false;
        } catch (NullPointerException e) {
            return false;
        }
        return true;
    }
    private static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    private static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }
    private static boolean isPalindrome(String str) {
        int i = 0, j = str.length() - 1;
        while (i < j)
            if (str.charAt(i++) != str.charAt(j--))
                return false;
        return true;
    }
 
    private static String reverseString(String str) {
        StringBuilder sb = new StringBuilder(str);
        return sb.reverse().toString();
    } 
	static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}