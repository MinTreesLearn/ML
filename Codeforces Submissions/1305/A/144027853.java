import java.util.*;
import java.io.*;
public class solution  {
    static FastReader in=new FastReader();
    static final Random random=new Random();
    static long mod=1000000007L;
    static HashMap<String,Integer>map=new HashMap<>();
 
    public static void main(String args[]) throws IOException {
       int t=in.nextInt();
       while(t-->0){
       	 int n=in.nextInt();
       	 int[] xi=new int[n];
       	 int[] yi=new int[n];

       	 for(int i=0;i<n;i++) xi[i]=in.nextInt();
         for(int i=0;i<n;i++) yi[i]=in.nextInt();

         Arrays.sort(xi);
         Arrays.sort(yi);

         for(int i:xi) System.out.print(i+" ");
         System.out.println();
         for(int i:yi) System.out.print(i+" ");
         System.out.println();
       }

    }
    static boolean containsSubsequence(String s,String a){
    	int i=0,j=0;
    	while(i<a.length() && j<s.length()){
    		if(s.charAt(j)==a.charAt(i)) i++;
    		j++;
    	}
    	return i>=a.length();
    }
    static boolean isPalindrome(String a){
    	int n=a.length();
    	for(int i=0;i<a.length();i++){
    		if(a.charAt(i)!=a.charAt(n-i-1)) return false;
    	}
    	return true;
    	
    }
    
    
    static int lengthOfLIS(int[] nums) 
    {
       int n=nums.length;
       int[] lisi = new int[n];
       for(int i=0;i<n;i++) lisi[i]=1;

       for(int i=1;i<n;i++){
       	 for(int j=0;j<i;j++){
       	 	if(nums[j]<=nums[i]){
       	 		lisi[i]=lisi[j]+1;
       	 	}
       	 }
       }
       return lisi[n-1];
    }
    // static int lengthOfLIS(int[] nums) 
    // {
    // int[] tails = new int[nums.length];
    // int size = 0;
    // for (int x : nums) {
    //     int i = 0, j = size;
    //     while (i != j) {
    //         int m = (i + j) / 2;
    //         if (tails[m] <= x)
    //             i = m + 1;
    //         else
    //             j = m;
    //     }
    //     tails[i] = x;
    //     if (i == size) ++size;
    // }
    // return size;
    // }
    


    
    static void swap(int[] arr,int a,int b){
    	int temp = arr[a];
    	arr[a] = arr[b];
    	arr[b] = temp;

    }
    static int max(int a, int b)
    {
        if(a<b)
        	return b;
        return a;
    }
    static int min(int a,int b){
    	if(a > b) 
    		return b;
    	return a;
    }
 
 
    static void ruffleSort(int[] a) {
        int n=a.length;
        for (int i=0; i<n; i++) {
            int oi=random.nextInt(n), temp=a[oi];
            a[oi]=a[i]; a[i]=temp;
        }
        Arrays.sort(a);
    }
 
    static < E > void print(E res)
    {
        System.out.println(res);
    }
 
 
    static  int gcd(int a,int b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
 
    static int lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }
 
 
    static int abs(int a)
    {
        if(a<0)
            return -1*a;
        return a;
    }
 
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt()
        {
            return Integer.parseInt(next());
        }
 
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
 
        int [] readintarray(int n) {
            int res [] = new int [n];
            for(int i = 0; i<n; i++)res[i] = nextInt();
            return res;
        }
        long [] readlongarray(int n) {
            long res [] = new long [n];
            for(int i = 0; i<n; i++)res[i] = nextLong();
            return res;
        }
    }
 
}
